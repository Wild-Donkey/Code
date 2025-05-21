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
unsigned a[10005], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0), Mod;
bool b[10005];
unsigned Power (unsigned x, unsigned y) {
  if(!y) {
    return 1;
  }
  unsigned tmp(Power(((long long)x * x) % Mod, y >> 1));
  if(y & 1) {
    return ((long long)x * tmp) % Mod;
  }
  return tmp;
}
unsigned Binom (unsigned x, unsigned y) {
  unsigned Up(1), Down(1);
  if (y > x) {
    return 0;
  }
  if(!y) {
    return 1;
  }
  for (register unsigned i(2); i <= x; ++i) {
    Up = ((long long)Up * i) % Mod;
  }
  for (register unsigned i(2); i <= y; ++i) {
    Down = ((long long)Down * i) % Mod;
  }
  for (register unsigned i(2); i <= x - y; ++i) {
    Down = ((long long)Down * i) % Mod;
  }
  Down = Power(Down, Mod - 2);
  return ((long long)Up * Down) % Mod;
}
unsigned Lucas (unsigned x, unsigned y) {
  if(x <= Mod && y <= Mod) {
    return Binom(x, y);
  }
  return ((long long)Binom(x % Mod, y % Mod) * Lucas(x / Mod, y / Mod)) % Mod;
}
inline void Clr() {
  n = RD();
  m = RD();
  Mod = RD();
}
int main() {
  t = RD();
  for (register unsigned T(1); T <= t; ++T){
    Clr();
    if(!(n && m)) {
      printf("1\n");
      continue; 
    }
    printf("%u\n", Lucas(n + m, n));
  }
  return Wild_Donkey;
}
/*
2
1 2 5
2 1 5
*/
