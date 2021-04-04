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
inline unsigned long long RD() {
  unsigned long long intmp = 0;
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
long long m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
bool b[10005];
inline void Clr() {}
long long Exgcd(long long x, long long y, long long &X, long long &Y) {
  if (y) {
    int tmp(Exgcd(y, x % y, Y, X));
    Y -= X * (x / y);
    //    printf("Exgcd(%d, %d, %d, %d)\n", x, y, X, Y);
    return tmp;
  }
  X = 1;
  Y = 0;
  //  printf("Exgcd(%d, %d, %d, %d)\n", x, y, X, Y);
  return x;
}
int main() {
  // double Ti(clock()), Mti(0);
  //   freopen("P5656_5.in", "r", stdin);
  //   freopen("P5656.out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  B = RD();
  A = RD();
  Exgcd(A, B, C, D);
  //    printf("%ld %ld %lu\n", C, D, E);
  C = ((((D - 1) % A) + A) % A) + 1;  // y_min
  printf("%lu\n", C);
  //  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
49555 59069 92955
33312 21610

*/