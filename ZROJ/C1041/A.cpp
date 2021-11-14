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
struct Pre {
  long long Val[6];
  unsigned Pos;
  inline const char operator < (const Pre &x) const {
    for (char i(0); i < 6; ++i) if(Val[i] ^ x.Val[i]) return Val[i] < x.Val[i];
    return 0;
  }
}P[200005], De[200005];
multiset<Pre> PS;
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
//  inline void Clr() {}
signed main() {
//  freopen("A4.in", "r", stdin);
//  freopen("A2.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) {
    P[i].Pos = i;
    for (unsigned j(0); j < 6; ++j) P[i].Val[j] = P[i - 1].Val[j] + RD();
    for (unsigned j(0); j < 6; ++j) P[i].Val[j] -= RD();
  }
  for (unsigned i(1); i <= n; ++i) {
    De[i].Pos = i;
    for (unsigned j(0); j < 6; ++j) De[i].Val[j] = De[i - 1].Val[j] + RD();
    for (unsigned j(0); j < 6; ++j) De[i].Val[j] -= RD();
  }
  if((P[n] < De[n]) || (P[n] < De[n])) {
    printf("No\n");
    return 0;
  }
  for (unsigned i(1); i < n; ++i) PS.insert(P[i]);
  for (unsigned i(1); i < n; ++i) {
    set<Pre>::iterator It(PS.find(De[i]));
    if(It == PS.end()) {printf("No\n");return 0;}
    PS.erase(It);
  }
  printf("Yes\n");
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
