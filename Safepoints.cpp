#include "Safepoints.h"

safepoint::safepoint(Node* safe, int safeHigh, int safeLow)
{
	safepoint::safe = safe;
	safepoint::safeHigh = safeHigh;
	safepoint::safeLow = safeLow;
}

safepoint::~safepoint()
{

}
