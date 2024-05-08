#include "Node.h"

Node::Node(int VorgangNr, std::string Bezeichnung, std::vector<int> Vorgänger, std::vector<int> Nachfolger, int Dauer, Node* last)
{
	Node::voragngsNr = VorgangNr;
	Node::bezeichnung = Bezeichnung;
	Node::vorgänger = Vorgänger;
	Node::nachfolger = Nachfolger;
	Node::dauer = Dauer;

	Node::nexts = { nullptr };
	Node::prevs = { nullptr };

	Node::next = nullptr;
	Node::prev = last;

	Node::FAZ = 0;
	Node::FEZ = 0;
	Node::SAZ = -99;
	Node::SEZ = -99;

	Node::gesamtPuffer = 0;
	Node::freierPuffer = 0;
}

Node::~Node()
{
}

