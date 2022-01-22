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
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node {
  vector <Node*> Son;
  unsigned long long f[120][120];
  Node* Fa;
  unsigned Dep, Len;
}N[65];
inline void DFS(Node* x) {
  x->Len = x->Dep = 0, x->f[0][0] = (unsigned long long)1 << 63;
  double Tmp[120][120];
  memset(Tmp, 0, sizeof(Tmp));
  for (auto i : x->Son) if (i != x->Fa) {
    i->Fa = x, DFS(i);
    for (unsigned Mem((x->Dep) << 1); Mem >= x->Dep; --Mem) {
      for (unsigned Med((x->Len) << 1); Med >= x->Len; --Med) {
        for (unsigned Sm((i->Dep) << 1); Sm >= i->Dep; --Sm) {
          for (unsigned Sd((i->Len) << 1); Sd >= i->Len; --Sd) {
            Tmp[max(Mem, Sm)][max(Mem + Sm, max(Med, Sd))] = Tmp;
          }
        }
      }
    }
  }
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i < n; ++i) A = RD(), B = RD(), N[A].Son.push_back(N + B), N[B].Son.push_back(N + A);
  DFS(N + 1);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
5
1 2
2 3
3 4
4 5
*/