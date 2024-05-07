#pragma once
#include "Node.h"

class Handler
{
public:

	Node* head = nullptr;
	Node* current = nullptr;
	Node* last = nullptr;
	//Linking:
	void linkingForwards();
	void linkingBackwards();

	//Utility / Helpers:
	Node* searchNode(int search);

	//Calculation loops:
	bool calculateForwards();
	void calculateBackwards();

	void recursionCalculate();
	
};