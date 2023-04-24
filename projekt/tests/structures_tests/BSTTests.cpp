#include <gtest/gtest.h>
#include "../../Structures/BST.cpp"
#include <string>

using namespace std;

TEST(BSTTest, InsertRoot) {
    BST tree;
    tree.insert(5);
    EXPECT_EQ(tree.getSize(), 1);
    EXPECT_EQ(tree.getRoot()->data, 5);
}

TEST(BSTTest, InsertLeft) {
    BST tree;
    tree.insert(5);
    tree.insert(3);
    EXPECT_EQ(tree.getSize(), 2);
    EXPECT_EQ(tree.getRoot()->left->data, 3);
}

TEST(BSTTest, InsertRight) {
    BST tree;
    tree.insert(5);
    tree.insert(8);
    EXPECT_EQ(tree.getSize(), 2);
    EXPECT_EQ(tree.getRoot()->right->data, 8);
}

TEST(BSTTest, InsertDuplicate) {
    BST tree;
    tree.insert(5);
    tree.insert(5);
    EXPECT_EQ(tree.getSize(), 2);
}

// Testy dla metody search()

TEST(BSTTest, SearchEmpty) {
    BST tree;
    EXPECT_EQ(tree.search(5), nullptr);
}

TEST(BSTTest, SearchNotFound) {
    BST tree;
    tree.insert(5);
    EXPECT_EQ(tree.search(7), nullptr);
}

TEST(BSTTest, SearchFound) {
    BST tree;
    tree.insert(5);
    EXPECT_NE(tree.search(5), nullptr);
}

// Testy dla metody remove()

TEST(BSTTest, RemoveEmpty) {
    BST tree;
    EXPECT_FALSE(tree.remove(5));
}

TEST(BSTTest, RemoveNotFound) {
    BST tree;
    tree.insert(5);
    EXPECT_FALSE(tree.remove(7));
    EXPECT_EQ(tree.getSize(), 1);
}

TEST(BSTTest, RemoveRoot) {
    BST tree;
    tree.insert(5);
    EXPECT_TRUE(tree.remove(5));
    EXPECT_EQ(tree.getSize(), 0);
    EXPECT_EQ(tree.getRoot(), nullptr);
}

TEST(BSTTest, RemoveLeaf) {
    BST tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    EXPECT_TRUE(tree.remove(3));
    EXPECT_EQ(tree.getSize(), 2);
    EXPECT_EQ(tree.getRoot()->left, nullptr);
}

TEST(BSTTest, RemoveOneChild) {
    BST tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    EXPECT_TRUE(tree.remove(7));
    EXPECT_EQ(tree.getSize(), 2);
}

TEST(BSTTest, RemoveTwoChildren) {
    BST tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    EXPECT_TRUE(tree.remove(5));
    EXPECT_EQ(tree.getSize(), 2);
}