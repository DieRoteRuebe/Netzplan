#include "Mainloop.h"
#include "Loader.h"
#include <string>
#include "Node.h"
#include "Handler.h"

Mainloop::Mainloop()
{
}

Mainloop::~Mainloop()
{
}

void Mainloop::run()
{
	Handler* handler = new Handler();
	std::string s = "Csv.csv";
	Loader::Loader(s, handler);
	handler->current = handler->head;
	handler->reorderNotes();
	
	int ii = 0;

	
	
}
