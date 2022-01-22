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
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned Prime[10005], CntP(0);
unsigned Sum[505][100005];
int Mu[100005];
char Flg(0);
bitset<100005> Isnt, Vis;
vector<unsigned> PrP[100005], Apr[100005];
inline void LiSh (unsigned Mx) {
  Mu[1] = Isnt[1] = 1;
  for (unsigned i(2); i <= Mx; ++i) {
    if(!(Isnt[i])) Prime[++CntP] = i, Mu[i] = -1, PrP[i].push_back(i);
    for (unsigned j(1), Cur; (Prime[j] * i <= Mx) && (j <= CntP); ++j) {
      Cur = Prime[j] * i;
      Isnt[Cur] = 1, Mu[Cur] = -Mu[i];
      for (auto k:PrP[i]) PrP[Cur].push_back(k);
      if(!(i % Prime[j])) {Mu[Cur] = 0; break;}
      else PrP[Prime[j] * i].push_back(Prime[j]);
    }
  }
}
inline void Mu0 (unsigned& x) {
  unsigned TmpM(x);
  x = 1;
  for (auto i:PrP[TmpM]) x *= i;
}
inline void Clr (unsigned x) {
  if(!Vis[x]) return;
  Vis[x] = 0; 
  for (auto i:PrP[x]) Clr(x / i);
}
inline void Ins(unsigned Pos, unsigned x) {
  if(Vis[x] || (x <= 500)) return;
  Vis[x] = 1, Apr[x].push_back(Pos);
  for (auto i:PrP[x]) Ins(Pos, x / i);
}
inline void Qry(unsigned x) {
  if(Vis[x]) return;
  Vis[x] = 1;
  if(x <= 500) Ans += Mu[x] * (Sum[x][B] - Sum[x][A - 1]);
  else {
    unsigned Tmp;
    Tmp = distance(Apr[x].begin(), upper_bound(Apr[x].begin(), Apr[x].end(), B));
    Tmp -= distance(Apr[x].begin(), upper_bound(Apr[x].begin(), Apr[x].end(), A - 1));
    Ans += Mu[x] * Tmp;
  }
  for (auto i:PrP[x]) Qry(x / i);
}
signed main() {
//  freopen("ex_B2.in", "r", stdin);
//  freopen("B.out", "w", stdout);
  LiSh(100000);
  n = RD(), m = RD();
//  for (unsigned i(1); i <= 100; ++i) {
//    printf("%u Size %u\n", i, PrP[i].size());
//    for (auto j:PrP[i]) printf("%u ", j);
//    putchar(0x0A); 
//  }
  for (unsigned i(1); i <= n; ++i) a[i] = RD(), Mu0(a[i]);
//  for (unsigned i(1); i <= n; ++i) printf("%u ", a[i]);
//  putchar(0x0A);
  for (unsigned i(1); i <= n; ++i) if(a[i] > 500) Ins(i, a[i]), Clr(a[i]);
  for (unsigned i(1); i <= 500; ++i) if(Mu[i])
    for (unsigned j(1); j <= n; ++j) {
      if(!(a[j] % i)) Sum[i][j] = 1;
      Sum[i][j] += Sum[i][j - 1]; 
    }
  for (unsigned i(1); i <= m; ++i)
    A = RD(), B = RD(), C = RD(), Ans = 0, Mu0(C), Qry(C), Clr(C), printf("%u\n", Ans);
  return Wild_Donkey;
}

