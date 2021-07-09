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
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned n, Cnt(0), k, t, Ans(0), Tmp(0), Now(0);
inline void Clr() {
  n = RD(), k = RD(), Now = 0;
}
unsigned XOR (unsigned x, unsigned y) {
  register unsigned z(0), Sq(1), X;
  if(x > y) swap(x, y);
  while (x && y) {
    X = (x % k) + (y % k);
    if(X >= k) X -= k;
    z += Sq * X;
    Sq *= k, x /= k, y /= k;
  }
  while (y) {
    X = y % k;
    z += Sq * X;
    Sq *= k, y /= k;
  }
  return z;
}
unsigned InXOR (unsigned x, unsigned y) {//x ^ z = y
  register unsigned z(0), Sq(1), X;
  while (x && y) {
    X = (y % k) + k - (x % k);
    if(X >= k) X -= k;
    z += Sq * X;
    Sq *= k, x /= k, y /= k;
  }
  while (y) {
    X = y % k;
    z += Sq * X;
    Sq *= k, y /= k;
  }
  while (x) {
    X = k - (y % k);
    z += Sq * X;
    Sq *= k, x /= k;
  }
  return z;
}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned T(1); T <= t; ++T){
    Clr();
    for (register unsigned i(0); i < n; ++i) {
      Tmp = XOR(i, Now);
      printf("%u\n", Tmp);
      fflush(stdout);
      Now = InXOR(Now, Tmp);
      if(RD()) break;
    }
  }
  return Wild_Donkey;
}

