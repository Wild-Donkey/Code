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
unsigned long long a, b, p, B, P, Ph, Inv, Tmp;
unsigned n, C, D, t, A;
unsigned Cnt(0), Ans(0);
char Flg(0);
inline char Clr() {
  a = RD(), P = p = RD(), b = RD(), C = Flg = 0;
  if (!p) return 1;
  b %= p, B = b, A = 1;
  return 0;
}
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) { if (y & 1) Rt = Rt * x % P; x = x * x % P, y >>= 1; }
  return Rt;
}
inline unsigned Phi(unsigned x) {
  unsigned Rt(x), Li(sqrt(x) + 1);
  for (unsigned i(2); i <= Li; ++i) if (!(x % i)) {
    // printf("Prime %u\n", i);
    Rt /= i, Rt *= (i - 1);
    while (!(x % i)) x /= i;
  }
  if (x > 1)  Rt /= x, Rt *= (x - 1);
  return Ph = Rt;
}
inline unsigned GCD(unsigned long long x, unsigned long long y) {
  unsigned SwT;
  while (y) SwT = x, x = y, y = SwT % y;
  // printf("%u\n", x);
  return D = x;
}
inline void BSGS() {
  unordered_map<unsigned, unsigned> S;
  Inv = B * Pow(Tmp = Pow(a, n), Ph - 1) % P;
  // printf("Calc %llu %llu %llu\n", P, a, B);
  for (unsigned i(n - 1); ~i; --i) S[Inv = Inv * a % P] = i;// printf("%u %llu\n", i, Inv);
  for (unsigned i(0), j(1); i < n; ++i, j = j * Tmp % P)
    if (S.find(j) != S.end()) { printf("%llu\n", ((i * n + S[j]) % Ph) + C); return; }
  printf("No Solution\n"); return;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  for (;;) {
    if (Clr()) return 0;
    if (b == 1) { printf("0\n");continue; }
    if (!a) { printf(b ? "No Solution\n" : "1"); continue; }
    while (GCD(a, P) > 1) if (!(b % D)) b /= D, P /= D, ++C, A = A * (a / D) % P;
    else { Flg = 1, printf((b ^ A) ? "No Solution\n" : "%u\n", C); break; }
    if (Flg) continue;
    n = sqrt(Phi(P)) + 1;
    B = Pow(Pow(a, C), Ph - 1) * B % P;
    // printf("BSGS %llu %llu %llu Phi %llu k %u\n", P, a, B, Ph, C);
    BSGS();
  }
  // system("pause");
  return Wild_Donkey;
}