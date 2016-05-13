#include "queue.h"
#include "graph.h"
#include <gtest.h>

TEST(Queue, can_create_queue)
{
	ASSERT_NO_THROW(D_heap_Queue que(10));
}

TEST(Queue, cant_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(D_heap_Queue que(-10));
}
////////////////////////////////////////////////
/*TEST(Queue, can_create_queue_from_mass)
{
	int size = 10;
	int *p = new int[size];
	ASSERT_NO_THROW(Queue que(p,10));
}

TEST(Queue, cant_create_queue_from_mass_with_negative_size)
{
	int size = 10;
	int *p = new int[size];
	ASSERT_ANY_THROW(Queue que(p,-10));
}*/
/////////////////////////////////////////////////
//Copy
TEST(Queue, can_create_copy_of_queue)
{
	D_heap_Queue q(10);
	ASSERT_NO_THROW(D_heap_Queue que(q));
}

TEST(Queue, can_create_copy_of_queue_correct)
{
	D_heap_Queue q(10);
	D_heap_Queue que(q);
	EXPECT_NE(&que, &q);
}
////////////////////////////////////////////////////
TEST(Queue, can_pop_queue)
{
	D_heap_Queue q(10);
	ASSERT_NO_THROW(q.Pop());
}

TEST(Queue, can_pop_queue_correct)
{
	Edge *e = new Edge[3];
	
	e[0].v1 = 10;
	e[0].v2 = 2;
	e[0].ves = 8;

	e[1].v1 = 2;
	e[1].v2 = 3;
	e[1].ves = 5;

	e[2].v1 = 3;
	e[2].v2 = 4;
	e[2].ves = 0;

	D_heap_Queue q(e,3);
	q.Pop();

	Edge *e1 = new Edge[2];
	
	e1[0].v1 = 10;
	e1[0].v2 = 2;
	e1[0].ves = 8;

	e1[1].v1 = 2;
	e1[1].v2 = 3;
	e1[1].ves = 5;

	D_heap_Queue q1(e1,2);

	EXPECT_EQ(q1,q);
}
////////////////////////////////////////////////////
TEST(Queue, can_IsEmpty)
{
	D_heap_Queue q(10);
	ASSERT_NO_THROW(q.IsEmpty());
}

TEST(Queue, can_IsEmpty_correct)
{
	D_heap_Queue q(10);
	EXPECT_EQ(q.IsEmpty(),0);
}
//////////////////////////////////////////////////Copy_queue_from_egde
TEST(Queue, can_copy_queue_from_egde)
{
	Edge *e = new Edge[5];
	ASSERT_NO_THROW(D_heap_Queue q(e,5));
}

TEST(Queue, cant_copy_queue_from_egde_with_negative_size)
{
	Edge *e = new Edge[5];
	ASSERT_ANY_THROW(D_heap_Queue q(e,-5));
}

TEST(Queue, cant_copy_queue_from_null_egde)
{
	Edge *e = 0;
	ASSERT_ANY_THROW(D_heap_Queue q(e,5));
}
////////////////////////////////////////////////////
//operator=
TEST(Queue, can_assign_queue)
{
	D_heap_Queue q(10);
	D_heap_Queue q1(10);
	ASSERT_NO_THROW(q = q1);
}

TEST(Queue, can_assign_queue_with_different_size)
{
	D_heap_Queue q(10);
	D_heap_Queue q1(100);
	ASSERT_NO_THROW(q = q1);
}

TEST(Queue, can_assign_queue_with_different_size_corrrect)
{
	D_heap_Queue q(10);
	D_heap_Queue q1(100);
	q = q1;
	EXPECT_EQ(q.GetQsize(), q1.GetQsize());
}
///////////////////////////////////////////////////
//operator==
TEST(Queue, can_compare_equal_queues)
{
	D_heap_Queue q(10);
	D_heap_Queue q1(10);
	ASSERT_NO_THROW(q == q1);
}

TEST(Queue, compare_equal_queues_return_true)
{
	D_heap_Queue q(10);   //из 0
	D_heap_Queue q1(10);
	EXPECT_TRUE(q == q1);
}

TEST(Queue, compare_not_equal_queues_return_false)
{
	D_heap_Queue q(6);   //из 0
	D_heap_Queue q1(10);
	EXPECT_FALSE(q == q1);
}

TEST(Queue, compare_queues_with_not_equal_ves_return_false)
{
	Edge *e = new Edge[2];
	e[0].v1 = 10;
	e[0].v2 = 2;
	e[0].ves = 7;

	e[1].v1 = 2;
	e[1].v2 = 3;
	e[1].ves = 5;

	D_heap_Queue q(e,2);
	Edge *e1 = new Edge[2];
	e1[0].v1 = 10;
	e1[0].v2 = 2;
	e1[0].ves = 8;

	e1[1].v1 = 2;
	e1[1].v2 = 3;
	e1[1].ves = 5;
	D_heap_Queue q1(e1,2);
	EXPECT_FALSE(q == q1);
}
/////////////////////////////////////////////////////
//operator !=
TEST(Queue, can_compare_not_equal_queues)
{
	D_heap_Queue q(3);
	D_heap_Queue q1(10);
	ASSERT_NO_THROW(q != q1);
}

TEST(Queue, compare_not_equal_queues_return_true)
{
	D_heap_Queue q(5);   //из 0
	D_heap_Queue q1(10);
	EXPECT_TRUE(q != q1);
}

TEST(Queue, compare_equal_queues_return_false)
{
	D_heap_Queue q(10);   //из 0
	D_heap_Queue q1(10);
	EXPECT_FALSE(q != q1);
}

TEST(Queue, compare_queues_with_not_equal_ves_return_true)
{
	Edge *e = new Edge[2];
	e[0].v1 = 10;
	e[0].v2 = 2;
	e[0].ves = 7;

	e[1].v1 = 2;
	e[1].v2 = 3;
	e[1].ves = 5;

	D_heap_Queue q(e,2);
	Edge *e1 = new Edge[2];
	e1[0].v1 = 10;
	e1[0].v2 = 2;
	e1[0].ves = 8;

	e1[1].v1 = 2;
	e1[1].v2 = 3;
	e1[1].ves = 5;
	D_heap_Queue q1(e1,2);
	EXPECT_TRUE(q != q1);
}