#include "Handler.h"
#include <iostream>

//Linking:
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

//Forwards Calculation, gets Called by recursionCalculateForwards();
bool Handler::calculateForwards()
{
	//when head:
	bool abzweigung = false;
	
	if (current == head)
	{
		current->FEZ = current->dauer;
		Handler::high = current->dauer;
	}

	Handler::high = current->FEZ;
	//Safe location cause crossing:
	if (current->nexts.size() > 1)
	{
		abzweigung = true;
		safepoint* safe = new safepoint(current, Handler::high, Handler::low);
		Handler::safes.push_back(safe);
	}

	//set next->FAZ to current->FEZ (for all Nodes in vec nexts):
	for (int i = 0; i < current->nexts.size(); i++)
	{
		if(current->nexts.back() != NULL)
		{
			if(current->nexts[i]->FAZ < Handler::high)
			{ 
			current->nexts[i]->FAZ = Handler::high;
			}
			current->nexts[i]->FEZ = current->nexts[i]->FAZ + current->nexts[i]->dauer;
		}

		
	}



	return abzweigung;
}

void Handler::recursionCalculateForwads()
{
	
	while (current != NULL)
	{
		bool abzweigung = Handler::calculateForwards();
		if(abzweigung == true)
		{ 
			for (int i = 0; i < current->nexts.size(); i++)
			{
				current = current->nexts[i];
				Handler::recursionCalculateForwads();
				current = Handler::safes.back()->safe;
				Handler::high = safes.back()->safeHigh;
				Handler::low = safes.back()->safeLow;
			}
			Handler::safes.pop_back();
		}

		last = current;
		current = current->nexts.back();
	}
}


//Backwards Calculation, gets Called by recursionCalculateBackwards();
bool Handler::calculateBackwards()
{
	//when head:
	bool abzweigung = false;

	if (current == last)
	{
		current->SEZ = current->FEZ;
		current->SAZ = current->SEZ - current->dauer;
	}
	Handler::low = current->SAZ;
	

	
	//Safe location cause crossing:
	if (current->prevs.size() > 1)
	{
		abzweigung = true;
		safepoint* safe = new safepoint(current, Handler::high, Handler::low);
		Handler::safes.push_back(safe);
	}

	//set next->SEZ to current->SAZ (for all Nodes in vector prevs) if current->SAZ is lower:
	for (int i = 0; i < current->prevs.size(); i++)
	{
		if (current->prevs.back() != NULL)
		{
			if (current->prevs[i]->SEZ == -99)
			{
				current->prevs[i]->SEZ = Handler::low;
			}
			else if (current->prevs[i]->SEZ > Handler::low)
			{
				current->prevs[i]->SEZ = Handler::low;
			}
			current->prevs[i]->SAZ = current->prevs[i]->SEZ - current->prevs[i]->dauer;
		}
	}

	return abzweigung;
}

void Handler::recursionCalculateBackwards()
{
	while (current != NULL)
	{
		bool abzweigung = Handler::calculateBackwards();
		if (abzweigung == true)
		{
			for (int i = 0; i < current->prevs.size(); i++)
			{
				current = current->prevs[i];
				Handler::recursionCalculateBackwards();
				current = Handler::safes.back()->safe;
				Handler::high = safes.back()->safeHigh;
				Handler::low = safes.back()->safeLow;
			}
			Handler::safes.pop_back();
		}

		last = current;
		current = current->prevs.back();
	}
}


//Puffer calculation:
void Handler::calculatePufferRecurion()
{

	while (current != NULL)
	{
		bool abzweigung = Handler::calculatePuffer();
		if (abzweigung == true)
		{
			for (int i = 0; i < current->nexts.size(); i++)
			{
				current = current->nexts[i];
				Handler::calculatePufferRecurion();
				current = Handler::safes.back()->safe;
			}
			Handler::safes.pop_back();
		}

		last = current;
		current = current->nexts.back();
	}
}

bool Handler::calculatePuffer()
{


	bool abzweigung = false;




	if (current->nexts.size() > 1)
	{
		abzweigung = true;
		safepoint* safe = new safepoint(current, Handler::high, Handler::low);
		Handler::safes.push_back(safe);
	}

	//Gesamtpuffer
	current->gesamtPuffer = current->SAZ - current->FAZ;

	//Freierpuffer
	for (int i = 0; i < current->nexts.size(); i++)
	{
		if (current->nexts.back() != NULL)
		{
			if (current->gesamtPuffer > current->nexts[i]->FAZ - current->FEZ)
			{
				current->freierPuffer = current->nexts[i]->FAZ - current->FEZ;
			}
		}
	}
	return abzweigung;
}


//Utilities:
Node* Handler::searchNode(int search)
{
	Node* Current = head;
	while (Current != NULL)
	{
		if (Current->vorgangsNr == search)
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



void Handler::addNode(int vorgangsNr, std::string bezeichnung, std::vector<int> vorgänger, std::vector<int> nachfolger, int dauer)
{
	tail->next = new Node(vorgangsNr, bezeichnung, vorgänger, nachfolger, dauer, tail);
	tail = tail->next;
}

void Handler::calculateAll()
{
	//forwadsblock
	Handler::current = Handler::head;
	Handler::recursionCalculateForwads();
	Handler::safes.clear();
	Handler::safes = std::vector<safepoint*>();

	//Backwardsblock
	Handler::current = Handler::last;
	Handler::recursionCalculateBackwards();
	Handler::safes.clear();
	Handler::safes = std::vector<safepoint*>();

	//Pufferblock
	Handler::current = Handler::head;
	Handler::calculatePufferRecurion();
	Handler::safes.clear();
	Handler::safes = std::vector<safepoint*>();
}
