#include "d-heap.h"

#include <gtest.h>

TEST(D_heap, can_create_d_heap)
{
	ASSERT_NO_THROW(D_heap heap(20,2));
}

TEST(D_heap, cant_create_heap_with_too_large_size)
{
	ASSERT_ANY_THROW(D_heap heap(MAX_D_HEAP_SIZE+1,2));
}

TEST(D_heap, cant_create_heap_with_negative_size)
{
	ASSERT_ANY_THROW(D_heap h1(-5,2));
}

TEST(D_heap, copied_vector_is_equal_to_source_one)
{
	D_heap h1(5,2);
	for (int i=0; i<h1.GetSize(); i++)
		h1.keys[i] = (rand() % 10);
	D_heap h2(h1);
	EXPECT_EQ(h1,h2);
}

TEST(D_heap, can_get_size)
{
	D_heap h1(5,2);
	ASSERT_NO_THROW(h1.GetSize());
}

TEST(D_heap, can_get_size_correct)
{
	D_heap h1(5,2);
	EXPECT_EQ(5,h1.GetSize());
}