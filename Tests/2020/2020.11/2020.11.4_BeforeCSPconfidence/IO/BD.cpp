#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <ctime>
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
int n(1);
char k[10001];
int main(int argc,char** argv) {
  unsigned long long s;
  if(argc>=1) {
    sscanf(argv[1],"%llu",&s);
    printf("%llu\n",s);
  } else {
    printf("sto");
    s=1;
  }
  freopen("IO.in", "w", stdout);
  srand(time(0)*s);//Seeds 
  for (register int i(1); i<=n; ++i) {
    printf("%d\n", (long long)(rand() - rand()) * (rand() - rand()));
  }
  return 0;
}
