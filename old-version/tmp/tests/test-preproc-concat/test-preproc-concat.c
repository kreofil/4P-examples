// struct ppVector.int v_int = {sizeof(v_int.@),&(v_int.@)};

//------------------------------------------------------------------------------
// Макроопределение, используемое для формирования специализации по шаблону
// Скрывает дополнительные манипуляции, связанные с установкой
// внутренних параметров
#define ppVector_VAR(foundation_type, vector_name) \
  struct ppVector.foundation_type vector_name = \
    {sizeof(vector_name.@), &(vector_name.@), 0, 0)};

ppVector_VAR(int, v_int)