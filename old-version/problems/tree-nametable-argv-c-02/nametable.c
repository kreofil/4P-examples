#include <stdio.h>
#include <ctype.h>

int nextName(FILE *infil, char *strBuf) {
  int c;
  int i_strBuf = -1;
  strBuf[0] = '\0';
 while(1) {
  c = getc(infil);
  if(c==EOF) {
    // endfile=1;
    return 1;
  }
  if(isalpha(c) || c=='_') {
    strBuf[++i_strBuf] = c;
    c = getc(infil);
    while(isalpha(c) || isdigit(c) || c=='_') {
      strBuf[++i_strBuf] = c;
      c = getc(infil);
    }
    strBuf[++i_strBuf] = '\0'; // для динамического ключа ограничений нет
    // endfile=0;
    return 0;
  }
 }
}


