#pragma once
#include "stdafx.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
using namespace std;
#define INVALID_NUMBER -1

class DataItem {

	int m_iId;
public:
	DataItem(int iId)
	{
		m_iId = iId;

	}

	int GetID()
	{
		return m_iId;
	}

};

class IsraelieQueueGroup
{
	std::vector<DataItem> m_GroupItems;

public:
	int m_SizePriority = 0;
	IsraelieQueueGroup()
	{
	}
	void PrintItems()
	{
		std::cout << " number of items " << m_GroupItems.size() << " priority=" << GetPriority() << std::endl;
		for (auto stGroupItem = m_GroupItems.begin(); stGroupItem != m_GroupItems.end(); ++stGroupItem)
		{
			std::cout << "[" << stGroupItem->GetID() << "]" << ' ' << std::endl;
		}

	}
	void Enque(DataItem csDataItem)
	{
		m_GroupItems.push_back(csDataItem);
		m_SizePriority++;
	}
	void Deque(DataItem &csDataItem)
	{
		if (!m_GroupItems.empty())
		{
			memcpy(&csDataItem, &m_GroupItems.front(), sizeof(DataItem));
			m_GroupItems.erase(m_GroupItems.begin());
		}
	}
	int NumberOfItems()
	{
		return m_GroupItems.size();
	}
	int GetPriority()
	{
		return m_SizePriority;
	}
	bool IsInGroup(int iId)
	{
		if (std::any_of(m_GroupItems.begin(), m_GroupItems.end(), [&](DataItem csDataItem) {return csDataItem.GetID() == iId; }))
			return true;
		return false;
	}
	bool operator > (IsraelieQueueGroup& csGroup) const
	{
		return (m_SizePriority > csGroup.GetPriority());
	}

	struct ByPriority
	{
		bool operator ()(const IsraelieQueueGroup &a, const  IsraelieQueueGroup &b) const
		{
			return a.m_SizePriority < b.m_SizePriority;
		}
	};

};

class IsraelieQueueImplimitation
{
	std::vector<IsraelieQueueGroup> m_Groups;
public:
	IsraelieQueueImplimitation()
	{

	}
	void PrintItemsByGroups()
	{

		for (auto i = m_Groups.begin(); i != m_Groups.end(); ++i)
		{
			std::cout << "Group - " << i - m_Groups.begin() << " :: " << std::endl;
			i->PrintItems();
			std::cout << std::endl;

		}
	}
	void Enque(int iID, int iFriendId = 99999)
		//israelie queue logic
	{
		DataItem item(iID);

		for (auto group = m_Groups.begin(); group != m_Groups.end(); ++group)
		{
			if (group->IsInGroup(iFriendId))
			{
				group->Enque(item);
				return;
			}



		}


		//reached here so we add to new group
		IsraelieQueueGroup csNewGroup;
		csNewGroup.Enque(item);
		m_Groups.push_back(csNewGroup);

	}
	int LargestGroupIndex()
	{
		if (m_Groups.empty())
			return INVALID_NUMBER;
		int maxElementIndex = std::max_element(m_Groups.begin(), m_Groups.end(), IsraelieQueueGroup::ByPriority()) - m_Groups.begin();
		return maxElementIndex;
	}
	int NumberOfElementsInLargesetGroup()
	{
		int iLargestGroupIndex = LargestGroupIndex();
		if (iLargestGroupIndex==INVALID_NUMBER)
			return INVALID_NUMBER;
		IsraelieQueueGroup maxElement = m_Groups[iLargestGroupIndex];
		return maxElement.NumberOfItems();
	}
	int NumberOfGroups()
	{
		return m_Groups.size();
	}
	// A pred function to adjust according to your score
	bool comparator(IsraelieQueueGroup& s1, IsraelieQueueGroup& s2)
	{
		return s1.GetPriority() < s2.GetPriority();
	}
	bool IsEmpty()
	{
		return m_Groups.empty();
	}

	void Deque(int &value)
	{
		

		if (m_Groups.empty())
		{
			return;
		}



		auto stMaxPriorityGroup = std::max_element(m_Groups.begin(), m_Groups.end(), IsraelieQueueGroup::ByPriority());
		DataItem item(0);
		stMaxPriorityGroup->Deque(item);
		value = item.GetID();

		//cleanup
		m_Groups.erase(
			std::remove_if(
				m_Groups.begin(),
				m_Groups.end(),
				[](IsraelieQueueGroup  & p) { return p.NumberOfItems() <= 0; }
			),
			m_Groups.end()
		);
	}
};




