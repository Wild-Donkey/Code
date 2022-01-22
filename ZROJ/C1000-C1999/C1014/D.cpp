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
const unsigned long long Mod(998244353);
const double Tin(0.0000001), Si(sin(0.2)), Cs(cos(0.2));
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned long long Val[1005];
char Flg(0);
struct Pnt {
  double Px, Py;
  double Dist (Pnt x) {
    double Delx(Px - x.Px), Dely(Py - x.Py);
    return sqrt(Delx * Delx + Dely * Dely);
  }
  inline void Rotate() {
    Pnt x(*this);
    Px = x.Px * Cs + x.Py * Si;
    Py = x.Py * Cs - x.Px * Si;
  }
  double Kw(Pnt x) {return (Py - x.Py) / (Px - x.Px);}
}Ps[105];
struct Line {
  double b, K;
  Line(Pnt x, Pnt y) {
    K = -1 / x.Kw(y), b = ((x.Py + y.Py) / 2) - (K * ((x.Px + y.Px) / 2));
    printf("(%lf, %lf) (%lf, %lf) y = %lf x + %lf\n", x.Px, x.Py, y.Px, y.Py, K, b);
  }
  inline Pnt Crs(Line x) {
    Pnt TmCr;
    TmCr.Px = (x.b - b) / (K - x.K);
    TmCr.Py = K * TmCr.Px + b;
    return TmCr;
  }
};
struct Cir {
  Pnt Cen;
  double R;
  Cir(Pnt P1, Pnt P2, Pnt P3) {
    printf("(%lf, %lf)(%lf, %lf)(%lf, %lf)\n", P1.Px, P1.Py, P2.Px, P2.Py, P3.Px, P3.Py);
    Line L1(P1, P2), L2(P2, P3);
    Cen = L1.Crs(L2);
    R = Cen.Dist(P1);
    printf("Cen(%lf, %lf) R %lf\n", Cen.Px, Cen.Py, R);
  }
  Cir(Pnt P1, Pnt P2) {
    Cen.Px = (P1.Px + P2.Px) / 2;
    Cen.Py = (P1.Py + P2.Py) / 2;
    R = P1.Dist(P2) / 2;
  }
  inline char InR (Pnt x) {return Cen.Dist(x) < (R - Tin);}
  inline char On(Pnt x) {return ((R - Tin) < Cen.Dist(x)) && (Cen.Dist(x) < (R + Tin));}
};
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) scanf("%lf%lf", &Ps[i].Px, &Ps[i].Py), Ps[i].Rotate();
  for (unsigned i(1); i <= n; ++i) {Ans += (Val[i] = RD()); if(Ans >= Mod) Ans -= Mod;}
  for (unsigned i(n - 2); i; --i) {
    for (unsigned j(i + 1); j < n; ++j) {
      for (unsigned k(j + 1); k <= n; ++k) {
        Cir Cur(Ps[i], Ps[j], Ps[k]);
        unsigned long long CVa((Val[i] * Val[j] % Mod) * Val[k] % Mod);
        for (unsigned l(1); l <= n; ++l) {
          if((l ^ i) && (l ^ j) && (l ^ k)) {
            if(Cur.InR(Ps[l])) CVa = CVa * Val[l] % Mod;
          }
        }
        Ans += CVa;
        if(Ans >= Mod) Ans -= Mod;
      }
    }
  }
  for (unsigned i(1); i < n; ++i) {
    for (unsigned j(i + 1); j <= n; ++j) {
      Cir Cur(Ps[i], Ps[j]);
      unsigned long long CVa(Val[i] * Val[j] % Mod);
      Flg = 0;
      for (unsigned k(1); k <= n; ++k) {
        if(Cur.On(Ps[k])) {Flg = 1;break;}
        if(Cur.InR(Ps[k])) {CVa = CVa * Val[k] % Mod; break;}
      }
      if(Flg) continue;
      Ans += CVa;
      if(Ans >= Mod) Ans -= Mod;
    }
  }
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}

