#pragma once
#include "Node.h"

class Handler
{
public:

	Node* head = nullptr;
	Node* current = nullptr;
	Node* last = nullptr;
	void reorderNotesForward();
	void reorderNotesBackwards();
	Node* searchNode(int search);

};