#pragma once
//������� �����
class dice
{
private:

	//�������� ������� �����
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



	// ����� ������ ������� x � y
	void swap();

	//����������� ��������
	void printDice();
	


	~dice();
};

