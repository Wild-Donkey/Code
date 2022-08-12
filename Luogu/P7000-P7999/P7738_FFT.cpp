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
struct Comp {
  double Rel, Vir;

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
  for (unsigned i(1); i <= n; ++i) {
    a[i] = RD();
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
20
21,22,23,24,25,26,27,28,29,30
31,32,33,34,35,36,37,38,39,40
41,42,43,44,45,46,47,48,49,50
51,52,53,54,55,56,57,58,59,60
61,62,63,64,65,66,67,68,69,70
71,72,73,74,75,76,77,78,79,80
81,82,83,84,85,86,87,88,89,90
91,92,93,94,95,96,97,98,99,100
101,102,103,104,105,106,107,108,109,110
111,112,113,114,115,116,117,118,119,120
121,122,123,124,125,126,127,128,129,130
131,132,133,134,135,136,137,138,139,140
141,142,143,144,145,146,147,148,149,150
151,152,153,154,155,156,157,158,159,160
161,162,163,164,165,166,167,168,169,170
171,172,173,174,175,176,177,178,179,180
181,182,183,184,185,186,187,188,189,190
191,192,193,194,195,196,197,198,199,200
*/