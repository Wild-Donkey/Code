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
unsigned m, n, k;
unsigned B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node {
  vector<Node*> Son;
  unsigned Size, CSon, f;
  inline void PreDFS() {
    Size = 1;
    for (auto i:Son) i->PreDFS(), Size += i->Size;
  }
  inline void DFS() {
    unsigned Sum(0), Flg(0);
    for (auto i:Son) if(i->Size > k) i->DFS(), f = max(i->f + 1, f);
    for (auto i:Son) {if(!(i->f)) Flg += (i->Size > 1); Sum += i->f;}
    if(Flg && (CSon >= k)) ++Sum;
    f = max(f, Sum);
  }
}N[800005], * A;
inline void Clr() {
  for (unsigned i(0); i <= n; ++i) N[i].Son.clear();
  memset(N, 0, (n + 1) * sizeof(Node));
  n = RD(), k = RD();
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(2); i <= n; ++i) {
      A = N + RD();
      A->Son.push_back(N + i);
      ++(A->CSon);
    }
    N[1].PreDFS(), N[1].DFS();
    printf("%u\n", N[1].f); 
  }
  return Wild_Donkey;
}

