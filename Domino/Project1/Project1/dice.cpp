#include "dice.h"
#include <iostream>
#include <vector>

using namespace std;



dice::dice(int x, int y)
{
	this->x = x;
	this->y = y;
}

void dice::setX(int x) {
	this->x = x;
}

int dice::getX() {
	return this->x;
}

int dice::getValue() {
	return this->value;
}

void dice::setY(int y) {
	this->y = y;
}

int dice::getY() {
	return this->y;
}

void dice::swap() {
	int swap = 0;
	swap = this->x;
	this->x = y;
	this->y = swap;
}

void dice::printDice() {
	cout << " [" << x << "/" << y << "] ";
}


dice::~dice()
{
}
