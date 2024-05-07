#include "Node.h"

Node::Node(int VorgangNr, std::string Bezeichnung, std::vector<int> Vorgänger, std::vector<int> Nachfolger, int Dauer, Node* last)
{
	Node::voragngsNr = VorgangNr;
	Node::bezeichnung = Bezeichnung;
	Node::vorgänger = Vorgänger;
	Node::nachfolger = Nachfolger;
	Node::dauer = dauer;

	Node::nexts = { nullptr };
	Node::prevs = { nullptr };

	Node::next = nullptr;
	Node::prev = last;
}

Node::~Node()
{
}

