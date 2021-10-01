#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
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
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned Lst[2000005], a[2][1000005][20], Pos[1000005][2][2], Bin[1000005], Log[1000005], m, n, Cnt(0), Ans(0);
inline unsigned Find(unsigned L, unsigned x, unsigned y) {
  register unsigned Tmp(Log[y - x + 1]);
  return max(a[L][x][Tmp], a[L][y - Bin[Tmp] + 1][Tmp]);
}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (register unsigned b(0); b < 2; ++b) {
    for (register unsigned i(1); i <= n; ++i) {
      Lst[++Cnt] = a[b][i][0] = RD();
    }
  }
  sort(Lst + 1, Lst + Cnt + 1);
  unique(Lst + 1, Lst + Cnt + 1);
  for (register unsigned b(0); b < 2; ++b) {
    for (register unsigned i(1); i <= n; ++i) {
      a[b][i][0] = lower_bound(Lst + 1, Lst + n + 1, a[b][i][0]) - Lst;
      if(Pos[a[b][i][0]][0][1]) {
        Pos[a[b][i][0]][1][0] = b;
        Pos[a[b][i][0]][1][1] = i;
      } else {
        Pos[a[b][i][0]][0][0] = b;
        Pos[a[b][i][0]][0][1] = i;
      }
    }
  }
  for (register unsigned i(1), j(0); i <= n; i <<= 1, ++j) {
    Bin[j] = i, Log[i] = j; 
  }
  for (register unsigned i(2); i <= n; ++i) {
    Log[i] = max(Log[i], Log[i - 1]);
  }
  for (register unsigned b(0); b < 2; ++b) {
    for (register unsigned i(1); i <= Log[n]; ++i) {
      for (register unsigned j(1); j + Bin[i] <= n + 1; ++j) {
        a[b][j][i] = max(a[b][j][i - 1], a[b][j + Bin[i - 1]][i - 1]);
//        printf("%u %u %u %u\n", b, i, j, a[b][j][i]); 
      }
    }
  }
  for (register unsigned i(n); i; --i) {
//    printf("%u (%u, %u) (%u, %u)\n", i, Pos[i][0][0], Pos[i][0][1], Pos[i][1][0], Pos[i][1][1]);
    if(Pos[i][0][0] ^ Pos[i][1][0]) {
      Ans = max(Ans, i);
//      break;
      continue;
    }
//    if(i <= Ans) {
//      break;
//    }
    if(Pos[i][0][1] > Pos[i][1][1]) {
      swap(Pos[i][0][1], Pos[i][1][1]);
    }
    if(Pos[i][0][1] + 1 == Pos[i][1][1]) {
      continue;
    }
    Ans = max(min(i, Find(Pos[i][0][0], Pos[i][0][1] + 1, Pos[i][1][1] - 1)), Ans);
  }
  printf("%u\n", Lst[Ans]);
//  }
  return Wild_Donkey;
}
/*
3
6 9 6
4 9 4

4
2 9 9 3
7 7 2 3

5
5 4 8 4 7
8 9 5 7 9

4
1 1 2 2
3 3 4 4

4
3 2 1 3
4 1 2 4

4
1 2 2 1
3 4 4 3


*/
