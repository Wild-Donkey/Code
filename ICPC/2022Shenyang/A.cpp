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
pair<int, int> a[100005], b[100005];
unsigned m, n;
unsigned long long Lenm, Lenn;
double Over(unsigned x) { return ((double)x * x * x) / 3.0; }
double PntCalc(unsigned X, unsigned Y, pair<int, int> *x, pair<int, int> *y) {
  double Rt(0);
  unsigned long long Sum(0);
  y[Y + 1] = {0x3f3f3f3f, 0x3f3f3f3f};
  for (unsigned long long i(1), j(1); i <= X; ++i) {
    Sum += (j - 1) * (x[i].first - x[i - 1].first);
    while (y[j].first <= x[i].first) Sum += x[i].first - y[j].first, ++j;
    Rt += Sum;
  }
  return Rt;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) a[i].first = RDsg(), a[i].second = RDsg();
  for (unsigned i(1); i <= m; ++i) b[i].first = RDsg(), b[i].second = RDsg();
  sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);
  for (unsigned i(1); i <= n; ++i) Lenn += (a[i].second - a[i].first);
  for (unsigned i(1); i <= m; ++i) Lenm += (b[i].second - b[i].first);
  if (Lenn == 0 && Lenm == 0) {
    printf("%.10lf\n", (PntCalc(n, m, a, b) + PntCalc(m, n, b, a)) / n / m);
    return 0;
  }
  if (Lenn == 0 || Lenm == 0) {
    if (Lenm == 0) {
      swap(n, m);
      for (unsigned i(max(n, m)); i; --i) swap(a[i], b[i]);
    }
    for (unsigned i(1), j(1); i <= n; ++i) {
      unsigned long long Cnt(0);
      while (b[j].second < a[i].first) {}
    }
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}