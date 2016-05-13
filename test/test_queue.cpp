#include "queue.h"

#include <gtest.h>

TEST(Queue, can_create_queue)
{
	ASSERT_NO_THROW(Queue que(10));
}

TEST(Queue, cant_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(Queue que(-10));
}
////////////////////////////////////////////////
TEST(Queue, can_create_queue_from_mass)
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
}
///////////////////////////////////////////////////
TEST(Queue, can_create_copy_of_queue)
{
	Queue q(10);
	ASSERT_NO_THROW(Queue que(q));
}

TEST(Queue, can_create_copy_of_queue_correct)
{
	Queue q(10);
	Queue que(q);
	EXPECT_EQ(que, q);
}
////////////////////////////////////////////////////
TEST(Queue, can_pop_queue)
{
	Queue q(10);
	ASSERT_NO_THROW(q.Pop());
}
/*
TEST(Queue, can_pop_queue_correct)
{
	Queue q(10);
	q.Insert();
	ASSERT_NO_THROW(q.Pop());
}*/
////////////////////////////////////////////////////
TEST(Queue, can_IsEmpty)
{
	Queue q(10);
	ASSERT_NO_THROW(q.IsEmpty());
}

TEST(Queue, can_IsEmpty_correct)
{
	Queue q(10);
	EXPECT_EQ(q.IsEmpty(),0);
}
/*
TEST(Queue, can_IsEmpty_correct)
{
	Queue q();
	EXPECT_EQ(q.IsEmpty(),1);
}*/
////////////////////////////////////////////////////
//operator=
TEST(Queue, can_assign_queue)
{
	Queue q(10);
	Queue q1(10);
	ASSERT_NO_THROW(q = q1);
}

TEST(Queue, can_assign_queue_with_different_size)
{
	Queue q(10);
	Queue q1(100);
	ASSERT_NO_THROW(q = q1);
}

TEST(Queue, can_assign_queue_with_different_size_corrrect)
{
	Queue q(10);
	Queue q1(100);
	q = q1;
	EXPECT_EQ(q, q1);
}
/////////////////////////////////////////////