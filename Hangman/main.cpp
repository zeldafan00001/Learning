#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
//[z][y][x]
bool running = false;
char SN[1][15];
char man[11][10][15] =
{ {"             ","             ","             ","             ","             ","             ","             ","#############"},
{"             ","    |        ","    |        ","    |        ","    |        ","    |        ","    |        ","#############" },
{"   []        ","    |        ","    |        ","    |        ","    |        ","    |        ","    |        ","#############" },
{"   []______  ","    |        ","    |        ","    |        ","    |        ","    |        ","    |        ","#############" },
{"   []______  ","    |     |  ","    |        ","    |        ","    |        ","    |        ","    |        ","#############" },
{"   []______  ","    |     |  ","    |     O  ","    |        ","    |        ","    |        ","    |        ","#############" },
{"   []______  ","    |     |  ","    |     O  ","    |    /|\x5c ","    |        ","    |        ","    |        ","#############" },
{"   []______  ","    |     |  ","    |     O  ","    |    /|\x5c ","    |     |  ","    |        ","    |        ","#############" },
{"   []______  ","    |     |  ","    |     O  ","    |    /|\x5c ","    |     |  ","    |    / \x5c ","    |        ","#############" } };

int lange = 0;
int count = 0;
char versuche[40];
char solve[40];
char rate[40];
int i, k = 0;
char inputU[40];
int win;

void name()
{
	for (int n = 0; n < 2; n++)
	{
		printf("Bitte geben sie den name des [%d] Spielers ein!\n>> ", n + 1);
		fgets(SN[n], 15, stdin); printf("\n");
	} // Namen eingabe
}

void hangman()
{
	for (int i = 0; i < 10; i++)
	{
		printf("%s\n", man[k][i]);
	} // Hangman Draw
	k++;
	//if (k == 9) { exit(-1); }
}

void wortEingabe()
{
	system("cls");
	printf("Geben sie ihr Wort ein!\n");
	fgets(rate, 40, stdin);
	lange = strlen(rate);
	win = lange - 1;
	for (i = 0; i < lange - 1; i++)
	{
		rate[i] = toupper(rate[i]);
		solve[i] = '#';
	}
	solve[i] = '\0';
	rate[i] = '\0';
}
int main()
{
	wortEingabe();
	while (!running)
	{
		system("cls");
		printf("%s\n", solve);
		printf("geben sie ein buchstaben ein!\n");
		hangman();
		if (strcmp(solve, rate) == 0)
		{
			running = true;
			break;
		}
		gets_s(inputU);

		for (int r = 0; r < lange - 1; r++)
		{
			if (rate[r] == toupper(inputU[0]))
			{
				solve[r] = toupper(inputU[0]);
			}
			
		}
		
	} 
	running = false;



	printf("Das wort ist %s mit einer lange von %d\n", rate, lange - 1);
	printf("%s", solve);
	Sleep(1000);
	while (!running)
	{
		system("cls");
		for (int i = 0; i < 10; i++)
		{
			printf("%s\n", man[k][i]);
		} // Hangman Draw
		_getch();
		k++;
		if (k == 9) { exit(-1); }
	}
	getchar();
	return 0;
}