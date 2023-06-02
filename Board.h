#pragma once
#include"Cell.h"
#include"Boardp.h"
#include<time.h>
#include<iostream>
using namespace std;
class Board :public Boardp	//board conatains two pointer of class cell and size to create dynamic arrays 
{
	Cell** map;//map at back end(original board) 

	int size;

	Cell** displaym;//map to be shown to user

public:
	Board(int s);//parameterized constructor

	Board();//default constructor

	void minegenerator();//function to generete mines at random positions

	void copy();//function to copy opened part of  original map to display map

	void printboard();//function to print the display map

	void numbergenerator();//function to generate numbers around mines

	void up(int, int);//function to open consective '0' upward and left right

	void down(int, int);//function to open consective '0' downward and left right

	void right(int, int);//function to open consective '0' on the right and up down

	void left(int, int);//function to open consective '0' on the left and up down

	void opener(int&,int&);//funcion which calls up,down,right and left function and also checks for other conditions

	//Cell** sm();
	//Cell** m();
	int getsize() const;//getter of size

	void play();//function which calls other function to perform functionality

	~Board();//destructor
};