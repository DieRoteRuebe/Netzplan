#pragma once
#include "Node.h"

class Handler
{
public:

	Node* head = nullptr;
	Node* current = nullptr;
	void reorderNotes();
	Node* searchNode(int search);

};