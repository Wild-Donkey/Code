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
unsigned X, Y, m, n;
unsigned A, B, C, D, t;
unsigned long long Ans(0);
int Dir[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                 {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
unordered_map<unsigned, map<unsigned, unsigned> > Row, Col, Main,
    Sub;  //(x, y) in Main[x+y-1](x) in Sub[n - x + y](x)
inline unsigned CalcBor() { return min(min(A - 1, X - A), min(B - 1, Y - B)); }
inline void Insert(unsigned x, unsigned y, unsigned z) {
  if (z) {
    Row[y][x] = z, Col[x][y] = z;
    Main[x + y - 1][x] = z, Sub[X - x + y][x] = z;
    return;
  }
  Row[y].erase(x), Col[x].erase(y);
  Main[x + y - 1].erase(x), Sub[X - x + y].erase(x);
}
inline void Get(map<unsigned, unsigned> &x, unsigned y) {
  auto Here(x.upper_bound(y));
  while (Here != x.end()) {
    if (Here->second) {
      D = min(D, Here->first - y);
      break;
    }
    x.erase(Here);
    Here = x.upper_bound(y);
  }
  Here = x.lower_bound(y);
  while (Here != x.begin()) {
    --Here;
    if (Here->second) {
      D = min(D, y - Here->first);
      return;
    }
    x.erase(Here);
    Here = x.lower_bound(y);
  }
}
inline unsigned GetPer(unsigned x, unsigned y) { return Col[x][y]; }
inline void Rotate(unsigned x, unsigned y, unsigned d, unsigned Omega) {
  if (!d) return;
  unsigned Pos[8][2], Tmp[8];
  for (unsigned i(0); i < 8; ++i)
    Pos[i][0] = x + d * Dir[i][0], Pos[i][1] = y + d * Dir[i][1];
  for (unsigned i(0), j(8 - Omega); i < 8; ++i, j = ((j + 1) & 7))
    Tmp[i] = GetPer(Pos[j][0], Pos[j][1]);
  for (unsigned i(0); i < 8; ++i) Insert(Pos[i][0], Pos[i][1], Tmp[i]);
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  X = RD(), Y = RD(), n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) A = RD(), B = RD(), Insert(A, B, i);
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD(), C = RD(), D = 0x3f3f3f3f;
    Get(Row[B], A), Get(Col[A], B);
    Get(Main[A + B - 1], A), Get(Sub[X - A + B], A);
    if (D <= CalcBor()) Rotate(A, B, D, C);
  }
  for (auto i : Row)
    for (auto j : i.second)
      if (j.second) Ans ^= (unsigned long long)j.second * j.first + i.first;
  printf("%llu\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*

*/