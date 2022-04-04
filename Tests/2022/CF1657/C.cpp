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
unsigned P[500005], Pj[500005];
char a[500005];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned To;
inline void Clr() {
  memset(a, 0, n + 2);
  memset(P, 0, (n + 2) << 2);
  memset(Pj, 0, (n + 2) << 2);
  n = RD(), Ans = 0;
  scanf("%s", a + 1);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1), R(0), Rq(0); i < n; ++i) {
      if (R <= i) {
        for (unsigned j(1); (i >= j) && (i + j <= n) && (a[i - j + 1] == a[i + j]); ++j) P[i] = j;
        R = i + P[i], Rq = i; continue;
      }
      unsigned Des((Rq << 1) - i); // Rq - (i - Rq - 1)
      if (P[Des] < Des - (Rq - P[Rq])) P[i] = P[Des];
      else {
        P[i] = Des - (Rq - P[Rq]);
        for (unsigned j(P[i] + 1); (i >= j) && (i + j <= n) && (a[i - j + 1] == a[i + j]); ++j) P[i] = j;
        R = i + P[i], Rq = i;
      }
    }
    for (unsigned i(1), R(0), Rq(0); i <= n; ++i) {
      if (R < i) {
        for (unsigned j(1); (i >= j) && (i + j - 1 <= n) && (a[i - j + 1] == a[i + j - 1]); ++j) Pj[i] = j;
        R = i + Pj[i] - 1, Rq = i; continue;
      }
      unsigned Des((Rq << 1) - i); // Rq - (i - Rq)
      if (Pj[Des] < Des - (Rq - Pj[Rq])) Pj[i] = Pj[Des];
      else {
        Pj[i] = Des - (Rq - Pj[Rq]);
        for (unsigned j(Pj[i] + 1); (i >= j) && (i + j - 1 <= n) && (a[i - j + 1] == a[i + j - 1]); ++j) Pj[i] = j;
        R = i + Pj[i] - 1, Rq = i;
      }
    }
    // for (unsigned i(1); i < n; ++i) printf("%u ", P[i]); putchar(0x0A);
    // for (unsigned i(1); i <= n; ++i) printf("%u ", Pj[i]); putchar(0x0A);
    To = 1;
    for (unsigned j(2); To <= n;) {
      char Flg(0), No(0);
      if (a[To] == ')') No = 1;
      else Cnt = 1;
      for (j = To + 1; j <= n; ++j) {
        // printf("%u %u %u %u\n", To, No, Cnt, j);
        if (!No) {
          if (a[j] == '(') ++Cnt;
          else { if (!Cnt) No = 1; else --Cnt; }
          // printf("%c %u %u\n", a[j], No, Cnt);
          if ((!No) && (!Cnt)) break;
        }
        unsigned Cur((To + j) >> 1);
        if ((j - To) & 1) { if (Cur - P[Cur] + 1 <= To) break; }
        else { if (Cur - Pj[Cur] + 1 <= To) break; }
      }
      if (j > n) break;
      else To = j, To = j + 1, ++Ans;
    }
    printf("%u %u\n", Ans, n - To + 1);
  }
  //  system("pause");
  return Wild_Donkey;
}