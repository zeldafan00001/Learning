#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include <time.h>

clock_t cbegin, cend;

void stc(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void scv(bool show) {
	CONSOLE_CURSOR_INFO cursor;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
	cursor.bVisible = show;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

struct daten {
	int _d_id;
	char _d_name[20];
	int _d_alter;

	struct daten* next;

};

typedef daten daten;

struct daten* anfang = NULL;
struct daten* neu;
struct daten* aktuell = anfang;

void DatenEingeben(int& id)
{
	scv(true);
	system("cls");
	daten* neu;
	char loop = 'q';
	while (loop == 'q')
	{
		system("cls");
		if (anfang == NULL)
		{
			anfang = (daten*)malloc(sizeof(daten));
			//printf("ANFANG");
			//getchar();
			printf("ID(%d)\n", id);
			printf("Name eingeben : ");
			gets_s(anfang->_d_name);

			printf("Alter eingeben : ");
			scanf_s("%d", &anfang->_d_alter);

			anfang->_d_id = id;

			id++;

			anfang->next = NULL;
			aktuell = anfang;

			printf("Weiter? YES(q) / NO(e)");
			loop = _getch();
		}
		else {

			neu = (daten*)malloc(sizeof(daten));
			aktuell->next = neu;

			//printf("NEU");
			aktuell = neu;

			getchar();
			printf("ID(%d)\n", id);
			printf("Name eingeben : ");
			gets_s(aktuell->_d_name);

			printf("Alter eingeben : ");
			scanf_s("%d", &aktuell->_d_alter);

			neu->next = NULL;
			aktuell->_d_id = id;
			id++;

			printf("Weiter? YES(q) / NO(e)");
			loop = _getch();
		}
	}
}

void DatenAusgeben(int id)
{

	daten* aktuell = anfang;

	system("cls");
	if (anfang != NULL)
	{
		do
		{
			printf("ID(%d) %s %d\n", aktuell->_d_id, aktuell->_d_name, aktuell->_d_alter);
			aktuell = (aktuell->next);

		} while (aktuell != NULL);
	}
	else
		printf("Keine Daten vorhanden! press ENTER");
	getchar();
	getchar();
}

void DatenSpeichern()
{

	daten* aktuell = anfang;
	FILE* dat;

	dat = fopen("daten.txt", "w");

	if (anfang != NULL)
	{
		do
		{
			fprintf(dat, "%d\t%s\t%d", aktuell->_d_id, aktuell->_d_name, aktuell->_d_alter);
			fprintf(dat, "\n");
			aktuell = (aktuell->next);

		} while (aktuell != NULL);
	}

	system("cls"); printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	stc(20); printf("\t\t SAVED "); stc(1);
	printf("."); Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500); stc(7);

}

void DatenEinlesenAusTxT(int& id_)
{
	char name[20];
	int id;
	int alter;

	FILE* dat;

	dat = fopen("daten.txt", "r");

	printf("moin");

	if (anfang == NULL)
	{
		anfang = (daten*)malloc(sizeof(daten));
		//aktuell = neu;

		fscanf(dat, "%d %s %d", &anfang->_d_id, anfang->_d_name, &anfang->_d_alter);

		anfang->next = NULL;
		aktuell = anfang;
	}

	while (fscanf(dat, "%d %s %d", &id, name, &alter) != EOF)
	{
		neu = (daten*)malloc(sizeof(daten));
		aktuell->next = neu;

		aktuell = neu;

		aktuell->_d_id = id;
		strcpy(aktuell->_d_name, name);
		aktuell->_d_alter = alter;

		//fscanf(dat, "%d %s %d", &aktuell->_d_id, aktuell->_d_name, &aktuell->_d_alter);

		neu->next = NULL;
	}

	fclose(dat);

	id_ = 1 + aktuell->_d_id;

	system("cls"); printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	stc(20); printf("\t\t SAVED "); stc(1);
	printf("."); Sleep(500); printf("."); Sleep(500); printf("."); Sleep(500); stc(15);

}

void end()
{
	double time_spent;
	cend = clock();
	system("CLS");
	printf("Programm Closed\n");
	printf("Runtime ( "); stc(10);  printf("%.2fsec", time_spent = (double)(cend - cbegin) / CLOCKS_PER_SEC); stc(7); printf(" )\n");
	_getch();
	exit(1);
}

void drawMenu(int& x, char menu[4][20]) {
	stc(79); printf(" MALLOC |  SAVE DATA  | by Kevin Schmitz\n"); stc(15);
	printf("\n\n\n\n\n\n\n");
	for (int display = 0; display < 6; display++) {
		if (display == x) {
			stc(10); printf("\t     %s\n", menu[display]); stc(15);
		}
		if (display != x) {
			printf("\t     %s\n", menu[display]);
		}
	}
	stc(79); printf("\n\n\n\n\n\n\n\n\n\nSPACE = EINGABE | W = HOCH |  S = RUNTER"); stc(15);
}

void input(int& keyP, int& x) {				// Setz das x 
	keyP = _getch();
	switch (keyP)
	{
	case 119:
		x--;
		if (x == 0)
			x = 1;
		break;
	case 115:
		x++;
		if (x == 6)
			x = 5;
		break;
	}
}

int main()
{
	system("mode 40, 25");
	int id = 1;								// ID - Ist die ID des nutzers im Struct
	int x_menu = 1;
	int keyP;

	char menu[6][20] = { " ",				// Das menu array wird benutz um das menu darzustellen
		"DATEN EINGEBEN",
		"DATEN AUSGEBEN",
		"SPEICHER DATEN",
		"DATEN EINLESEN",
		"BEENDE ROGRAMM" };

	cbegin = clock();						// mit cbegin wird angefangen die zeit zu zählen

	while (true) {							// Start des neuen Menü design 
		
		scv(false);
		system("cls");

		drawMenu(x_menu, menu);
		input(keyP, x_menu);

		if (GetAsyncKeyState(VK_SPACE))		// nur wenn space gedrückt wird
		{
			switch (x_menu)
			{
			case 1:
				DatenEingeben(id);
				break;
			case 2:
				DatenAusgeben(id);
				break;
			case 3:
				DatenSpeichern();
				break;
			case 4:
				DatenEinlesenAusTxT(id);
				break;
			case 5:
				end();
				break;
			}
		}
	}
	return 0;

}