//------------------------------------------------------------------------------
// Файл minus.cpp - задает функцию.вычитания
//------------------------------------------------------------------------------

#include "int.h"
#include "double.h"

// Функция вычитания, использующая только RTTI.
Number* operator- (Number& n1, Number& n2)
{
	// Первый аргумент - целое число.
    if(Int* pInt1 = dynamic_cast<Int*>(&n1))
	{
		// Второй аргумент - целое число.
	    if(Int* pInt2 = dynamic_cast<Int*>(&n2))
		{
			return new Int(pInt1->GetValue() - pInt2->GetValue());
		}
		// Второй аргумент - действительное число.
	    else if(Double* pDouble2 = dynamic_cast<Double*>(&n2))
		{
			return new Double(pInt1->GetValue() - pDouble2->GetValue());
		}
	}
	// Первый аргумент - действительное число.
    else if(Double* pDouble1 = dynamic_cast<Double*>(&n1))
	{
		// Второй аргумент - целое число.
	    if(Int* pInt2 = dynamic_cast<Int*>(&n2))
		{
			return new Double(pDouble1->GetValue() - pInt2->GetValue());
		}
		// Второй аргумент - действительное число.
	    else if(Double* pDouble2 = dynamic_cast<Double*>(&n2))
		{
			return new Double(pDouble1->GetValue() - pDouble2->GetValue());
		}
	}
	return nullptr;
}


