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
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
struct Node;
struct Edge{ 
  Node* To;
  Edge* Nxt;
}E[400005], * CntE(E);
struct Node {
  Edge* Fst; 
  Node* Fa;
  unsigned long long Size, Sum, Ans, Bro;
}N[200005];
void PreDFS(Node* x) {
  x->Size = 1;
  Edge* Sid(x->Fst);
  while (Sid) {
    if(Sid->To != x->Fa) {
      Sid->To->Fa = x, PreDFS(Sid->To);
      x->Size += Sid->To->Size;
      x->Sum += Sid->To->Sum + Sid->To->Size;
    }
    Sid = Sid->Nxt;
  } 
}
void DFS(Node* x, unsigned long long y) {
  unsigned long long TTmp(0);
  A = n - x->Size, B = x->Size;
  if(!(x->Fa)) x->Ans = x->Sum;
  else x->Ans = x->Fa->Ans + A - B;
  Edge* Sid(x->Fst);
  while (Sid) {
    if(Sid->To != x->Fa) {
      TTmp += Sid->To->Sum;
    }
    Sid = Sid->Nxt;
  } 
  Sid = x->Fst;
  while (Sid) {
    if(Sid->To != x->Fa) {
      DFS(Sid->To, TTmp);
    }
    Sid = Sid->Nxt;
  } 
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i < n; ++i) {
    A = RD(), B = RD();
    (++CntE)->Nxt = N[A].Fst, N[A].Fst = CntE, CntE->To = N + B;
    (++CntE)->Nxt = N[B].Fst, N[B].Fst = CntE, CntE->To = N + A;
  }
  PreDFS(N + 1), DFS(N + 1, N[1].Sum);
  for (unsigned i(1); i <= n; ++i) printf("%llu\n", N[i].Ans);
//  }
//  system(\"pause\");
  return Wild_Donkey;
}

