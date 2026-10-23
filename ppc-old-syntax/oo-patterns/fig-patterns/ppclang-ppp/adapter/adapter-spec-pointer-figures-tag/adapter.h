#ifndef __figure_container_adapter__
#define __figure_container_adapter__

//==============================================================================
// figure-container-adapter.h - описание адаптера для контейнера
// Реализован через указатель на контейнер
//==============================================================================

#include "figure.h"
#include "container.h"

//------------------------------------------------------------------------------
// Адаптер контейнера
// typedef struct ContainerAdapter {Container *container;} ContainerAdapter;

//------------------------------------------------------------------------------
// Фигура - адаптер контейнера
Figure + < contAdapter: Container*; >;

#endif // __figure_container_adapter__
