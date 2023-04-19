#include <gtest/gtest.h>
#include "../../Structures/Heap.h"
#include <string>

using namespace std;

TEST(HeapTest, EmptyHeap)
{
    Heap heap;
    EXPECT_EQ(0, heap.getSize());
    EXPECT_EQ(-1, heap.peek());
    heap.pop();
    EXPECT_EQ(0, heap.getSize());
}

TEST(HeapTest, SingleElementHeap)
{
    Heap heap;
    heap.push(42);
    EXPECT_EQ(1, heap.getSize());
    EXPECT_EQ(42, heap.peek());
    heap.pop();
    EXPECT_EQ(0, heap.getSize());
}

TEST(HeapTest, LargerHeap)
{
    Heap heap;
    heap.push(3);
    heap.push(2);
    heap.push(1);
    heap.push(4);
    heap.push(5);
    EXPECT_EQ(5, heap.getSize());
    EXPECT_EQ(5, heap.peek());
    heap.pop();
    EXPECT_EQ(4, heap.getSize());
    EXPECT_EQ(4, heap.peek());
    heap.pop();
    EXPECT_EQ(3, heap.getSize());
    EXPECT_EQ(3, heap.peek());
    heap.pop();
    EXPECT_EQ(2, heap.getSize());
    EXPECT_EQ(2, heap.peek());
    heap.pop();
    EXPECT_EQ(1, heap.getSize());
    EXPECT_EQ(1, heap.peek());
    heap.pop();
    EXPECT_EQ(0, heap.getSize());
    EXPECT_EQ(-1, heap.peek());
}


TEST(HeapTest, PushAndPopTest) {
    Heap heap;
    heap.push(5);
    heap.push(7);
    heap.push(3);
    heap.push(1);

    EXPECT_EQ(heap.getSize(), 4);

    EXPECT_EQ(heap.peek(), 7);

    heap.pop();
    EXPECT_EQ(heap.getSize(), 3);
    EXPECT_EQ(heap.peek(), 5);

    heap.pop();
    EXPECT_EQ(heap.getSize(), 2);
    EXPECT_EQ(heap.peek(), 3);

    heap.pop();
    EXPECT_EQ(heap.getSize(), 1);
    EXPECT_EQ(heap.peek(), 1);

    heap.pop();
    EXPECT_EQ(heap.getSize(), 0);
    ASSERT_DEATH(heap.peek(), "");
}

TEST(HeapTest, SearchTest) {
    Heap heap;
    heap.push(5);
    heap.push(7);
    heap.push(3);
    heap.push(1);

    EXPECT_EQ(heap.search(3), 2);
    EXPECT_EQ(heap.search(7), 0);
    EXPECT_EQ(heap.search(5), 1);
    EXPECT_EQ(heap.search(10), -1);
}