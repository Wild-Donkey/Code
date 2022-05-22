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
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node {
  Node* LS, * RS;
  unsigned Val; 
}N[10000005], *Stack[10000005], **STop(Stack), *Root(NULL);
inline void Print() {
  for (unsigned i(1); i <= n; ++i)
    printf("%u LS %u RS %u\n", i, N[i].LS - N, N[i].RS - N);
}
inline void Prt() {
  unsigned long long LXor(0), RXor(0);
  for (unsigned long long i(1); i <= n; ++i) LXor ^= i * (N[i].LS ? (N[i].LS - N + 1) : 1);
  for (unsigned long long i(1); i <= n; ++i) RXor ^= i * (N[i].RS ? (N[i].RS - N + 1) : 1);
  printf("%llu %llu\n", LXor, RXor);
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) {
    N[i] = {NULL, NULL, RD()};
    while ((STop > Stack) && ((*STop)->Val > N[i].Val)) --STop;
    if(STop > Stack) N[i].LS = (*STop)->RS, (*STop)->RS = N + i, *(++STop) = N + i;
    else N[i].LS = Root, Root = *(++STop) = N + i;
//    Print();
  }
  Prt();
//  }
  return Wild_Donkey;
}

