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
const char List[10] = "  DRUL";
char Mp[2000][2000], Ans[4000000];
pair<unsigned, unsigned> Queue[4000000], *Head, *Tail;

char One;

unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
inline void Clr() {
  n = RD(), m = RD();
  for (unsigned i(0); i < n; ++i) {
    scanf("%s", Mp[i]);
    for (unsigned j(0); j < m; ++j) Mp[i][j] -= '0', Mp[i][j] ^= ((i ^ j) & 1);
  }
  Head = Tail = Queue;
  Cnt = 0, One = Mp[0][0] ^ 1;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    if (n == m && n == 1) {
      printf("0\n");
      continue;
    }
    *(Tail++) = {0, 0};
    while (Head < Tail) {
      unsigned Curx(Head->first), Cury(Head->second);
      // printf("(%u, %u)\n", Curx, Cury);
      ++Head;
      if (Curx && Mp[Curx - 1][Cury] < 2 && (One ^ Mp[Curx - 1][Cury])) {
        Mp[Curx - 1][Cury] = 4;
        *(Tail++) = {Curx - 1, Cury};
      }
      if (Cury && Mp[Curx][Cury - 1] < 2 && (One ^ Mp[Curx][Cury - 1])) {
        Mp[Curx][Cury - 1] = 5;
        *(Tail++) = {Curx, Cury - 1};
      }
      if (Curx + 1 < n && Mp[Curx + 1][Cury] < 2 &&
          (One ^ Mp[Curx + 1][Cury])) {
        Mp[Curx + 1][Cury] = 2;
        *(Tail++) = {Curx + 1, Cury};
      }
      if (Cury + 1 < m && Mp[Curx][Cury + 1] < 2 &&
          (One ^ Mp[Curx][Cury + 1])) {
        Mp[Curx][Cury + 1] = 3;
        *(Tail++) = {Curx, Cury + 1};
      }
    }
    // printf("Done\n");
    if (Mp[n - 1][m - 1] < 2) {
      printf("-1\n");
      continue;
    }
    unsigned Backx(n - 1), Backy(m - 1);
    while (Backx | Backy) {
      // printf("(%u, %u) %u\n", Backx, Backy, Mp[Backx][Backy]);
      Ans[Cnt++] = List[Mp[Backx][Backy]];
      switch (Mp[Backx][Backy]) {
        case 2: {
          --Backx;
          break;
        }
        case 3: {
          --Backy;
          break;
        }
        case 4: {
          ++Backx;
          break;
        }
        case 5: {
          ++Backy;
          break;
        }
      }
    }
    printf("%u\n", Cnt);
    for (unsigned i(Cnt - 1); ~i; --i) putchar(Ans[i]);
    putchar(0x0A);
  }
  //  system("pause");
  return Wild_Donkey;
}
/*
3
2 2
01
11
2 2
01
10
2 2
10
11
*/