#include "pch.h"
#include "..\simpleQueue\simpleQueue.h"
#define GTEST_COUT std::cerr << "[          ] [ INFO ]"
TEST(Simple_Queue, insert_in_to_single_group)
{
	IsraelieQueueImplimitation stTsraelieQueue;
	stTsraelieQueue.Enque(1);
  EXPECT_EQ(stTsraelieQueue.NumberOfGroups(), 1);
  
}



TEST(Simple_Queue, is_empty)
{
	IsraelieQueueImplimitation stTsraelieQueue;
	
	EXPECT_EQ(stTsraelieQueue.IsEmpty(), true);

}

TEST(Simple_Queue, order_with_equal_size_single_groups)
{
	IsraelieQueueImplimitation stTsraelieQueue;
	stTsraelieQueue.Enque(1);
	stTsraelieQueue.Enque(2);
	stTsraelieQueue.Enque(3);
	int value;
	stTsraelieQueue.Deque(value);

	EXPECT_EQ(value, 1);
	stTsraelieQueue.Deque(value);

	EXPECT_EQ(value, 2);
	stTsraelieQueue.Deque(value);

	EXPECT_EQ(value, 3);

}

TEST(Simple_Queue, is_empty_after_dequeue)
{
	IsraelieQueueImplimitation stTsraelieQueue;
	stTsraelieQueue.Enque(1);
	int value;
	stTsraelieQueue.Deque(value);

	EXPECT_EQ(stTsraelieQueue.IsEmpty(), true);

}
TEST(Simple_Queue, sanity_largest_group_index)
{
	IsraelieQueueImplimitation stTsraelieQueue;
	stTsraelieQueue.Enque(1);
	
	EXPECT_EQ(stTsraelieQueue.LargestGroupIndex(), 0);

}

TEST(Simple_Queue, sanity_largest_group_number_of_elelments)
{
	IsraelieQueueImplimitation stTsraelieQueue;
	stTsraelieQueue.Enque(1);
	stTsraelieQueue.Enque(3, 2);
	EXPECT_EQ(stTsraelieQueue.NumberOfElementsInLargesetGroup(), 1);
}

TEST(Simple_Queue, sanity_no_items_largest_group_index)
{
	IsraelieQueueImplimitation stTsraelieQueue;

	EXPECT_EQ(stTsraelieQueue.LargestGroupIndex(), INVALID_NUMBER);

}

TEST(Simple_Queue, sanity_no_items_largest_group_number_of_elelments)
{
	IsraelieQueueImplimitation stTsraelieQueue;
	EXPECT_EQ(stTsraelieQueue.NumberOfElementsInLargesetGroup(), INVALID_NUMBER);
}


TEST(IsraelieQueue, insert_in_to_2_groups_no_friends)
{
	IsraelieQueueImplimitation stTsraelieQueue;
	stTsraelieQueue.Enque(1);
	stTsraelieQueue.Enque(2);
	EXPECT_EQ(stTsraelieQueue.NumberOfGroups(), 2);

}

TEST(IsraelieQueue, insert_in_to_2_groups_friend_specified_but_not_there)
{
	IsraelieQueueImplimitation stTsraelieQueue;
	stTsraelieQueue.Enque(1);
	stTsraelieQueue.Enque(2,99);
	EXPECT_EQ(stTsraelieQueue.NumberOfGroups(), 2);

}

TEST(IsraelieQueue, insert_in_to_group_chained)
{
	IsraelieQueueImplimitation stTsraelieQueue;
	stTsraelieQueue.Enque(1);
	stTsraelieQueue.Enque(2,1);
	stTsraelieQueue.Enque(3,2);
	stTsraelieQueue.Enque(4, 3);
	EXPECT_EQ(stTsraelieQueue.NumberOfGroups(), 1);
	EXPECT_EQ(stTsraelieQueue.NumberOfElementsInLargesetGroup(), 4);

}
TEST(IsraelieQueue, insert_in_to_2_groups_with_friends)
{
	IsraelieQueueImplimitation stTsraelieQueue;
	stTsraelieQueue.Enque(1);
	stTsraelieQueue.Enque(2);
	stTsraelieQueue.Enque(3, 2);
	EXPECT_EQ(stTsraelieQueue.NumberOfGroups(), 2);

}

TEST(IsraelieQueue, insert_in_to_2_groups_with_friends_largest_group_index)
{
	IsraelieQueueImplimitation stTsraelieQueue;
	stTsraelieQueue.Enque(1);
	stTsraelieQueue.Enque(2);
	stTsraelieQueue.Enque(3, 2);
	EXPECT_EQ(stTsraelieQueue.LargestGroupIndex(), 1);

}

TEST(IsraelieQueue, insert_in_to_2_groups_with_friends_largest_group_number_of_elelments)
{
	IsraelieQueueImplimitation stTsraelieQueue;
	stTsraelieQueue.Enque(1);
	stTsraelieQueue.Enque(2);
	stTsraelieQueue.Enque(3, 2);
	EXPECT_EQ(stTsraelieQueue.NumberOfElementsInLargesetGroup(), 2);

}

TEST(IsraelieQueue_priority_change, pass_prioirty)
{
	IsraelieQueueImplimitation stTsraelieQueue;
	stTsraelieQueue.Enque(1);
	stTsraelieQueue.Enque(2);
	stTsraelieQueue.Enque(3, 2);
	GTEST_COUT << "group 1 should be largest" << std::endl;
	EXPECT_EQ(stTsraelieQueue.LargestGroupIndex(), 1);
	GTEST_COUT << "group 0 would get 2 additional elements and become the largest and more important" << std::endl;
	stTsraelieQueue.Enque(4, 1);
	stTsraelieQueue.Enque(5, 4);
	EXPECT_EQ(stTsraelieQueue.LargestGroupIndex(), 0);
}

TEST(IsraelieQueue_priority_change, pass_prioirty_after_dequeue)
{
	IsraelieQueueImplimitation stTsraelieQueue;
	stTsraelieQueue.Enque(1);
	stTsraelieQueue.Enque(2);
	stTsraelieQueue.Enque(3, 2);
	stTsraelieQueue.Enque(4);
	
	GTEST_COUT << "group 1 should be largest" << std::endl;
	EXPECT_EQ(stTsraelieQueue.LargestGroupIndex(), 1);
	GTEST_COUT << "dqueing-group 1 should disappear" << std::endl;
	int value;
	stTsraelieQueue.Deque(value);
	stTsraelieQueue.Deque(value);
	EXPECT_EQ(stTsraelieQueue.LargestGroupIndex(), 0);


}

TEST(IsraelieQueue_priority_change, order_with_equal_size_multi_groups)
{
	IsraelieQueueImplimitation stTsraelieQueue;
	stTsraelieQueue.Enque(1);
	stTsraelieQueue.Enque(2,1);
	stTsraelieQueue.Enque(3);
	stTsraelieQueue.Enque(4,3);
	int value;
	stTsraelieQueue.Deque(value);

	EXPECT_EQ(value, 1);
	stTsraelieQueue.Deque(value);

	EXPECT_EQ(value, 2);
	stTsraelieQueue.Deque(value);

	EXPECT_EQ(value, 3);
	stTsraelieQueue.Deque(value);

	EXPECT_EQ(value, 4);

}

TEST(IsraelieQueue_priority_change, order_with_mixed_size_multi_groups)
{
	IsraelieQueueImplimitation stTsraelieQueue;
	stTsraelieQueue.Enque(1);
	stTsraelieQueue.Enque(2, 1);
	stTsraelieQueue.Enque(3);
	stTsraelieQueue.Enque(4);
	EXPECT_EQ(stTsraelieQueue.NumberOfGroups(), 3);
	int value;
	stTsraelieQueue.Deque(value);

	EXPECT_EQ(value, 1);
	stTsraelieQueue.Deque(value);

	EXPECT_EQ(value, 2);
	stTsraelieQueue.Deque(value);

	EXPECT_EQ(value, 3);
	stTsraelieQueue.Deque(value);

	EXPECT_EQ(value, 4);

}
