#include <gtest/gtest.h>
#include "../../Structures/List.cpp"

TEST(ListTest, PushFront) {
    List list;
    list.pushFront(1);
    list.pushFront(2);
    list.pushFront(3);
    EXPECT_EQ(list.popFront(), 3);
    EXPECT_EQ(list.popFront(), 2);
    EXPECT_EQ(list.popFront(), 1);
    EXPECT_EQ(list.popFront(), -1);
}

TEST(ListTest, PushBack) {
    List list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    EXPECT_EQ(list.popFront(), 1);
    EXPECT_EQ(list.popFront(), 2);
    EXPECT_EQ(list.popFront(), 3);
    EXPECT_EQ(list.popFront(), -1);
}

TEST(ListTest, FindElementByValue) {
    List list;
    list.pushFront(1);
    list.pushFront(2);
    list.pushFront(3);
    Elem* elem = list.findElementByValue(2);
    EXPECT_NE(elem, nullptr);
    EXPECT_EQ(elem->data, 2);
}

TEST(ListTest, DeleteItemMiddle) {
    List list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    Elem* elem = list.findElementByValue(2);
    ASSERT_NE(elem, nullptr);
    list.deleteItem(2);
    EXPECT_EQ(list.popFront(), 1);
    EXPECT_EQ(list.popFront(), 3);
    EXPECT_EQ(list.popFront(), -1);
}

TEST(ListTest, DeleteItemFirst) {
    List list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    Elem* elem = list.findElementByValue(1);
    ASSERT_NE(elem, nullptr);
    list.deleteItem(1);
    EXPECT_EQ(list.popFront(), 2);
    EXPECT_EQ(list.popFront(), 3);
    EXPECT_EQ(list.popFront(), -1);
}

TEST(ListTest, DeleteItemLast) {
    List list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    Elem* elem = list.findElementByValue(3);
    ASSERT_NE(elem, nullptr);
    list.deleteItem(3);
    EXPECT_EQ(list.popFront(), 1);
    EXPECT_EQ(list.popFront(), 2);
    EXPECT_EQ(list.popFront(), -1);
}

TEST(ListTest, FullTests) {
    List list;
    list.loadFromFile("tab1.txt");
    list.deleteItem(6);
    list.deleteItem(10);
    list.deleteItem(2);
    list.deleteItem(4);
    list.deleteItem(8);
    list.printFront();
    list.insertOnIndex(0,2);
    list.insertOnIndex(1,6);
    list.insertOnIndex(2,8);
    list.insertOnIndex(1,4);
    list.insertOnIndex(0,0);
    list.printFront();
}

