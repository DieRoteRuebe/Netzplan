#pragma once
#include <string>
#include <vector>

class Node
{
public:
	Node* next;
	Node* prev = nullptr;
	std::vector<Node*> nexts;
	std::vector<Node*> prevs;


	Node(int VorgangNr, std::string Bezeichnung, std::vector<int> Vorgänger, std::vector<int> Nachfolger, int Dauer, Node* last);
	~Node();


	int vorgangsNr;
	std::string bezeichnung;
	std::vector<int> vorgänger;
	std::vector<int> nachfolger;
	int dauer;
	//Siehe Zeichnung:
	int FAZ;
	int FEZ;
	int SAZ;
	int SEZ;

	int gesamtPuffer;
	int freierPuffer;
};