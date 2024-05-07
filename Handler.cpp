#include "Handler.h"

void Handler::reorderNotes()
{
	Node* found = NULL;
	while(current->next != NULL)
	{ 
		if(!current->nachfolger.empty())
		{ 
		std::vector<int> temp = head->nachfolger;
				for(auto i = temp.begin(); i != temp.end(); i++)
				{
					int search = *i;
					if (current->nexts.back() == nullptr)
					{
						current->nexts.pop_back();
					}
					found = searchNode(search);
					if (found != NULL)
					{
						current->nexts.push_back(found);
					}
				}
		}
		current = current->next;
	}
}

Node* Handler::searchNode(int search)
{
	Node* Current = head;
	while (Current->next != NULL)
	{
		if (Current->voragngsNr == search)
		{
			return Current;
		}
		else
		{
			Current = Current->next;
		}
	}
	return nullptr;
}
