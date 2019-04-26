#include <iostream>
using namespace std;

class Tester1
{
private:
	int hohe;
	int lange;
public:
	void rechner(int hohe,int lange);
	int area() { return hohe * lange; }
};

void Tester1::rechner(int x, int y)
{
	hohe = x;
	lange = y;
}

int main()
{
	int h, l;
	Tester1 test;
	
	cout << "Bitte geben sie die Hoehe ein!" << endl << ">> ";
	cin >> h;
	cout << "Bitte geben sie die Laenge ein!" << endl << ">> ";
	cin >> l;

	test.rechner(h, l);

	cout << "Die Area ist : " << test.area() << endl;

	system("pause");
	return 0;

}