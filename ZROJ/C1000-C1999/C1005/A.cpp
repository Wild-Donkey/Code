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
#include <string>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
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
unsigned A2n[40], Bin[40], m, n, p;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Clr() {
  A = RD(), B = RD(), C = RD(), D = RD();
}
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long PTm(1);
  while (y) {
    if(y & 1) PTm = PTm * x % p;
    y >>= 1;
    x = x * x % p;
  }
  return PTm;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  p = RD(), t = RD(), Bin[0] = 1;
  for (unsigned i(1); i <= 32; ++i) Bin[i] = Bin[i - 1] << 1;
  for (unsigned T(1); T <= t; ++T){
    Clr();
    if(((A + B) % p) ^ ((C + D) % p)) { printf("-1\n"); continue; }
    B = (A + B) % p;
    A2n[0] = A;
    for (unsigned i(1); i <= 32; ++i) {A2n[i] = A2n[i - 1] << 1; if(A2n[i] >= p) A2n[i] -= p;}
    D = Pow(B, p - 2);
//    printf("S %u InvS %u\n", B, D);
    for (unsigned i(0); i <= 32; ++i) {
      unsigned long long Now(A2n[i] + p - C);
      if(Now >= p) Now -= p;
//      printf("Need, %u Have %u\n", Now, Bin[i]);
      if(Now * D % p < Bin[i]) {printf("%u\n", i); break;}
    }
  }
  return Wild_Donkey;
}

