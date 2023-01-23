#include <gtest/gtest.h>
#include "clrs.hpp"
#include <iostream>

using std::cout;
using std::endl;

class VectorTest : public ::testing::Test {

};

TEST(hello, hello) {
    EXPECT_EQ(1, 1);
}


TEST(sort, insert) {
    vector<int> v1{5, 2, 1, 4, 6};
    /*
    cout << "Raw Array => [ ";
    for (auto i : v1) {
        cout << i << " ";
    }
    cout << "]"<< endl;
    */
    EXPECT_EQ(Insertion_Sort_Nondec(v1), Status::OK);
    EXPECT_EQ(v1[0], 1);
    EXPECT_EQ(v1[1], 2);
    EXPECT_EQ(v1[2], 4);
    EXPECT_EQ(v1[3], 5);
    EXPECT_EQ(v1[4], 6);
    cout << v1 << endl;

    vector<int> v2{};
    EXPECT_EQ(Insertion_Sort_Nondec(v2), Status::ARRAY_IS_EMPTY);

    EXPECT_EQ(Insertion_Sort_Nonasc(v1), Status::OK);
    cout << v1 << endl;
}

TEST(sort, find) {
    vector<int> v1{4, 33, 22, 11, 42, 5, 31};
    int index = -1;
    EXPECT_EQ(Find_value(v1, 33, index), Status::OK);
    EXPECT_EQ(index, 1);
    EXPECT_EQ(Find_value(v1, 31, index), Status::OK);
    EXPECT_EQ(index, 6);
    EXPECT_EQ(Find_value(v1, 312, index), Status::VAL_NOT_FOUND);

    vector<int> v2{};
    EXPECT_EQ(Find_value(v2, 0, index), Status::ARRAY_IS_EMPTY);
}

TEST(sort, add_bin) {
    vector<int> v1{1, 1, 0, 1};
    vector<int> v2{0, 1, 0, 1};
    vector<int> ret = Bin_Addition(v1, v2);
    cout << v1 << " + " << v2 << " = " << ret << endl;


    vector<int> v4{0, 0, 1};
    vector<int> v5{0, 1, 1};
    vector<int> v6 = Bin_Addition(v4, v5);
    cout << v4 << " + " << v5 << " = " << v6 << endl;
}

TEST(sort, select) {
    vector<int> v1{5, 2, 1, 4, 6};
    EXPECT_EQ(Select_Sort_Nondec(v1), Status::OK);
    cout << v1 << endl;
}