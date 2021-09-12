#include <algorithm>
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
unsigned n(1);
unsigned A, B, C, D, t;
unsigned long long Ans(0), Tmp(0);
unsigned F1[100005], F2[100005], g1[100005], g2[100005];
char aP[100005], * a(aP);
void Manacher(unsigned* f1, unsigned* f2) {
  Tmp = 0;
  for (unsigned k(1), Ri(0), l, m(0); k <= n; ++k) {
    if (k >= Ri) l = 1;
    else l = min(Ri - k + 1, f1[(m << 1) - k]);
    while (a[k + l] == a[k - l]) ++l;
    f1[k] = l;
    if (k + l > Ri) Ri = k + l - 1, m = k;
  }
  // for (unsigned k(1); k <= n; ++k) printf("%u %u\n", k, f1[k]);
  for (unsigned k(2), Ri(0), l, m(0); k <= n; ++k) {
    if (k >= Ri) l = 0;
    else l = min(Ri - k, f2[(m << 1) - k - 1]);
    while (a[k + l] == a[k - l - 1]) ++l;
    f2[k] = l;
    if (k + l > Ri) Ri = k + l - 1, m = k;
  }
  // for (unsigned k(1); k <= n; ++k) printf("%u %u\n", k, f2[k]);
  for (unsigned k(1); k <= n; ++k) Tmp += f1[k] + f2[k];
  Ans = max(Ans, Tmp);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  fread(a + 1, 1, 100002, stdin);
  while (a[1] < 'a') ++a;
  while (a[n] >= 'a') ++n;
  a[0] = 'A', --n;
  Manacher(F1, F2);
  for (unsigned i(1); i <= n; ++i) {
    // printf("%llu\n", Ans);
    if ((i - F1[i] > 0) && (i + F1[i] <= n)) {
      char TmpC(a[i - F1[i]]);
      // printf("Let %u To %u");
      a[i - F1[i]] = a[i + F1[i]], Manacher(g1, g2), a[i - F1[i]] = TmpC;
      TmpC = a[i + F1[i]];
      a[i + F1[i]] = a[i - F1[i]], Manacher(g1, g2), a[i + F1[i]] = TmpC;
    }
    if ((i - F2[i] - 1 > 0) && (i + F2[i] <= n)) {
      char TmpC(a[i - F2[i] - 1]);
      a[i - F2[i] - 1] = a[i + F2[i]], Manacher(g1, g2), a[i - F2[i] - 1] = TmpC;
      TmpC = a[i + F2[i]];
      a[i + F2[i]] = a[i - F2[i] - 1], Manacher(g1, g2), a[i + F2[i]] = TmpC;
    }
  }
  printf("%llu\n", Ans);
  //  }
  // system("pause");
  return Wild_Donkey;
}