#pragma once
#include <string>
#include "Handler.h"

class Saver
{
public:
	Saver(std::string fileName, Handler* handler);
	~Saver();

	void csvSafe(std::string fileName, Handler* handler);
};