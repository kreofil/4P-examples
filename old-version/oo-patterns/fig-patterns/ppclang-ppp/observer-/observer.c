#include <stdio.h>

typedef struct Observer Observer; // Предварительное описание наблюдателя

#define MAXOBSERVERS 10   // Максимальное число подключаемых наблюдателей

typedef struct Subject {  // Обобщенный субъект
  Observer* views[MAXOBSERVERS];   // Массив доступных наблюдателей
  int len;                // количество подключенных наблюдателей
  int value;              // некоторое значение
}<> Subject;

// Инициализация субъекта
void InitSubject(Subject *subject) {
  subject->len = 0;
  subject->value = 0;
}

// Добавление наблюдателя
_Bool AttachView(Subject *subject, Observer *observer) {
  if(len < MAXOBSERVERS) {
    subject->views[++len] = observer;
    return 1;
  } else {
    perror("Array of observes full!!\n")
    return 0;
  }
}

// Формирование значения и уведомление наблюдателей об изменении
void setSubjectVal(Subject *subject, int val) {
  subject->value = val;
  Notify(subject);
}

// Предоставление субъектом значения
int GetValue(Subject *subject) {
  return subject->value;
}

// Уведомление видов об изменении субъекта
void Notify(Subject *subject) {
  for(size_t i = 0; i < subject->len; ++i) {

  }
}

typedef struct Observer { // Обобщенный наблюдатель
  Subject *model;         // Модель, предоставляющая делимое
  int denom;              // Делитель
}<> Observer;

// Инициализация наблюдателя и связь с его с субъектом
void InitObserver(Observer *view, Subject *mod, int div) {
  view->model = mod;
  view->denom = div;
  view->model->attach(this); // Наблюдатель связывается с субъектом}
}

// Обновление информации, путем обращения к субъекту
void Update<Observer *observer>() = 0;



  protected:
    Subject *getSubject() {
        return model;
    }
    int getDivisor() {
        return denom;
    }
};

void Subject::notify() {
  // 5. Publisher broadcasts
  for (int i = 0; i < views.size(); i++)
    views[i]->update();
}

class DivObserver: public Observer {
  public:
    DivObserver(Subject *mod, int div): Observer(mod, div){}
    void update() {
        // 6. "Pull" information of interest
        int v = getSubject()->getVal(), d = getDivisor();
        cout << v << " div " << d << " is " << v / d << '\n';
    }
};

class ModObserver: public Observer {
  public:
    ModObserver(Subject *mod, int div): Observer(mod, div){}
    void update() {
        int v = getSubject()->getVal(), d = getDivisor();
        cout << v << " mod " << d << " is " << v % d << '\n';
    }
};

int main() {
  Subject subj;
  DivObserver divObs1(&subj, 4); // 7. Client configures the number and
  DivObserver divObs2(&subj, 3); //    type of Observers
  ModObserver modObs3(&subj, 3);
  subj.setVal(14);
  subj.setVal(15);
  subj.setVal(10);
}
