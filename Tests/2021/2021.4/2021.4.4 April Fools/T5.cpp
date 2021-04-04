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
unsigned a[10005], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
bool b[10005];
inline void Clr() {}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (register unsigned i(1); i <= n; ++i) {
    a[i] = RD();
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
please finish the sudokus and try to connect the numbers in the yellow squares into a single number from left to right sudokus are in I TF s
P/L/E/A/S/E/-....-/F/I/N/I/S/H/-....-/T/H/E/-....-/S/U/D/O/K/U/S/-....-/A/N/D/-....-/T/R/Y/-....-/T/O/-....-/C/O/N/N/E/C/T/-....-/T/H/E/-....-/N/U/M/B/E/R/S/-....-/I/N/-....-/T/H/E/-....-/Y/E/L/L/O/W/-....-/S/Q/U/A/R/E/S/
-....-/I/N/T/O/-....-/A/-....-/S/I/N/G/L/E/-....-/N/U/M/B/E/R/-....-/F/R/O/M/-....-/L/E/F/T/-....-/T/O/-....-/R/I/G/H/T/.-.-.-/-....-/S/U/D/O/K/U/S/-....-/A/R/E/-....-/I/N/-....-/I/---../..---/....-/T/F/-----/S/
*/
