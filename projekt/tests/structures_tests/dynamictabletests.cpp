#include "../../Structures/DynamicTable.h"
#include <gtest/gtest.h>

TEST(DynamicTableTest, InsertBackTest) {
    DynamicTable dt;
    dt.insertBack(1);
    EXPECT_EQ(1, dt.get(0));

    dt.insertBack(2);
    EXPECT_EQ(2, dt.get(1));
}

TEST(DynamicTableTest, InsertFrontTest) {
    DynamicTable dt;
    dt.insertFront(1);
    EXPECT_EQ(1, dt.get(0));

    dt.insertFront(2);
    EXPECT_EQ(2, dt.get(0));
}

TEST(DynamicTableTest, InsertOnIndexTest) {
    DynamicTable dt;
    dt.insertBack(1);
    dt.insertBack(3);

    dt.insertOnIndex(1, 2);
    EXPECT_EQ(2, dt.get(1));
}

TEST(DynamicTableTest, DelTest) {
    DynamicTable dt;
    dt.insertBack(1);
    dt.insertBack(2);
    dt.insertBack(3);

    dt.del(1);
    EXPECT_EQ(2, dt.getSize());
    EXPECT_EQ(3, dt.get(1));
}

TEST(DynamicTableTest, DelFrontTest) {
    DynamicTable dt;
    dt.insertBack(1);
    dt.insertBack(2);

    dt.delFront();
    EXPECT_EQ(1, dt.getSize());
    EXPECT_EQ(2, dt.get(0));
}

TEST(DynamicTableTest, DelBackTest) {
    DynamicTable dt;
    dt.insertBack(1);
    dt.insertBack(2);

    dt.delBack();
    EXPECT_EQ(1, dt.getSize());
    EXPECT_EQ(1, dt.get(0));
}

TEST(DynamicTableTest, GetTest) {
    DynamicTable dt;
    dt.insertBack(1);
    dt.insertBack(2);
    dt.insertBack(3);

    EXPECT_EQ(2, dt.get(1));
    EXPECT_EQ(-1, dt.get(3));
}

TEST(DynamicTableTest, IndexOfTest) {
    DynamicTable dt;
    dt.insertBack(1);
    dt.insertBack(2);
    dt.insertBack(3);

    EXPECT_EQ(1, dt.indexOf(2));
    EXPECT_EQ(-1, dt.indexOf(4));
}

TEST(DynamicTableTest, FullTest) {
    DynamicTable dt;
    dt.loadFromFile("tab1.txt");
    dt.del(2);
    dt.del(3);
    dt.del(0);
    dt.del(0);
    dt.del(0);
    dt.insertOnIndex(0, 2);
    dt.insertOnIndex(1, 6);
    dt.insertOnIndex(2, 8);
    dt.insertOnIndex(1, 4);
    dt.insertOnIndex(0, 0);

    EXPECT_EQ(0, dt.get(0));
    EXPECT_EQ(2, dt.get(1));
    EXPECT_EQ(4, dt.get(2));
    EXPECT_EQ(6, dt.get(3));
    EXPECT_EQ(8, dt.get(4));
}

