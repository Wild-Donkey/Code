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
struct Node {
  unsigned Val, Pos;
  inline const char operator<(const Node& x) const { return Val < x.Val; }
} a[200005], *Top(a);
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Clr() { n = RD(), B = 1, Ans = 0x3f3f3f3f, Top = a; }
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) {
      A = RD();
      while ((Top > a) && (Top->Val >= A)) --Top;
      (++Top)->Val = A, Top->Pos = i;
    }
    m = RD();
    for (Node* i(Top); i > a; --i) i->Val -= (i - 1)->Val;
    for (Node* i(a + 1); i <= Top; ++i) {
      // printf("Val %u %u\n", i->Pos, i->Val);
      C = min(Ans, m / i->Val);
      Ans = C, m -= i->Val * C;
      // printf("Ans %u Pos %u B %u\n", Ans, i->Pos, B);
      while (B <= i->Pos) printf("%u ", Ans), ++B;
    }
    putchar(0x0A);
  }
  //  system("pause");
  return Wild_Donkey;
}