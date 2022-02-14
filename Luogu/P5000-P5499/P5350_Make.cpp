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
#include <random>
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
unsigned long long Mod(1000000007);
unsigned Ans[300005], a[300005], m, n;
unsigned A, B, C, D, t, Opt, OV;
unsigned Cnt(0), Tmp(0);
std::mt19937 generator(time(0));
inline unsigned Rand(unsigned x) { return (generator() % x) + 1; }
inline unsigned Rand(unsigned x, unsigned y) { return (generator() % (y - x + 1)) + x; }
inline void Mn(unsigned& x) { x -= ((x >= Mod) ? Mod : 0); }
//  inline void Clr() {}
signed main() {
  freopen("P5350.in", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = 10, m = 10;
  printf("%u %u\n", n, m);
  for (unsigned i(1); i <= n; ++i) printf("%u ", a[i] = (generator() % Mod)); putchar(0x0A);
  for (unsigned i(1); i <= m; ++i) {
    printf("%u ", (Opt = 1 + (generator() % 6)));
    if (Opt < 4 || Opt > 5) {
      A = Rand(n), B = Rand(n); if (A > B) swap(A, B);
      printf("%u %u ", A, B);
      switch (Opt) {
      case(1): {
        ++Cnt;
        for (unsigned j(A); j <= B; ++j) Ans[Cnt] += a[j], Mn(Ans[Cnt]);
        break;
      }
      case(2): {
        printf("%u", OV = generator() % Mod);
        for (unsigned j(A); j <= B; ++j) a[j] = OV;
        break;
      }
      case(3): {
        printf("%u", OV = generator() % Mod);
        for (unsigned j(A); j <= B; ++j) a[j] += OV, Mn(a[j]);
        break;
      }
      case(6): {
        unsigned Mid((B - A) >> 1);
        for (unsigned j(0); j <= Mid; ++j) swap(a[A + j], a[B - j]);
        break;
      }
      }
    }
    else {
      unsigned Len(Rand(n >> 1));
      A = Rand(n - (Len << 1) + 1), B = A + Len - 1;
      C = Rand(B + 1, n - Len + 1), D = C + Len - 1;
      if (generator() & 1) swap(A, C), swap(B, D);
      printf("%u %u %u %u", A, B, C, D);
      if (Opt & 1) for (unsigned j(0); j < Len; ++j) swap(a[A + j], a[C + j]);
      else for (unsigned j(0); j < Len; ++j) a[C + j] = a[A + j];
    }
    putchar(0x0A);
  }
  freopen("P5350.ans", "w", stdout);
  for (unsigned i(1); i <= Cnt; ++i) printf("%u\n", Ans[i]);
  for (unsigned i(1); i <= n; ++i) printf("%u ", a[i]); putchar(0x0A);
  //  }
  //  system("pause");
  return Wild_Donkey;
}