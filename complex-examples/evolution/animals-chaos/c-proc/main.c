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
  AnyAnimal ae = {elephant, .elephant=&e};
  AnyAnimal ad = {dog,      .dog=&d};
  AnyAnimal ap = {penguin,  .penguin=&p};
  AnyAnimal aw = {worm,     .worm=&w};

  Moving(&ae);
  Moving(&ad);
  Moving(&ap);
  Moving(&aw);

  printf("--- Использование специализаций через обобщенный указатель ---\n");
  AnyAnimal* any;
  any =  &ae;
  Moving(any);
  any =  &ad;
  Moving(any);
  any =  &ap;
  Moving(any);
  any =  &aw;
  Moving(any);

  printf("\n==== Использование группы пловцов ====\n");
  printf("--- Прямое использование специализаций ---\n");
  SwimmingAnimal sp = {penguin, .penguin=&p};
  Swimming(&sp);

  printf("--- Использование специализаций через обобщенный указатель ---\n");
  SwimmingAnimal* swimmer;
  swimmer =  &sp;
  Swimming(swimmer);

  printf("\n==== Использование группы говорунов ====\n");
  printf("--- Прямое использование специализаций ---\n");
  SpeakingAnimal spe = {elephant, .elephant=&e};
  Speaking(&spe);
  SpeakingAnimal spd = {dog,      .dog=&d};
  Speaking(&spd);
  SpeakingAnimal spp = {penguin,  .penguin=&p};
  Speaking(&spp);

  printf("--- Использование специализаций через обобщенный указатель ---\n");
  SpeakingAnimal* speaker;
  speaker =  &spe;
  Speaking(speaker);
  speaker =  &spd;
  Speaking(speaker);
  speaker =  &spp;
  Speaking(speaker);

  return 0;
}
