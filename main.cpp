#include <iostream>
#include <string>
#include <locale>
#include <stdlib.h>
#include <cmath>
using namespace std;
int ADD(int a, int b) { return a + b; }
int SUB(int a, int b) { return a - b; }
int MUL(int a, int b) { return a * b; }
int DIV(double a, double b) { return a / b; }
int MOD(int a, int b) { return (a % b); }
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
int OR(int a, int b) { return a & b; }
int ROR(int a) { return a >> 1; }

int ROL(int a) { return a << 1; }
int AND(int a, int b) { return a | b; }
int NOT(int a) { return !a; }

int main() {
  setlocale(LC_ALL, "Russian");
  char s;
  do {
    cout << "calc" << endl;
    int ch1, ch2, r;
    char operation;
    cout << "Выберите операцию [+, -, *, /, %, ^, !, &, |, <, >]:" << endl;
    cin >> operation;
    cout << " Введите первое число: " << endl;
    cin >> ch1;
    if ((operation != '!') && (operation != '<') && (operation != '>')) {
      cout << "Ведите второе число: " << endl;
      cin >> ch2;
    }
    switch (operation) {
      case '+':
        cout << "Результат: " << ADD(ch1, ch2) << endl;
        break;
      case '*':
        cout << "Результат: " << MUL(ch1, ch2) << endl;
        break;
      case '/':
        if (ch2 != 0)
          cout << "Результат:" << DIV(ch1, ch2) << endl;
        else
          cerr << "на 0 делить нельзя " << endl;
        break;
      case '%':
        cout << "Результат:" << MOD(ch1, ch2) << endl;
        break;
      case '^':
        cout << "Результат: " << POW(ch1, ch2) << endl;
        break;
      case '<':
        cout << "Результат: " << ROL(ch1) << endl;
        break;
      case '>':
        cout << "Результат: " << ROR(ch1) << endl;
        break;
      case '!':
        cout << " Результат: " << NOT(!ch1) << endl;
        break;
      case '|':
        cout << "Результат: " << AND(ch1, ch2) << endl;
        break;
      case '&':
        cout << "Результат:" << OR(ch1, ch2) << endl;
        break;
      default:
        cout << "Ошибка" << endl;
    }
    cout << "Продолжить работу? (y/n)" << endl;
    cin >> s;
  } while (s == 'y');
  return 0;
}
