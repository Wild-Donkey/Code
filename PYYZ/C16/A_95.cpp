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
unsigned long long Fac[1000005], Inv[1000005];
long long Stack[105][2], Ek, Wh;
unsigned STop(0), a[400005], m, n, P;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
//  inline void Clr() {}
inline long long Exgcd(long long x, long long y) {
  long long Swt, Stk[105];
  unsigned Tp(0);
  while (y) Stk[++Tp] = x / y, Swt = x, x = y, y = Swt % y;
  Ek = (x < 0) ? (-1) : 1, Wh = 0;
  for (;Tp;--Tp) Swt = Ek, Ek = Wh, Wh = Swt - Wh * Stk[Tp];
  return (x > 0) ? x : -x;
}
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) { if (y & 1) Rt = Rt * x % B;  x = x * x % B, y >>= 1; }
  return Rt;
}
inline unsigned long long Lucas(unsigned x, unsigned y) {
  if (x < B) {
    if (x < y) return 0;
    return (Fac[x] * Inv[y] % B) * Inv[x - y] % B;
  }
  return Lucas(x / B, y / B) * Lucas(x % B, y % B) % B;
}
inline unsigned Calc() {
  unsigned long long Rt(0);
  for (unsigned i(1); i < B; ++i) Fac[i] = Fac[i - 1] * i % B;
  Inv[B - 1] = Pow(Fac[B - 1], B - 2);
  for (unsigned i(B - 2); ~i; --i) Inv[i] = Inv[i + 1] * (i + 1) % B;
  // for (unsigned i(0); i < B; ++i) printf("%u ", Fac[i]); putchar(0x0A);
  // for (unsigned i(0); i < B; ++i) printf("%u ", Inv[i]); putchar(0x0A);
  for (unsigned i(0); i <= n; ++i) Rt = (Rt + Lucas(n, i) * a[i]) % B;
  // for (unsigned i(0); i <= n; ++i) printf("%u ", Lucas(n, i)); putchar(0x0A);
  // printf("Calc %u To %llu\n", B, Rt);
  return Rt;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD() - 1, A = P = RD(), m = sqrt(n) + 1, Fac[0] = 1;
  for (unsigned i(0); i <= n; ++i) a[i] = RD();
  if (n <= 1000) {
    for (unsigned i(n); i; --i)for (unsigned j(0); j < i; ++j)
      a[j] += a[j + 1], a[j] -= ((a[j] >= P) ? P : 0);
    printf("%u\n", a[0]);
    return 0;
  }
  for (unsigned i(2); i <= m; ++i) {
    if (!(A % i)) {
      B = 1;
      while (!(A % i)) B *= i, A /= i;
      Stack[++STop][0] = B, Stack[STop][1] = Calc();
    }
  }
  if (A > 1) Stack[++STop][0] = B = A, Stack[STop][1] = Calc();
  for (unsigned i(1); i < STop; ++i) {
    long long Ca(Stack[i + 1][1] - Stack[i][1]);
    Ca /= Exgcd(Stack[i][0], -Stack[i + 1][0]);
    // printf("Exgcd %lld %lld = %lld %lld Ca %lld\n", Stack[i][0], -Stack[i + 1][0], Ek, Wh, Ca);
    Ek *= Ca, Ek %= Stack[i + 1][0], Ek += Stack[i + 1][0], Ek -= (Ek >= Stack[i + 1][0]) ? Stack[i + 1][0] : 0;
    // printf("Ex %lld\n", Ek);
    Stack[i + 1][0] *= Stack[i][0];
    Stack[i + 1][1] = Ek * Stack[i][0] + Stack[i][1];
  }
  printf("%lld\n", Stack[STop][1] % P);
  //  }
  // system("pause");
  return Wild_Donkey;
}