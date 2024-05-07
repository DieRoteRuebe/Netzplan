#include "Handler.h"

void Handler::linkingForwards()
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

void Handler::linkingBackwards()
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

bool Handler::calculateForwards()
{
	//when head:
	bool abzweigung = false;
	int highest = current->dauer;
		if (current->voragngsNr == 1)
		{
			current->FAZ = 0;
			current->FEZ = current->dauer;
		}


		if (!current->nexts.empty())
		{
			if (current->nexts.size() > 1)
			{
				abzweigung = true;
			}
			for (int i = 0; i < current->nexts.size(); i++)
			{
				if(current->nexts[i] != NULL)
				{ 
					if (current->nexts[i]->FEZ > highest)
					{
						highest = current->nexts[i]->FEZ;
					}

					if(current->nexts[i]->FAZ < highest)
					{
						current->nexts[i]->FAZ = highest;
					}
					current->nexts[i]->FEZ = current->nexts[i]->FAZ + current->nexts[i]->dauer;
				}
				
			}
		}
	return abzweigung;
}

void Handler::calculateBackwards()
{
}

void Handler::recursionCalculate()
{
	while (current != NULL)
	{
		
		bool abzweigung = Handler::calculateForwards();
		Node* safepoint = current;
		if(abzweigung == true)
		{ 
			for (int i = 0; i < current->nexts.size(); i++)
			{
				current = current->nexts[i];
				Handler::recursionCalculate();
				current = safepoint;
			}
		}
		current = current->nexts[0];
	}
}
