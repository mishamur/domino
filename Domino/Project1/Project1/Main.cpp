/* ������
 ����: ������� ������ �������
 (�� ������ ������� ��������-������ � ������� ������ � ���� ������ � ����), �������� ����. 
 ����������� ������ �������, ������ ������, �����. ����������� ���� ���� �������. 
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
	DiceOfSet player1; //���� ������� ������

	game game;

	game.playGame();

	system("pause");
}
