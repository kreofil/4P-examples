//------------------------------------------------------------------------------
// Файл int.cpp - определяет методы класса, задающего целое число.
//------------------------------------------------------------------------------

#include <iostream>
using namespace std;

#include "int.h"
#include "double.h"

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Вычитание второго аргумента из целочисленного.
Number* Int::Subtract(Number& num2)
{
	// Второй аргумент - целое число.
    if(Int* pInt = dynamic_cast<Int*>(&num2))
    {
		return new Int(_value - pInt->GetValue());
    }
    // Второй аргумент - действительное число.
    else if(Double* pDouble = dynamic_cast<Double*>(&num2))
    {
		return new Double(_value - pDouble->GetValue());
	}
	else
	{
		return 0;
	}
}

// Вывод значения числа в стандартный поток
void Int::StdOut()
{
	cout << "It is Int. Value = " << _value << endl;
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Конструктор, обеспечивающий инициализацию числа.
Int::Int(int v): _value(v)
{}
