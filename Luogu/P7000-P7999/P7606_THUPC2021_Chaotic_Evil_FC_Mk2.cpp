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
unsigned a[105][3][2][2], m, n, Des[2], Lim;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0);
char Flg(0);
struct Node {
  unsigned L, G;
  Node Go(unsigned Dire, unsigned FB) {
    Node New(*this);
    New.L += a[A][Dire][FB][0];
    New.G += a[A][Dire][FB][1];
    if (New.L >= Lim) New.L -= Lim;
    if (New.G >= Lim) New.G -= Lim;
    // printf("Do %u:(%u, %u) %u %u\n", A, Dire, FB, New.L, New.G);
    return New;
  }
  const inline char operator <(const Node& x) const {
    return (L ^ x.L) ? (L < x.L) : (G < x.G);
  }
  inline void Print(unsigned x) { printf("%u: %u %u\n", x, L, G); }
}Tmp;
set<Node> f[2][105][105];
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), Lim = RD();
  for (unsigned i(1); i <= n; ++i) {
    a[i][2][1][0] = RD();
    a[i][2][1][1] = RD();
    a[i][1][1][0] = RD();
    a[i][1][1][1] = RD();
    a[i][0][1][0] = RD();
    a[i][0][1][1] = RD();
    a[i][0][0][0] = RD();
    a[i][0][0][1] = RD();
    a[i][1][0][0] = RD();
    a[i][1][0][1] = RD();
    a[i][2][0][0] = RD();
    a[i][2][0][1] = RD();
  }
  Des[0] = RD(), Des[1] = RD(), f[0][50][50].insert((Node) { 0, 0 });
  for (A = 1; A <= n; ++A) {
    for (unsigned i(0); i <= 100; ++i) for (unsigned j(0); j <= 100; ++j) f[A & 1][i][j].clear();
    for (auto k : f[(A & 1) ^ 1][0][0]) {
      f[A & 1][1][1].insert(k.Go(0, 0));
      f[A & 1][1][0].insert(k.Go(1, 0));
      f[A & 1][0][1].insert(k.Go(2, 1));
    }
    for (unsigned j(1); j <= 100; ++j) {
      for (auto k : f[(A & 1) ^ 1][0][j]) {
        f[A & 1][1][j + 1].insert(k.Go(0, 0));
        f[A & 1][1][j].insert(k.Go(1, 0));
        f[A & 1][0][j - 1].insert(k.Go(2, 0));
        f[A & 1][0][j + 1].insert(k.Go(2, 1));
      }
    }
    for (unsigned i(1); i <= 100; ++i) {
      for (unsigned j(1); j <= 100; ++j) {
        for (auto k : f[(A & 1) ^ 1][i][j]) {
          f[A & 1][i + 1][j + 1].insert(k.Go(0, 0));
          f[A & 1][i - 1][j - 1].insert(k.Go(0, 1));
          f[A & 1][i + 1][j].insert(k.Go(1, 0));
          f[A & 1][i - 1][j].insert(k.Go(1, 1));
          f[A & 1][i][j - 1].insert(k.Go(2, 0));
          f[A & 1][i][j + 1].insert(k.Go(2, 1));
        }
      }
    }
  }
  for (auto j : f[n & 1][50][50]) if (j.L == Des[0] && j.G == Des[1]) { Flg = 1; break; }
  printf(Flg ? "Chaotic Evil\n" : "Not a true problem setter\n");
  //  }
  return Wild_Donkey;
}