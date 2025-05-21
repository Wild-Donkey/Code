#include <bits/stdc++.h>
#define Wild_Donkey 0
#define foreplay for
#define wild while
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
unsigned m, n, t;
unsigned long long Ans(0);
unsigned Buck[1000005];
unsigned a[200005], Pre[200005];
unsigned long long b[200005];
unsigned long long f[200005][2];
inline void Clr() {}
signed main() {
  // freopen("color2.in", "r", stdin);
  // freopen("duel.out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    n = RD();
    for (unsigned i(1); i <= n; ++i)
      Pre[i] = Buck[b[i] = a[i] = RD()], Buck[a[i]] = i;
    for (unsigned i(n); i; --i)
      if (b[i] != b[i - 1]) b[i] = 0;
    for (unsigned i(1); i <= n; ++i) b[i] += b[i - 1];
    unsigned long long Mx(0);
    for (unsigned i(1); i <= n; ++i) {
      f[i][1] = Mx;
      if (Pre[i])
        f[i][1] =
            max(f[i][1], f[Pre[i] + 1][1] + a[i] + b[i - 1] - b[Pre[i] + 1]);
      f[i][0] = max(f[i][1], f[i - 1][0] + b[i] - b[i - 1]);
      Mx += b[i] - b[i - 1], Mx = max(f[i][1], Mx);
    }
    printf("%llu\n", f[n][0]);
    for (unsigned i(1); i <= n; ++i) Buck[a[i]] = 0;
  }
  //  system("pause");
  return Wild_Donkey;
}
/*
g++ P11233_CSP2024_Color.cpp -O3
*/