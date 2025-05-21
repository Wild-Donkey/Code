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
unsigned long long Bin[55], B[55], A, Ans(0);
unsigned C, D, t, m, n;
unsigned Cnt(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), Bin[0] = 1;
  for (unsigned i(1); i <= 50; ++i) Bin[i] = (Bin[i - 1] << 1);
  for (unsigned i(1); i <= n; ++i) {
    A = RD();
    for (unsigned j(50); ~j; --j) if (A & Bin[j]) {
      if (B[j]) A ^= B[j];
      else { B[j] = A; break; }
    }
  }
  for (unsigned i(50); ~i; --i) if ((B[i]) && (!(Ans & Bin[i]))) Ans ^= B[i];
  printf("%llu\n", Ans);
  //  }
//  system("pause");
  return Wild_Donkey;
}