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
unsigned Cnt(0), n(0), Tmp(0), N, Ans(0);
unsigned Polar[2005], Acros;
unsigned Dif[2005], Sum[2005];
unsigned f[1005][1005], g[1005][1005];
pair<double, unsigned> Bucket[1005], TmpFind;
char Flg(0);
inline unsigned Calcf(const unsigned &x) {return x * (n - x - 2);}
inline unsigned C2(const unsigned &x) {return (x * (x - 1)) >> 1;}
struct Pnt {
  long long Hor, Ver;
  inline double Arct(const Pnt& x) { return atan2(x.Ver - Ver, x.Hor - Hor); }
}P[1005];
signed main() {
  //  freopen("P2742_3.in", "r", stdin);
  N = ((n = RD()) << 1) - 1;
  for (unsigned i(1); i <= n; ++i) P[i].Hor = RDsg(), P[i].Ver = RDsg();
  for (unsigned i(1); i <= n; ++i) {
    Cnt = 0;
    for (unsigned j(1); j <= n; ++j) if(j ^ i)
      Bucket[++Cnt].first = P[i].Arct(P[j]), Bucket[Cnt].second = j;
    sort(Bucket + 1, Bucket + n), Cnt = 0;
    for (unsigned j(1); j <= n; ++j) if (Bucket[j].second)
      Polar[++Cnt] = Bucket[j].second;
    for (unsigned j(1); j < n; ++j) {//Calc Dif
      unsigned Cur(Polar[j]);
      TmpFind = make_pair(P[Cur].Arct(P[i]), 0);
      Acros = lower_bound(Bucket + 1, Bucket + n, TmpFind) - Bucket;
      Dif[j] = (Acros > j) ? (n + j - 1 - Acros) : (j - Acros);
    }
    for (unsigned j(1); j < n; ++j) Polar[j + n - 1] = Polar[j];
    for (unsigned j(1); j < n; ++j) Dif[j + n - 1] = Dif[j];
    for (unsigned j(1); j < N; ++j) Sum[j] = Dif[j] + Sum[j - 1];
    for (unsigned j(1); j < n; ++j) f[i][Polar[j]] = Calcf(Dif[j]); //Calc f
    for (unsigned j(1); j < n; ++j) { //Calc g
      unsigned Cur((j > Dif[j]) ? j : (j + n - 1)), Lst(Cur - Dif[j]);
      g[i][Polar[j]] = Sum[Cur - 1] - Sum[Lst - 1] - C2(Dif[j]);
    }
  }
  for (unsigned i(2); i <= n; ++i) for (unsigned j(1); j < i; ++j)
    if(f[i][j] == g[i][j] + g[j][i]) ++Ans; 
  printf("%u\n", Ans);
  return 0;
}
