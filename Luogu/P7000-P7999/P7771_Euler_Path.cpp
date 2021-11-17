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
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0), ATop(0);
unsigned Ans[200005], Top(0);
struct Node;
struct Edge {
  Node* To;
}E[200005];
inline char Cmp(Edge* x, Edge* y) {return x->To < y->To;}
struct Node {
  vector <Edge*> To; 
  unsigned Last, Idg, Odg;
}N[100005], *S, *T;
inline void DFS(Node* x) {
//  printf("DFS %u Top %u\n", x - N, x->Last);
  for (;x->Last < x->To.size();) DFS(x->To[(x->Last)++]->To);
  Ans[Top--] = x - N;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), Top = (m = RD() + 1);
  for (unsigned i(1); i < m; ++i) {
    ++(N[A = RD()].Odg), ++(N[B = RD()].Idg);
    E[i].To = N + B;
    N[A].To.push_back(E + i);
  }
  for (Node* i(N + n); i > N; --i) {
    sort(i->To.begin(), i->To.end(), Cmp);
    if(i->Idg == i->Odg) continue;
    if(i->Idg == (i->Odg + 1)) {
      if(T){printf("No\n"); return 0;}
      T = i; continue;
    }
    if((i->Idg + 1) == i->Odg) {
      if(S){printf("No\n"); return 0;}
      S = i; continue;
    }
    printf("No\n"); return 0;
  }
  if(!S) S = N + 1, T = N + n + 1, E[m + 1].To = T, S->To.push_back(E + m + 1);
  DFS(S);
  if(Ans[0]) for (unsigned i(0); i < m; ++i) printf("%u ", Ans[i]);
  else for (unsigned i(1); i <= m; ++i) printf("%u ", Ans[i]);
  putchar(0x0A);
//  }
  return Wild_Donkey;
}
/*
3 3
1 2
2 3
3 1
*/
