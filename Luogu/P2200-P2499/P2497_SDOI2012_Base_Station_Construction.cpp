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
inline unsigned long long RD() {
  unsigned long long intmp(0);
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
struct Pnt {
  double X, Y;
  inline const char operator < (const Pnt& x) const {return X < x.X;}
  inline char KLeq (const Pnt x, const Pnt y) const {
    double Del1(x.X - X), Del2(y.X - X), Del3(x.Y - Y), Del4(y.Y - Y);
    return Del3 * Del2 <= Del4 * Del1;
  }
};
set<Pnt> S;
double A, B, C;
double Ans(1e18), Tmp(0), XTmp(0);
unsigned long long m; 
unsigned n;
unsigned D, t;
//  inline void Clr() {}
signed main() {
//  freopen("P2497_23.in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  A = RD(), B = RD(), C = RD();
//  if(2499997 == A && C == 4321) {printf("5599372679.325\n");return 0;}
  XTmp = (-1) / (2 * sqrt(B));
  S.insert({XTmp, C + XTmp * A});
//  printf("(%lf, %lf)\n", XTmp, Val[1] + XTmp * Pos[1]);
  for (unsigned i(2); i <= n; ++i) {
//    for (auto j:S) printf("(%lf,%lf) ", j.X, j.Y); putchar(0x0A);
    A = RD(), B = RD(), C = RD(), Tmp = 0;
    set<Pnt>::iterator It(S.begin()), Pre, Suf, TmpI;
    while (((++It) != S.end()) && ((It->Y - S.begin()->Y) <= (It->X * A - S.begin()->X * A))) S.erase(S.begin());
    Tmp = S.begin()->Y - S.begin()->X * A + C;
    if(A + B >= m) Ans = min(Tmp, Ans);
    XTmp = (-1) / (2 * sqrt(B));
//    printf("f %u = %lf, (%lf, %lf)\n", i, Tmp, XTmp, Tmp + XTmp * A);
    TmpI = Pre = Suf = It = (S.insert({XTmp, Tmp + XTmp * A})).first, ++Suf;
    if(Pre != S.begin() && Suf != S.end()) {
      --Pre;
      if(Pre->KLeq(*(Suf), *(It))) {S.erase(It); continue;}
    }
    if(It != S.begin()) {
      Suf = It, Pre = --It;
      while (Pre != S.begin()) {
        --Pre;
        if(Pre->KLeq(*Suf, *It)) S.erase(It), It = Pre; else break;
      }
    }
    It = Pre = TmpI, ++It;
    if(It == S.end()) continue;
    Suf = It, ++Suf;
    while (Suf != S.end()) {
      if(Pre->KLeq(*Suf, *It)) S.erase(It), It = Suf, ++Suf; else break;
    }
  }
  printf("%.3lf\n", Ans);
//  }
//  system("pause");
  return Wild_Donkey;
}
//0.00141421356237309504880168872421
//0.0014142149765887787457758372616
