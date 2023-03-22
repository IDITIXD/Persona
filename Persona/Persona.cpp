#include <iostream>
#include <cstring>
#include <typeinfo>
using namespace std;
#define N 5

class PERSONA
{
protected:
	int cena;	//цена в час
	int tim;	//количество часов в месяц
	int zarplata;	//зарплата

	void count() { zarplata = cena * tim; }
public:
	PERSONA(int Cena, int Tim) :
		cena(Cena), tim(Tim) {
		count();
	}
	virtual ~PERSONA() {}
	virtual void Show() = 0;
	int DO() { return zarplata; }
};

class SLUJAHIY : public PERSONA
{
public:
	SLUJAHIY(int Cena, int Tim) : PERSONA(Cena, Tim) {}
	~SLUJAHIY() {}
	virtual void Show() { cout << "\tзарплата служащего = " << DO() << endl; }
};

class RABOCHIY : public PERSONA
{
public:
	RABOCHIY(int Cena, int Tim) :PERSONA(Cena, Tim) {}
	~RABOCHIY() {}
	void Show() { cout << "\tзарплата рабочего = " << DO() << endl; }
};

class INGENER : public PERSONA
{
public:
	INGENER(int Cena, int Tim) :PERSONA(Cena, Tim) {}
	~INGENER() {}
	void Show() { cout << "\tзарплата инженера = " << DO() << endl; }
};


//-------------------------------------------------------------------------------------
void main()
{
	setlocale(0, "");
	SLUJAHIY SLUJAHIY(200, 100);
	RABOCHIY rab(300, 2);
	INGENER ing(350, 100);

	PERSONA** mas = new PERSONA * [N];
	for (int i = 0; i < N; i++)    mas[i] = NULL;

	mas[0] = &SLUJAHIY;
	mas[1] = &rab;
	mas[2] = &ing;
	int i = 0;

	while (mas[i])
	{
		mas[i]->Show();
		i++;
	}

	int max = mas[0]->DO();
	int imin = 0;
	i = 1;
	while (mas[i])
	{
		if (max < mas[i]->DO()) {
			max = mas[i]->DO(); imin = i;
		}
		i++;
	}

	cout << "Максимальная зарплата у -" << typeid(*mas[imin]).name() << "- \n";
	delete[] mas;
}
