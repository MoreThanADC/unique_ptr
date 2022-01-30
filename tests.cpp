#include "gtest/gtest.h"

#include "Unique.hpp"

#include <memory>

// class UniqueTest : public ::testing::Test {


// }

TEST(UniquePointerTests, CreatePointerWithoutArgsAndExpectNullptr) {
    Unique::Uniq<int> uniq;
    EXPECT_EQ(uniq.get(), nullptr);
}

TEST(UniquePointerTests, CreatePointerWithOneArgumentAndExpectAdressesAreTheSame) {
    int* number = new int(42);
    Unique<int> uniq{number};
    EXPECT_EQ(uniq.get(), number);
}

TEST(UniquePointerTests, CreatePonterWiithOneArgumentUsingMoveSemanticAndExpectAdressesAreTheSame) {
    int* number = new int(42);
    Unique<int> uniq{std::move(number)};
    EXPECT_EQ(uniq.get(), number);
}

TEST(UniquePointerTests, UsingStarOperatorExpectAccessToTheElement) {
    int* number = new int(42);
    Unique<int> uniq{number};
    EXPECT_EQ(*uniq, *number);
}

TEST(UniquePointerTests, UsingRelaseExpectReturnedValueIsRawPointer) {
    int* number = new int(42);
    Unique<int> uniq{number};
    EXPECT_EQ(uniq.release(), number);
    delete number;
}

TEST(UniquePointerTests, UsingRelaseExpectUniqeIsNullpointer) {
    int* number = new int(42);
    Unique<int> uniq{number};
    uniq.release();
    EXPECT_EQ(uniq.get(), nullptr);
    delete number;
}

TEST(UniquePointerTests, UsingResetWitoutArgumentsExpectNullptr) {
    int* number = new int(42);
    Unique<int> uniq{number};
    uniq.reset();
    EXPECT_EQ(uniq.get(), nullptr);
}

TEST(UniquePointerTests, UsingResetWithArgumentExpectNewPointerInPlaceOldPointer) {
    int* number = new int(42);
    Unique<int> uniq{number};
    int* number2 = new int(10);
    uniq.reset(number2);
    EXPECT_EQ(uniq.get(), number2);
}
