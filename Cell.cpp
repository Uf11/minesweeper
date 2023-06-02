#include "Cell.h"
using namespace std;
void Cell::setsymbol(char a)
{
	symbol = a;
}
char Cell::getsymbol() const
{
	return symbol;
}
void Cell::printcell() const
{
	cout << symbol;
}
void Cell::setopened(bool a)
{
	opened = a;
}
bool Cell::getopened() const
{
	return opened;
}
Cell::Cell() :opened(false),symbol('0')
{
}