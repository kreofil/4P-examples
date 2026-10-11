//
// BrackRecVirth.c - рекурсивный распознаватель вложенности круглых скобок.
// Построен на основе диаграмм Вирта, эквивалентных следующей РБНФ
//
// $S = {/ "(" [ S ] ")" /}.
//
// Используется булевский фиксатор для выхода из цикла,
// а также состояния ошибки и успешного завершения.
// Обобщенное состояние используется в качестве начального.


#include <stdio.h>
#include <string.h>


_Bool S();
_Bool Z();

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
  // size_t n = 256;
  // ssize_t len = getline(&str, &n, is);
  fgets(str, 256, stdin);
}

//==============================================================================
// Описание автомата S, распознающего вложенность скобок
//==============================================================================

//------------------------------------------------------------------------------
// Обобщение, определяющее состояния автомата S
typedef struct StateS{}<S1, S2, S3, True, False: void;>StateS;

//------------------------------------------------------------------------------
// Обобщенная функция и обработчики, реализующие состояния автомата S

// Обобщенная функция реализует начальное состояние
_Bool CalcStateS<StateS* state>() {
//_0: // Начало диаграммы
  if(str[i] == '(') {
    i++;
    init_spec(StateS.S1, state);
    return 1;
  }
  init_spec(StateS.False, state);
  return 0; // Первый символ цепочки некорректен
            // что это ошибка, лучше определить снаружи
};

_Bool CalcStateS<StateS.S1* state>() {
// _1: // Точка 1 диаграммы
  if(str[i] == ')') {
    i++;
    init_spec(StateS.S3, state);
    return 1;
  }
  if(S()) {
    init_spec(StateS.S2, state);
    return 1;
  }
  erFlag++;
  printf(
    "Position %d, Error 1: I want closed bracket or next opened bracket!\n", i);
  init_spec(StateS.False, state);
  return 0;
}

_Bool CalcStateS<StateS.S2* state>() {
// _2: // Точка 2 диаграммы
  if(str[i] == ')') {
    i++;
    init_spec(StateS.S3, state);
    return 1;
  }
  erFlag++;
  printf("Position %d, Error 2: I want to close bracket!\n", i);
  init_spec(StateS.False, state);
  return 0;
}

_Bool CalcStateS<StateS.S3* state>() {
// _3: // Точка 3 диаграммы
  if(str[i] == '(') {
    i++;
    init_spec(StateS.S1, state);
    return 1;
  }
  init_spec(StateS.True, state);
  return 0;
}

_Bool CalcStateS<StateS.False* state>() {
  return 0;
}

_Bool CalcStateS<StateS.True* state>() {
  return 1;
}

//------------------------------------------------------------------------------
// Автомат, реализующий распознавание нетерминала S.
_Bool S() {
  struct StateS state;
  while(CalcStateS<&state>());
  return CalcStateS<&state>();
}

//==============================================================================
// Описание автомата Z, запускающий распознаватель
//==============================================================================


//------------------------------------------------------------------------------
// Обобщение, определяющее состояния автомата Z
typedef struct StateZ{}<S1, True, False: void;>StateZ;

//------------------------------------------------------------------------------
// Обобщенная функция и обработчики, реализующие состояния автомата Z

_Bool CalcStateZ<StateZ* state>() {
//_0: // Начало диаграммы
  if(S()) {
    init_spec(StateZ.S1, state);
    return 1;
  }
  init_spec(StateZ.False, state);
  return 0; // Первый символ цепочки некорректен
            // что это ошибка, лучше определить снаружи
};

_Bool CalcStateZ<StateZ.S1* state>() {
// _1: // Точка 1 диаграммы
    // За последней скобкой должен быть "конец строки"
  if(str[i] == '\n') {
    init_spec(StateZ.True, state);
    return 0;
  }
  erFlag++;
  printf("Position %d, Error 3: I want end of line!\n", i);
  init_spec(StateZ.False, state);
  return 0;
}

_Bool CalcStateZ<StateZ.False* state>() {
  return 0;
}

_Bool CalcStateZ<StateZ.True* state>() {
  return 1;
}

//------------------------------------------------------------------------------
// Автомат, реализующий распознавание нетерминала Z.
_Bool Z() {
  struct StateZ state;
  while(CalcStateZ<&state>());
  return CalcStateZ<&state>();
}

// Функция, реализующая распознавание нетерминала Z.
_Bool oldZ() {
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

