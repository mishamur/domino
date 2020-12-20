#include "game.h"
#include <iostream>
#include <vector>
#include "dice.h"
#include "DiceOfSet.h"
#include <algorithm>
#include <conio.h>
#include <windows.system.display.h>


using namespace std;

void gotoxy(int xpos, int ypos)
{
	COORD scrn;

	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

	scrn.X = xpos; scrn.Y = ypos;

	SetConsoleCursorPosition(hOuput, scrn);
}

//void game::checkEmpty() {
//	if (player1.a.size() == 0) {
//
//	}
//}

void game::turn(DiceOfSet &player2) {
	while (flagTurn) {
		/*system("cls");
		cout << "Ход второго игрока: ";
		gotoxy(80 - playingField.a.size(), 15);
		playingField.printAllDice();
		gotoxy(5, 25);
		cout << "какую кость ты хочешь положить?";

		gotoxy(5, 28);
		cout << "Твои кости: ";
		player2.printAllDice();
		cout << endl << endl;*/


		/*	player2.a.front().printDice();
			cout << endl << endl;
			player2.a.back().printDice();*/
			bool chekTakeDice = true;
			//если можно положить кость
		for (int i = 0; i < player2.a.size(); i++) {
			if (player2.a.at(i).getX() == playingField.a.front().getX() ||
				player2.a.at(i).getY() == playingField.a.front().getX() ||

				player2.a.at(i).getX() == playingField.a.back().getY() ||
				player2.a.at(i).getY() == playingField.a.back().getY()) {
				chekTakeDice = false;
				//интерфейс
				system("cls");
				gotoxy(80 - playingField.a.size(), 15);
				playingField.printAllDice();
				gotoxy(5, 25);
				cout << "какую кость ты хочешь положить?";

				gotoxy(5, 28);
				cout << "Твои кости: ";
				player2.PrintPlayerDice();
				cout << endl << endl;

				//индекс кости в руке
				int num = 0;
				

				do {
					cout << "введи индекс кости которую хочешь положить :  ";
					cin >> num;
				} while (num < 0 || num > player2.a.size() - 1);

				if (player2.a.at(num).getX() == playingField.a.front().getX() && player2.a.at(num).getY() == playingField.a.back().getY() ||
					player2.a.at(num).getY() == playingField.a.front().getX() && player2.a.at(num).getX() == playingField.a.back().getY()) {
					cout << "Куда положишь? " << endl << "1.Начало" << endl << "2. Конец" << endl;
					int dir = 0;
					do {
						cin >> dir;
					} while (dir < 1 || dir > 2);

					//в начало
					if (dir == 1) {
						if (player2.a.at(num).getY() == playingField.a.front().getX()) {
							//кладём её в начало нашей игровой доски и удаляем из руки
							playingField.a.insert(playingField.a.begin(), player2.a.at(num));
							player2.a.erase(player2.a.begin() + num);

							flagTurn = 0;
							player2.missTurn = false;
							break;
						}
						else if (player2.a.at(num).getX() == playingField.a.front().getX()) {
							//свапаем координаты нашей кости, кладём её в начало нашей игровой доски и удаляем из руки
							player2.a.at(num).swap();
							playingField.a.insert(playingField.a.begin(), player2.a.at(num));
							player2.a.erase(player2.a.begin() + num);

							flagTurn = 0;
							player2.missTurn = false;
							break;
						}
					}
					else if (dir == 2) {
						if (player2.a.at(num).getX() == playingField.a.back().getY()) {
							//кладём её в конец нашей игровой доски и удаляем из руки
							playingField.a.push_back(player2.a.at(num));
							player2.a.erase(player2.a.begin() + num);

							flagTurn = 0;
							player2.missTurn = false;
							break;
						}
						else if (player2.a.at(num).getY() == playingField.a.back().getY()) {
							//свапаем координаты нашей кости, кладём её в конец нашей игровой доски и удаляем из руки
							player2.a.at(num).swap();
							playingField.a.push_back(player2.a.at(num));
							player2.a.erase(player2.a.begin() + num);

							flagTurn = 0;
							player2.missTurn = false;
							break;
						}
					}

				}
				if (player2.a.at(num).getX() == playingField.a.front().getX() || player2.a.at(num).getY() == playingField.a.front().getX() ||
					player2.a.at(num).getX() == playingField.a.back().getY() || player2.a.at(num).getY() == playingField.a.back().getY()) {
					//проверка на положить в начало
					if (player2.a.at(num).getY() == playingField.a.front().getX()) {
						//кладём её в начало нашей игровой доски и удаляем из руки
						playingField.a.insert(playingField.a.begin(), player2.a.at(num));
						player2.a.erase(player2.a.begin() + num);

						flagTurn = 0;
						player2.missTurn = false;
						break;
					}
					else if (player2.a.at(num).getX() == playingField.a.front().getX()) {
						//свапаем координаты нашей кости, кладём её в начало нашей игровой доски и удаляем из руки
						player2.a.at(num).swap();
						playingField.a.insert(playingField.a.begin(), player2.a.at(num));
						player2.a.erase(player2.a.begin() + num);

						flagTurn = 0;
						player2.missTurn = false;
						break;
					}
					//проверка на положить в конец

					else if (player2.a.at(num).getX() == playingField.a.back().getY()) {
						//кладём её в конец нашей игровой доски и удаляем из руки
						playingField.a.push_back(player2.a.at(num));
						player2.a.erase(player2.a.begin() + num);

						flagTurn = 0;
						player2.missTurn = false;
						break;
					}

					else if (player2.a.at(num).getY() == playingField.a.back().getY()) {
						//свапаем координаты нашей кости, кладём её в конец нашей игровой доски и удаляем из руки
						player2.a.at(num).swap();
						playingField.a.push_back(player2.a.at(num));
						player2.a.erase(player2.a.begin() + num);

						flagTurn = 0;
						player2.missTurn = false;
						break;
					}
				}

			}
		}
		//если нельзя положить кость то мы берём кости из базара пока у нас не будет подходящей, или базар не опустеет 
		if ( heap.a.size() != 0 && flagTurn == 1 && chekTakeDice == true) {
			//интерфейс
			system("cls");
			gotoxy(80 - playingField.a.size(), 15);
			playingField.printAllDice();
			gotoxy(5, 25);
			cout << "какую кость ты хочешь положить?";

			gotoxy(5, 28);
			cout << "Твои кости: ";
			player2.PrintPlayerDice();
			cout << endl << endl;

			cout << endl << "БЕРУ КОСТЬ ИЗ БАЗАРА " << endl;
			system("pause");
			
			player2.a.push_back(heap.a.back());
			heap.a.pop_back();
		}
		else if (heap.a.size() == 0 && flagTurn == 1 && chekTakeDice == true) {
			player2.missTurn = true; 	
			system("cls");
			gotoxy(80 - playingField.a.size(), 15);
			playingField.printAllDice();

			gotoxy(5, 28);
			cout << "Твои кости: ";
			player2.PrintPlayerDice();
			cout << endl << endl;

			cout << "Пропускаю ход потому что нечем ходить!"<< endl;
			system("pause");
			flagTurn = 0;
		}

	}
	
}

game::game()
{
	for (int i = 0; i < 7; i++) {

		for (int j = 0; j < 7; j++) {
			if (j >= i) {
				this->heap.a.push_back(dice(i, j));
			}
		}	
	}
	random_shuffle(heap.a.begin(), heap.a.end());
}

//определение первого хода//
bool game::firstTurn() {

	//double
	int value1 = -1;
	int value2 = -1;
	int it1 = 0;
	int it2 = 0;
	for (int i = 0; i < player1.a.size(); i++) {


		if (player1.a[i].getX() == player1.a[i].getY() && player1.a[i].getX() > value1) {
			value1 = player1.a[i].getX();
			it1 = i;
		}

		if (player2.a[i].getX() == player2.a[i].getY() && player2.a[i].getX() > value2) {
			value2 = player2.a[i].getX();
			it2 = i;
		}
	}

	if (value1 > value2) {
		cout << "Первым ходит 1 игрок выбрасывая свою кость!!!!"<<endl;
		playingField.a.push_back(player1.a[it1]);
		player1.a.erase(player1.a.begin() + it1);



		/*for (auto it : player1.a) {
			if (it.used == true) {
				player1.a.erase(player1.a.begin()+2);
			}
		}*/

		return true;
	}
	else {
		playingField.a.push_back(player2.a[it2]);
		player2.a.erase(player2.a.begin() + it2);
		cout << "Первым ходит 2 игрок выбрасывая свою кость!!!!"<<endl;
		return false;
	}
	//if нет дублей 
	if (value1 == value2) {
		value1 = 0;
		value2 = 0;

		for (int i = 0; i < player1.a.size(); i++) {
			if ((player1.a[i].getValue()) > value1) {
				value1 = player1.a[i].getX() + player1.a[i].getY();
				it1 = i;
			}

			if ((player2.a[i].getValue()) > value2) {
				value2 = player2.a[i].getX() + player2.a[i].getY();
				it1 = i;
			}
		}
		if (value1 > value2) {
			cout << "Первым ходит 1 игрок выбрасывая свою кость!!!!"<<endl;
			playingField.a.push_back(player1.a[it1]);
			player1.a.erase(player1.a.begin() + it1);
			return true;
		}
		else {
			cout << "Первым ходит 2 игрок выбрасывая свою кость!!!!"<<endl;
			playingField.a.push_back(player1.a[it1]);
			player1.a.erase(player1.a.begin() + it1);
			return false;
		}
	}
	/////////////////////////////////
}

void game::playGame() {
	

	//раздача костей игрокам
	for (int i = 0; i < 7; i++) {
		player1.a.push_back(heap.a.back());
		heap.a.pop_back();

		player2.a.push_back(heap.a.back());
		heap.a.pop_back();
	}


//	firstTurn();

	
		if (firstTurn()) {//начинает первый игрок выбрасывая свою кость
			system("pause");
			while (flagOfEnd) {
				
				//если нечем ходить обоим игрокам//////////////////////
				if (player1.missTurn == true && player2.missTurn == true) {
					int countPlayer1 = 0;
					int countPlayer2 = 0;

					for (int i = 0; i < player1.a.size(); i++) {
						countPlayer1 = countPlayer1 + (player1.a.at(i).getX() + player1.a.at(i).getY());
					}

					for (int i = 0; i < player2.a.size(); i++) {
						countPlayer2 = countPlayer2 + (player2.a.at(i).getX() + player2.a.at(i).getY());
					}

					if (countPlayer1 < countPlayer2) {
						flagOfEnd = false;
						system("cls");
						cout << "  -------------ПЕРВЫЙ ИГРОК ВЫИГРАЛ-------------   " << endl;
						break;
					}
					else if (countPlayer2 < countPlayer1) {
						flagOfEnd = false;
						system("cls");
						cout << "  -------------ВТОРОЙ ИГРОК ВЫИГРАЛ-------------   " << endl;
						break;
					}
					else if (countPlayer1 == countPlayer2) {
						flagOfEnd = false;
						system("cls");
						cout << "  ---------------НИЧЬЯ-------------   " << endl;
						break;
					}
				}
				//////////////////////////////////

				system("cls");
				cout << "------ХОД ВТОРОГО ИГРОКА-------";
				system("pause");



				flagTurn = true;

				//конец игры кончились кости
				if (player1.a.size() == 0) {
					flagOfEnd = false;
					flagTurn = false;
					system("cls");
					cout << "  -------------ПЕРВЫЙ ИГРОК ВЫИГРАЛ-------------   " << endl;
					
					break;
				}
				else if (player2.a.size() == 0) {
					flagOfEnd = false;
					flagTurn = false;
					system("cls");
					cout << "  -------------ВТОРОЙ ИГРОК ВЫИГРАЛ-------------   " << endl;
					break;
				}

				
				turn(player2);


				//если нечем ходить обоим игрокам
				if (player1.missTurn == true && player2.missTurn == true) {
					int countPlayer1 = 0;
					int countPlayer2 = 0;

					for (int i = 0; i < player1.a.size(); i++) {
						countPlayer1 = countPlayer1 + (player1.a.at(i).getX() + player1.a.at(i).getY());
					}

					for (int i = 0; i < player2.a.size(); i++) {
						countPlayer2 = countPlayer2 + (player2.a.at(i).getX() + player2.a.at(i).getY());
					}

					if (countPlayer1 < countPlayer2) {
						flagOfEnd = false;
						system("cls");
						cout << "  -------------ПЕРВЫЙ ИГРОК ВЫИГРАЛ-------------   " << endl;
						break;
					}
					else if (countPlayer2 < countPlayer1) {
						flagOfEnd = false;
						system("cls");
						cout << "  -------------ВТОРОЙ ИГРОК ВЫИГРАЛ-------------   " << endl;
						break;
					}
					else if (countPlayer1 == countPlayer2) {
						flagOfEnd = false;
						system("cls");
						cout << "  ---------------НИЧЬЯ-------------   " << endl;
						break;
					}

				}
	


				//ход первого игрока
				flagTurn = true;

				//конец игры кончились кости
				if (player1.a.size() == 0) {
					flagOfEnd = false;
					flagTurn = false;
					system("cls");
					cout << "  -------------ПЕРВЫЙ ИГРОК ВЫИГРАЛ-------------   " << endl;

					break;
				}
				else if (player2.a.size() == 0) {
					flagOfEnd = false;
					flagTurn = false;
					system("cls");
					cout << "  -------------ВТОРОЙ ИГРОК ВЫИГРАЛ-------------   " << endl;
					break;
				}


				system("cls");
				cout << "------ХОД ПЕРВОГО ИГРОКА-------";
				system("pause");


				turn(player1);


			}
		}
		else{//начинает второй игрок выбрасывая свою кость
			system("pause");
			while (flagOfEnd) {
				

				//если нечем ходить обоим игрокам
				if (player1.missTurn == true && player2.missTurn == true) {
					int countPlayer1 = 0;
					int countPlayer2 = 0;

					for (int i = 0; i < player1.a.size(); i++) {
						countPlayer1 = countPlayer1 + (player1.a.at(i).getX() + player1.a.at(i).getY());
					}

					for (int i = 0; i < player2.a.size(); i++) {
						countPlayer2 = countPlayer2 + (player2.a.at(i).getX() + player2.a.at(i).getY());
					}

					if (countPlayer1 < countPlayer2) {
						flagOfEnd = false;
						system("cls");
						cout << "  -------------ПЕРВЫЙ ИГРОК ВЫИГРАЛ-------------   " << endl;
						break;
					}
					else if (countPlayer2 < countPlayer1) {
						flagOfEnd = false;
						system("cls");
						cout << "  -------------ВТОРОЙ ИГРОК ВЫИГРАЛ-------------   " << endl;
						break;
					}
					else if (countPlayer1 == countPlayer2) {
						flagOfEnd = false;
						system("cls");
						cout << "  ---------------НИЧЬЯ-------------   " << endl;
						break;

					}

				}

				system("cls");
				cout << "------ХОД ПЕРВОГО ИГРОКА-------";
				system("pause");

				flagTurn = true;

				//конец игры кончились кости
				if (player1.a.size() == 0) {
					flagOfEnd = false;
					flagTurn = false;
					system("cls");
					cout << "  -------------ПЕРВЫЙ ИГРОК ВЫИГРАЛ-------------   " << endl;

					break;
				}
				else if (player2.a.size() == 0) {
					flagOfEnd = false;
					flagTurn = false;
					system("cls");
					cout << "  -------------ВТОРОЙ ИГРОК ВЫИГРАЛ-------------   " << endl;
					break;
				}

				turn(player1);

				//если нечем ходить обоим игрокам
				if (player1.missTurn == true && player2.missTurn == true) {
					int countPlayer1 = 0;
					int countPlayer2 = 0;

					for (int i = 0; i < player1.a.size(); i++) {
						countPlayer1 = countPlayer1 + (player1.a.at(i).getX() + player1.a.at(i).getY());
					}

					for (int i = 0; i < player2.a.size(); i++) {
						countPlayer2 = countPlayer2 + (player2.a.at(i).getX() + player2.a.at(i).getY());
					}

					if (countPlayer1 < countPlayer2) {
						flagOfEnd = false;
						system("cls");
						cout << "  -------------ПЕРВЫЙ ИГРОК ВЫИГРАЛ-------------   " << endl;
						break;
					}
					else if (countPlayer2 < countPlayer1) {
						flagOfEnd = false;
						system("cls");
						cout << "  -------------ВТОРОЙ ИГРОК ВЫИГРАЛ-------------   " << endl;
						break;
					}
					else if (countPlayer1 == countPlayer2) {
						flagOfEnd = false;
						system("cls");
						cout << "  ---------------НИЧЬЯ-------------   " << endl;
						break;

					}

				}


				//ход второго игрока
				flagTurn = true;

				//конец игры кончились кости
				if (player1.a.size() == 0) {
					flagOfEnd = false;
					flagTurn = false;
					system("cls");
					cout << "  -------------ПЕРВЫЙ ИГРОК ВЫИГРАЛ-------------   " << endl;
					break;
				}
				else if (player2.a.size() == 0) {
					flagOfEnd = false;
					flagTurn = false;
					system("cls");
					cout << "  -------------ВТОРОЙ ИГРОК ВЫИГРАЛ-------------   " << endl;
					break;
				}


				system("cls");
				cout << "------ХОД ВТОРОГО ИГРОКА-------";
				system("pause");
				turn(player2);
			}
		}
		
	
}



game::~game()
{
}
