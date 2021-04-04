#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <ctime>
#include <windows.h>
using namespace std;
inline int RD() {
  int Itmp(0), Isig(1);
  char Ichr(getchar());
  while ((Ichr != '-') && ((Ichr > '9') || (Ichr < '0'))) {
    Ichr = getchar();
  }
  if (Ichr == '-') {
    Isig = -1;
    Ichr = getchar();
  }
  while ((Ichr >= '0') && (Ichr <= '9')) {
    Itmp = Itmp * 10 + Ichr - '0';
    Ichr = getchar();
  }
  return Itmp * Isig;
}
inline void PR(int Prtmp, bool SoE) {
  int Prstk(0), Prlen(0);
  if (Prtmp < 0) {
    putchar('-');
    Prtmp = -Prtmp;
  }
  do {
    Prstk = Prstk * 10 + Prtmp % 10;
    Prtmp /= 10;
    ++Prlen;
  } while (Prtmp);
  do {
    putchar(Prstk % 10 + '0');
    Prstk /= 10;
    --Prlen;
  } while (Prlen);
  if (SoE) {
    putchar('\n');
  } else {
    putchar(' ');
  }
  return;
}
long long Ti;
char k[100001];
int main() {
  for (unsigned long long i=1;; i++) {
    sprintf(k,"BD.exe %llu",i);
    system(k);//Seeds 
    Ti = clock();
    system("T.exe");
    printf("T_Time = %lld\n", clock() - Ti);
    Ti = clock();
    system("Tfc.exe");
    printf("Tfc_Time = %lld\n", clock() - Ti);
    if(system("fc IO.out IOfc.out")) {
      printf("Error!");
      MessageBox(NULL,"error!!!!!","tql",MB_YESNO);//MB
      break;
    }
    else {
      printf("AC %d\n");
    }
  }
  return 0;
}
