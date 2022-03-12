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
bitset<100005> Vis;
unsigned a[100005], Stack[100005], Opt[400100][2];
unsigned m, n, A, B, C, D, t, STop(0);
unsigned Cnt(0), Ans(0), Tmp(0);
char Flg(0);
inline void DFS(unsigned x){
  Stack[++STop] = x, Vis[x] = 1;
  if(!Vis[a[x]]) DFS(a[x]);
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
  for (unsigned i(1); i <= n; ++i) if(!Vis[i]) {
    STop = 0, DFS(i);
//    printf("DFS %u Len %u\n", i, )
    if(STop > 1) {
      Flg ^= 1;
      Opt[++Ans][0] = Stack[1], Opt[Ans][1] = n + 1;
      Opt[++Ans][0] = Stack[2], Opt[Ans][1] = n + 2;
      for (unsigned i(3); i <= STop; ++i) Opt[++Ans][0] = Stack[i], Opt[Ans][1] = n + 2;
      Opt[++Ans][0] = Stack[1], Opt[Ans][1] = n + 2;
      Opt[++Ans][0] = Stack[2], Opt[Ans][1] = n + 1;
    }
  }
  if(Flg) Opt[++Ans][0] = n + 1, Opt[Ans][1] = n + 2;
  if(!Ans) printf("0 0\n");
  else printf("2 %u\n", Ans);
  for (unsigned i(1); i <= Ans; ++i) printf("%u %u\n", Opt[i][0], Opt[i][1]);
//  }
//  system("pause");
  return Wild_Donkey;
}
/*
6
3 4 5 6 1 2
*/
