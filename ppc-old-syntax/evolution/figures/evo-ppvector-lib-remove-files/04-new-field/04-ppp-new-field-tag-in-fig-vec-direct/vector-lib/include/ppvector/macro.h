#ifndef __ppvector_macro__
#define __ppvector_macro__
// macro.h
// Заголовочный файл, обеспечивающий полный интрефейс к возможностям
// процедурно-параметрического вектора

//==============================================================================
// Препроцессорные определения, служащие оберткой, расширяющей функциональность.
//==============================================================================

//------------------------------------------------------------------------------
// Макроопределение, используемое для формирования специализации по шаблону
// Скрывает дополнительные манипуляции, связанные с установкой
// внутренних параметров
#define ppVector_VAR(foundation_type, vector_name)      \
struct ppVector.foundation_type vector_name;          \
vector_name.foundation_size = sizeof(vector_name.@);  \
vector_name.foundation_addr = &(vector_name.@);       \
vector_name.size = 0;                                 \
vector_name.capacity = 0;                             \
vector_name.vec_memory = NULL;
// struct ppVector.foundation_type vector_name =
// {sizeof(vector_name.@), &(vector_name.@),0,0};

//------------------------------------------------------------------------------
// Макрос, используемый для занесения значения в хвост вектора.
// Обертывает функцию ppVector_push_back и предварительное присваивание
// пересылаемого значения внутренней переменной
#define ppVector_PUSH_BACK(vector_name, value) \
vector_name.@ = (value); ppVector_push_back((ppVector*)&vector_name);

//------------------------------------------------------------------------------
// Макрос, используемый для чтения элемента из вектора в заданную переменну.
// Обертывает функцию ppVector_index и присваивание внутренней переменной
// указанной внешней переменной
#define ppVector_GET_VAL_INDEX(destination, vector_name, index) \
ppVector_index((ppVector*)&vector_name, (index)); destination = vector_name.@;

//------------------------------------------------------------------------------
// Макрос для занесения первого элемента вектора в указанную переменную
#define ppVector_GET_FRONT_VAL(destination, vector_name) \
ppVector_front((ppVector*)&vector_name); destination = vector_name.@;

//------------------------------------------------------------------------------
// Макрос для занесения последнего элемента вектора в указанную переменную
#define ppVector_GET_BACK_VAL(destination, vector_name) \
ppVector_back((ppVector*)&vector_name); destination = vector_name.@;

#endif // __ppvector_macro__
