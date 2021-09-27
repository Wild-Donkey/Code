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
const double Deg(1.7);
double Sin(sin(Deg)), Cos(cos(Deg));
unsigned Cnt(0), n(0), Tmp(0), N, Ans(0);
unsigned Polar[2005], Acros;
unsigned Dif[2005], Sum[2005];
unsigned f[1005][1005], g[1005][1005];
pair<double, unsigned> Bucket[1005], TmpFind;
char Used[1005], Flg(0);
inline int dcmp(int x) { return (x < 0) ? (-1) : ((x > 0) ? 1 : 0); }
inline long long Sq(const long long& x) { return x * x; }
inline double Sq(const double& x) { return x * x; }
inline unsigned Calcf(const unsigned &x) {return x * (n - x - 2);}
inline unsigned C2(const unsigned &x) {return (x * (x - 1)) >> 1;}
struct Pnt {
  long long Hor, Ver;
  Pnt() {}
  Pnt(const long long& x, const long long& y) { Hor = x, Ver = y; }
  Pnt operator+(const Pnt& x) const { return (Pnt) { Hor + x.Hor, Ver + x.Ver }; }
  Pnt operator-(const Pnt& x) const { return (Pnt) { Hor - x.Hor, Ver - x.Ver }; }
  Pnt operator*(long long x) { return (Pnt) { Hor* x, this->Ver* x }; }
  inline void Rotate() {
    Pnt x(*this);
    this->Hor = x.Hor * Cos + x.Ver * Sin, Ver = x.Ver * Cos - x.Hor * Sin;
  }
  inline double Arct(const Pnt& x) { return atan2(x.Ver - Ver, x.Hor - Hor); }
  inline double Kof(const Pnt& x) { return (double)(Ver - x.Ver) / (Hor - x.Hor); }
  inline double DisSrc() { return sqrt(Hor * Hor + Ver * Ver); }
  inline double Len(const Pnt& x) { return sqrt(Sq(Hor - x.Hor) + Sq(Ver - x.Ver)); }
  inline long long Dot(const Pnt& x) { return Hor * x.Hor + Ver * x.Ver; }
  inline long long Crs(const Pnt& x) { return Hor * x.Ver - Ver * x.Hor; }
  inline char VA(const Pnt& x, const Pnt& y) { // V is 1, A is 0
    return (Ver - x.Ver) * (y.Hor - Hor) < (y.Ver - Ver) * (Hor - x.Hor);
  }
}P[1005];
struct Seg {
  Pnt* Fst, * Scd;
  Seg() {}
  Seg(Pnt* x, Pnt* y) { Fst = x, Scd = y; }
  inline double Len() { return this->Fst->Len(*Scd); }
  inline double Kof() { return this->Fst->Kof(*Scd); }
  inline char Pos(const Pnt& x) { return ((*(this->Scd) - *(this->Fst)).Crs(x - *(this->Fst)) < 0); }
  inline char Pos(Pnt* x) { return Pos(*x); }
}S[3005];
struct Trang {
  Pnt* Fst, * Scd, * Trd;
  Trang() {}
  Trang(Pnt* x, Pnt* y, Pnt* z) { Fst = x, Scd = y, Trd = z; }
  inline char In(const Pnt& x) { return Seg(Fst, Scd).Pos(x) | Seg(Scd, Trd).Pos(x) | Seg(Trd, Fst).Pos(x); }
}T[3005];
inline char CmpLTR(const unsigned x, const unsigned y) { return P[x].Hor < P[y].Hor; }
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
//    for (unsigned j(1); j < n; ++j) printf("%u ", Polar[j]);
//    for (unsigned j(1); j < n; ++j) printf("%lf ", Bucket[j].first);
//    putchar('\n');
    for (unsigned j(1); j < n; ++j)
      f[i][Polar[j]] = Calcf(Dif[j]); //Calc f
    for (unsigned j(2); j < n; ++j) {//Calc g
      unsigned Cur(((j - 1) > Dif[j - 1]) ? (j - 1) : (j + n - 2)), Lst(Cur - Dif[j - 1]);
      g[i][Polar[j]] = Sum[Cur] - Sum[Lst - 1] - C2(Dif[j]);
    }
    printf("Pol[%u]:\n", i);
    for (unsigned j(1); j < n; ++j) printf("%u ", Polar[j]);
    printf("\nSum[%u]:\n", i);
    for (unsigned j(1); j < N; ++j) printf("%u ", Sum[j]);
    printf("\nDif[%u]:\n", i);
    for (unsigned j(1); j < n; ++j) printf("%u ", Dif[j]);
    printf("\nf[%u]:\n", i);
    for (unsigned j(1); j <= n; ++j) printf("%u ", f[i][j]);
    printf("\ng[%u]:\n", i);
    for (unsigned j(1); j <= n; ++j) printf("%u ", g[i][j]);
    putchar('\n');
  }
  for (unsigned i(2); i <= n; ++i)
    for (unsigned j(1); j < i; ++j)
      if(f[i][j] == g[i][j] + g[j][i]) ++Ans; 
  printf("%u\n", Ans);
  return 0;
}
