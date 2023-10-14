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
const unsigned long long Mod(998244353), One21(2097151);
inline void Mn(unsigned &x) { x -= (x >= Mod) ? Mod : 0; }
inline void Mn(unsigned long long &x) { x -= (x >= Mod) ? Mod : 0; }
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) {
    printf("y %u Rt %llu x %llu\n", y, Rt, x);
    if (y & 1) Rt = Rt * x % Mod;
    y >>= 1, x = x * x % Mod;
  }
  return Rt;
}
unsigned W[2097152], IW[2097152];
unsigned a[2097152], b[2097152];
unsigned n, m, l;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
void Init() {
  unsigned long long w(Pow(3, (Mod - 1) >> 21));
  printf("%llu\n", w);
  W[0] = IW[0] = 1;
  for (unsigned i(1); !(i >> 21); ++i) W[i] = W[i - 1] * w % Mod;
  w = Pow(w, Mod - 2);
  for (unsigned i(1); !(i >> 21); ++i) IW[i] = IW[i - 1] * w % Mod;
  // for (unsigned i(0); !(i >> 21); ++i) printf("%u\n", W[i]);
  // printf("Init\n");
}
void DIT(unsigned *F, unsigned N) {  // Len = 2^N
  for (unsigned i(1), I(1 << 20); !(i >> N); i <<= 1, I >>= 1) {
    for (unsigned j(0), J(0); !(j >> N); ++j, J = ((J + I) & One21))
      if (!(j & i)) {
        // printf("%u And %u J %u\n", j, j ^ i, J);
        unsigned long long TmA(F[j]),
            TmB(F[j ^ i] * (unsigned long long)W[J] % Mod);
        Mn(F[j] = TmA + TmB);
        Mn(F[j ^ i] = Mod + TmA - TmB);
      }
  }
}
void DIF(unsigned *F, unsigned N) {  // Len = 2^N
  for (unsigned i(1 << (N - 1)), I(1 << (21 - N)); i; i >>= 1, I <<= 1) {
    for (unsigned j(0), J(0); !(j >> N); ++j, J = ((J + I) & One21))
      if (!(j & i)) {
        // printf("%u And %u J %u I %u\n", j, j ^ i, J, I);
        unsigned long long TmA(F[j]), TmB(F[j ^ i]);
        Mn(F[j] = TmA + TmB);
        F[j ^ i] = (Mod + TmA - TmB) * IW[J] % Mod;
      }
  }
}
unsigned Tms(unsigned *F, unsigned *G, unsigned lFG) {
  unsigned N(0);
  while ((lFG - 1) >> N) ++N;
  DIF(F, N), DIF(G, N);
  for (unsigned i((1 << N) - 1); ~i; --i)
    F[i] = (unsigned long long)F[i] * G[i] % Mod;
  DIT(F, N);
  unsigned long long IN(Pow(1 << N, Mod - 2));
  for (unsigned i((1 << N) - 1); ~i; --i) F[i] = F[i] * IN % Mod;
  return lFG;
}

//  inline void Clr() {}
signed main() {
  // freopen("Normal.in", "r", stdin);
  freopen("Normal.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  Init();
  return 0;
  n = RD() + 1, m = RD() + 1;
  for (unsigned i(0); i < n; ++i) a[i] = RD();
  for (unsigned i(0); i < m; ++i) b[i] = RD();
  l = Tms(a, b, n + m - 1);
  for (unsigned i(0); i < l; ++i) printf("%u ", a[i]);
  putchar(0x0A);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
2 3
1 2 3
4 5 6 7
*/