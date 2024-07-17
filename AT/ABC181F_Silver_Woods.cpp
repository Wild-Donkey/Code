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
pair<double, double> a[105];
unsigned Fa[105], Stack[105], *Top(Stack);
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned Find(unsigned x) {
  while (x ^ Fa[x]) *(++Top) = x, x = Fa[x];
  while (Top > Stack) Fa[*(Top--)] = x;
  return x;
}
double Sq(double x) { return x * x; }
double DisQ(unsigned x, unsigned y) {
  return Sq(a[x].first - a[y].first) + Sq(a[x].second - a[y].second);
}
void Merge(unsigned x, unsigned y) { x = Find(x), y = Find(y), Fa[x] = y; }
char Judge(double x) {
  for (unsigned i(n + 1); ~i; --i) Fa[i] = i;
  for (unsigned i(1); i <= n; ++i) {
    if (a[i].second + 100 < x) Merge(0, i);
    if (100 - a[i].second < x) Merge(n + 1, i);
  }
  x = x * x;
  for (unsigned i(1); i < n; ++i) {
    for (unsigned j(i + 1); j <= n; ++j)
      if (DisQ(i, j) < x) Merge(i, j);
  }
  return Find(0) == Find(n + 1);
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) a[i].first = RDsg(), a[i].second = RDsg();
  double L(0), R(200), Mid;
  while (R - L > 0.00001) {
    Mid = ((R + L) / 2);
    if (Judge(Mid))
      R = Mid;
    else
      L = Mid;
  }
  printf("%lf\n", L / 2);
  //  }
  //  system("pause");
  return Wild_Donkey;
}