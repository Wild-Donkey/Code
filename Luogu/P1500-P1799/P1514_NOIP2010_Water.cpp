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
unsigned a[505][505], Range[505][505][2], m, n;
unsigned Q[250005][2], Hd(0), Tl(0);
unsigned List[505][2], NowR(1), Last(0);
unsigned Cnt(0), Ans(0), Tmp(0);
char Ava[505][505];
//  inline void Clr() {}
inline void Merge(unsigned Fx, unsigned Fy, unsigned Tx, unsigned Ty) {
  if (Range[Fx][Fy][0] > m) return;
  Range[Tx][Ty][0] = min(Range[Tx][Ty][0], Range[Fx][Fy][0]);
  Range[Tx][Ty][1] = max(Range[Tx][Ty][1], Range[Fx][Fy][1]);
}
inline void DFS(unsigned x, unsigned y) {
  if (Range[x][y][0]) return;
  if (x == n) Range[x][y][0] = Range[x][y][1] = y;
  else Range[x][y][0] = 0x3f3f3f3f;
  if ((x < n) && (a[x + 1][y] < a[x][y])) DFS(x + 1, y), Merge(x + 1, y, x, y);
  if ((x > 1) && (a[x - 1][y] < a[x][y])) DFS(x - 1, y), Merge(x - 1, y, x, y);
  if ((y < m) && (a[x][y + 1] < a[x][y])) DFS(x, y + 1), Merge(x, y + 1, x, y);
  if ((y > 1) && (a[x][y - 1] < a[x][y])) DFS(x, y - 1), Merge(x, y - 1, x, y);
  // printf("(%u, %u): [%u %u]\n", x, y, Range[x][y][0], Range[x][y][1]);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= m; ++j) a[i][j] = RD();
  for (unsigned i(1); i <= m; ++i) Q[++Tl][0] = 1, Q[Tl][1] = i, Ava[1][i] = 1;
  while (Hd ^ Tl) {
    unsigned Curx(Q[++Hd][0]), Cury(Q[Hd][1]);
    if ((Curx > 1) && (!Ava[Curx - 1][Cury]) && (a[Curx - 1][Cury] < a[Curx][Cury]))
      Ava[Curx - 1][Cury] = 1, Q[++Tl][0] = Curx - 1, Q[Tl][1] = Cury;
    if ((Curx < n) && (!Ava[Curx + 1][Cury]) && (a[Curx + 1][Cury] < a[Curx][Cury]))
      Ava[Curx + 1][Cury] = 1, Q[++Tl][0] = Curx + 1, Q[Tl][1] = Cury;
    if ((Cury > 1) && (!Ava[Curx][Cury - 1]) && (a[Curx][Cury - 1] < a[Curx][Cury]))
      Ava[Curx][Cury - 1] = 1, Q[++Tl][0] = Curx, Q[Tl][1] = Cury - 1;
    if ((Cury < m) && (!Ava[Curx][Cury + 1]) && (a[Curx][Cury + 1] < a[Curx][Cury]))
      Ava[Curx][Cury + 1] = 1, Q[++Tl][0] = Curx, Q[Tl][1] = Cury + 1;
  }
  for (unsigned i(1); i <= m; ++i) Ans += Ava[n][i];
  if (Ans < m) {
    printf("0\n%u\n", m - Ans);
    return 0;
  }
  for (unsigned i(1); i <= m; ++i) {
    DFS(1, i);
    if (Range[1][i][0] < m) List[++Cnt][0] = Range[1][i][0], List[Cnt][1] = Range[1][i][1];
  }
  Ans = 0;
  for (unsigned i(1); i <= Cnt; ++i) {
    // printf("%u-> [%u, %u]\n", NowR, List[i][0], List[i][1]);
    if (NowR < List[i][0]) NowR = Last + 1, Last = 0, ++Ans;
    Last = max(Last, List[i][1]);
  }
  if (NowR <= m) ++Ans;
  printf("1\n%u\n", Ans);
  //  }
  // system("pause");
  return Wild_Donkey;
}