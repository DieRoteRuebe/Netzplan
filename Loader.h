#pragma once
#include <string>
#include "Handler.h"



class Loader
{
public:
	Loader(std::string fileName, Handler* handler);
	~Loader();

	void csvLoad(std::string fileName, Handler* handler);

};