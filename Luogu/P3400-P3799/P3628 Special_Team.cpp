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
unsigned m, n, Cnt(0),  D, t, Ans(0), Tmp(0);
long long A, B, C, Sum[1000005], sumSquare[1000005], f[1000005], a[1000005];
bool b[10005];
inline void Clr() {}
struct Hull {
  long long x, y;
  unsigned Address;
}H[1000005], *L(H), *R(H), New;
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  A = RDsg();
  B = RDsg();
  C = RDsg();
  Sum[0] = 0;
  for (register unsigned i(1); i <= n; ++i) {
    a[i] = RD();
    Sum[i] = Sum[i - 1] + a[i];
    sumSquare[i] = Sum[i] * Sum[i] * A;
  }
  /*
  f[i] = f[j] + A(Sum[i] - Sum[j])^2 + B(Sum[i] - Sum[j]) + C
  f[i] = f[j] + A(Sum[i]^2 - 2Sum[i]Sum[j] + Sum[j]^2) + B(Sum[i] - Sum[j]) + C
  f[i] = f[j] + ASum[i]^2 - 2ASum[i]Sum[j] + ASum[j]^2 + BSum[i] - BSum[j] + C
  f[j] + ASum[j]^2 = (2ASum[i] + B)Sum[j] + f[i] - BSum[i] - ASum[i]^2 - C
  k = 2ASum[i] + B
  x = Sum[i]
  y = f[i] + ASum[i]^2
  */
  for (register unsigned i(1); i <= n; ++i) {
    while (L < R && (((L + 1)->y - L->y) > (((L + 1)->x - L->x) * (((A * Sum[i]) << 1) + B)))) {
//      printf("Pop %u\n", L - H);
      ++L;
    }
    Tmp = Sum[i] - Sum[L->Address];
    f[i] = f[L->Address] + Tmp * Tmp * A + Tmp * B + C;
    New.Address = i;
    New.x = Sum[i];
    New.y = f[i] + sumSquare[i];
    while (L < R && (((New.y - R->y) * (R->x - (R - 1)->x)) > ((R->y - (R - 1)->y) * (New.x - R->x)))) {
      --R;
    }
    *(++R) = New;
//    printf("%d %d %d %d %d\n", i, f[i], New.x, New.y, ((A * Sum[i]) << 1) + B);
  }
  printf("%lld\n", f[n]);
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



