// Пример диспетчеризации с двумя аргументами и двумя альтернативами

// Примечание. Количество альтернатив на производительность ОО диспетчеризации
// не должно влиять, так как обращение к виртуальным методам осуществляется одинаково

// Основа для первого элемента
typedef struct d0 {} d0;
// Основа для второго элемента
typedef struct d1 {} d1;
// Обобщение
typedef struct g {
    int key;
    union {
        d0 x0;
        d1 x1;
    };
} g;

// Экземпляр g.
g x0 = {.key = 0};
g x1 = {.key = 1};

void mm(g* x0, g* x1) {
    switch(x0->key) {
        case 0:
            switch(x1->key) {
                case 0:
                    break;
                case 1:
                    break;
                default:
                    break;
            }
        case 1:
            switch(x1->key) {
                case 0:
                    break;
                case 1:
                    break;
                default:
                    break;
            }
        default:
            break;
    }
}


// Это для проверки работоспособности. На самом деле может замениться на вызов из теста
int main() {
    mm(&x0, &x0);
    mm(&x0, &x1);
    mm(&x1, &x0);
    mm(&x1, &x1);
    return 0;
}
