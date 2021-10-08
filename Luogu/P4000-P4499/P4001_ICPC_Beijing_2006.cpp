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
const int Direc[12] = {-1005, 1005, -1, 1, -1006, 1006, -1005, 1005, -1, 1, -1006, 1006};
const unsigned char Inv[12] = {7, 6, 9, 8, 11, 10, 1, 0, 3, 2, 5, 4};
struct Node {
  unsigned Edge[12], Dep;
}N[1005][1005], * Q[1000005];
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0);
unsigned Hd, Tl;
inline char BFS() {
  Hd = Tl = 0, (Q[++Tl] = N[1] + 1)->Dep = 1;
  while (Hd ^ Tl) {
    Node* Cur(Q[++Hd]);
    for (unsigned char i(0); i < 12; ++i) if(Cur->Edge[i]) {
      Node* To(Cur + Direc[i]);
      if(To->Dep >= 0x3f3f3f3f) To->Dep = Cur->Dep + 1, Q[++Tl] = To;
    }
  }
  return N[n][m].Dep < 0x3f3f3f3f;
}
inline unsigned DFS(Node* x, const unsigned& Come) {
  if(x == N[n] + m) {Ans += Come; return Come;}
  unsigned Cur(Come);
  for (unsigned char i(0); i < 12; ++i) if (x->Edge[i]) {
    Node* To(x + Direc[i]);
    if(To->Dep == x->Dep + 1) {
      unsigned Push(min(x->Edge[i], Cur)), Tmp(DFS(To, Push));
      if(Tmp < Push) To->Dep = 0x3f3f3f3f;
      x->Edge[i] -= Tmp;
      To->Edge[Inv[i]] += Tmp;
      Cur -= Tmp;
      if(!Cur) break;
    }
  }
  return Come - Cur;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j < m; ++j)
    N[i][j].Edge[3] = N[i][j + 1].Edge[2] = RD();
  for (unsigned i(1); i < n; ++i) for (unsigned j(1); j <= m; ++j)
    N[i][j].Edge[1] = N[i + 1][j].Edge[0] = RD();
  for (unsigned i(1); i < n; ++i) for (unsigned j(1); j < m; ++j)
    N[i][j].Edge[5] = N[i + 1][j + 1].Edge[4] = RD();
  for (unsigned i(n + 1); ~i; --i) for (unsigned j(m + 1); ~j; --j) N[i][j].Dep = 0x3f3f3f3f;
 
  while (BFS()) {
//    printf("A Round Begining Ans %u\n", Ans);
    DFS(N[1] + 1, 0x3f3f3f3f);
    for (unsigned i(n + 1); ~i; --i) for (unsigned j(m + 1); ~j; --j) N[i][j].Dep = 0x3f3f3f3f;
  }
  printf("%u\n", Ans);
//  }
  return Wild_Donkey;
}

