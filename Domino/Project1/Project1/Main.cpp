/* ДОМИНО
 Дано: Раздача костей игрокам
 (по одному массиву объектов-костей у каждого игрока и один массив – куча), имитация игры. 
 Реализовать классы «Кость», «Набор Костей», «Игра». Имитировать игру двух игроков. 
*/

#include <iostream>
#include <locale.h>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include <vector>
#include <algorithm>
#include "dice.h"
#include "DiceOfSet.h"
#include "game.h"

using namespace std;

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "RUS");
	DiceOfSet player1; //рука первого игрока

	game game;

	game.playGame();

	system("pause");
}
