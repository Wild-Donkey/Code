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
unsigned long long b[202], Ans;
unsigned ECnt(0), m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
struct Trian {
  unsigned long long Beg, Dir, Low;
  inline const char operator < (const Trian& x) const {  return (Low ^ (x.Low)) ? (Low < x.Low) : (Beg < x.Beg);  }
}a[12];
struct Edit {
  unsigned long long Pos;
  char Ty;
  inline const char operator < (const Edit& x) const {  return (Pos ^ x.Pos) ? (Pos < x.Pos) : (Ty > x.Ty);  }
}E[22];
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) 
    b[++Cnt] = a[i].Beg = RD(), a[i].Low = RD(), b[++Cnt] = a[i].Beg + (a[i].Dir = RD());
  sort(a + 1, a + n + 1);
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(i + 1); j <= n; ++j) if(a[j].Low < a[i].Low + a[i].Dir) {
      unsigned long long Cur(a[i].Beg + a[i].Dir - (a[j].Low - a[i].Low));
      if(a[j].Beg < Cur && a[j].Beg + a[j].Dir > Cur) b[++Cnt] = Cur;
    }
  }
  sort(b + 1, b + Cnt + 1), Cnt = unique(b + 1, b + Cnt + 1) - b - 1;
//  for (unsigned i(1); i <= Cnt; ++i) printf("%llu ", b[i]); putchar(0x0A);
  for (unsigned i(1); i < Cnt; ++i) {
    ECnt = 0;
//    printf("Still %u Trigs [%llu, %llu)\n", n, b[i], b[i + 1]);
    for (unsigned j(1); j <= n; ++j) if (a[j].Beg == b[i]) {
      E[++ECnt] = {a[j].Low, 0};
      E[++ECnt] = {a[j].Low + a[j].Dir, 1};
      if(b[i + 1] == a[j].Beg + a[j].Dir) swap(a[j], a[n]), --j, --n;
      else a[j].Beg = b[i + 1], a[j].Dir -= b[i + 1] - b[i];
    }
    sort(E + 1, E + ECnt + 1);
    for (unsigned j(1), k(0); j < ECnt; ++j) {
//      printf("Pos %llu Type %u To Pos %llu Type %u\n", E[j].Pos, E[j].Ty, E[j + 1].Pos, E[j + 1].Ty);
      k ^= 1;
      if(k) {
//        printf("Ans %llu -> ", Ans);
        Ans += (((E[j + 1].Pos - E[j].Pos) * (b[i + 1] - b[i])) << 1);
        if(E[j].Ty ^ E[j + 1].Ty) {
          if(E[j].Ty) Ans += (b[i + 1] - b[i]) * (b[i + 1] - b[i]);
          else Ans -= (b[i + 1] - b[i]) * (b[i + 1] - b[i]);
        }
//        printf("%llu\n", Ans);
      }
    }
  }
  printf("%.1lf\n", (double)Ans / 2);
//  }
//  system("pause");
  return Wild_Donkey;
}

