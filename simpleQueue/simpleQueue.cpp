// simpleQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include "simpleQueue.h"
using namespace std;

int main()
{
	IsraelieQueueImplimitation stTsraelieQueue;
	stTsraelieQueue.Enque(1);
	cout << "after 1 item" << std::endl;

	stTsraelieQueue.PrintItemsByGroups();
	stTsraelieQueue.Enque(2,1);
	cout << "after 2 item -expect add to group " << std::endl;

	stTsraelieQueue.PrintItemsByGroups();
	stTsraelieQueue.Enque(3,2);
	cout << "after 3 item -expect add to group " << std::endl;

	stTsraelieQueue.PrintItemsByGroups();


	stTsraelieQueue.Enque(5);
	cout << "after 4 item -expect new  group " << std::endl;

	stTsraelieQueue.PrintItemsByGroups();
	cout << "adding 6 items to new group 1 " << std::endl;
	std::vector<int> v1 = { 10, 11, 12, 13, 14, 15 };

	for (const int& i : v1) // access by const reference
		stTsraelieQueue.Enque(i,5);

	stTsraelieQueue.PrintItemsByGroups();
	cout << "after adding 6 items to new group 1 " << std::endl;

	stTsraelieQueue.Enque( 16, 10);
	stTsraelieQueue.PrintItemsByGroups();
	cout << "after one more element to group 1 " << std::endl;

	int dequed_value;
	stTsraelieQueue.Deque(dequed_value);
	stTsraelieQueue.PrintItemsByGroups();
	cout << "after deque 1 : " << dequed_value  << std::endl;

	stTsraelieQueue.Deque(dequed_value);
	stTsraelieQueue.PrintItemsByGroups();
	cout << "after deque 2: " << dequed_value << std::endl;


	cout << "adding 6 items to  group 1 and changing priorirty " << std::endl;
	std::vector<int> v2 = { 20, 21, 22, 23, 24, 25 };

	for (const int& i : v2) // access by const reference
		stTsraelieQueue.Enque(i, 3);

	stTsraelieQueue.PrintItemsByGroups();
	stTsraelieQueue.Deque(dequed_value);
	stTsraelieQueue.PrintItemsByGroups();
	cout << "after deque 3: " << dequed_value << std::endl;

	getchar();

    return 0;

}

