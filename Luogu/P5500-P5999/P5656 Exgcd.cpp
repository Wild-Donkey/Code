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
long long m, n, Cnt(0), A, B, C, D, E, F, G, t, Ans(0), Tmp(0);
bool b[10005];
inline void Clr() {}
long long Exgcd(long long x, long long y, long long &X, long long &Y) {
  if(y) {
    int tmp(Exgcd(y, x % y, Y, X));
    Y -= X * (x/y);
//    printf("Exgcd(%d, %d, %d, %d)\n", x, y, X, Y);
    return tmp; 
  }
  X = F / x;
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
  n = RD();
  for (register unsigned i(1); i <= n; ++i) {
    A = RD();
    B = RD();
    F = RD();
    E = Exgcd(A, B, C, D);
    if(F % E) {
      printf("-1\n");
      continue;
    }
    F /= E;
    A /= E;
    B /= E;
//    printf("%ld %ld %lu\n", C, D, E);
    C = ((((C - 1) % B) + B) % B) + 1;//x_min
    E = (F - A * C) / B;//y_max
    if(E > 0) {//y_max>0
//      printf("%lu %lu %lu\n", F, A, B);
      printf("%lu %lu ", (E + A - 1) / A, C);//Num_ans, x_min
      C = ((((D - 1) % A) + A) % A) + 1;//y_min
      G = (F - B * C) / A;//x_max
      printf("%lu %lu %lu\n", C, G, E);
      continue;
    }
    D = ((((D - 1) % A) + A) % A) + 1;
    printf("%lu %lu\n", C, D);
    continue;
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
49555 59069 92955
33312 21610

*/
