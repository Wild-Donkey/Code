#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned Addre[2000005], B[2000005], m, n, Cnt(0), t, Tmp(0);
unsigned long long Ans;
struct Pnt {
  unsigned a, b;
  inline const char operator<(const Pnt &x) const{
    return this->a < x.a; 
  }
}P[2000005];
inline void Clr() {
  n = RD(), Ans = 0;
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned T(1); T <= t; ++T){
    Clr();
    for (register unsigned i(1); i <= n; ++i) {
      P[i].a = RDsg() + 1000001, P[i].b = B[i] = RD();
    }
    sort(P + 1, P + n + 1);
    sort(B + 1, B + n + 1);
    for (register unsigned i(1); i <= n; ++i) {
      P[i].b = lower_bound(B + 1, B + n + 1, P[i].b) - B;
    }
    for (register unsigned i(1), j(0); i <= n; ++i) {
      if(j > P[i].b) {
//        printf("%u %u %u %u\n", i, j, P[i].b, Addre[P[i].b]);
        Ans = max(Ans, (unsigned long long)(P[i].a - P[Addre[P[i].b]].a) * B[P[i].b]);
      } else {
        while (j <= P[i].b) {
          Addre[j++] = i;
        }
      }
    }
//    printf("%u\n", Ans);
    for (register unsigned i(n), j(0); i; --i) {
      if(j > P[i].b) {
        Ans = max(Ans, (unsigned long long)(P[Addre[P[i].b]].a - P[i].a) * B[P[i].b]);
      } else {
        while (j <= P[i].b) {
          Addre[j++] = i;
        }
      }
    }
    printf("%llu\n", Ans);
  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
1
3
-10 4
-5 10
-20 -2
*/
