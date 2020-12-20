#include "DiceOfSet.h"
#include <vector>
using namespace std;

DiceOfSet::DiceOfSet()
{
}


void DiceOfSet::PrintPlayerDice() {

	cout << endl;
	for (int i = 0; i < this->a.size(); i++) {
		cout << "   " << i << "   ";
	}

	cout << endl;

	for (int i = 0; i < this->a.size(); i++) {
		a.at(i).printDice();
	}
}

void DiceOfSet::printAllDice(){
	for (int i = 0; i < this->a.size(); i++) {
		 a.at(i).printDice();
	}
}

ostream &operator<<(ostream &cout, DiceOfSet diceOfSet) {
	diceOfSet.printAllDice();
	return cout;
}

DiceOfSet operator+=( DiceOfSet &diceOfSet, dice &Dice) {
	diceOfSet.a.push_back(Dice);
	return diceOfSet;
}

DiceOfSet::~DiceOfSet()
{
}
