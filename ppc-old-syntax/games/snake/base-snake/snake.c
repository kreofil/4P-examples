// Для компиляции программы введите ppclang -xc snake.c -o snake

//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#ifdef WINDOWS
// Библиотека, нужна для использования функции Sleep().
#include <windows.h>
// Библиотека, нужна для использования функций kbhit() и getch().
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>

#define STDIN_FILENO 0
#define NB_DISABLE 0
#define NB_ENABLE 1

#define Sleep(x) usleep(x*1000)
unsigned int usleep (unsigned int __seconds);

int kbhit() {
  struct timeval tv;
  fd_set fds;
  tv.tv_sec = 0;
  tv.tv_usec = 0;
  FD_ZERO(&fds);
  FD_SET(STDIN_FILENO, &fds);
  select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
  return FD_ISSET(STDIN_FILENO, &fds);
}

void nonblock(int state) {
  struct termios ttystate;

  // Get the terminal state.
  tcgetattr(STDIN_FILENO, &ttystate);

  if (state == NB_ENABLE) {
    // Turn off canonical mode.
    ttystate.c_lflag &= ~ICANON;
    // Minimum of number input read.
    ttystate.c_cc[VMIN] = 1;
  } else if (state == NB_DISABLE) {
    // Turn on canonical mode.
    ttystate.c_lflag |= ICANON;
  }
  // Set the terminal attributes.
  tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}

int getch() {
  return fgetc(stdin);
}

#endif

// snake_size - размер змейки.
// change_x, change_y - в какую сторону движется змейка.
// coordinates_x[1000], coordinates_y[1000] - массивы, хранящие координаты
//                                            частей тела змейки.
// Kоординаты головы змейки хранятся в coordinates_x[1], coordinates_y[1].
// food_x, food_y - координаты еды.

int snake_size, change_x, change_y, coordinates_x[1000], coordinates_y[1000];
int food_x = -1, food_y = -1;

// a[1000][1000] - наша таблица, в которой происходит вся игра.
char a[1000][1000];

// Константы:
// N - размер таблицы, а именно высота.
// M - ширина таблицы.
// INTERVAL - интервал в миллисекундах, через каждый этот промежуток
//            времени змейка будет передвигаться.
///const int N = 13, M = 17, INTERVAL = 200;
const int N = 13, M = 17, INTERVAL = 350;

//------------------------------------------------------------------------------
// Начало фрагмента процедурно-параметрической обработки нажатия клавиш,
// управляющих перемещением змейки
//------------------------------------------------------------------------------

// Обобщение собирающее воедино события по управлению движением
typedef struct UserAction{}<> UserAction;
UserAction + <Left: void;>;     // Движение влево
UserAction + <Right: void;>;    // Движение вправо
UserAction + <Up: void;>;       // Движение вверх
UserAction + <Down: void;>;     // Движение вниз

// Обобщающая функция, реализующая прерывание игры
_Bool ChangeDirection<UserAction* action>(char symbol) {
  if(symbol=='q') {
    printf("\rQuit \n");
    nonblock(NB_DISABLE); exit(0);
  }
  return 0;
}
// Перемещение влево
_Bool ChangeDirection<UserAction.Left* action>(char symbol) {
  if(symbol=='h') {
    if (change_x != 0 || change_y != 1) { // left
      change_x = 0; change_y = -1;
    }
    return 1;
  }
  return 0;
}
// Перемещение вправо
_Bool ChangeDirection<UserAction.Right* action>(char symbol) {
  if(symbol=='l') {
    if (change_x != 0 || change_y != -1) { // right
      change_x = 0; change_y = 1;
    }
    return 1;
  }
  return 0;
}
// Перемещение вверх
_Bool ChangeDirection<UserAction.Up* action>(char symbol) {
  if(symbol=='k') {
    if (change_x != 1 || change_y != 0) { // up
      change_x = -1; change_y = 0;
    }
    return 1;
  }
  return 0;
}
// Перемещение вниз
_Bool ChangeDirection<UserAction.Down* action>(char symbol) {
  if(symbol=='j') {
    if (change_x != -1 || change_y != 0) { // down
      change_x = 1; change_y = 0;
    }
    return 1;
  }
  return 0;
}

// функция, считывающая нажатую клавишу.
void change_direction() {
  // Cчитываем нажатую клавишу с помощью функции getch().
  char symbol = getch();
  int userActionSize = get_spec_size(UserAction);
  for(int i = 0; i <= userActionSize; i++) {
    UserAction* pAction = get_spec_ptr(UserAction, i);
    // Полиморфное изменение направления в зависимости от символа
    if(ChangeDirection<pAction>(symbol)) {break;};
  }
}

//------------------------------------------------------------------------------
// Завершение фрагмента процедурно-параметрической обработки нажатия клавиш,
// управляющих перемещением змейки
//------------------------------------------------------------------------------


// функция для вывода таблицы
void show_table() {
  // Очищаем консоль.
#ifdef WINDOWS
  system("cls");
#else
  system("clear");
#endif

  // Выводим таблицу и края.
  for (int i = 0; i <= N + 1; ++i) {
    for (int j = 0; j <= M + 1; ++j) {
      printf("\x1b[1;32m%c\x1b[0m%s",
        (i == 0 || j == 0 || i == N + 1 || j == M + 1 ?
        '#' : a[i][j]),
        (j <= M ? "" : "\n")
      );
    }
  }
  printf("\x1b[1;33m%d\x1b[0m\n", snake_size);
}

// Очищаем координаты, в которых располагалась змейка.
void clear_snake_on_table() {
  for (int i = 1; i <= snake_size; ++i)
    a[coordinates_x[i]][coordinates_y[i]] = ' ';
}

// Красим координаты змейки.
void show_snake_on_table() {
  // Изменяем тип головы.
  if (change_x == 1 && change_y == 0)
    a[coordinates_x[1]][coordinates_y[1]] = 'v';
  if (change_x == -1 && change_y == 0)
    a[coordinates_x[1]][coordinates_y[1]] = '^';
  if (change_x == 0 && change_y == 1)
    a[coordinates_x[1]][coordinates_y[1]] = '>';
  if (change_x == 0 && change_y == -1)
    a[coordinates_x[1]][coordinates_y[1]] = '<';

  // Красим змейку.
  for (int i = 2; i <= snake_size; ++i)
    a[coordinates_x[i]][coordinates_y[i]] = '@';
}

// Проверяем, съела ли змейка саму себя.
_Bool game_over() {
  for (int i = 2; i <= snake_size; ++i)
    // Eсли координаты головы змейки равны координате какой-либо части тела
    // змейки, то змейка съела саму себя.
    if (coordinates_x[1] == coordinates_x[i] &&
        coordinates_y[1] == coordinates_y[i])
      return 1;
  // Если все координаты различны, то все в порядке - играем дальше.
  return 0;
}

// Проверяем, не вышла ли змейка за поле, если да то возвращаем ее обратно.
void check_coordinates() {
  if (coordinates_x[1] > N) coordinates_x[1] = 1;
  if (coordinates_x[1] < 1) coordinates_x[1] = N;
  if (coordinates_y[1] > M) coordinates_y[1] = 1;
  if (coordinates_y[1] < 1) coordinates_y[1] = M;
}

// функция следующего хода, в которой наша змейка сдвигается в сторону
// на 1 ячейку.
void next_step() {
  // Чистим таблицу от змейки.
  clear_snake_on_table();

  // Передвигаем тело змейки.
  for (int i = snake_size; i >= 2; --i) {
    coordinates_x[i] = coordinates_x[i - 1];
    coordinates_y[i] = coordinates_y[i - 1];
  }

  // Передвигаем голову змейки.
  coordinates_x[1] += change_x;
  coordinates_y[1] += change_y;

  // Проверяем в порядке ли координаты.
  check_coordinates();

  // Если голова змейки там же где и еда, то увеличиваем размер змейки
  // и очищаем координаты змейки.
  if (coordinates_x[1] == food_x && coordinates_y[1] == food_y) {
    snake_size++;
    food_x = -1;
    food_y = -1;
  }

  // Рисуем змейку.
  show_snake_on_table();

  // Если змея укусила себя.
  if (game_over()) {
    // Cообщаем всю правду о игроке.
    printf("You're looser! \n");
    // Приостанавливаем игру.
#ifdef WINDOWS
    system("pause");
#endif
    // Завершаем программу.
    exit(0);
  }
}

// функция проверки на наличие еды на карте.
_Bool food_check() {
  // Если координаты еды неопределенны, то возвращаем true.
  if (food_x == -1 && food_y == -1) return 0;
  // В остальных случаях false.
  return 1;
}

// функция добавления еды на карту.
void place_food() {
  ///std::srand(std::time(NULL));
  srand(time(NULL));
  // Cтавим в рандомное место еду.
  for (int i = 1; i <= 9; ++i) {
    int x = rand();
    int y = rand();
    if (x < 0) x *= -1;
    if (y < 0) y *= -1;
    x %= (N + 1);
    y %= (M + 1);
    if (x == 0) ++x;
    if (y == 0) ++y;
    if (a[x][y] != '@' && a[x][y] != 'v' && a[x][y] != '^' &&
        a[x][y] != '<' && a[x][y] != '>') {
      food_x = x;
      food_y = y;
      a[x][y] = '+';
      return;
    }
  }
}

// Начальные установки.
void standart_settings() {
  // Размер змеи - 2.
  snake_size = 2;

  // Змейка занимает две клетки вправо от координаты {1,1}.
  coordinates_x[1] = 1;
  coordinates_y[1] = 2;
  coordinates_x[2] = 1;
  coordinates_y[2] = 1;

  // Змейка движется вправо.
  change_x = 0;
  change_y = 1;
}

int main() {
  // Задаем стандартные настройки.
  standart_settings();

#ifndef WINDOWS
  memset(a, ' ', sizeof(a));
  nonblock(NB_ENABLE);
#endif

  // Бесконечный цикл.
  while (1) {
    // Если нажата клавиша, обрабатываем нажатую клавишу.
    if (kbhit() != 0)
     change_direction();

    // Двигаем змейку.
    next_step();

    // Если нет еды, то ставим ее.
    if (!food_check())
      place_food();

    // Рисуем змейку.
    show_table();

    // "Усыпляем" программу на заданный интервал.
    Sleep(INTERVAL);
    // usleep(INTERVAL*1000);
  }
}
