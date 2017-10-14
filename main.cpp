#include <iostream>
#include <string>
#include <locale>
#include <stdlib.h>
#include <cmath>
#include <limits>
using namespace std;
int ADD(int a, int b) {
	return a + b;
}
int SUB(int a, int b) {
	return a - b;
}
int MUL(int a, int b) {
	return a * b;
}
int DIV(double a, double b) {
	return a / b;
}
int MOD(int a, int b) {
	return (a % b);
}
double POW(double a, double b) {
	if (b > 0) {
		for (int i = 0, j = a; i < b - 1; i++) a *= j;
		return a;
	} else if (b < 0) {
		for (int i = 0, j = a; i < (b + 1) * (-1); i++) a *= j;
		return 1 / a;
	} else
		return 1;
}
int OR(int a, int b) {
	return a & b;
}
int ROR(int a) {
	return a » 1;
}

int ROL(int a) {
	return a « 1;
}
int AND(int a, int b) {
	return a | b;
}
int NOT(int a) {
	return !a;
}

int main() {
	setlocale(LC_ALL, "Russian");
	char s;
	do {
		cout « "calc" « endl;
		int ch1, ch2, r;
		char operation;
		bool a=true;
		do {

			cout « "выберите операцию [+, -, *, /, %, ^, !, &, |, <, >]:" « endl;
			cin » operation;
			if(operation != '+' && operation != '-' && operation != '*' &&
			        operation != '/' && operation != '%' && operation != '^' &&
			        operation != '!' && operation != '&' && operation != '|' &&
			        operation != '<' && operation != '>')
				cerr«"ошибка"«endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		} while(operation != '+' && operation != '-' && operation != '*' &&
		        operation != '/' && operation != '%' && operation != '^' &&
		        operation != '!' && operation != '&' && operation != '|' &&
		        operation != '<' && operation != '>');
		do {
			cin » ch1;
			if(!cin.good()) {
				cerr«"Error"«endl;
				a=false;
			} else a=true;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		} while(a!=true);
		if ((operation != '!') && (operation != '<') && (operation != '>')) {
			do {
				cin » ch2;
				if(!cin.good()) {
					cerr«"Error"«endl;
					a=false;
				} else a=true;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
			} while(a!=true);
		}
		switch (operation) {
			case '+':
				cout « "результат: " « ADD(ch1, ch2) « endl;
				break;
			case '*':
				cout « "результат: " « MUL(ch1, ch2) « endl;
				break;
			case '/':
				if (ch2 != 0)
					cout « "результат:" « DIV(ch1, ch2) « endl;
				else
					cerr « "на 0 делить нельзя" « endl;
				break;
			case '%':
				cout « "результат:" « MOD(ch1, ch2) « endl;
				break;
			case '^':
				cout « "результат:" « POW(ch1, ch2) « endl;
				break;
			case '<':
				cout « "результат:" « ROL(ch1) « endl;
				break;
			case '>':
				cout « "результат:" « ROR(ch1) « endl;
				break;
			case '!':
				cout « "результат:" « NOT(!ch1) « endl;
				break;
			case '|':
				cout « "результат:" « AND(ch1, ch2) « endl;
				break;
			case '&':
				cout « "результат:" « OR(ch1, ch2) « endl;
				break;
			default:
				cout « "ошибка" « endl;
		}
		do {
			cout « "продолжить работу? (y/n)" « endl;
			cin » s;
			if(s!='n'&&s!='y')
				cerr«"Error"«endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		} while(s!='n'&&s!='y');
	} while (s == 'y');
	return 0;
}
