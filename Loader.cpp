#include "Loader.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "Node.h"


Loader::Loader(std::string fileName, Handler* handler)
{
	Loader::csvLoad(fileName, handler);
}

Loader::~Loader()
{
}

void Loader::csvLoad(std::string fileName, Handler* handler)
{
	Node* current = handler->head;

	std::ifstream input;
	input.open(fileName);
	std::string line = "";
	std::getline(input, line);

	while (std::getline(input, line))
	{

		int vorgangsNr;
		std::string bezeichnung;
		std::vector<int> vorgänger;
		std::string vorgängerTemp;
		std::vector<int> nachfolger;
		std::string nachfolgerTemp;
		int dauer;
		std::string temp;
		std::stringstream String(line);
		std::getline(String, temp, ',');
		vorgangsNr = stoi(temp);
		std::getline(String, bezeichnung, ',');
		std::getline(String, vorgängerTemp, ',');
		if (vorgängerTemp.size() > 1)
		{
			std::string temp = "";
			for(int i = 0; i < vorgängerTemp.size(); i++)
			{
				
				temp += vorgängerTemp[i];
				if (vorgängerTemp[i] == ' ' || i == vorgängerTemp.size()-1)
				{
					vorgänger.push_back(std::stoi(temp));
					temp = "";
				}

			}
			
		}
		else if (vorgängerTemp.size() == 1)
		{
			vorgänger.push_back(std::stoi(vorgängerTemp));
		}
		std::getline(String, nachfolgerTemp, ',');
		if (nachfolgerTemp.size() > 1)
		{
			std::string temp = "";
			for (int i = 0; i < nachfolgerTemp.size(); i++)
			{
				
				temp += nachfolgerTemp[i];
				if (nachfolgerTemp[i] == ' ' || i == nachfolgerTemp.size()-1)
				{
					nachfolger.push_back(std::stoi(temp));
					temp = "";
				}

			}

		}
		else if (nachfolgerTemp.size() == 1)
		{
			nachfolger.push_back(std::stoi(nachfolgerTemp));
		}

		std::getline(String, temp, ',');
		dauer = stoi(temp);
		
		
		if(handler->head == nullptr)
		{ 
		handler->head = new Node(vorgangsNr, bezeichnung, vorgänger, nachfolger, dauer, nullptr);
		current = handler->head;
		}
		else
		{
			
			current->next = new Node(vorgangsNr, bezeichnung, vorgänger, nachfolger, dauer, current);
			current = current->next;
		}
		
		

		line = "";
	}

}

