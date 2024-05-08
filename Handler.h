#pragma once
#include "Node.h"
#include "Safepoints.h"

class Handler
{
public:
	std::vector<safepoint*> safes;
	int userinput = 0;
	int high = 0;
	int low = 0;
	std::string s;
	std::string ss;
	Node* head = nullptr;
	Node* current = nullptr;
	Node* last = nullptr;
	Node* tail = nullptr;

	//Dinamic Node Linking:
	void linkingForwards();
	void linkingBackwards();

	
	//Utility / Helpers:
	Node* searchNode(int search);
	void addNode(int vorgangsNr, std::string bezeichnung, std::vector<int> vorgänger, std::vector<int> nachfolger, int dauer);

	void calculateAll();
	//Calculation loops:
	bool calculateForwards();
	bool calculateBackwards();

	void calculatePufferRecurion();
	bool calculatePuffer();

	void recursionCalculateForwads();
	void recursionCalculateBackwards();
	
	
};