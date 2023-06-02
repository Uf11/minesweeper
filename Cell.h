#pragma once
#include<iostream>
using namespace std;
class Cell	//each cell contains a symbol and bool to identify if its opened or not
{
	char symbol;

	bool opened;
public:
	Cell();
	void setopened(bool);//setters

	void setsymbol(char a);

	bool getopened()  const;//getters

	char getsymbol() const;

	void printcell() const;//print function
};