#include <iostream>
#include <vector>
#pragma once
#include "dice.h";

using namespace std;

//���� ������
class DiceOfSet
{
public:
	//������ ������
	vector <dice> a;
	
	//���������� ���� ����� ������
	 void printAllDice();

	 void PrintPlayerDice();

	bool missTurn = false;

	friend ostream &operator<<(ostream &cout, DiceOfSet diceOfSet);

	DiceOfSet();
	~DiceOfSet();
};

