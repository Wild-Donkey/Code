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
unsigned long long Le, Ri, Mid;
unsigned m, n(0);
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node {
  vector<Node*> To;
  Node* Fa;
  unsigned Val;
}N[100005];
inline unsigned long long DFS(Node* x) {
//  printf("DFS %u\n", x - N);
  vector<unsigned long long> Sons;
  for (auto i:x->To) if(i != x->Fa) i->Fa = x, Sons.push_back(DFS(i));
  sort(Sons.begin(), Sons.end());
  unsigned long long My(x->Val);
  unsigned Miu(0);
  for (auto i:Sons) if(My + i <= Mid) ++Miu, My += i; else break;
  Cnt += Sons.size() - Miu;
  if(My == Mid) {++Cnt;return 0;}
  return My;
}
inline void Clr() {
  for (unsigned i(1); i <= n; ++i) N[i].To.clear();
  n = RD(), m = RD();
  Le = Ri = 0;
}
signed main() {
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(1); i < n; ++i) {
      A = RD(), B = RD();
      N[A].To.push_back(N + B);
      N[B].To.push_back(N + A);
    }
    for (unsigned i(1); i <= n; ++i) Le = max(Le, (unsigned long long)(N[i].Val = RD())), Ri += N[i].Val;
    while (Le < Ri) {
      Mid = (Le + Ri) >> 1;
      Cnt = 0, A = DFS(N + 1);
      if(A) ++Cnt;
      if(Cnt <= m) Ri = Mid;
      else Le = Mid + 1;
    }
    printf("Case #%u: %llu\n", T, Le);
  }
  return Wild_Donkey;
}
/*
100

*/
