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
unsigned m, n, Len, Cnt[25], A, B, C, D, t, Ans(0), Tmp(0);
unsigned Ti;
char a[15], b[2000050], S[15], Flg;
void Print(unsigned x) {
  for (unsigned i = Len; i; --i) putchar(b[i] + '0');
  putchar('\n');
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  A = RD(), n = RD();
  while (A) a[++m] = A % 10, A /= 10;
  // for (unsigned i(1); i <= (m >> 1); ++i) swap(a[i], a[m - i + 1]);
  // for (unsigned i(1); i <= m; ++i) ++Cnt[a[i]];
  for (unsigned i(1); i <= n; ++i) S[RD()] = 1;
  Len = Cnt[0] = m;
  if ((a[1] == 5) && S[5] && S[0]) { printf("-1\n");return 0; }
  if ((a[1] == 0) && S[0]) { printf("-1\n");return 0; }
  if ((a[1] == 2) || (a[1] == 4) || (a[1] == 6) || (a[1] == 8)) if (S[0] && S[2] && S[4] && S[6] && S[8]) { printf("-1\n");return 0; }
  if (n == 10) { printf("-1\n");return 0; }
  for (;Len <= 2000000;) {
    Flg = 0, ++Ti;
    for (unsigned i(1); i <= m; ++i) {
      --Cnt[b[i]];
      if (i + 1 <= Len) --Cnt[b[i + 1]];
      b[i] += a[i], b[i + 1] += ((b[i] >= 10) ? (1) : (0)), b[i] -= ((b[i] >= 10) ? (10) : (0));
      ++Cnt[b[i]];
      if (i + 1 <= Len) ++Cnt[b[i + 1]];
      else if (b[i + 1]) ++Cnt[b[i + 1]], Len = i + 1;
      // for (char i(0); i < 10; ++i) printf("%u ", Cnt[i]);
      // putchar('\n');
    }
    for (unsigned i(m + 1); b[i] >= 10; ++i) {
      --Cnt[b[i]];
      if (i + 1 <= Len) --Cnt[b[i + 1]];
      ++b[i + 1], b[i] -= 10;
      ++Cnt[b[i]];
      if (i + 1 <= Len) ++Cnt[b[i + 1]];
      if (b[i + 1] && (i + 1 > Len)) ++Cnt[b[i + 1]], Len = i + 1;
    }
    for (char i(0); i < 10; ++i) if (S[i] && Cnt[i]) { Flg = 1; break; }
    if (!Flg) { Print(Len); break; }
    // Print(Len);
    if (Ti >= 100000000) break;
  }
  // printf("%u\n", Len);
  if (Flg) printf("-1\n");
  // system("pause");
  return Wild_Donkey;
}
/*
30 9
0 1 2 3 4 5 6 7 9
100000 9
0 1 2 3 4 5 6 7 9
*/