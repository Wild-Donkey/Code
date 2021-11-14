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
unsigned  m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char a[1005][1005], b[1005][1005];
void DFS(unsigned x, unsigned y) {
  b[x][y] = 1;
  if (a[x - 1][y]) { if ((!b[x - 1][y]) && (a[x - 1][y] == a[x][y])) DFS(x - 1, y); }
  else { Cnt = 1; return; }
  if (a[x + 1][y]) { if ((!b[x + 1][y]) && (a[x + 1][y] == a[x][y])) DFS(x + 1, y); }
  else { Cnt = 1; return; }
  if (a[x][y - 1]) { if ((!b[x][y - 1]) && (a[x][y - 1] == a[x][y])) DFS(x, y - 1); }
  else { Cnt = 1; return; }
  if (a[x][y + 1]) { if ((!b[x][y + 1]) && (a[x][y + 1] == a[x][y])) DFS(x, y + 1); }
  else { Cnt = 1; return; }
}
void Clr(unsigned x, unsigned y) {
  b[x][y] = 0;
  if (b[x - 1][y]) Clr(x - 1, y);
  if (b[x + 1][y]) Clr(x + 1, y);
  if (b[x][y - 1]) Clr(x, y - 1);
  if (b[x][y + 1]) Clr(x, y + 1);
}
void Del(unsigned x, unsigned y) {
  if (a[x - 1][y] && ((a[x - 1][y] & 1) == (a[x][y] & 1))) Del(x - 1, y);
  if (a[x + 1][y] && ((a[x + 1][y] & 1) == (a[x][y] & 1))) Del(x + 1, y);
  if (a[x][y - 1] && ((a[x][y - 1] & 1) == (a[x][y] & 1))) Del(x, y - 1);
  if (a[x][y + 1] && ((a[x][y + 1] & 1) == (a[x][y] & 1))) Del(x, y + 1);
  a[x][y] = 0;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  // freopen("A.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1), j; i <= n; ++i) {
    A = RD(), B = RD();
    if (a[A][B]) { printf("illegal\n"); return 0; }
    a[A][B] = (i & 1) + 1;
    if (a[A - 1][B] && ((a[A - 1][B] & 1) ^ (a[A][B] & 1))) { Cnt = 0, DFS(A - 1, B), Clr(A - 1, B); if (!Cnt) Del(A - 1, B); }
    if (a[A + 1][B] && ((a[A + 1][B] & 1) ^ (a[A][B] & 1))) { Cnt = 0, DFS(A + 1, B), Clr(A + 1, B); if (!Cnt) Del(A + 1, B); }
    if (a[A][B - 1] && ((a[A][B - 1] & 1) ^ (a[A][B] & 1))) { Cnt = 0, DFS(A, B - 1), Clr(A, B - 1); if (!Cnt) Del(A, B - 1); }
    if (a[A][B + 1] && ((a[A][B + 1] & 1) ^ (a[A][B] & 1))) { Cnt = 0, DFS(A, B + 1), Clr(A, B + 1); if (!Cnt) Del(A, B + 1); }
    Cnt = 0, DFS(A, B), Clr(A, B);
    if (!Cnt) { printf("illegal\n"); return 0; }
    Tmp = 1, j = 1;
    while (a[A + j][B] == (i & 1) + 1) ++j, ++Tmp;
    j = 1;
    while (a[A - j][B] == (i & 1) + 1) ++j, ++Tmp;
    if (Tmp >= m) { printf(((i & 1) ? "Alice %u\n" : "Bob %u\n"), i);return 0; }
    j = 1, Tmp = 1;
    while (a[A][B + j] == (i & 1) + 1) ++j, ++Tmp;
    j = 1;
    while (a[A][B - j] == (i & 1) + 1) ++j, ++Tmp;
    if (Tmp >= m) { printf(((i & 1) ? "Alice %u\n" : "Bob %u\n"), i);return 0; }
    j = 1, Tmp = 1;
    while (a[A + j][B + j] == (i & 1) + 1) ++j, ++Tmp;
    j = 1;
    while (a[A - j][B - j] == (i & 1) + 1) ++j, ++Tmp;
    if (Tmp >= m) { printf(((i & 1) ? "Alice %u\n" : "Bob %u\n"), i);return 0; }
    j = 1, Tmp = 1;
    while (a[A - j][B + j] == (i & 1) + 1) ++j, ++Tmp;
    j = 1;
    while (a[A + j][B - j] == (i & 1) + 1) ++j, ++Tmp;
    if (Tmp >= m) { printf(((i & 1) ? "Alice %u\n" : "Bob %u\n"), i);return 0; }
    // for (unsigned k(1); k <= 10; ++k) {
    //   for (unsigned l(1); l <= 10; ++l) printf("%u ", a[k][l]);
    //   putchar('\n');
    // }
    // putchar('\n');
  }
  printf("draw\n");
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
28 10
1 1
10 1
1 2
10 2
2 1
10 3
3 1
10 4
1 3
2 2
2 3
10 5
3 3
1 4
10 6
2 4
10 7
3 4
10 8
4 4
10 9
4 3
10 10
4 2
9 1
4 1
3 2
2 2
*/