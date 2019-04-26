#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
// Rechtsklick auf 3D Wurfel > Eigenschaften > Linker > Eingabe > zusätzliche Abhängikeit > Bearbeiten > winmm.lib Einfügen
//[z][y][x]
bool running = false;
HANDLE hConsole;
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

int lange = 0, count = 0, win, aw, versu;
char versuche[40];
char solve[40];
char rate[40];
int i, k = 0, fail = 0;
char inputU[40];
char temp[40];


void name()
{
	for (int n = 0; n < 2; n++)
	{
		printf("Bitte geben sie den name des [%d] Spielers ein!\n>> ", n + 1);
		fgets(SN[n], 15, stdin); printf("\n");
	} // Namen eingabe
} // void name() ende
void hangman()
{
	for (int i = 0; i < 10; i++)
	{
		printf("%s\n", man[k][i]);
	} // Hangman Draw
	//if (k == 9) { exit(-1); }
} //void hangman() ende
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

void game()
{
	
	while (!running)
	{
		system("cls");
		printf("Wollen sie ein Wort oder ein Buchstaben eingeben? \n[ 1 Buchstabe | 2 Wort ]\n");
		printf("%s\n\n", solve);
		hangman();
		aw = _getch();

		if (aw == 49)
		{ 
			system("cls");
			printf("%s\n", solve);
			printf("Benutze Worter : ");
			printf("geben sie ein buchstaben ein!\n");

			hangman(); // wiedergabe des hangmans

			gets_s(inputU);

			for (int r = 0; r < lange - 1; r++)
			{
				if (rate[r] == toupper(inputU[0])) { solve[r] = toupper(inputU[0]); } // vergleicht ein wort mit buchstaben
				if (rate[r] != toupper(inputU[0])) { fail++; } // wenn kein buchstabe im wort vorhanden ist!;

			}
			if (fail == lange - 1) { k++; Beep(500, 500);}
			fail = 0;

			for (versu = 0; versu < lange - 1;)
			{
				versuche[versu] = toupper(inputU[0]);
				break;
			}
			//versuche[versu++] = '\0';
			if (strcmp(solve, rate) == 0)
			{
				running = true;
				break;
			} // Vergleicht die wörter ( Gibt bescheid wenn beide gleich sind ) 
			  
			
			versu++;
		} // Wort eingabe || if (aw == 49)

		if (aw == 50)
		{
			printf("%s\n", solve);
			printf("geben sie ihr wort ein!\n");
			hangman();
			fgets(inputU, 40, stdin);

			for (i = 0; i < lange - 1; i++)
			{
				temp[i] = toupper(inputU[i]);
			} 
			temp[i] = '\0';

			if (strcmp(rate, temp) == 0) {
				win = 1;
				running = true;
				break;
			} // Vergleicht das wort ob es richtig ist
			if (strcmp(rate, temp) != 0) {
				k = 8;
				hangman();
				Beep(750, 500);
				win = 0;
				running = true;
				break;
			} // Vergleicht das wort ob es Falsch ist
		}
	}
}
int main()
{
	//PlaySound("musik.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("mode 50, 20");

	wortEingabe();
	game();
	
	printf("Das wort ist %s mit einer lange von %d\n", rate, lange - 1);
	printf("%s", rate);
	Sleep(1000);

	getchar();
	return 0;
}
