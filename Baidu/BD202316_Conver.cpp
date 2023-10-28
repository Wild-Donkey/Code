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
const unsigned long long Mod(998244353), One21(2097151), Cover(1073741823),
    InvRevMod(998244351), R_Sq(682155965), R1(75497471), R3(226492413);
inline void Mn(unsigned &x) { x -= (x >= Mod) ? Mod : 0; }
inline void Mn(unsigned long long &x) { x -= (x >= Mod) ? Mod : 0; }
inline unsigned Mned(unsigned x) { return x - ((x >= Mod) ? Mod : 0); }
inline unsigned AR_to_A(unsigned long long x) {  // Less than Mod
  return Mned((x + (((x & Cover) * InvRevMod) & Cover) * Mod) >> 30);
}
inline unsigned Mult(unsigned long long x, unsigned long long y) {
  return AR_to_A(x * y);
}
inline unsigned A_to_AR(unsigned long long x) { return AR_to_A(x * R_Sq); }
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(R1);
  while (y) {
    if (y & 1) Rt = Mult(Rt, x);
    y >>= 1, x = Mult(x, x);
  }
  return Rt;
}
unsigned W[2097152], IW[2097152];
unsigned a[100005], Pool[524288];
unsigned n, m, l;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
void Init() {
  unsigned long long w(Pow(R3, (Mod - 1) >> 21));
  W[0] = IW[0] = R1;
  for (unsigned i(1); !(i >> 21); ++i) W[i] = Mult(W[i - 1], w);
  w = Pow(w, Mod - 2);
  for (unsigned i(1); !(i >> 21); ++i) IW[i] = Mult(IW[i - 1], w);
}
void DIT(unsigned *F, unsigned N) {  // Len = 2^N
  for (unsigned i(1), I(1 << 20); !(i >> N); i <<= 1, I >>= 1) {
    for (unsigned j(0), J(0); !(j >> N); ++j, J = ((J + I) & One21))
      if (!(j & i)) {
        unsigned long long TmA(F[j]), TmB(Mult(F[j ^ i], W[J]));
        Mn(F[j] = TmA + TmB);
        Mn(F[j ^ i] = Mod + TmA - TmB);
      }
  }
}
void DIF(unsigned *F, unsigned N) {  // Len = 2^N
  for (unsigned i(1 << (N - 1)), I(1 << (21 - N)); i; i >>= 1, I <<= 1) {
    for (unsigned j(0), J(0); !(j >> N); ++j, J = ((J + I) & One21))
      if (!(j & i)) {
        unsigned long long TmA(F[j]), TmB(F[j ^ i]);
        Mn(F[j] = TmA + TmB), Mn(TmB = Mod + TmA - TmB);
        F[j ^ i] = Mult(TmB, IW[J]);
      }
  }
}
void Tms(unsigned *F, unsigned *G, unsigned N) {
  // printf("Mul %u %u Len %u\n", F - Pool, G - Pool, 1 << N);
  DIF(F, N), DIF(G, N);
  for (unsigned i((1 << N) - 1); ~i; --i) F[i] = Mult(F[i], G[i]);
  DIT(F, N);
  unsigned long long IN(Pow(A_to_AR(1 << N), Mod - 2));
  for (unsigned i((1 << N) - 1); ~i; --i) F[i] = Mult(F[i], IN);
  memset(G, 0, 1 << (N + 2));
}
signed main() {
  Init();
  n = RD();
  for (unsigned i(0); i < n; ++i) a[i] = A_to_AR(RD());
  for (unsigned i(0); i < n; ++i)
    a[i] = Pow(Mult(a[i], A_to_AR(RD())), Mod - 2);
  for (unsigned i(0); i < n; ++i)
    Pool[i << 2] = A_to_AR(Mned(Mod + 1 - AR_to_A(a[i]))),
              Pool[(i << 2) ^ 1] = a[i];
  for (unsigned i(1), I(2); i < n; i <<= 1, ++I) {
    // for (unsigned k(0); k < (n << 2); ++k) printf("%u ", AR_to_A(Pool[k]));
    // putchar(0x0A);
    for (unsigned j(0); j + i < n; j += (i << 1)) {
      Tms(Pool + (j << 2), Pool + ((j + i) << 2), I);
    }
  }
  // for (unsigned i(0); i <= n; ++i) printf("%u ", AR_to_A(Pool[i]));
  // putchar(0x0A);
  for (unsigned i((n >> 1) + 1); i <= n; ++i) Mn(Ans += Pool[i]);
  Mn(Ans = Mod + 1 - AR_to_A(Ans));
  if (Ans == 0)
    printf("-1\n");
  else
    printf("%u\n", AR_to_A(Pow(A_to_AR(Ans), Mod - 2)));
  return Wild_Donkey;
}
/*
4
1 1 1 1
1 1 1 1
*/