#include <algorithm>
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
const unsigned long long Mod(998244353);
inline unsigned long long Pow(unsigned long long x) {
  unsigned long long TmP(1);
  unsigned y(Mod - 2);
  while (y) {
    if(y & 1) TmP = TmP * x % Mod;
    y >>= 1, x = x * x % Mod;
  }
  return TmP;
}
unsigned long long Ans(0);
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
struct Node {
  vector<Node*> To;
  Node* Fa;
  unsigned long long f, p, g, If, Ip;
}N[100005];
inline void DFS(Node* x) {
  x->g = x->f = 0;
  for (auto i:x->To) if(i != x->Fa){
    i->Fa = x, DFS(i);
    x->f = (x->f * (1 + Mod - i->g) + (1 + Mod - x->g) * i->g) % Mod;
    x->g = x->g * (Mod + 1 - i->g) + i->g;
  } 
  Ans = (Ans + x->g * (x->Ip) + x->p) % Mod;
  x->g = (x->g + (Mod + 1 - x->g) * x->p) % Mod;
//  printf("Node %u f %llu g %llu\n", x - N, x->f, x->g);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) N[i].p = RD(), N[i].p = N[i].p * Pow(RD()) % Mod;
  for (unsigned i(1); i <= n; ++i) {N[i].Ip = 1 + Mod - N[i].p; if(N[i].Ip >= Mod) N[i].Ip -= Mod;}
  for (unsigned i(1); i < n; ++i) {
    A = RD(), B = RD();
    N[A].To.push_back(N + B);
    N[B].To.push_back(N + A); 
  }
  DFS(N + 1);
  printf("%llu\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}

