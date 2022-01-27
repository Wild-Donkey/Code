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
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char a[1505][1505];
unordered_map <unsigned, unsigned> S;
inline void DFS(unsigned x, unsigned y) {
  ++A, a[x][y] = 0;
  for (unsigned i(0); i < 9; ++i) {
    unsigned X(x + (i / 3) - 1), Y(y + (i % 3) - 1);
    if (a[X][Y] == '*') DFS(X, Y);
  }
}
//  inline void Clr() {}
signed main() {
  freopen("star.in", "r", stdin);
  freopen("star.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) {
    scanf("%s", a[i] + 1);
  }
  for (unsigned j(1); j <= n; ++j) for (unsigned i(1); i <= m; ++i)
    if (a[j][i] == '*') A = 0, DFS(j, i), S[A] += 1;
  for (auto i : S) Ans = max(Ans, i.second * i.first), ++Cnt;
  printf("%u %u\n", Cnt, Ans);
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
5 7
*......
..**..*
.*...*.
...*...
....*..

3 4


10 10
**..**.**.
***....*..
*...**.**.
...*..*...
..........
**...**.*.
..*.*....*
..........
***..*.*..
.***..*...

4 12
*/