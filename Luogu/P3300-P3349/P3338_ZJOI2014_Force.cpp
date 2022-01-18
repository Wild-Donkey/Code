#include <algorithm>
#include <bitset>
#include <cmath>
#include <math.h>
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
#define _USE_MATH_DEFINES
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
const double Pi(acos(-1));
double Ans[100005], q[100005];
unsigned m, n(1);
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
char Inv(0);
struct Cplx {
  double Rel, Img;
  inline Cplx operator+ (const Cplx& x) {
    Cplx Rt(x);
    Rt.Rel += Rel, Rt.Img += Img;
    return Rt;
  }
  inline Cplx operator- (const Cplx& x) {
    Cplx Rt(*this);
    Rt.Rel -= x.Rel, Rt.Img -= x.Img;
    return Rt;
  }
  inline Cplx operator* (const Cplx& x) {
    Cplx Rt;
    Rt.Rel = Rel * x.Rel - Img * x.Img;
    Rt.Img = Rel * x.Img + Img * x.Rel;
    // printf("(%.2lf,%.2lf)*(%.2lf,%.2lf)=(%.2lf,%.2lf)\n", Rel, Img, x.Rel, x.Img, Rt.Rel, Rt.Img);
    return Rt;
  }
  inline Cplx operator/ (const double& x) {
    Cplx Rt(*this);
    Rt.Rel /= x, Rt.Img /= x;
    return Rt;
  }
}a[270000], b[270000];
inline Cplx e(unsigned x, unsigned y) {
  Cplx Rt;
  double Arc(x * 2 * Pi / y);
  Rt.Rel = cos(Arc), Rt.Img = (Inv ? (sin(Arc)) : (-sin(Arc)));
  // printf("%u/%u %lf+%lfi\n", x, y, Rt.Rel, Rt.Img);
  return Rt;
}
inline void DIF(Cplx* f) {
  for (unsigned i(1), j(n >> 1); j; i <<= 1, j >>= 1) {
    // for (unsigned k(0); k < n; ++k) printf("(%.2lf,%.2lf)", a[k].Rel, a[k].Img); putchar(0x0A);
    for (unsigned k(0); k < n; ++k)if (!(k & j)) {
      Cplx Tma(f[k]), Tmb(f[k + j]);
      f[k] = Tma + Tmb;
      f[k + j] = (Tma - Tmb) * e(k, j << 1);
    }
  }
}
inline void DIT(Cplx* f) {
  for (unsigned i(n >> 1), j(1); i; i >>= 1, j <<= 1) {
    for (unsigned k(0); k < n; ++k)if (!(k & j)) {
      Cplx Tma(f[k]), Tmb(f[k + j] * e(k, j << 1));
      f[k] = Tma + Tmb;
      f[k + j] = Tma - Tmb;
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
  m = RD();
  while (n < (m + 1)) n <<= 1; n <<= 1;
  for (unsigned i(1); i <= m; ++i) scanf("%lf", q + i);
  for (unsigned i(1); i <= m; ++i) a[i].Rel = q[i];
  for (unsigned i(1); i <= m; ++i) b[i].Rel = (double)1 / i / i;
  // a[1].Rel = b[0].Rel = 1, a[0].Rel = b[1].Rel = 2;
  Inv = 0, DIF(a), DIF(b);
  for (unsigned i(0); i < n; ++i) a[i] = a[i] * b[i];
  // for (unsigned i(0); i < n; ++i) printf("(%.2lf,%.2lf)", a[i].Rel, a[i].Img); putchar(0x0A);
  Inv = 1, DIT(a);
  for (unsigned i(0); i <= m; ++i) Ans[i] = a[i].Rel / n;
  // for (unsigned i(0); i < n; ++i) printf("%lf ", Ans[i]); putchar(0x0A);
  memset(a, 0, sizeof(a));
  for (unsigned i(0); i <= m; ++i) a[m - i].Rel = q[i];
  Inv = 0, DIF(a);
  for (unsigned i(0); i < n; ++i) a[i] = a[i] * b[i];
  Inv = 1, DIT(a);
  for (unsigned i(0); i <= m; ++i) Ans[i] -= (a[m - i] / n).Rel;
  for (unsigned i(1); i <= m; ++i) printf("%lf\n", Ans[i]);
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
2
2
2

5
4006373.885184
15375036.435759
1717456.469144
8514941.004912
1410681.345880
*/