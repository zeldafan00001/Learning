#include <iostream>
#include "Quelle.h"
using namespace std;
struct Spieler
{
	int level;
	int cordsY[10];
	int cordsX[10];
};
struct Bot
{
	int level;
	int cordsY[10];
	int cordsX[10];
};

void structuren(Spieler Player, Spieler Gegner)
{
	for (int s = 0; s < 9; s++)
	{
		Player.cordsY[s] = s + 2;
		Player.cordsX[s] = s + 5;
		Gegner.cordsX[s] = s + 7;
		Gegner.cordsY[s] = s + 3;
	}
}

int main()
{

	cout << endl << "Player.CordsY" << endl;
	for (int s = 0; s < 9; s++)
	{
		cout << "X: " << Player.cordsX[s] << " | Y: " << Player.cordsY[s] << endl;
	}

	cout << endl << "Gegner.CordsY" << endl;
	for (int s = 0; s < 9; s++)
	{
		cout << "X: " << Gegner.cordsX[s] << " | Y: " << Gegner.cordsY[s] << endl;
	}

	getchar();
	return 0;
}