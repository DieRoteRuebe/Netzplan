#pragma once
#include "Node.h"
#include "Safepoints.h"

class Handler
{
public:


	std::vector<safepoint*> safes;


	Node* head = nullptr;
	Node* current = nullptr;
	Node* last = nullptr;
	//Linking:
	void linkingForwards();
	void linkingBackwards();


	int high = 0;
	int low = 0;

	
	//Utility / Helpers:
	Node* searchNode(int search);

	//Calculation loops:
	bool calculateForwards();
	bool calculateBackwards();

	void recursionCalculateForwads();
	void recursionCalculateBackwards();
	
};