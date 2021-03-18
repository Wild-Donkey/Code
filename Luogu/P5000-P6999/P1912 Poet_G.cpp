#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned a[10005], m, n, Cnt(0), He, Ta, t, Ans(0), Tmp(0);
bool flg;
char Poem[10005][31];
struct Line {
  unsigned Adre, l, r;
}Li[10005];
void Clr() {
  n = RD();
  L = RD();
  P = RD();
  flg = 0;
  He = 1;// ╤сап 
  Ta = 1;
  Li[1].Adre = 0;
  Li[1].l = 0;
  Li[1].r = n; 
  Sum[0] = 0;
  char chtmp(getchar());
  for (register unsigned i(1); i <= n; ++i) {
    while (chtmp < 33 || chtmp > 127){
      chtmp = getchar();
    }
    Cnt = 0;
    while (chtmp >= 33 && chtmp <= 127) {
      Poem[i][Cnt++] = chtmp;
      chtmp = getchar();
    }
    a[i] = Cnt;
  }
  return;
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  t = RD();
    for (register unsigned T(1); T <= t; ++T){
    Clr();
    for (register unsigned i(1); i <= n; ++i) {
      Sum[i] = Sum[i - 1] + a[i] + 1;
    }
    for (register unsigned i(1); i <= n; ++i) {
      tmp = Doit(Sum);
      if(tmp == 0x3f3f3f3f) {
        flg = 1;
        ;
      }
      f[i] = f[Li[Hd].Adre] + tmp;
    }
    for (register unsigned i(1); i <= 20; ++i){
      putchar('-');
    }
    putchar('\n');
  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



