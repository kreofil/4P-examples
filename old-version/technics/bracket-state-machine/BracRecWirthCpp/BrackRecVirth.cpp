//
// BrackRecVirth.cpp - рекурсивный распознаватель вложенности круглых скобок.
// Построен на основе диаграмм Вирта, эквивалентных следующей РБНФ
//
// $S = {/ "(" [ S ] ")" /}.
//

#include <iostream>
#include <string>

using namespace std;

string str;	// Строка с входной цепочкой, имитирующая входную ленту
int i;	// Текущее положение входной головки

int erFlag; // Флаг, фиксирующий наличие ошибок в середине правила

// Функция, реализующая чтение символов в буфер из входного потока.
// Используется для ввода с клавиатуры распознаваемой строки.
// Ввод осуществляется до нажатия на клавишу Enter.
// Символ '\n' является концевым маркером входной строки.
void GetOneLine(istream &is, string &str) {
	char ch;
	str = "";
	for(;;) {
		is.get(ch);
		if(is.fail() || ch == '\n') break;
		str += ch;
	}
	str += '\n'; // Добавляется концевой маркер
}

// Функция, реализующая распознавание нетерминала S.
bool S() {
//_0: // Начало диаграммы
	if(str[i] == '(') {
		i++;
		goto _1;
	}
	return false;// Первый символ цепочки некорректен
		  // что это ошибка, лучше определить снаружи
  _1: // Точка 1 диаграммы
		if(str[i] == ')') {
			i++;
			goto _3;
		}
		if(S()) {
			goto _2;
		}
		erFlag++;
		cout  << "Position " << i << ", "
  			  << "Error 1: I want closed bracket or next opened bracket!\n";
		return false;
  _2: // Точка 2 диаграммы
		if(str[i] == ')') {
			i++;
			goto _3;
		}
		erFlag++;
		cout  << "Position " << i << ", "
  			  << "Error 2: I want closed bracket!\n";
		return false;
  _3: // Точка 3 диаграммы
		if(str[i] == '(') {
			i++;
			goto _1;
		}
		goto _end;
  _end: // Точка end диаграммы
	return true;
}

// Функция, реализующая распознавание нетерминала Z.
bool Z() {
//_0: // Начало диаграммы
	if(S()) goto _1;
	return false;// Первый символ цепочки некорректен
		  // что это ошибка, лучше определить снаружи
  _1: // Точка 1 диаграммы
    // За последней скобкой должен быть "конец строки"
	if(str[i] == '\n')
	{
		goto _end; // Все прошло нормально
	}
	erFlag++;
	cout << "Position " << i << ", "
	     << "Error 3: I want end of line!\n";
	return false;
  _end:
	return true;
}

// Функция запускающая разбор и определяющая корректность его завершения,
// если первый символ не принадлежит цепочки
bool Parser() {
	// Начальная инициализация.
	erFlag = 0;
	i = 0;

	// Процесс пошел!
	if(Z())
	{
		return true; // Все прошло нормально
	}
	else {
		if(erFlag)
			cout  << "Position " << i << ", "
				<< "Error 4: Internal Error!\n";
		else
			cout  << "Position " << i << ", "
				<< "Error 5: Incorrect first symbol of S!\n";
		return false; // Есть ошибки
	}
}

// Главная функция используется для тестирования до тех пор,
// пока не будет прочитана пустая строка
int main () {
	string strCursor;
	str = "";
	// Цикл распознавания различных входных цепочек
	do {
		// Чтение очередной входной цепочки в буфер
		cout << "Input bracket\'s expression!: ";

		// Формируем очередную строку скобок для распознавания.
		GetOneLine(cin, str);

		// Здесь начинается разбор принятой строки.
		if(Parser())
			cout << "+++++ OK! +++++\n";
		else
			cout << "----- Fatal error (look upper error message)! -----\n";

		// Вывод разобранной строки и значения позиции входой головки.
		cout << "Line: " << str;
		strCursor = " Pos: " + string(i, '-');
		strCursor +='^';
		cout << strCursor << "  i = " << i << "\n\n";

	} while(str != "\n");
	cout << "Goodbye!\n";
	return 0;
}
