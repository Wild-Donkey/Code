#include <windows.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <queue>
#include <string>
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
long long Ti, n;
char k[100001];
int main() {
  n = RD();
  for (unsigned long long i = 1; i <= n; i++) {
    // printf("%d\n", i);
    system("P1874_Fast_Sum_rand.exe");
    // printf("%d\n", i);
    Ti = clock();
    system("P1874_Fast_Sum_new.exe");
    Ti = clock() - Ti;
    // printf("my_Time = %lld\n", clock() - Ti);
    // printf("%d\n", i);
    // Ti = clock();
    system("P1874_Fast_Sum_std.exe");
    // printf("Tfc_Time = %lld\n", clock() - Ti);
    // printf("%d\n", i);
    if (system("fc P1874std.out P1874.out")) {
      printf("Error!");
      break;
    }
  }
  system("pause");
  return 0;
}