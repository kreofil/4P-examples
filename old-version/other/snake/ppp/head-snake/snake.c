// Для компиляции программы введите ppclang -xc snake.ppc -o snake
// В данном коде хочется реализовать зачальную змейку - головастика,
// состоящую только из одной головы

// Процедурно-параметрический полиморфизм реализован пока только в Linux
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>

//------------------------------------------------------------------------------
// Настройка ввода-вывода на непосредственную обработку клавиш

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

//------------------------------------------------------------------------------
// Описание данных, используемых в программе

// snake_size - размер змейки.

// coordinates_x[1000], coordinates_y[1000] - массивы, хранящие координаты
//                                            частей тела змейки.

// Kоординаты головы змейки хранятся в coordinates_x[1], coordinates_y[1].
// food_x, food_y - координаты еды.

int snake_size, coordinates_x[1000], coordinates_y[1000];
int food_x = -1, food_y = -1;

// Константы:
// N - размер таблицы, а именно высота.
// M - ширина таблицы.
// INTERVAL - интервал в миллисекундах, через каждый этот промежуток
//            времени змейка будет передвигаться.
///const int N = 13, M = 17, INTERVAL = 200;
const int INTERVAL = 350;
#define N 13
#define M 17
// a[1000][1000] - наша таблица (игровое поле), в которой происходит вся игра.
char a[N+2][M+2];

//------------------------------------------------------------------------------
// Обобщение собирающее воедино события по управлению движением
typedef struct Direction{}<> Direction;
Direction + <Left: void;>;     // Движение влево
Direction + <Right: void;>;    // Движение вправо
Direction + <Up: void;>;       // Движение вверх
Direction + <Down: void;>;     // Движение вниз

//------------------------------------------------------------------------------
// Направление движения тоже можно реализовать, используя Direction
Direction direction;

//------------------------------------------------------------------------------
// Для более удобного задания нового направления можно использовать оболочки
void SetLeftDirection(Direction* d) { // Задать направление влево
  // эта функция как-то влияет на ввод данных.
  init_spec(Direction.Left, d);
}
void SetRightDirection(Direction* d) { // Задать направление вправо
  init_spec(Direction.Right, d);
}
void SetUpDirection(Direction* d) { // Задать направление вверх
  init_spec(Direction.Up, d);
}
void SetDownDirection(Direction* d) { // Задать направление вниз
  init_spec(Direction.Down, d);
}

//------------------------------------------------------------------------------
// Обобщение, используемое для анализа нажатой клавиши, после чего
// формируется соответствующее действие, связанное в направлением движения
// или другими функциями программы
typedef struct Key{}<> Key; // Прерывание работы программы
Key + <Left: void;>;     // Движение влево
Key + <Right: void;>;    // Движение вправо
Key + <Up: void;>;       // Движение вверх
Key + <Down: void;>;     // Движение вниз

//------------------------------------------------------------------------------
// Функции, осуществляющие анализ нажатия клавиш и выбор направления движения

// Обобщающая функция, реализующая прерывание игры
_Bool KeyReaction<Key* k>(char symbol) {
  if(symbol=='q') {
    printf("\r\x1b[1;35mQuit\x1b[0m\n");
    nonblock(NB_DISABLE); exit(0);
  }
  return 0;
}
// Перемещение влево
_Bool KeyReaction<Key.Left* k>(char symbol) {
  if(symbol=='h') {
    struct Direction.Right rd;   // Запретное движение вправо
    if(spec_index_cmp(&direction, &rd) == -1) { // Не в противоположную сторону
      SetLeftDirection(&direction);
    }
    return 1;
  }
  return 0;
}
// Перемещение вправо
_Bool KeyReaction<Key.Right* k>(char symbol) {
  if(symbol=='l') {
    struct Direction.Left ld;   // Запретное движение влево
    if(spec_index_cmp(&ld, &direction) == -1) { // Не в противоположную сторону
      SetRightDirection(&direction);
    }
    return 1;
  }
  return 0;
}
// Перемещение вверх
_Bool KeyReaction<Key.Up* k>(char symbol) {
  if(symbol=='k') {
    struct Direction.Down dd;   // Запретное движение вниз
    if(spec_index_cmp(&dd, &direction) == -1) { // Не в противоположную сторону
      SetUpDirection(&direction);
    }
    return 1;
  }
  return 0;
}
// Перемещение вниз
_Bool KeyReaction<Key.Down* k>(char symbol) {
  if(symbol=='j') {
    struct Direction.Up ud;   // Запретное движение вверх
    if(spec_index_cmp(&ud, &direction) == -1) { // Не в противоположную сторону
      SetDownDirection(&direction);
    }
    return 1;
  }
  return 0;
}

// функция, считывающая нажатую клавишу.
void change_direction() {
  // Cчитываем нажатую клавишу с помощью функции getch().
  char symbol = getch();
  int userActionSize = get_spec_size(Direction);
  for(int i = 0; i < userActionSize; i++) {
    Key* pKey = get_spec_ptr(Key, i);
    // Полиморфное изменение направления в зависимости от символа
    if(KeyReaction<pKey>(symbol)) {break;};
  }
}

// функция для вывода таблицы
void show_table() {
  // Очищаем консоль.
  system("clear");
  // Выводим таблицу и края.
  for (int i = 0; i <= N + 1; ++i) {
    for (int j = 0; j <= M + 1; ++j) {
      printf("\x1b[1;32;47m%c\x1b[0m%s",
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
//   for (int i = 1; i <= snake_size; ++i)
//     a[coordinates_x[i]][coordinates_y[i]] = ' ';
  // Почему бы не очистить только последнюю координату?
  a[coordinates_x[snake_size]][coordinates_y[snake_size]] = ' ';
}

//------------------------------------------------------------------------------
// Полиморфные функции,определяющие вариант для рисования головы
void DirectionHead<Direction* d>() = 0;
void DirectionHead<Direction.Left* d>() {
  a[coordinates_x[1]][coordinates_y[1]] = '<';
}
void DirectionHead<Direction.Right* d>() {
  a[coordinates_x[1]][coordinates_y[1]] = '>';
}
void DirectionHead<Direction.Up* d>() {
  a[coordinates_x[1]][coordinates_y[1]] = '^';
}
void DirectionHead<Direction.Down* d>() {
  a[coordinates_x[1]][coordinates_y[1]] = 'v';
}

// Красим координаты змейки.
void show_snake_on_table() {
  // Изменяем тип головы.
  DirectionHead<&direction>();


  // Красим змейку.
  // Почему бы не покрасить только вторую ячейку? Остальные уже покрашены...
  if(snake_size > 1) {
    a[coordinates_x[2]][coordinates_y[2]] = '@';
  }
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

// Формирование новых координат головы змейки
// с использованием полиморфизма
void NextHeadCoord<Direction* d>() {};
void NextHeadCoord<Direction.Left* d>() {
  --coordinates_y[1];
}
void NextHeadCoord<Direction.Right* d>() {
  ++coordinates_y[1];
}
void NextHeadCoord<Direction.Up* d>() {
  --coordinates_x[1];
}
void NextHeadCoord<Direction.Down* d>() {
  ++coordinates_x[1];
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
  NextHeadCoord<&direction>();

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
    printf("\x1b[1;34m\rYou're looser!\x1b[0m\n\n");
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
  // snake_size = 2;
  // Размер змеи - 1.
  snake_size = 1;

  // Змейка занимает две клетки вправо от координаты {1,1}.
  coordinates_x[1] = 1;
  coordinates_y[1] = 2;
  // coordinates_x[2] = 1;
  // coordinates_y[2] = 1;

  // Змейка движется вправо.
  SetRightDirection(&direction);
}

int main() {
  // Задаем стандартные настройки.
  standart_settings();

  memset(a, ' ', sizeof(a));
  nonblock(NB_ENABLE);
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
  }
}
