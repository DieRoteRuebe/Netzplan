#pragma once
#include "Node.h"

class safepoint
{
public:
	safepoint(Node* safe, int safeHigh, int safeLow);
	~safepoint();

	Node* safe;
	int safeHigh;
	int safeLow;
};