#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <ctime>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#define Wild_Donkey 0
#define INFi 0x3f3f3f3f3f3f3f3f
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
map<pair<unsigned, unsigned>, unsigned> List;
unsigned m, n, Now;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
inline void Build(unsigned L, unsigned R) {
  List[make_pair(L, R)] = Now;
  if(L == R) return;
  unsigned Mid((L + R) >> 1);
  Build(L, Mid);
  Build(Mid + 1, R);
}
signed main() {
//  freopen("A4.in", "r", stdin);
  freopen("A.ans", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  Now = (n = RD()) << 1;
  for (; ~Now; --Now) Build(0, Now);
  for (unsigned i(0); i <= n; ++i) {
    for (unsigned j(i); j <= n; ++j) printf("%u ", List[make_pair(i, j)]);
    putchar(0x0A);
  }
  return Wild_Donkey;
}
/*
3
2 1 0 0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 1 0 0 0 0 0
1 0 0 0 0 0 0 0 0 0 0 0
1 1 0 0 0 0 0 0 0 0 0 0
1 1 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
*/
