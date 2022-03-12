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
double HallLen(0), Sin(sin(Deg)), Cos(cos(Deg));
unsigned Cnt(0), n(0), Tmp(0);
unsigned Polar[1005][1005], LeToRi[100005];
unsigned Hall[100005], HTop(0), MidRi(0);
pair<double, unsigned> Bucket[100005];
char Used[100005], Flg(0);
inline int dcmp(int x){return (x < 0) ? (-1) : ((x > 0) ? 1 : 0 );}
inline long long Sq(const long long &x) {return x * x;}
inline double Sq(const double &x) {return x * x;}
struct Pnt {
//  long long Hor,Ver;
  double Hor,Ver;
  Pnt operator+(const Pnt &x) {return (Pnt){this->Hor + x.Hor, this->Ver + x.Ver};}
  Pnt operator-(const Pnt &x) {return (Pnt){this->Hor - x.Hor, this->Ver - x.Ver};}
  Pnt operator*(long long x) {return (Pnt){this->Hor * x, this->Ver * x};}
  inline void Rotate() {
    Pnt x(*this);
    this->Hor = x.Hor * Cos + x.Ver * Sin;
    this->Ver = x.Ver * Cos - x.Hor * Sin;
  }
  inline double Kof(const Pnt &x) {return (double)(this->Ver - x.Ver) / (this->Hor - x.Hor);}
  inline double DisSrc() {return sqrt(this->Hor * this->Hor + this->Ver * this->Ver);}
  inline double Len(const Pnt &x) {return sqrt(Sq(this->Hor - x.Hor) + Sq(this->Ver - x.Ver));}
  inline long long Dot(const Pnt &x){ return this->Hor * x.Hor + this->Ver * x.Ver;}
  inline long long Crs(const Pnt &x){ return this->Hor * x.Ver - this->Ver * x.Hor;}
  inline char VA (const Pnt &x, const Pnt &y) { // V is 1, A is 0
    return (this->Ver - x.Ver) * (y.Hor - this->Hor) < (y.Ver - this->Ver) * (this->Hor - x.Hor);
  }
}P[100005];
inline char CmpLTR(const unsigned x, const unsigned y) {return P[x].Hor < P[y].Hor;}
/*inline char meet(Pnt a,Pnt b,Pnt c,Pnt d){
  long long a1(Crs(a-b,a-c)), a2(cross(a-b,a-d)), c1(cross(c-d,c-a)), c2(cross(c-d,c-b));
  return (DisSrc(a1)*dcmp(a2)<0)&&(dcmp(c1)*dcmp(c2)<0);
}*/
signed main() {
//  freopen("P2742_3.in", "r", stdin);
  n = RD();
//  printf("SC %lf %lf\n", Sin, Cos);
//  for (unsigned i(1); i <= n; ++i) P[i].Hor = RDsg(), P[i].Ver = RDsg();
  for (unsigned i(1); i <= n; ++i) scanf("%lf%lf", &P[i].Hor, &P[i].Ver), P[i].Rotate();
//  for (unsigned i(1); i <= n; ++i) printf("(%d, %d)\n", P[i].Hor, P[i].Ver);
//  for (unsigned i(1); i <= n; ++i) {
////    printf("%u:\n", i);
////    for (unsigned j(1); j <= n; ++j) printf("k %u %u is %lf\n", i, j, P[i].Kof(P[j]));
////    for (unsigned j(1); j <= n; ++j) printf("%d / %d is %lf\n", (P[i].Ver - P[j].Ver), (P[i].Hor - P[j].Hor), (double)(P[i].Ver - P[j].Ver) / (P[i].Hor - P[j].Hor));
//    for (unsigned j(1); j <= n; ++j)
//      Bucket[j].first = P[i].Kof(P[j]), Bucket[j].second = j;
//    sort(Bucket + 1, Bucket + n + 1);
//    for (unsigned j(1); j <= n; ++j) Polar[i][j] = Bucket[j].second;
////    for (unsigned j(1); j <= n; ++j) printf("%u ", Polar[i][j]);
////    for (unsigned j(1); j <= n; ++j) printf("%lf ", Bucket[j].first);
////    putchar('\n');
//  }
  for (unsigned i(1); i <= n; ++i) LeToRi[i] = i;
  sort(LeToRi + 1, LeToRi + n + 1, CmpLTR);
  Hall[++HTop] = LeToRi[1], Hall[++HTop] = LeToRi[2];
  Used[LeToRi[1]] = Used[LeToRi[2]] = 1;
//  for (unsigned i(1); i <= n; ++i) printf("%u (%lf, %lf)\n", i, P[i].Hor, P[i].Ver);
//  for (unsigned i(1); i <= n; ++i) printf("%u ", LeToRi[i]); putchar('\n');
  for (unsigned i(3); i <= n; ++i) {
    while ((HTop > 1) && (P[Hall[HTop]].VA(P[Hall[HTop - 1]], P[LeToRi[i]])))
      Used[Hall[HTop]] = 0, --HTop;
    Hall[++HTop] = LeToRi[i], Used[Hall[HTop]] = 1;
  }
  Tmp = n - 1, MidRi = HTop;
  while (Used[LeToRi[MidRi]]) --MidRi;
  Hall[++HTop] = LeToRi[n - 1], Used[LeToRi[n - 1]] = 1, Used[Hall[1]] = 0;
  for (unsigned i(n - 2); i; --i) {
    if(Used[LeToRi[i]]) continue;
    while ((HTop > MidRi) && (!(P[Hall[HTop]].VA(P[LeToRi[i]], P[Hall[HTop - 1]]))))
      --HTop;
    Hall[++HTop] = LeToRi[i];
  }
//  for (unsigned i(1); i <= HTop; ++i) {
//    printf("%u %u\n", i, Hall[i]);
//  }
//  for (unsigned i(1); i < HTop; ++i) printf("%u %lf\n", i, P[Hall[i]].Len(P[Hall[i + 1]]));
  for (unsigned i(1); i < HTop; ++i) HallLen += P[Hall[i]].Len(P[Hall[i + 1]]);
  printf("%.2lf\n", HallLen);
}
