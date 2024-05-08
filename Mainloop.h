#pragma once
#include "Node.h"
#include "Handler.h"
#include "Saver.h"
#include "Loader.h"
#include "IoStreams.h"

class Mainloop
{
public:
	Mainloop();
	~Mainloop();

	void run();
	
	bool runvar = true;
};