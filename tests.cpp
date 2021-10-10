#include "gtest/gtest.h"
#include "Unique_ptr.cpp"
#include <memory>


TEST(UniquePointerTests, CreatePointerWithoutArgumentsAndExpectNullptrAfterCallGet) {
    Unique<int> uniq;
    EXPECT_EQ(uniq.get(), nullptr);
}

TEST(UniquePointerTests, CreatePointerWithOneIntAsArgumentAndExpectAdressesAreTheSame) {
    int* number = new int(5);
    Unique<int> uniq{number};
    EXPECT_EQ(uniq.get(), number);
}

TEST(UniquePointerTests, CreatePointerWithOneArgumentUsingMoveSemanticAndExpectAdressesAreTheSame) {
    int* number = new int(5);
    Unique<int> uniq{std::move(number)};
    EXPECT_EQ(uniq.get(), number);
}

// TEST(UniquePointerTests, UsingStarOperatorExpectAccessToTheElement) {
//     int* number = new int(5);
//     Unique<int> uniq{number};
//     EXPECT_EQ(*uniq, 5);
// }

// TEST(UniquePointerTests)
