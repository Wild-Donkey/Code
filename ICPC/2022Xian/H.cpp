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
unsigned n, c[65536], Cnt[65536], Ans[65536];
unsigned t, An, Ro, Xo;
unsigned Tmp(0);
char X[65536], Opr[65536], Cur(0);
inline void Clr() {
  memset(Cnt, 0, n << 2);
  memset(X, 0, n), Cur = 0;
  n = RD(), An = RD(), Ro = RD(), Xo = RD();
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(0); i < n; ++i) ++Cnt[c[i] = RD()];
    sort(c, c + n), Tmp = 0;
    for (unsigned i(0); i < n && An; ++i)
      if (Cnt[i]) {  // Cut the top to 3
        while (Cnt[i] > 3 && An) Ans[Cur] = i, Opr[Cur++] = '&', --An, --Cnt[i];
        Tmp += Cnt[i] - 1;
      }
    if (Tmp <= An) {                     // All in and
      for (unsigned i(0); i < n; ++i) {  // Unique
        if (Cnt[i] > 1) { Ans[Cur] = i, Opr[Cur++] = '&', --An, --Cnt[i]; }
        if (Cnt[i] > 1) { Ans[Cur] = i, Opr[Cur++] = '&', --An, --Cnt[i]; }
      }
      for (unsigned i(0); i < n && An; ++i)  // Drop the small
        if (Cnt[i]) Ans[Cur] = i, Opr[Cur++] = '&', --An, --Cnt[i];
    } else {                                 // And all in
      for (unsigned i(0); i < n && An; ++i)  // Erase The Twos
        if (Cnt[i] == 2) Ans[Cur] = i, Opr[Cur++] = '&', --An, --Cnt[i];
      if (An) {
        for (unsigned i(n - 1); (~i) && (An > 1); --i)  // Erase the Threes
          if (Cnt[i] == 3) {
            Ans[Cur] = i, Opr[Cur++] = '&', --An, --Cnt[i];
            Ans[Cur] = i, Opr[Cur++] = '&', --An, --Cnt[i];
          }
        if (An) {                                // Still one And left
          for (unsigned i(0); i < n && An; ++i)  // Find a three make it two
            if (Cnt[i] > 1) Ans[Cur] = i, Opr[Cur++] = '&', --An, --Cnt[i];
        }
      }
    }  // Now there was no And
    for (unsigned i(0); i < n && Xo > 1; ++i)
      while (Cnt[i] > 2 && Xo > 1) {
        Ans[Cur] = i, Opr[Cur++] = '^', --Xo, --Cnt[i];
        Ans[Cur] = i, Opr[Cur++] = '^', --Xo, --Cnt[i];
      }  // Now there is no more than one Xor or no more than 2 Cnt
    for (unsigned i(0); i < n; ++i)  // Generate the Ans
      if (Cnt[i]) {
        X[i] = 1, Ans[Cur] = i, --Cnt[i];
        if (Xo)
          Opr[Cur++] = '^', --Xo;
        else
          Opr[Cur++] = '|', --Ro;
      }
    for (unsigned i(0); i < n; ++i)
      while (Cnt[i]) {
        if (Xo)
          Ans[Cur] = i, Opr[Cur++] = '^', --Xo, --Cnt[i], X[i] ^= 1;
        else
          Ans[Cur] = i, Opr[Cur++] = '|', --Ro, --Cnt[i];
      }
    for (unsigned i(n - 1); ~i; --i) putchar(X[i] + '0');
    putchar(0x0A);
    for (unsigned i(0); i < n; ++i) putchar(Opr[i]);
    putchar(0x0A);
    for (unsigned i(0); i < n; ++i) printf("%u ", Ans[i]);
    putchar(0x0A);
  }
  //  system("pause");
  return Wild_Donkey;
}