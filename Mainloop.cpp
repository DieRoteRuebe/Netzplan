#include "Mainloop.h"
#include <string>
#include "Safepoints.h"
#include <iostream>

Mainloop::Mainloop()
{
}

Mainloop::~Mainloop()
{
}

void Mainloop::run()
{
	Handler* handler = new Handler();
	iostreams* io = new iostreams();
	io->beginMessage(handler);
	
	//Linking block
	Loader::Loader(handler->s, handler);
	handler->current = handler->head;
	handler->linkingForwards();
	handler->current = handler->last;
	handler->tail = handler->last;
	handler->linkingBackwards();

	//forwadsblock
	handler->current = handler->head;
	handler->recursionCalculateForwads();
	handler->safes.clear();
	handler->safes = std::vector<safepoint*>();

	//Backwardsblock
	handler->current = handler->tail;
	handler->recursionCalculateBackwards();
	handler->safes.clear();
	handler->safes = std::vector<safepoint*>();

	//Pufferblock
	handler->current = handler->head;
	handler->calculatePufferRecurion();
	handler->safes.clear();
	handler->safes = std::vector<safepoint*>();

	//Userins and outs:
	do 
	{
		int userinput = 0;
		io->mainmenu(handler);
		
		std::cin >> userinput;
		switch (userinput)
		{
		case 1:
			io->askforSavefileName(handler);
			Saver::Saver(handler->ss, handler);
			break;
		case 2:
			io->printFunctionLinear(handler);
			break;
		case 3:
			io->changeNode(handler);
			break;
		case 4:
			io->dataforNewNode(handler);
			break;
		case 5:
			io->asktoPrintNode(handler);
			break;
		case 9:
			Mainloop::runvar = false;
			break;
		default:
			io->enterKorrekt();

		}

	} while (Mainloop::runvar == true);
	


	bool runvar = true;

	int ii = 0;

	
	
}
