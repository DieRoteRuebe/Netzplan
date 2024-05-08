#include "IoStreams.h"
#include <iostream>
#include <fstream>

iostreams::iostreams()
{
}

iostreams::~iostreams()
{
}

void iostreams::printFunctionLinear(Handler* handler)
{
	std::cout << '\n';
	std::cout << '\n';
	Node* temp = handler->head;
	while (temp)
	{
		std::string tempVorgänger;
		std::string tempNachfolger;
		std::cout << "#######################################################" << '\n';
		for (auto i = temp->vorgänger.begin(); i != temp->vorgänger.end(); i++)
		{
			tempVorgänger += std::to_string(*i);
			tempVorgänger += ' ';
		}
		for (auto i = temp->nachfolger.begin(); i != temp->nachfolger.end(); i++)
		{
			tempNachfolger += std::to_string(*i);
			tempNachfolger += ' ';
		}

		std::cout << "-------------------------------------------------------" << '\n';
		std::cout << "VorgangsNr: " << temp->vorgangsNr << "   Bezeichnung:" << temp->bezeichnung << '\n';
		std::cout << "Dauer: " << temp->dauer << "   Gesamtpuffer: " << temp->gesamtPuffer << " Freierpuffer: " << temp->freierPuffer << '\n';
		std::cout << "FAZ: " << temp->FAZ << "   FEZ: " << temp->FEZ << '\n';
		std::cout << "SAZ: " << temp->SAZ << "   SEZ: " << temp->SEZ << '\n';
		std::cout << "Vorgaenger: " << tempVorgänger << '\n';
		std::cout << "Nachfolger: " << tempNachfolger << '\n';
		std::cout << "-------------------------------------------------------" << '\n';

		temp = temp->next;
	}
	std::cout << "#######################################################" << '\n';
	std::cout << '\n';
	std::cout << '\n';
	std::cout << std::endl;
}

void iostreams::beginMessage(Handler* handler)
{
	std::cout << "Please enter the filename to load the csv.csv: ";
	std::cin >> handler->s;
	std::cout << '\n';
	std::ifstream file;
	file.open(handler->s);
	while (!file.is_open())
	{
		std::cout << "Sorry couldnt find your file, please Enter the correct Name: ";
		std::cin >> handler->s;
		file.open(handler->s);
	}
	file.close();
	std::cout << "File was successfully loaded" << '\n';
	std::cout << std::endl;
}

void iostreams::askforSavefileName(Handler* handler)
{
	std::cout << "Please enter a Name to save the Calculated File: ";
	std::cin >> handler->ss;
	std::cout << '\n';
}

void iostreams::mainmenu(Handler* handler)
{
	std::cout << "-------------------------------------------------------" << '\n';
	std::cout << "Mainmenu" << '\n';
	std::cout << "-------------------------------------------------------" << '\n';
	std::cout << "What do you want to do next?:" << '\n';
	std::cout << "To safe the file press 1" << '\n';
	std::cout << "To print the Plan linear press 2" << '\n';
	std::cout << "To change a Node press 3" << '\n';
	std::cout << "To add a Node press 4" << '\n';
	std::cout << "To print a single Node press 5" << '\n';
	std::cout << "To Quit press 9" << '\n';
	std::cout << "-------------------------------------------------------" << '\n';
}

void iostreams::enterKorrekt()
{
	std::cout << "Please Enter a korrekt number" << '\n';
	std::cout << std::endl;
}

void iostreams::printSingleNode(Node* node)
{
	Node* temp = node;
	std::string tempVorgänger;
	std::string tempNachfolger;
	for (auto i = temp->vorgänger.begin(); i != temp->vorgänger.end(); i++)
	{
		tempVorgänger += std::to_string(*i);
		tempVorgänger += ' ';
	}
	for (auto i = temp->nachfolger.begin(); i != temp->nachfolger.end(); i++)
	{
		tempNachfolger += std::to_string(*i);
		tempNachfolger += ' ';
	}
	std::cout << "-------------------------------------------------------" << '\n';
	std::cout << "VorgangsNr: " << temp->vorgangsNr << "   Bezeichnung:" << temp->bezeichnung << '\n';
	std::cout << "Dauer: " << temp->dauer << "   Gesamtpuffer: " << temp->gesamtPuffer << " Freierpuffer: " << temp->freierPuffer << '\n';
	std::cout << "FAZ: " << temp->FAZ << "   FEZ: " << temp->FEZ << '\n';
	std::cout << "SAZ: " << temp->SAZ << "   SEZ: " << temp->SEZ << '\n';
	std::cout << "Vorgaenger: " << tempVorgänger << '\n';
	std::cout << "Nachfolger: " << tempNachfolger << '\n';
	std::cout << "-------------------------------------------------------" << '\n';
	std::cout << std::endl;
}

void iostreams::changeNode(Handler* handler)
{
	int tempVorangsNr = 0;
	int inputTemp = 0;
	std::cout << "To change a node we must find it first, please enter the Vorgangsnummer: ";
	do
	{
		
		std::cin >> tempVorangsNr;
		std::cout << '\n';
		handler->current = handler->searchNode(tempVorangsNr);
		if (handler->current == NULL)
		{
			std::cout << "Node could not be found, please enter an existing Vorgangsnummer " << '\n';
			std::cout << "To continue and try again press 1, to cancel 2: "; std::cin >> inputTemp; std::cout << '\n';
			if (inputTemp == 2)
			{
				break;
			}
		}
		std::cout << "You selected the following Node: " << '\n';
		iostreams::printSingleNode(handler->current);
	} while (handler->current == NULL);
	if (handler->current != NULL)
	{
		std::cout << "What do you want to change?" << '\n';
		std::cout << "For duration press 1" << '\n';
		std::cout << "To cancel press 2" << '\n';
		std::cin >> inputTemp;
	}
	if (inputTemp == 1)
	{
		int tempDur = -1;
		std::cout << "Please enter the new duration: " << '\n';
		do
		{
			std::cin >> tempDur;
			if (tempDur < 0)
			{
				std::cout << "Please enter a valid number greater or euqal 0" << '\n';
				std::cin >> tempDur;
			}

		} while (tempDur < 0);
		handler->current->dauer = tempDur;
		std::cout << '\n';
		std::cout << '\n';
		std::cout << "Node was changed: " << '\n';
		iostreams::printSingleNode(handler->current);
		std::cout << '\n';
		std::cout << '\n';
		std::cout << "Did a new calculation for the Nodes" << '\n';
		std::cout << "Returning to menu now" << '\n';
		handler->calculateAll();
	}
	else
	{
		std::cout << '\n';
		std::cout << '\n';
		std::cout << "Returning to menu now" << '\n';
	}
	
	std::cout << '\n';
	std::cout << std::endl;
}

void iostreams::dataforNewNode(Handler* handler)
{
	int vorgangsNr = -1;
	std::string bezeichnung;
	std::vector<int> vorgänger;
	std::string vorgängerTemp;
	std::vector<int> nachfolger;
	std::string nachfolgerTemp;
	int dDauer = 0;
	int exitToggle = 0;
	int endExitToggle = 0;

	do
	{
		std::cout << "To create a new Node enter the operation number first: " << '\n';
		std::cin >> vorgangsNr;
		std::cout << "Checking if Node already exists... " << '\n';
		Node* searchedNode = handler->searchNode(vorgangsNr);
		do
		{
			if (searchedNode != NULL)
			{
				vorgangsNr = -1;
				std::cout << "The node exists " << '\n';
				std::cout << "To continue and try again press 1, to exit to mainmenu 3: "; std::cin >> exitToggle; std::cout << '\n';
				if (exitToggle == 3)
				{
					return;
				}
				std::cout << "Please enter a operation number which does not exist: " << '\n';
				std::cin >> vorgangsNr;
				searchedNode = handler->searchNode(vorgangsNr);
			}
			else
			{
				std::cout << "Node does not exist, New instructions follow now" << '\n';
			}

		} while (searchedNode != NULL);
		exitToggle = 0;
		do
		{
			std::cout << "Please enter the Description: " << '\n';
			std::cin >> bezeichnung;
			std::cout << '\n';
			std::cout << "Do you want to save the description? Press 1 to save and continue, 2 to cancel, to enter a new description" << '\n';
			std::cout << "OR to exit to mainmenu press 3: " << '\n';
			std::cin >> exitToggle;
			if (exitToggle == 2)
			{
				bezeichnung = "";
			}
			else if(exitToggle == 3)
			{
				return;
			}

		} while (exitToggle != 1);

		exitToggle = 0;
		std::cout << '\n';
		std::cout << '\n';

		do
		{
			std::cout << "Please enter the following nodes to this node, please enter only one node after another" << '\n';
			std::cout << "Enter 1 previous Node now: ";
			int temp = 0;
			int eingabe = 0;
			std::cin >> temp;
			std::cout << '\n';
			nachfolger.push_back(temp);
			temp = 0;
			do
			{
				eingabe = 0;
				std::cout << "Do you want to add another node to link? Press 1 to enter another node, 2 to save and contiue" << '\n';
				std::cin >> eingabe;

				if (eingabe != 2)
				{
					std::cout << "Enter the next node now: " << std::endl;
					std::cin >> temp;
					std::cout << '\n';
					vorgänger.push_back(temp);
					temp = 0;
				}
				
			} while (eingabe != 2);
			std::cout << "Do you want to save the follwoing nodes? Press 1 to save and continue, 2 to cancel, to enter other nodes" << '\n';
			std::cout << "OR to exit to mainmenu press 3: " << '\n';
			std::cin >> exitToggle;
			if (exitToggle == 2)
			{
				vorgänger.clear();
				vorgänger = std::vector<int>();
			}
			else if (exitToggle == 3)
			{
				return;
			}

		} while (exitToggle != 1);
		exitToggle = 0;
		std::cout << '\n';
		std::cout << '\n';


		//Get the previous Nodes:
		do
		{
			std::cout << "Please enter the previous nodes to this node, please enter only one node after another" << '\n';
			std::cout << "Enter 1 previous Node now: ";
			int temp = 0;
			int eingabe = 0;
			std::cin >> temp;
			std::cout << '\n';
			vorgänger.push_back(temp);
			temp = 0;
			do
			{
				eingabe = 0;
				std::cout << "Do you want to add another node to link? Press 1 to enter another node, 2 to save and contiue" << '\n';
				std::cin >> eingabe;
				std::cout << '\n';
				if (eingabe != 2)
				{
					std::cout << "Enter the next node now: " << std::endl;
					std::cin >> temp;
					std::cout << '\n';
					vorgänger.push_back(temp);
					temp = 0;
				}
			} while (eingabe != 2);
			std::cout << '\n';
			std::cout << "Do you want to save the the prevois nodes? Press 1 to save and continue, 2 to cancel, to enter other nodes" << '\n';
			std::cout << "OR to exit to mainmenu press 3: " << '\n';
			std::cin >> exitToggle;
			if (exitToggle == 2)
			{
				vorgänger.clear();
				vorgänger = std::vector<int>();
			}
			else if (exitToggle == 3)
			{
				return;
			}

		} while (exitToggle != 1);
		std::cout << '\n';
		std::cout << '\n';
		exitToggle = 0;

		//Get the Duration
		do
		{
			std::cout << "Please enter the duration now: " << '\n';
			std::cin >> dDauer;
			std::cout << "Do you want to save the duration? Press 1 to save and continue, 2 to cancel, to enter other nodes" << '\n';
			std::cout << "OR to exit to mainmenu press 3: " << '\n';
			std::cin >> exitToggle;
			if (exitToggle == 2)
			{
				nachfolgerTemp = "";
			}
			else if (exitToggle == 3)
			{
				return;
			}
			

		} while (exitToggle != 1);


		//Loops to print the data
		for (auto i = vorgänger.begin(); i != vorgänger.end(); i++)
		{
			vorgängerTemp += *i;
			vorgängerTemp += ' ';
		}
		for (auto i = nachfolger.begin(); i != nachfolger.end(); i++)
		{
			nachfolgerTemp += *i;
			nachfolgerTemp += ' ';
		}
		//Print the Data and make sure everything is right
		std::cout << '\n'; 
		std::cout << '\n'; 
		std::cout << '\n';
		std::cout << "Cool we are now set to continue" << '\n';
		std::cout << '\n';
		std::cout << '\n';
		std::cout << "You entered the following values: " << '\n';
		std::cout << "Operation number: " << vorgangsNr << '\n';
		std::cout << "Description: " << bezeichnung << '\n';
		std::cout << "Previous nodes: " << vorgängerTemp << '\n';
		std::cout << "Following nodes: " << nachfolgerTemp << '\n';
		std::cout << "Duration: " << dDauer << '\n';
		std::cout << "Please Check if your entered values are correct, it isnt possible to delete nodes " << '\n';
		std::cout << "If you want to continue and save press 1, to cancel and begin new 2" << '\n';
		std::cin >> endExitToggle;
	}
	while (endExitToggle != 1);

	std::cout << "The node will now be created, everything will be newly linked and calculated" << '\n';



	//Insert the links into the corresponding nodes and Return with a Failure if returning node == NULL:
	for (auto i = vorgänger.begin(); i != vorgänger.end(); i++)
	{
		Node* temp = nullptr;
		temp = handler->searchNode(*i);
		temp->nachfolger.push_back(vorgangsNr);
		if (temp == NULL)
		{
			std::cout << "Warning one of your following nodes wasnt found... Exiting now to mainmenu" << std::endl;
			return;
		}

	}
	for (auto i = nachfolger.begin(); i != nachfolger.end(); i++)
	{
		Node* temp = nullptr;
		temp = handler->searchNode(*i);
		temp->vorgänger.push_back(vorgangsNr);
		if (temp == NULL)
		{
			std::cout << "Warning one of your following nodes wasnt found... Exiting now to mainmenu" << std::endl;
			return;
		}

	}

	handler->addNode(vorgangsNr, bezeichnung, vorgänger, nachfolger, dDauer);

	handler->current = handler->head;
	handler->linkingForwards();
	handler->current = handler->last;
	handler->tail = handler->last;
	handler->linkingBackwards();

	handler->calculateAll();

	std::cout << "DONE" << '\n';
	std::cout << '\n';
	std::cout << std::endl;
}

void iostreams::asktoPrintNode(Handler* handler)
{
	int usertemp = -1;
	Node* tempNode = nullptr;
	do
	{
		std::cout << "Please enter the operation number of the corresponding node: " << '\n';
		std::cin >> usertemp; std::cout << std::endl;
		tempNode = handler->searchNode(usertemp);
		if(tempNode == NULL)
		{
			int exitToggle = 0;
			usertemp = -1;
			std::cout << "Node does not exist" << '\n';
			std::cout << "To try again press 1, to cancel press 2" << '\n';
			std::cin >> exitToggle;
			if (exitToggle == 2)
			{
				return;
			}
			exitToggle = 0;
			std::cout << "Please enter an existing operation number: " << '\n';
			std::cin >> usertemp; std::cout << '\n';
			tempNode = handler->searchNode(usertemp);
		}

	} while (tempNode == NULL);
	std::cout << "Node will be printed: " << '\n';
	std::cout << '\n';
	iostreams::printSingleNode(tempNode);
	std::cout << '\n';
	std::cout << std::endl;
}
