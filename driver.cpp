
#include"Board.h"
#include"Boardp.h"
#include<iostream>
#include <windows.h>
using namespace std;
int main()
{
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);//changing backgroung colour of consol

	Board b;

	b.play();

	return 0;
}