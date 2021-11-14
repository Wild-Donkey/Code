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
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
unsigned a[30], Vis[2], Cur(0), Ti, m, n, n2, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
unsigned Tot, f[10005], Base[15], Set[10005][2], Map[1000005], Size(0);
char Init[30], Now[2], Block[30][30], List[15][3];
inline void Clr() {
  for (unsigned i(1); i <= Size; ++i) Map[Set[i][0]] = 0;
  n = RD(), m = 0, n2 = n << 1;
  Size = Cur = Ans = 0;
  memset(a, 0, sizeof(a));
  memset(Set, 0, sizeof(Set));
  memset(Block, 0, sizeof(Block));
  Vis[0] = Vis[1] = 0;
}
inline void DFS(char x, char L) {
  Vis[L] |= (1 << x), ++Now[L];
  for (unsigned i(0); i < n; ++i)
    if (L) { if (((a[x] >> i) & 1) && (!(Vis[L ^ 1] & (1 << i)))) DFS(i, 0); }
    else { if (((a[i] >> x) & 1) && (!(Vis[L ^ 1] & (1 << i)))) DFS(i, 1); }
}
inline void DFS2(char x, unsigned y, char L, char R) {
  if (x > Cur) { if (L && (L == R)) Set[++Size][0] = y, Set[Size][1] = L, Map[y] = Size; return; }
  for (unsigned i(0); i <= List[x][2]; ++i)
    DFS2(x + 1, y + i * Base[x - 1], L + i * List[x][0], R + i * List[x][1]);
}
inline char Sub(unsigned x, unsigned y) {
  if (x == y) return 0;
  for (unsigned i = 1; i <= Cur; ++i) {
    if ((x % (List[i][2] + 1)) < (y % (List[i][2] + 1))) return 0;
    x /= (List[i][2] + 1), y /= (List[i][2] + 1);
  }
  return 1;
}
signed main() {
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(0); i < n; ++i) {
      scanf("%s", &Init);
      for (unsigned j(0); j < n; ++j)
        if (Init[j] ^ '0') a[i] |= (1 << j), ++m;
    }
    for (unsigned i(0); i < (n2); ++i) if (!(Vis[i & 1] & (1 << (i >> 1))))
      Now[0] = Now[1] = 0, DFS(i >> 1, i & 1), ++Block[Now[0]][Now[1]];
    for (unsigned i(1); i <= n; ++i) if (Block[i][i]) Ans += Block[i][i] * i * i, Block[i][i] = 0;
    for (unsigned i(0); i <= n; ++i) for (unsigned j(0); j <= n; ++j)
      if (Block[i][j]) List[++Cur][2] = Block[i][j], Block[i][j] = 0, List[Cur][0] = i, List[Cur][1] = j;
    Base[0] = 1;
    for (unsigned i(1); i <= Cur; ++i) Base[i] = Base[i - 1] * (List[i][2] + 1);
    DFS2(1, 0, 0, 0);
    for (unsigned i(1); i <= Size; ++i) {
      f[i] = Set[i][1] * Set[i][1];
      for (unsigned j(1); j <= Size; ++j)
        if (Sub(Set[i][0], Set[j][0]))
          Tmp = Map[Set[i][0] - Set[j][0]], f[i] = min(f[i], f[j] + Set[Tmp][1] * Set[Tmp][1]);
    }
    printf("%u\n", Ans + f[Size] - m);
  }
  system("pause");
  return Wild_Donkey;
}
/*
1
8
00001001
00000000
00000000
00000000
00010000
00000000
01001000
00000010
*/