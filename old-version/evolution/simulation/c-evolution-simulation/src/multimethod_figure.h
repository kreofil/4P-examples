#ifndef _multimethod_figure_h_
#define _multimethod_figure_h_
//------------------------------------------------------------------------------
// Мультиметод, осуществляющий анализ различных комбинаций
// Геометрических фигур
//------------------------------------------------------------------------------
#include "figure.h"

// Одномерный параметрический массив, формируемый для указателей на
// обработчики специализаций. Создается в динамической памяти
// после регистрации всех специализаций.
typedef void (*multimethod_figure_pointer)(figure* p_f1, figure* p_f2);
// Обобщающая функция, осуществляющая обращение к массиву указателей
// на обработчики специализаций
void multimethod_figure(figure* p_f1, figure* p_f2);
// Регистрация обработчика специализации в массиве обработчиков
void _multimethod_figure_spec_register(unsigned (*get_spec_tag1)(),
                                       unsigned (*get_spec_tag2)(),
                                 multimethod_figure_pointer spec);
#endif // _multimethod_figure_h_
