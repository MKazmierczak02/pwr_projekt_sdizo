#include <gtest/gtest.h>
#include "../../Structures/List.h"

// Test dodawania elementów na początku listy
TEST(ListTest, PushFront) {
    List list;
    list.pushFront(1);
    list.pushFront(2);
    list.pushFront(3);
    EXPECT_EQ(list.popFront(), 3);
    EXPECT_EQ(list.popFront(), 2);
    EXPECT_EQ(list.popFront(), 1);
    EXPECT_EQ(list.popFront(), -1); // oczekiwany brak elementów
}

// Test dodawania elementów na końcu listy
TEST(ListTest, PushBack) {
    List list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    EXPECT_EQ(list.popFront(), 1);
    EXPECT_EQ(list.popFront(), 2);
    EXPECT_EQ(list.popFront(), 3);
    EXPECT_EQ(list.popFront(), -1); // oczekiwany brak elementów
}

// Test wyszukiwania elementu po wartości
TEST(ListTest, FindElementByValue) {
    List list;
    list.pushFront(1);
    list.pushFront(2);
    list.pushFront(3);
    Elem* elem = list.findElementByValue(2);
    EXPECT_NE(elem, nullptr);
    EXPECT_EQ(elem->data, 2);
}

// Test usuwania elementu ze środka listy
TEST(ListTest, DeleteItemMiddle) {
    List list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    Elem* elem = list.findElementByValue(2);
    ASSERT_NE(elem, nullptr);
    list.deleteItem(elem);
    EXPECT_EQ(list.popFront(), 1);
    EXPECT_EQ(list.popFront(), 3);
    EXPECT_EQ(list.popFront(), -1); // oczekiwany brak elementów
}

// Test usuwania pierwszego elementu z listy
TEST(ListTest, DeleteItemFirst) {
    List list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    Elem* elem = list.findElementByValue(1);
    ASSERT_NE(elem, nullptr);
    list.deleteItem(elem);
    EXPECT_EQ(list.popFront(), 2);
    EXPECT_EQ(list.popFront(), 3);
    EXPECT_EQ(list.popFront(), -1); // oczekiwany brak elementów
}

// Test usuwania ostatniego elementu z listy
TEST(ListTest, DeleteItemLast) {
    List list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    Elem* elem = list.findElementByValue(3);
    ASSERT_NE(elem, nullptr);
    list.deleteItem(elem);
    EXPECT_EQ(list.popFront(), 1);
    EXPECT_EQ(list.popFront(), 2);
    EXPECT_EQ(list.popFront(), -1); // oczekiwany brak elementów
}

// Test wczytywania danych z pliku
TEST(ListTest, LoadFromFile) {
    List list;
    list.loadFromFile("tab1.txt");
    list.deleteItem(6);
    list.deleteItem(10);
    list.deleteItem(2);
    list.deleteItem(4);
    list.deleteItem(8);
    list.pushOnIndex();




}

