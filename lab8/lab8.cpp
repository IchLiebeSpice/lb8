#include "stdafx.h"

using namespace std;

class Factory
{
protected:
	string value;

public:
	Factory() { value = ""; }
	long ShowBin();
	long ShowOct();
	string ShowHex();
private:
	Factory(string a) { value = a; }
};

class SymbString : public Factory
{
public:
	SymbString() { value = ""; }
	SymbString(string sym) { value = sym; };
};

class DecString : public Factory
{
public:
	DecString() { value = ""; }
	DecString(string dec) { value = dec; };
};

long Factory::ShowBin() {
	char mem[30];
	_itoa(atoi(value.c_str()), mem, 2);
	return atoi(mem);
}

long Factory::ShowOct() {
	char mem[30];

	_itoa(atoi(value.c_str()), mem, 8);
	return atoi(mem);
}
string Factory::ShowHex() {
	char mem[30];
	_itoa(atoi(value.c_str()), mem, 16);
	return (const char*)_strupr(mem);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	SymbString symb;
	DecString decs;
	string sym, dec;

	int exit = 0;
	do {
		int q = 0;
		cout << endl << endl << "1. Создать объект типа SymbString"
			<< endl << "2. Создать объект типа DecString"
			<< endl << "3. Удалить объект типа SymbString"
			<< endl << "4. Удалить объект типа DecString"
			<< endl << "5. ShowBin для DecString"
			<< endl << "6. ShowOct для DecString"
			<< endl << "7. ShowHex для DecString"
			<< endl << "8. Выход"
			<< endl << "Выбор: ";
		cin >> q;


		switch (q) {
		case 1:
			cout << endl << endl << "Введите значение: ";
			cin >> sym;
			symb = SymbString(sym);
			cout << "Объект создан.";
			break;
		case 2:
			cout << endl << endl << "Введите значение: ";
			cin >> dec;
			decs = DecString(dec);
			cout << "Объект создан.";
			break;
		case 3:
			cout << endl << endl;
			symb = SymbString("");
			cout << "Объект удален.";
			break;
		case 4:
			cout << endl << endl;
			decs = DecString("");
			cout << "Объект удален.";
			break;
		case 5:
			cout << endl << endl
				<< "Двоичное представление:" << endl << "\t" << decs.ShowBin();
			break;
		case 6:
			cout << endl << endl
				<< "Восьмиричное представление: " << endl << "\t" << decs.ShowOct();
			break;
		case 7:
			cout << endl << endl
				<< "Шеснадцатиричное представление: " << endl << "\t" << decs.ShowHex();
			break;

		case 8: 
			exit = 1; 
			break;
		}
	} while (exit == 0);

	return 0;
}
