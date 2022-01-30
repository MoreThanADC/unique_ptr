#include "gtest/gtest.h"

#include "Unique.hpp"

#include <memory>
#include <stdexcept>
#include <string>

constexpr const int testValue = 42;
const std::string testString = "Ala ma kota";

class UniqueTestWithNullptr : public ::testing::Test {
public:
    Unique<int> uniq = nullptr;
};

class UniqueTestWithRealValue : public ::testing::Test {
public:
    Unique<int> uniq = new int(testValue);
};

TEST_F(UniqueTestWithNullptr, CreatePointerWithoutArgsAndExpectNullptr) {
    EXPECT_EQ(uniq.get(), nullptr);
}

TEST_F(UniqueTestWithNullptr, UsingStarOperatorOnNullptrExpectThrowAnException) {
    EXPECT_THROW(*uniq, std::runtime_error);
}

TEST_F(UniqueTestWithRealValue, CreatePointerWithOneArgumentAndExpectAdressesAreTheSame) {
    EXPECT_EQ(*uniq.get(), testValue);
}

TEST_F(UniqueTestWithRealValue, CreatePonterWithOneArgumentUsingMoveAndExpectAdressesAreTheSame) {
    Unique<int> newUniq{std::move(uniq)};
    EXPECT_EQ(*newUniq.get(), testValue);
}

TEST_F(UniqueTestWithRealValue, UsingStarOperatorExpectAccessToTheElement) {
    EXPECT_EQ(*uniq, testValue);
}

TEST_F(UniqueTestWithRealValue, UsingRelaseExpectThatReturnedValueIsRawPointer) {
    auto rawPtr = uniq.release();
    EXPECT_EQ(*rawPtr, testValue);
    delete rawPtr;
}

TEST_F(UniqueTestWithRealValue, UsingRelaseExpectThatResourceHasBeenReleased) {
    auto rawPtr = uniq.release();
    EXPECT_EQ(uniq.get(), nullptr);
    delete rawPtr;
}

TEST_F(UniqueTestWithRealValue, UsingResetWitoutArgumentsExpectNullptr) {
    uniq.reset();
    EXPECT_EQ(uniq.get(), nullptr);
}

TEST_F(UniqueTestWithRealValue, UsingResetWithArgumentExpectNewPointerInPlaceOldPointer) {
    int* newValue = new int(10);
    uniq.reset(newValue);
    EXPECT_EQ(uniq.get(), newValue);
}

TEST (UniqueTestWithOtherType, CreatePointerWithOneArgumentAsStringAndExpectAdressesAreTheSame) {
    Unique<std::string> uniq = new std::string(testString);
    EXPECT_EQ(*uniq.get(), testString);
}