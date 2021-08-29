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
unsigned List[10] = { 1, 4, 6, 8, 9 };
unsigned List2[10] = { 25, 27 };
unsigned List3[10] = { 33, 35 };
unsigned List4[10] = { 57 };
unsigned List5[10] = { 77 };
unsigned Sub[10];
unsigned m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
char a[100005], Flg, Tg[4];
inline void Clr() {
  n = RD(), Flg = Tg[0] = Tg[1] = Tg[2] = Tg[3] = 0;
  scanf("%s", a + 1);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  Sub[2] = 0, Sub[3] = 1, Sub[5] = 2, Sub[7] = 3;
  for (register unsigned T(1); T <= t; ++T) {
    Clr();
    for (register unsigned i(1); i <= n; ++i) {
      for (register unsigned j(0); j <= 4; ++j) {//1, 4, 6, 8, 9
        if (a[i] == List[j] + '0') {
          printf("%u\n%u\n", 1, List[j]);
          Flg = 1;
          break;
        }
      }
      if (Flg) break;
    }
    if (Flg) continue;
    if ((a[1] == '2') || (a[1] == '3') || (a[1] == '5') || (a[1] == '7')) {
      Tg[Sub[a[1] - '0']] = 1;
    }
    for (register unsigned i(2); i <= n; ++i) {
      if ((a[i] == '2') || (a[i] == '3') || (a[i] == '5') || (a[i] == '7')) {
        if ((a[i] == '2') || (a[i] == '5')) {// x2, x5
          printf("%u\n%c%c\n", 2, a[1], a[i]);
          Flg = 1;
          break;
        }
        if (a[i] == '3') {
          if (Tg[1]) {
            printf("%u\n33\n", 2);
            Flg = 1;
            break;
          }
        }
        if (a[i] == '7') {
          if (Tg[0]) {
            printf("%u\n27\n", 2);
            Flg = 1;
            break;
          }
          if (Tg[2]) {
            printf("%u\n57\n", 2);
            Flg = 1;
            break;
          }
          if (Tg[3]) {
            printf("%u\n77\n", 2);
            Flg = 1;
            break;
          }
        }
        Tg[Sub[a[i] - '0']] = 1;
      }
    }
    if (Flg) continue;
  }
  // system("pause");
  return Wild_Donkey;
}