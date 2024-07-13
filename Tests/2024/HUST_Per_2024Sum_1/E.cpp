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
char Map[2005][2005];
unsigned Dis[2005][2005];
unsigned m, n, k, Hd(0), Tl(0);
unsigned Que[4000005][2];
unsigned f[10005];
char Itmp[2005];
unsigned Sx, Sy;
unsigned A, B, C, D, t;
unsigned Ans(0), Tmp(0);
struct Gdd {
  unsigned v, r, x, y, Dist;
  void In() {
    v = RD();
    r = RD() - 1;
    x = RD();
    y = RD();
    Dist = Dis[x][y];
  }
  const char operator< (const Gdd& x) const { return r + Dist < x.r + x.Dist; }
}G[2005];
void Go(unsigned x, unsigned y, unsigned Dist) {
  if (Map[x][y] && (Dis[x][y] > Dist + 1)) {
    Dis[x][y] = Dist + 1;
    Que[++Tl][0] = x, Que[Tl][1] = y;
  }
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), k = RD();
  for (unsigned i(1); i <= n; ++i) {
    scanf("%s", Itmp + 1);
    for (unsigned j(1); j <= m; ++j) {
      if (Itmp[j] == 'B') Sx = i, Sy = j, Itmp[j] = '.';
      if (Itmp[j] == '.') Map[i][j] = 1;
      Dis[i][j] = 0x3f3f3f3f;
    }
  }
  Que[++Tl][0] = Sx, Que[Tl][1] = Sy, Dis[Sx][Sy] = 0;
  while (Tl ^ Hd) {
    unsigned Curx(Que[++Hd][0]);
    unsigned Cury(Que[Hd][1]);
    unsigned Ds(Dis[Curx][Cury]);
    if (Ds > 5000) break;
    Go(Curx + 1, Cury, Ds);
    Go(Curx - 1, Cury, Ds);
    Go(Curx, Cury + 1, Ds);
    Go(Curx, Cury - 1, Ds);
  }
  // for (unsigned i(1); i <= n; ++i) {
  //   for (unsigned j(1); j <= m; ++j) {
  //     printf("%u ", Dis[i][j]);
  //   }
  //   putchar(0x0A);
  // }
  for (unsigned i(1); i <= k; ++i) G[i].In();
  sort(G + 1, G + k + 1);
  for (unsigned i(1); i <= k; ++i) {
    // printf("%u r %u %u (%u, %u)\n", G[i].v, G[i].r, G[i].Dist, G[i].x, G[i].y);
    if (G[i].r < G[i].Dist) continue;
    // if (!(G[i].Dist)) Tmp += G[i].v;
    for (unsigned j(G[i].r + G[i].Dist); j >= (G[i].Dist << 1); --j) {
      f[j] = max(f[j], f[j - (G[i].Dist << 1)] + G[i].v);
    }
    // for (unsigned j(0); j <= 20; ++j) printf("%u ", f[j]);putchar(0x0A);
  }
  for (unsigned i(0); i <= 10000; ++i) Ans = max(Ans, f[i]);
  printf("%u\n", Ans + Tmp);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
4 5 4
.....
.###.
.....
B~~~~
10 6 1 1
20 2 3 1
25 10 1 5
999 1 3 1
4 5 4
..#..
.###.
....#
B~~~~
10 6 1 1
20 2 3 1
25 10 1 5
999 1 3 1


*/