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
unsigned a[100005], m, n;
unsigned A, B, C, D, t;
unsigned Stack[105], STop(0);
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned Prime[10005], CntP(0);
unsigned Sum[100005][1005];
int Mu[100005];
char Flg(0);
bitset<100005> Isnt, Vis;
vector<unsigned> PrP[100005];
vector<unsigned> Apr[100005];
inline void LiSh (unsigned Mx) {
  Mu[1] = Isnt[1] = 1;
  for (unsigned i(2); i <= Mx; ++i) {
    if(!(Isnt[i])) Prime[++CntP] = i, Mu[i] = -1;
    for (unsigned j(1); (Prime[j] * i <= Mx) && (j <= CntP); ++j) {
      Isnt[Prime[j] * i] = 1, Mu[Prime[j] * i] = -Mu[i];
      if(!(i % Prime[j])) {Mu[Prime[j] * i] = 0; break;}
    }
  }
}
inline void Mu0 (unsigned& x) {
  for (unsigned i(1); (i <= CntP) && (Prime[i] <= x) && (x > 1); ++i) {
    if(!(x % Prime[i])) {
      while (!(x % Prime[i])) x /= Prime[i];
      Stack[++STop] = Prime[i];
    }
  }
  while (STop) {x *= Stack[STop--];}
}
inline void Clr (unsigned x) {
  if(!Vis[x]) return;
  Vis[x] = 0; 
  for (auto i:PrP[x]) Clr(x / i);
}
inline void Ins(unsigned Pos, unsigned x) {
  if(Vis[x]) return;
  Vis[x] = 1, Apr[x].push_back(Pos);
  for (auto i:PrP[x]) Ins(Pos, x / i);
}
inline void Qry(unsigned x) {
  if(Vis[x]) return;
  Vis[x] = 1; 
  unsigned Le, Ri;
  Le = distance(Apr[x].begin(), upper_bound(Apr[x].begin(), Apr[x].end(), A - 1));
  Ri = distance(Apr[x].begin(), upper_bound(Apr[x].begin(), Apr[x].end(), B));
  Ans += Mu[x] * (Ri - Le);
//  printf("Qry %u [%u, %u]\n", x, Le, Ri);
  for (auto i:PrP[x]) Qry(x / i);
}
signed main() {
//  freopen("ex_B2.in", "r", stdin);
//  freopen("B.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  LiSh(100000);
  n = RD(), m = RD();
//  for (unsigned i(1); i <= 100; ++i) printf("%d ", Mu[i]);
  for (unsigned i(1); i <= n; ++i) a[i] = RD(), Mu0(a[i]);
//  for (unsigned i(1); i <= n; ++i) printf("%u ", a[i]);
//  putchar(0x0A); 
  for (unsigned i(1); i <= 100000; ++i) {
    for (unsigned j(1), x(i); (Prime[j] <= x) && (x > 1); ++j) {
      if(!(x % Prime[j])) {
        while (!(x % Prime[j])) x /= Prime[j];
        PrP[i].push_back(Prime[j]);
      }
    }
//    printf("%u: %u-> ", i, PrP[i].size());
//    for (unsigned j(0); j < PrP[i].size(); ++j) printf("%u ", PrP[i][j]);
//    putchar(0x0A);
  }
  for (unsigned i(1); i <= n; ++i) Ins(i, a[i]), Clr(a[i]);
//  for (unsigned i(1); i <= 100000; ++i) if(Apr[i].size()) {
//    printf("%u: %u-> ", i, Apr[i].size());
//    for (auto j:Apr[i]) printf("%u ", j);
//    putchar(0x0A);
//  }
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD(), C = RD(), Ans = 0, Mu0(C), Qry(C), Clr(C); 
    printf("%u\n", Ans);
  }
//  }
  return Wild_Donkey;
}

