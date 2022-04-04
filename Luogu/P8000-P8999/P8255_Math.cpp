#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned long long RD() {
  unsigned long long intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
unsigned long long m, n;
unsigned long long A, B, C, D;
unsigned t, Cnt(0), Ans(0), Tmp(0);
inline void Clr() {
  n = RD(), m = RD();
}
inline unsigned long long Gcd(unsigned long long x, unsigned long long y) {
  unsigned long long TmG;
  while (y) { TmG = x, x = y, y = TmG % y; }
  return x;
}
signed main() {
//  freopen("math.in", "r", stdin);
//  freopen("math.out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    if(m % n) { printf("-1\n"); continue; }
    m /= n, A = n * n;
    B = Gcd(A, m), C = sqrt(B);
    if((C * C) != B) { printf("-1\n"); continue; }
    printf("%llu\n", m / C);
  }
  return Wild_Donkey;
}

