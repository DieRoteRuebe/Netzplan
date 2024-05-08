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
	file << "Vorgangsnummer,Bezeichnung,Vorg�nger,Nachfolger,Dauer,FAZ,FEZ,SAZ,SEZ,Gesamtpuffer,Freierpuffer" << '\n';
	Node* node = handler->head;
	while (node != NULL)
	{
		std::string tempVorg�nger;
		std::string tempNachfolger;
		for (auto i = node->vorg�nger.begin(); i != node->vorg�nger.end(); i++)
		{
			tempVorg�nger += std::to_string(*i);
			tempVorg�nger += ' ';
		}
		for (auto i = node->nachfolger.begin(); i != node->nachfolger.end(); i++)
		{
			tempNachfolger += std::to_string(*i);
			tempNachfolger += ' ';
		}
		file << node->vorgangsNr << "," << node->bezeichnung << "," << tempVorg�nger << "," << tempNachfolger << "," << node->dauer << "," << node->FAZ << "," << node->FEZ << "," << node->SAZ << "," << node->SEZ << "," << node->gesamtPuffer << "," << node->freierPuffer << '\n';
		node = node->next;
	}
	file.close();
	std::cout << "File was saved to: " << fileName << '\n';
	std::cout << '\n';
	std::cout << '\n';

}
