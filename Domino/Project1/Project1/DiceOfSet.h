#include <iostream>
#include <vector>
#pragma once
#include "dice.h";

using namespace std;

//рука игрока
class DiceOfSet
{
public:
	//вектор костей
	vector <dice> a;
	
	//отобразить весь набор костей
	 void printAllDice();

	 void PrintPlayerDice();

	bool missTurn = false;

	friend ostream &operator<<(ostream &cout, DiceOfSet diceOfSet);

	DiceOfSet();
	~DiceOfSet();
};

