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
unsigned a[2000005], Sum[2000005], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
char Flg, f[2000005][2];
inline void Clr() {
  memset(f, 0, n + 1);
  n = RD(), Sum = 0;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned T(1); T <= t; ++T) {
    Clr();
    for (register unsigned i(1); i <= n; ++i) {
      f[i][1] = a[i] = RD(), f[i][0] = f[i][1] ^ 1, Sum ^= a[i];
      if (a[i] > 1) Flg = 1;
    }
    if (!Sum) {
      printf("Draw\n");
      continue;
    }
    if (!Flg) {
      for (register unsigned i(2); i <= n; ++i) {
        for (register unsigned j(1); j + i - 1 <= n; ++j) {
          f[j][1] = (f[j][1 ^ a[j + i - 1]] & f[j + 1][1 ^ a[j]]) ^ 1;
          f[j][0] = (f[j][a[j + i - 1]] & f[j + 1][a[j]]) ^ 1;
          // printf("%u %u %u\n", i, j, f[j]);
        }
      }
      printf(f[1] ? "Alice\n" : "Bob\n");
      continue;
    }
    for (register unsigned i(31), _1(1 << 31); i < 0x3f3f3f3f; --i, _1 >>= 1) {
      Sum = 0;
      for (register unsigned j(1); j <= n; ++j) {
        f[j][1] = (a[j] & _1) >> i, f[i][0] = f[i][1] ^ 1, Sum ^= f[j][1];
      }
      if (!Sum) continue;
      for (register unsigned k(2); k <= n; ++k) {
        for (register unsigned j(1); j + k - 1 <= n; ++j) {
          f[j][1] = (f[j][1 ^ ((a[j + k - 1] & _1) >> i)] & f[j + 1][1 ^ ((a[j] & _1) >> i)]);
          f[j][0] = (f[j][(a[j + k - 1] & _1) >> i] & f[j + 1][(a[j] & _1) >> i]);
          printf("%u %u %u %u\n", k, j, f[j][0], f[j][1]);
        }
      }
      break;
    }
    printf(f[1] ? "Alice\n" : "Bob\n");
    continue;
  }
  system("pause");
  return Wild_Donkey;
}
/*
1 A
01 A
10 A
100 A
010 B
001 A
1000 A
0100 A
0010 A
0001 A
10000 A
01000 B
00100 B
00010 B
00001 A
100000 A
010000 A
001000 A
000100 A
000010 A
000001 A
11 B
101 B
110 A
1001 B
1100 B
1010 A
0110 B
10001 B
0101101101011010
1
5
1 0 1 0 1
*/