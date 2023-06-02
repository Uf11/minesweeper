#pragma once
#include"Cell.h"
class Boardp//board private is a abstract class to show polymorhism
{	
public:
	virtual void minegenerator() =0;
	virtual void copy() =0;
	virtual void printboard() =0;
	virtual void numbergenerator() =0;
	virtual void up(int, int) =0;
	virtual void down(int, int) =0;
	virtual void right(int, int) =0;
	virtual void left(int, int) =0;
	virtual void opener(int&, int&) =0;
	~Boardp() {};
};
