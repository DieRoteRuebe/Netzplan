#include "Saver.h"
#include <fstream>
#include <iostream>

Saver::Saver(std::string fileName, Handler* handler)
{
	Saver::csvSafe(fileName, handler);
}

Saver::~Saver()
{
}

void Saver::csvSafe(std::string fileName, Handler* handler)
{
	std::ofstream file;
	file.open(fileName);
	file << "Vorgangsnummer,Bezeichnung,Vorgänger,Nachfolger,Dauer,FAZ,FEZ,SAZ,SEZ,Gesamtpuffer,Freierpuffer" << '\n';
	Node* node = handler->head;
	while (node != NULL)
	{
		std::string tempVorgänger;
		std::string tempNachfolger;
		for (auto i = node->vorgänger.begin(); i != node->vorgänger.end(); i++)
		{
			tempVorgänger += std::to_string(*i);
			tempVorgänger += ' ';
		}
		for (auto i = node->nachfolger.begin(); i != node->nachfolger.end(); i++)
		{
			tempNachfolger += std::to_string(*i);
			tempNachfolger += ' ';
		}
		file << node->vorgangsNr << "," << node->bezeichnung << "," << tempVorgänger << "," << tempNachfolger << "," << node->dauer << "," << node->FAZ << "," << node->FEZ << "," << node->SAZ << "," << node->SEZ << "," << node->gesamtPuffer << "," << node->freierPuffer << '\n';
		node = node->next;
	}
	file.close();
	std::cout << "File was saved to: " << fileName << '\n';
	std::cout << '\n';
	std::cout << '\n';

}
