//==============================================================================
// main.c - содержит главную функцию,
// обеспечивающую простое тестирование
//==============================================================================

#include <stdio.h>
#include "animals.h"

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
  Elephant  e;
  Dog       d;
  Penguin   p;
  Worm      w;

  printf("==== Использование общей группы животных ====\n");

  printf("--- Прямое использование специализаций ---\n");
  e.Moving();
  d.Moving();
  p.Moving();
  w.Moving();

  printf("--- Использование специализаций через обобщенный указатель ---\n");
  AnyAnimal* any;
  any =  &e;
  any->Moving();
  any =  &d;
  any->Moving();
  any =  &p;
  any->Moving();
  any =  &w;
  any->Moving();

  printf("\n==== Использование группы пловцов ====\n");
  printf("--- Прямое использование специализаций ---\n");
  p.Swimming();

  printf("--- Использование специализаций через обобщенный указатель ---\n");
  SwimmingAnimal* swimmer;
  swimmer =  &p;
  swimmer->Swimming();

  printf("\n==== Использование группы говорунов ====\n");
  printf("--- Прямое использование специализаций ---\n");
  e.Speaking();
  d.Speaking();
  p.Speaking();

  printf("--- Использование специализаций через обобщенный указатель ---\n");
  SpeakingAnimal* speaker;
  speaker =  &e;
  speaker->Speaking();
  speaker =  &d;
  speaker->Speaking();
  speaker =  &p;
  speaker->Speaking();

  return 0;
}
