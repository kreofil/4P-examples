// Реализация клиентского кода, осуществляющего вывод (рисование) фигур

#include "client-draw.h"

// Вывод содержимого контейнера
void ClientDraw::DrawContainer(std::ofstream &ofst) {
  container.Out(ofst);
}
