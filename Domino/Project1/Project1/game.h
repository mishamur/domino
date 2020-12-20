#include <iostream>
#include <vector>
#include "dice.h"
#include "DiceOfSet.h"
#pragma once

using namespace std;
class game
{
public:
	//в конструкторе наш базар заполняется и перемешивается 
	game();

	//куча(базар)
	DiceOfSet heap;
	
	//набор костей первого игрока
	DiceOfSet player1;
	//набор костей второго игрока
	DiceOfSet player2;

	//игровое поле
	DiceOfSet playingField;

	//флаг победы
	bool flagOfEnd = true;

	//первый ход
	bool firstTurn();

	bool flagTurn = 1;

	//играть!!!
	void playGame();

	//ход игрока
	void turn(DiceOfSet &player2);
	//если у одного из игроков заканчиваются кости
	//void checkEmpty();


	~game();
};

