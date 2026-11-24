//==============================================================================
// Простейшая ОО программа, осуществляющая чтение строки цифр во внутренний
// буфер, из которого эти символы выводятся в столбик
//==============================================================================

#include <stdio.h>
#include <string.h>

#define MAX_STR_SIZE 256    // размер буфера строки

//------------------------------------------------------------------------------
// Интерфейст читателя цифр. Включает вспомогательные данные и функции
// помимо переопределяемой далее функции чтения строки.
class IReader {
protected:
  char* buf;
public:
  IReader(char* b): buf{b} { b[0] = '\0'; }
  char* getBuf() {
    return buf;
  }
  virtual void readDigStr() = 0;
};

//------------------------------------------------------------------------------
// Читатель строки, допускающий на выходе любые символы, а не только цифры
class BadReader: public IReader {
public:
  BadReader(char* b): IReader{b} {}
  void readDigStr() {
    fgets(buf, MAX_STR_SIZE, stdin);
    buf[strlen(buf) - 1] = '\0';    // убрали `\n`
    printf("Bad reader string = %s\n", buf);
  }
};

//------------------------------------------------------------------------------
// Читатель, оставляющий после прочтения только цифры
class DigReader: public IReader {
public:
  DigReader(char* b): IReader{b} {}
  void readDigStr() {
    fgets(buf, MAX_STR_SIZE, stdin);
    // Оставление только цифровых символов
    int len = strlen(buf);
    int j = 0;
    for(int i = 0; i < len; ++i) {
      if((buf[i] >= '0') && (buf[i] <= '9')) {
        buf[j++] = buf[i]; // Пропуск цифры
      }
    }
    buf[j] = '\0';    // конец цифровой строки
    printf("%s\n", buf);
  }
};

//------------------------------------------------------------------------------
// Интерфейс принтеров, обрабатывающих цифры
class IPrinter {
protected:
  IReader* reader;
public:
  IPrinter(IReader* r): reader{r} {}
  virtual void outDigits() = 0;
};


//------------------------------------------------------------------------------
// Принтер, печатающий цифры как есть
class DigPrinter: public IPrinter {
public:
  DigPrinter(IReader* r): IPrinter{r} {}
  void outDigits() {
    char* buf = reader->getBuf();
    int len = strlen(buf);
    for(int i = 0; i < len; ++i) {
      putchar(buf[i]);
      putchar('\n');
    }
  }
};

//------------------------------------------------------------------------------
// Принтер, печатающий цифры и их названия
class WordPrinter: public IPrinter {
  static const char* wd[];
public:
  WordPrinter(IReader* r): IPrinter{r} {}
  void outDigits() {
    char* buf = reader->getBuf();
    int len = strlen(buf);
    for(int i = 0; i < len; ++i) {
      printf("%c: %s\n", buf[i], wd[buf[i]-'0']);
    }
  }
};
// Массив названий, используемый для печати после сопоставления с цифрами
const char* WordPrinter::wd[] = {
  "zero", "one", "two", "three", "four",
  "five", "six", "seven", "eight", "nine"
};

//------------------------------------------------------------------------------
// Тестовая функция демонстрирующая взаимодействие читателей строк и
// принтеров через абстрактные интерфейсы
int main() {
  // Буфер, используемый для строки
  char buf[MAX_STR_SIZE];

  // Абстрактные интерфейсы для подключения читателей строки и принтеров
  IReader* ir;
  IPrinter* ip;

  // Использования читателя, оставляющего в строке только цифры
  DigReader dr(buf);
  ir = &dr;
  printf("Input string for the good reader: ");
  ir->readDigStr();

  DigPrinter dp(ir);
  ip = &dp;
  ip->outDigits();

  WordPrinter wp(ir);
  ip = &wp;
  ip->outDigits();

  // Демонстрация плохого читателя, пропускающего не цифры
  BadReader br(buf);
  ir = &br;
  printf("Input string for the bad reader: ");
  ir->readDigStr();

  ip = &dp;
  ip->outDigits();

  // Может упасть, если во водимой строке будут не только цифры
  ip = &wp;
  ip->outDigits();

  return 0;
}

