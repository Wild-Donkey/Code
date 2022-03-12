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
vector<unsigned> Cir[100005];
bitset<100005> Vis;
unsigned a[100005], De[100005], Opt[400100][2];
unsigned m, n, A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void DFS(unsigned x){
  Cir[Cnt].push_back(x), Vis[x] = 1;
  if(Vis[a[x]]) return;
  DFS(a[k]);
}
inline void Swp(unsigned x, unsigned y, unsigned z) {
  Opt[++Ans][0] = x, Opt[Ans][1] = z;
  Opt[++Ans][0] = y, Opt[Ans][1] = z + 1;
  Opt[++Ans][0] = x, Opt[Ans][1] = z + 1;
  Opt[++Ans][0] = y, Opt[Ans][1] = z;
  swap(De[x], De[y]);
  swap(De[z], De[z + 1]);
}
inline void TriSwp(unsigned x, unsigned y, unsigned z) {
  Opt[++Ans][0] = x, Opt[Ans][1] = z;
  Opt[++Ans][0] = y, Opt[Ans][1] = z + 1;
  Opt[++Ans][0] = x, Opt[Ans][1] = z + 1;
  Opt[++Ans][0] = y, Opt[Ans][1] = z;
  swap(De[x], De[y]);
  swap(De[z], De[z + 1]);
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  for (unsigned i(n + 4); i; --i) De[i] = i;
  for (unsigned i(1); i <= n; ++i) if(!Vis[i]) ++Cnt, DFS(Vis[i]);
  for (unsigned i(1); i <= Cnt; ++i) {
    if(Cir[i].size() >= 3) {
      ++A;
      if(Cir[i].size() > 4) ++B;
    }
    else if(Cir[i].size() == 2) Swp(Cri[i][0], Cir[i][1], n + 1);
  }
  if(A <= 1) printf("2 ");
  else {
    if(B <= 3) printf("3 ");
    else printf("4 ");
  }
  for (unsigned i(1); i <= Cnt; ++i) if(Cir[i].size() == 3) {
    if()
  }
  printf("%u\n", Ans);
  for (unsigned i(1); i <= Ans; ++i) printf("%u %u\n", Opt[i][0], Opt[i][1]);
//  }
//  system("pause");
  return Wild_Donkey;
}

