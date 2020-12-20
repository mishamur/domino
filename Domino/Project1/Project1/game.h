#include <iostream>
#include <vector>
#include "dice.h"
#include "DiceOfSet.h"
#pragma once

using namespace std;
class game
{
public:
	//� ������������ ��� ����� ����������� � �������������� 
	game();

	//����(�����)
	DiceOfSet heap;
	
	//����� ������ ������� ������
	DiceOfSet player1;
	//����� ������ ������� ������
	DiceOfSet player2;

	//������� ����
	DiceOfSet playingField;

	//���� ������
	bool flagOfEnd = true;

	//������ ���
	bool firstTurn();

	bool flagTurn = 1;

	//������!!!
	void playGame();

	//��� ������
	void turn(DiceOfSet &player2);
	//���� � ������ �� ������� ������������� �����
	//void checkEmpty();


	~game();
};

