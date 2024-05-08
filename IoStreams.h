#pragma once
#include "Handler.h"


class iostreams
{
public:
	iostreams();
	~iostreams();

	
	void printFunctionLinear(Handler* handler);

	void beginMessage(Handler* handler);
	void askforSavefileName(Handler* handler);
	void mainmenu(Handler* handler);
	void enterKorrekt();
	void printSingleNode(Node* node);
	void changeNode(Handler* handler);
	void dataforNewNode(Handler* handler);
	void asktoPrintNode(Handler* handler);
};