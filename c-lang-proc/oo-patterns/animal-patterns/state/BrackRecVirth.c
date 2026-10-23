//
// BrackRecVirth.c - рекурсивный распознаватель вложенности круглых скобок.
// Построен на основе диаграмм Вирта, эквивалентных следующей РБНФ
//
// $S = {/ "(" [ S ] ")" /}.
//

#include <stdio.h>
#include <string.h>

char str[256];  // Строка с входной цепочкой, имитирующая входную ленту
// string str; // Строка с входной цепочкой, имитирующая входную ленту
int i;          // Текущее положение входной головки
int erFlag;     // Флаг, фиксирующий наличие ошибок в середине правила

// Функция, реализующая чтение символов в буфер из входного потока.
// Используется для ввода с клавиатуры распознаваемой строки.
// Ввод осуществляется до нажатия на клавишу Enter.
// Символ '\n' является концевым маркером входной строки.
void GetOneLine(FILE *is, char* str) {
  str[0] = '\0';
  // ssize_t n = 256;
  // ssize_t len = getline(&str, &n, is);
  fgets(str, 256, stdin);
}

// Функция, реализующая распознавание нетерминала S.
_Bool S() {
//_0: // Начало диаграммы
  if(str[i] == '(') {
    i++;
    goto _1;
  }
  return 0; // Первый символ цепочки некорректен
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
  printf(
    "Position %d, Error 1: I want closed bracket or next opened bracket!\n", i);
  return 0;
_2: // Точка 2 диаграммы
  if(str[i] == ')') {
    i++;
    goto _3;
  }
  erFlag++;
  printf("Position %d, Error 2: I want closed bracket!\n", i);
  return 0;
_3: // Точка 3 диаграммы
  if(str[i] == '(') {
    i++;
    goto _1;
  }
  goto _end;
_end: // Точка end диаграммы
  return 1;
}

// Функция, реализующая распознавание нетерминала Z.
_Bool Z() {
//_0: // Начало диаграммы
  if(S()) goto _1;
  return 0; // Первый символ цепочки некорректен
            // что это ошибка, лучше определить снаружи
_1: // Точка 1 диаграммы
    // За последней скобкой должен быть "конец строки"
  if(str[i] == '\n') {
    goto _end; // Все прошло нормально
  }
  erFlag++;
  printf("Position %d, Error 3: I want end of line!\n", i);
  return 0;
_end:
  return 1;
}

// Функция запускающая разбор и определяющая корректность его завершения,
// если первый символ не принадлежит цепочки
_Bool Parser() {
  // Начальная инициализация.
  erFlag = 0;
  i = 0;

  // Процесс пошел!
  if(Z()) {
    return 1; // Все прошло нормально
  } else {
    if(erFlag) {
      printf("Position %d , Error 4: Internal Error!\n", i);
    } else {
      printf("Position %d, Error 5: Incorrect first symbol of S!\n", i);
    }
    return 0; // Есть ошибки
  }
}

// Главная функция используется для тестирования до тех пор,
// пока не будет прочитана пустая строка
int main () {
  char strCursor[256];
  str[0] = '\0';
  // Цикл распознавания различных входных цепочек
  // do {
  // while(str[0] != '\n') {
  while(1) {
    // Чтение очередной входной цепочки в буфер
    printf("Input bracket\'s expression!: ");

    // Формируем очередную строку скобок для распознавания.
    GetOneLine(stdin, str);
    if(str[0] == '\n') {
      break;
    }

    // Здесь начинается разбор принятой строки.
    if(Parser()) {
      printf("+++++ OK! +++++\n");
    } else {
      printf("----- Fatal error (look upper error message)! -----\n");
    }

    // Вывод разобранной строки и значения позиции входой головки.
    printf("Line: %s", str);

    // strCursor = " Pos: " + string(i, '-');
    // strCursor +='^';
    // cout << strCursor << "  i = " << i << "\n\n";
    printf(" Pos: ");
    for(int j = 0; j < i; ++j) {
      printf("%c", '-');
    }
    printf("^  i = %d\n\n", i);

  }
  // } while(str[0] != '\n');
  printf("Goodbye!\n");
  return 0;
}

