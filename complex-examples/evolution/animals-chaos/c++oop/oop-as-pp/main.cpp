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
  ElephantAsAnimal ae{&e};
  DogAsAnimal ad{&d};
  PenguinAsAnimal ap{&p};
  WormAsAnimal aw{&w};

  ae.Moving();
  ad.Moving();
  ap.Moving();
  aw.Moving();

  printf("--- Использование специализаций через обобщенный указатель ---\n");
  AnyAnimal* any;
  any =  &ae;
  any->Moving();
  any =  &ad;
  any->Moving();
  any =  &ap;
  any->Moving();
  any =  &aw;
  any->Moving();

  printf("\n==== Использование группы пловцов ====\n");
  printf("--- Прямое использование специализаций ---\n");
  PenguinAsSwimmingAnimal sp{&p};
  sp.Swimming();

  printf("--- Использование специализаций через обобщенный указатель ---\n");
  SwimmingAnimal* swimmer;
  swimmer =  &sp;
  swimmer->Swimming();

  printf("\n==== Использование группы говорунов ====\n");
  printf("--- Прямое использование специализаций ---\n");
  ElephantAsSpeakingAnimal spe{&e};
  spe.Speaking();
  DogAsSpeakingAnimal spd{&d};
  spd.Speaking();
  PenguinAsSpeakingAnimal spp{&p};
  spp.Speaking();

  printf("--- Использование специализаций через обобщенный указатель ---\n");
  SpeakingAnimal* speaker;
  speaker =  &spe;
  speaker->Speaking();
  speaker =  &spd;
  speaker->Speaking();
  speaker =  &spp;
  speaker->Speaking();

  return 0;
}
