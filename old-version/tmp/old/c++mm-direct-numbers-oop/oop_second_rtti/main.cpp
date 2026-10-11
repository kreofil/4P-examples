//------------------------------------------------------------------------------
// Файл main.cpp - задает тестовую функцию.
//------------------------------------------------------------------------------

#include <iostream>
using namespace std;

#include "int.h"
#include "double.h"

// Функция вычитания, использующая множественный полиморфизм.
Number* operator- (Number& n1, Number& n2);

// Маленький тест.
int main(void)
{
	Number* rez;
	Int i1(10);
	i1.StdOut();
	Int i2(3);
	i2.StdOut();
	Double d1(3.14);
	d1.StdOut();
	Double d2(2.7);
	d2.StdOut();
	rez = i1 - i2;	rez->StdOut(); delete rez;
	rez = i2 - i1;	rez->StdOut(); delete rez;
	rez = d1 - d2;	rez->StdOut(); delete rez;
	rez = d2 - d1;	rez->StdOut(); delete rez;
	rez = i1 - d2;	rez->StdOut(); delete rez;
	rez = i2 - d1;	rez->StdOut(); delete rez;
	rez = d1 - i2;	rez->StdOut(); delete rez;
	rez = d2 - i1;	rez->StdOut(); delete rez;

	return 0;
}