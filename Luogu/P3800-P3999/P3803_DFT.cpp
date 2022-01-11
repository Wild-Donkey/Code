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
#define Pi 3.141592653589793238462643383279502884197169399
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
double Cp[2100000][2];
unsigned m, n, nn, Lgn(0);
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(1);
char Inv(0);
struct Cplx {
  double Rel, Img;
  inline Cplx() {}
  inline Cplx(unsigned x) {
    Rel = Cp[x][0]; Img = Inv ? Cp[x][1] : -Cp[x][1];
  }
  inline Cplx operator + (const Cplx& x) {
    Cplx Rt(x);
    Rt.Rel += Rel, Rt.Img += Img;
    return Rt;
  }
  inline Cplx operator + (const double& x) {
    Cplx Rt(*this);
    Rt.Rel += x, Rt.Img;
    return Rt;
  }
  inline Cplx operator - (const Cplx& x) {
    Cplx Rt(x);
    Rt.Rel = Rel - Rt.Rel, Rt.Img = Img - Rt.Img;
    return Rt;
  }
  inline Cplx operator - (const double& x) {
    Cplx Rt(*this);
    Rt.Rel -= x, Rt.Img;
    return Rt;
  }
  inline Cplx operator * (const Cplx& x) {
    Cplx Rt;
    Rt.Rel = Rel * x.Rel - Img * x.Img, Rt.Img = Img * x.Rel + Rel * x.Img;
    return Rt;
  }
  inline Cplx operator * (const double& x) {
    Cplx Rt(*this);
    Rt.Rel *= x, Rt.Img *= x;
    return Rt;
  }
  inline Cplx operator / (const Cplx& x) {
    Cplx Rt;
    double TmpDe(x.Rel * x.Rel + x.Img * x.Img);
    Rt.Rel = (Rel * x.Rel + Img * x.Img) / TmpDe;
    Rt.Img = (Img * x.Rel - Rel * x.Img) / TmpDe;
    return Rt;
  }
  inline Cplx operator / (const double& x) {
    Cplx Rt(*this);
    Rt.Rel /= x, Rt.Img /= x;
    return Rt;
  }
}a[2100000], b[2100000];
inline void DIT(Cplx* f) {
  for (unsigned i(Lgn), j(1); i; --i, j <<= 1) {
    // printf("Layer%u:\n", i);
    for (unsigned k(0); k < n; ++k) if (!(k & j)) {
      Cplx Tma(f[k]), Tmb(f[k + j]), W(Cplx((k & ((j << 1) - 1)) << (i - 1)) * Tmb);
      f[k] = Tma + W;
      f[k + j] = Tma - W;
    }
  }
}
inline void DIF(Cplx* f) {
  for (unsigned i(1), j(n >> 1); i <= Lgn; ++i, j >>= 1) {
    // printf("Layer%u:\n", i);
    for (unsigned k(0); k < n; ++k) if (!(k & j)) {
      Cplx Tma(f[k]), Tmb(f[k + j]);
      f[k] = Tma + Tmb;
      f[k + j] = (Tma - Tmb) * Cplx((k & (j - 1)) << (i - 1));
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
  nn = RD() + 1, m = RD() + 1, n = nn + m - 1;
  while (Tmp < n) Tmp <<= 1, ++Lgn; n = Tmp;
  // printf("%u %u %u\n", nn, m, n);
  for (unsigned i(0); i <= n; ++i) {
    double Arc(Pi * 2 * i / n);
    Cp[i][0] = cos(Arc), Cp[i][1] = sin(Arc);
  }
  // for (unsigned i(0); i < n; ++i) printf("%u ", Rev[i]);putchar(0x0A);
  for (unsigned i(0); i < nn; ++i) a[i].Rel = RD();
  for (unsigned i(0); i < m; ++i) b[i].Rel = RD();
  DIF(a), DIF(b);
  // printf("DFT A:\n");
  // for (unsigned i(0); i < n; ++i) printf("%u %lf + %lfi\n", i, a[i].Rel, a[i].Img);
  // printf("DFT B:\n");
  // for (unsigned i(0); i < n; ++i) printf("%u %lf + %lfi\n", i, b[i].Rel, b[i].Img);
  for (unsigned i(0); i < n; ++i) a[i] = a[i] * b[i];
  // for (unsigned i(0); i < n; ++i) a[i] = b[Rev[i]];
  // printf("DFT A * DFT B:\n");
  // for (unsigned i(0); i < n; ++i) printf("%u %lf + %lfi\n", i, a[i].Rel, a[i].Img);
  // for (unsigned i((n >> 1) - 1); i; --i) swap(a[i], a[n - i]);
  // printf("DFT A * DFT B:\n");
  // for (unsigned i(0); i < n; ++i) printf("%u %lf + %lfi\n", i, a[i].Rel, a[i].Img);
  Inv = 1, DIT(a);
  for (unsigned i(0); i < n; ++i) a[i] = a[i] / n;
  // printf("A * B:\n");
  // for (unsigned i(0); i < n; ++i) printf("%u %lf + %lfi\n", i, a[i].Rel, a[i].Img);
  for (unsigned i(0); i < m + nn - 1; ++i) printf("%u ", (unsigned)(a[i].Rel + 0.5));putchar(0x0A);
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
1 1
2 1
1 2

2,1
3,0 1,-2 -1,0 1,2
4,0 0,-2 0,0 0,2

7 0
2 5 7 4 4 3 2 6
0
2,5,7,4,4,3,2,6
2 4 7 2 5 3 4 6
*/