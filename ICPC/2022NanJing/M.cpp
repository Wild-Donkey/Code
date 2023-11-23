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
const double Ep(0.00000001);
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
typedef pair<int, int> Pnt;
struct Seg {
  Pnt L, R;
  inline void Init(Pnt x, Pnt y) {
    if (x.first > y.first)
      R = x, L = y;
    else
      L = x, R = y;
  }
  inline double Find(int x) {
    if (L.first == R.first) return 0x7f7f7f7f;
    if (x <= L.first || x > R.first) return 0x7f7f7f7f;
    if (x == R.first) return R.second;
    double K((double)(R.second - L.second) / (R.first - L.first));
    return L.second + (x - L.first) * K;
  }
} S[2005];
unsigned Fa[2005];
char Done[2005];
Pnt P[2005];
inline unsigned Find(unsigned x) {
  if (Fa[x] == x) return x;
  return Fa[x] = Find(Fa[x]);
}
unsigned m, n;
inline unsigned GL(unsigned x) { return (x - 1 > 0) ? x - 1 : n; }
inline unsigned GN(unsigned x) { return (x + 1 <= n) ? x + 1 : 1; }
inline void Udt(unsigned x, unsigned y) {
  Fa[x] = Find(y), Done[x] = 1;
  unsigned Cur(GL(x));
  int Lst(P[x].second);
  while (P[Cur].second >= Lst && !Done[Cur])
    Udt(Cur, y), Lst = P[Cur].second, Cur = GL(Cur);
  Cur = GN(x), Lst = P[x].second;
  while (P[Cur].second >= Lst && !Done[Cur])
    Udt(Cur, y), Lst = P[Cur].second, Cur = GN(Cur);
}
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Corner(unsigned x) {
  unsigned Layer(0);
  for (unsigned j(1); j <= n; ++j)
    Layer += (S[j].Find(P[x].first) < P[x].second - Ep);
  Done[x] = 1;
  if (!(Layer & 1)) ++Ans, Udt(x, x);
}
unsigned A, B, C, D, t;
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) {
    A = RDsg(), B = RDsg();
    P[i] = {A, B}, Fa[i] = i;
  }
  P[0] = P[n], P[n + 1] = P[1];
  for (unsigned i(1); i <= n; ++i) S[i].Init(P[i - 1], P[i]);
  for (unsigned i(1); i <= n; ++i)
    if (!Done[i]) {
      unsigned Ls(GL(i)), Nx(GN(i));
      if (P[Ls].second < P[i].second) {
        Udt(i, Ls);
        continue;
      }
      if (P[Nx].second < P[i].second) {
        Udt(i, Nx);
        continue;
      }
      if (P[Nx].second > P[i].second && P[Ls].second > P[i].second) {
        Corner(i);
        continue;
      }
    }
  do {
    unsigned Low(0);
    int Lowe(10000000);
    for (unsigned i(1); i <= n; ++i)
      if (!Done[i])
        if ((!(P[i].second == P[i - 1].second &&
               P[i].second == P[i + 1].second)) &&
            P[i].second < Lowe)
          Low = i, Lowe = P[i].second;
    if (!Low) break;
    Corner(Low);
  } while (1);
  printf("%u\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}