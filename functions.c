#include "exe.h"

void clearBuffer() { // Função de Limpeza de Buffer
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
};