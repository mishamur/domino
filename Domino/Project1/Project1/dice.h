#pragma once
//Игровая кость
class dice
{
private:

	//Значения игровой кости
	int x;
	int y;
	int value = x + y;
public:
	
	bool used = false;

	dice(int x, int y);

	int getX();
	void setX(int x);

	int getY();
	void setY(int y);

	int getValue();



	// метод меняет местами x и y
	void swap();

	//отображение косточки
	void printDice();
	


	~dice();
};

