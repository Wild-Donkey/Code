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
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#define Wild_Donkey 0
#define foreplay for
#define wild
#define Pi 3.14159265359
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
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt[2005], Ans(0), Tmp(0);
typedef pair<int, int> Point;
Point a[2005];
double Arc[2005];
long long Cross(Point x, Point y) {
  return (long long)x.first * y.second - (long long)x.second * y.first;
}
Point operator-(Point x, Point y) {
  return {x.first - y.first, x.second - y.second};
}
char Up(Point x, Point y, Point z) { return Cross(y - x, z - y) < 0; }
double Pole(Point x) { return atan2(x.first, x.second); }
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), Ans = 1;
  for (unsigned i(1); i <= n; ++i) a[i].first = RDsg(), a[i].second = RDsg();
  sort(a + 1, a + n + 1);
  vector<Point> CurU, CurD;
  CurU.push_back(a[1]);
  CurU.push_back(a[2]);
  for (unsigned i(3); i <= n; ++i) {
    while (CurU.size() >= 2 &&
           !Up(CurU[CurU.size() - 2], CurU[CurU.size() - 1], a[i]))
      CurU.pop_back();
    CurU.push_back(a[i]);
  }
  CurD.push_back(a[1]);
  CurD.push_back(a[2]);
  for (unsigned i(3); i <= n; ++i) {
    while (CurD.size() >= 2 &&
           Up(CurD[CurD.size() - 2], CurD[CurD.size() - 1], a[i]))
      CurD.pop_back();
    CurD.push_back(a[i]);
  }
  vector<Point> Hull(CurD);
  Hull.insert(Hull.end(), CurU.rbegin() + 1, CurU.rend() - 1);
  set<Point> InHull(Hull.begin(), Hull.end());
  for (unsigned i(1); i <= n; ++i)
    if (!(InHull.count(a[i]))) {
      memset(Cnt, 0, (n + 1) << 2);
      m = 0;
      for (auto j : Hull) Arc[m++] = Pole(j - a[i]);
      sort(Arc, Arc + m);
      Arc[m] = Arc[0] + 2 * Pi;
      unsigned Pos;
      for (unsigned j(1); j <= n; ++j)
        if ((j ^ i) && !(InHull.count(a[j]))) {
          Cnt[lower_bound(Arc, Arc + m + 1, Pole(a[j] - a[i])) - Arc]++;
        }
      Cnt[0] += Cnt[m];
      for (unsigned j(0); j < m; ++j) Ans += (Cnt[j] == 0);
    }
  printf("%u\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}