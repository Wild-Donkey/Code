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
char Sig(0);
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  Sig = rdch - '0', rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  if (Sig) n = (~n) + 1;
  char Code[35];
  for (unsigned i(0); i <= 31; ++i) Code[i] = (n & 1), n >>= 1;
  for (unsigned i(31); ~i; --i) putchar('0' + Code[i]);putchar(0x0A);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
00000000000000000000000011000011
10000000000000000000000011000011
*/