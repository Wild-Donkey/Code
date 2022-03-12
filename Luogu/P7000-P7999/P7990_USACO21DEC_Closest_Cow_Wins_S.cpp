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
pair<unsigned, unsigned long long> Grass[200005];
unsigned long long V[400005], Ans(0);
unsigned Rg[200005][2];
unsigned Cow[200005], b[400005];
unsigned m, n, My;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), My = RD();
  for (unsigned i(1); i <= n; ++i) Grass[i].first = RD() + 1, Grass[i].second = RD();
  for (unsigned i(1); i <= m; ++i) Cow[i] = RD() + 1;
  sort(Grass + 1, Grass + n + 1), sort(Cow + 1, Cow + m + 1);
  Cow[0] = 0, Cow[++m] = 1000000002;
  for (unsigned i(0), j(1); j <= n; ++j) {
    while(Cow[i + 1] < Grass[j].first) ++i;
    V[i + m] += Grass[j].second, Grass[j].second += Grass[j - 1].second;
    unsigned Dis;
    if((i ^ (m - 1)) && ((!i) || (Cow[i + 1] - Grass[j].first < Grass[j].first - Cow[i]))) {
      Rg[j][1] = Cow[i + 1]; 
      Dis = Cow[i + 1] - Grass[j].first;
      Rg[j][0] = (Dis <= Grass[j].first) ? (Grass[j].first - Dis) : 0;
    }
    else {
      Rg[j][0] = Cow[i];
      Dis = Grass[j].first - Cow[i];
      Rg[j][1] = Grass[j].first + Dis;
    }
//    printf("%u: %u (%u, %u)\n", j, Grass[j].first, Rg[j][0], Rg[j][1]);
  }
  for (unsigned i(0), L(0), R(1); R <= n; ++R) {
    while (Grass[R].first > Cow[i + 1]) ++i;
    while (Rg[L + 1][1] <= Rg[R][0]) ++L;
    V[i] = max(V[i], Grass[R].second - Grass[L].second);
  }  
  for (unsigned i(0); i < m; ++i) V[i + m] -= V[i];
  m <<= 1, sort(V, V + m);
//  for (unsigned i(0); i < m; ++i) printf("V %u : %llu\n", i, V[i]);
  unsigned Lim(((My >= m) ? 0 : (m - My)) + 1);
//  printf("To %u\n", Lim);
  for (unsigned i(m); i >= Lim; --i) Ans += V[i - 1];
  printf("%llu\n", Ans);
//  }
//  system("pause");
  return Wild_Donkey;
}

