#include "disjoint_set.h"

#include <gtest.h>

TEST(Disjoint_set, can_create_disjoint_set)
{
	ASSERT_NO_THROW(Disjoint_set set());
}
//////////////////////////////////
TEST(Disjoint_set, cant_create_disjoint_set_with_negative_size)
{
	ASSERT_ANY_THROW(Disjoint_set set(-2));
}
///////////////////////////////////
TEST(Disjoint_set, can_create_Singleton)
{
	Disjoint_set set;
	ASSERT_ANY_THROW(set.CreateSingleton(1));
}

TEST(Disjoint_set, cant_create_Singleton_with_x_less_then_0)
{
	Disjoint_set set;
	ASSERT_ANY_THROW(set.CreateSingleton(-1));
}
//////////////////////////////////////
TEST(Disjoint_set, can_FindSubset)
{
	Disjoint_set set;
	set.CreateSingleton(0);
	set.CreateSingleton(1);
	ASSERT_NO_THROW(set.FindSubset(0));
}

TEST(Disjoint_set, cant_FindSubset_with_negative_size)
{
	Disjoint_set set;
	set.CreateSingleton(0);
	set.CreateSingleton(1);
	ASSERT_ANY_THROW(set.FindSubset(-2));
}

TEST(Disjoint_set, cant_FindSubset_with_doesnt_exist_elem_in_set)
{
	Disjoint_set set;
	set.CreateSingleton(0);
	set.CreateSingleton(1);
	ASSERT_ANY_THROW(set.FindSubset(2));
}

TEST(Disjoint_set, cant_FindSubset_with_size_too_large)
{
	Disjoint_set set;
	set.CreateSingleton(0);
	set.CreateSingleton(1);
	ASSERT_ANY_THROW(set.FindSubset(100));
}
/////////////////////////////////////////////////////////
TEST(Disjoint_set, can_GetMaxsize)
{
	Disjoint_set set;
	ASSERT_NO_THROW(set.GetMaxsize());
}
//////////////////////////////////////////////////
//Union