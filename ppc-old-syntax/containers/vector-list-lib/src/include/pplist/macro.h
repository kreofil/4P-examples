#ifndef __pplist_macro__
#define __pplist_macro__
// macro.h
// Заголовочный файл, обеспечивающий полный интрефейс к возможностям
// процедурно-параметрического списка

//==============================================================================
// Препроцессорные определения, служащие оберткой, расширяющей функциональность.
//==============================================================================

//------------------------------------------------------------------------------
// Макроопределение, используемое для формирования специализации по шаблону
// Скрывает дополнительные манипуляции, связанные с установкой
// внутренних параметров
#define ppList_VAR(foundation_type, list_name)      \
struct ppList.foundation_type list_name;          \
list_name.foundation_size = sizeof(list_name.@);  \
list_name.foundation_addr = &(list_name.@);       \
list_name.size = 0;                                 \
list_name.head = NULL;                             \
list_name.tail = NULL;                             \
list_name.current = NULL;

//------------------------------------------------------------------------------
// Макрос, используемый для занесения значения в хвост списка.
// Обертывает функцию ppList_push_back и предварительное присваивание
// пересылаемого значения внутренней переменной
#define ppList_PUSH_BACK(list_name, value) \
list_name.@ = (value); ppList_push_back((ppList*)&list_name);

//------------------------------------------------------------------------------
// Макрос, используемый для чтения элемента из списка в заданную переменну.
// Обертывает функцию ppList_index и присваивание внутренней переменной
// указанной внешней переменной
// #define ppList_GET_VAL_INDEX(destination, list_name, index) \
// ppList_index((ppList*)&list_name, (index)); destination = list_name.@;

//------------------------------------------------------------------------------
// Макрос для занесения первого элемента списка в указанную переменную
#define ppList_GET_FRONT_VAL(destination, list_name) \
ppList_front((ppList*)&list_name); destination = list_name.@;

//------------------------------------------------------------------------------
// Макрос для занесения последнего элемента списка в указанную переменную
#define ppList_GET_BACK_VAL(destination, list_name) \
ppList_back((ppList*)&list_name); destination = list_name.@;

//------------------------------------------------------------------------------
// Макрос для занесения текущего элемента списка в указанную переменную
#define ppList_GET_CURRENT_VAL(destination, list_name) \
ppList_current((ppList*)&list_name); destination = list_name.@;

#endif // __pplist_macro__
