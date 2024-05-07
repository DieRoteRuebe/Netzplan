#include "Handler.h"

void Handler::reorderNotesForward()
{
	
	while(current != NULL)
	{ 
		Node* found = NULL;
		if(!current->nachfolger.empty())
		{ 
		std::vector<int> temp = current->nachfolger;
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
						found = NULL;
					}
				}
				//erase Vektor and shrink capacity to free Mem
				temp.clear();
				temp = std::vector<int>();
		}
		
		
		last = current;
		current = current->next;
		
	}
}

void Handler::reorderNotesBackwards()
{
	while (current != NULL)
	{
		Node* found = NULL;
		if (!current->vorgänger.empty())
		{
			std::vector<int> temp = current->vorgänger;
			for (auto i = temp.begin(); i != temp.end(); i++)
			{
				int search = *i;
				if (current->prevs.back() == nullptr)
				{
					current->prevs.pop_back();
				}
				found = searchNode(search);
				if (found != NULL)
				{
					current->prevs.push_back(found);
					found = NULL;
				}
			}
			//erase Vektor and shrink capacity to free Mem
			temp.clear();
			temp = std::vector<int>();
		}


		last = current;
		current = current->prev;

	}
}

Node* Handler::searchNode(int search)
{
	Node* Current = head;
	while (Current != NULL)
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
