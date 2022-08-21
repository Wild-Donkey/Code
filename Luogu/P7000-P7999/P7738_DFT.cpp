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
inline unsigned long long RDll() {
  unsigned long long intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
double Pie(3.141592653589793238462643383279502884197169399);
const char HexList[17] = "084C2A6E195D3B7F";
char Debug(0);
char Pp[65536], Hex[256];
inline void Mn(unsigned& x) { x -= ((x >= 256) ? 256 : 0); }
inline const double Sqr(const double& x) { return x * x; }
inline unsigned long long myRand(unsigned long long& k1,
                                 unsigned long long& k2) {
  unsigned long long k3(k1), k4(k2);
  k1 = k4;
  k3 ^= (k3 << 23);
  k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
  return k2 + k4;
}
inline unsigned PopC(unsigned long long x) {
  if (Debug) printf("Popc %llu\n", x);
  return Pp[x >> 48] + Pp[(x >> 32) & 65535] + Pp[(x >> 16) & 65535] +
         Pp[x & 65535];
}
struct Comp {
  double Rel, Vir;
  inline const Comp operator+(const double& x) const { return {Rel + x, Vir}; }
  inline const Comp operator-(const double& x) const { return {Rel - x, Vir}; }
  inline const Comp operator*(const double& x) const {
    return {Rel * x, Vir * x};
  }
  inline const Comp operator/(const double& x) const {
    return {Rel / x, Vir / x};
  }
  inline void operator+=(const double& x) { Rel += x; }
  inline void operator-=(const double& x) { Rel -= x; }
  inline void operator*=(const double& x) { Rel *= x, Vir *= x; }
  inline void operator/=(const double& x) { Rel /= x, Vir /= x; }
  inline const Comp operator+(const Comp& x) const {
    return {Rel + x.Rel, Vir + x.Vir};
  }
  inline const Comp operator-(const Comp& x) const {
    return {Rel - x.Rel, Vir - x.Vir};
  }
  inline const Comp operator*(const Comp& x) const {
    return {x.Rel * Rel - x.Vir * Vir, x.Rel * Vir + x.Vir * Rel};
  }
  inline const Comp operator/(const Comp& x) const {
    const double Mother(Sqr(x.Rel) + Sqr(x.Vir));
    return Comp{(x.Rel * Rel + x.Vir * Vir), (x.Vir * Rel - x.Rel * Vir)} /
           Mother;
  }
  inline const char operator<(const Comp& x) const { return Rel < x.Rel; }
  inline void operator+=(const Comp& x) { Rel += x.Rel, Vir += x.Vir; }
} W[256];
unsigned long long A, B;
char a[256], Flg(0);
unsigned n, m;
unsigned C, D, t;
struct Word {
  unsigned long long Val[4];
  inline void Rd() {
    scanf("%s", a), C = RD();
    for (unsigned i(63); ~i; --i) Val[i >> 4] <<= 4, Val[i >> 4] |= Hex[a[i]];
    if (Flg)
      for (unsigned i(0); i < 4; ++i) Val[i] ^= 0xFFFFFFFFFFFFFFFF;
    for (unsigned i(0); i < 256; ++i) a[i] = ((Val[i >> 6] >> (i & 63)) & 1);
  }
  inline const unsigned Diff(const Word& x) const {
    unsigned Rt(0);
    for (unsigned i(0); i < 4; ++i) Rt += PopC(Val[i] ^ x.Val[i]);
    return Rt;
  }
} Wd[400005], Q;
struct Plane {
  pair<Comp, unsigned> Pnt[400005];
  inline void Print() {
    for (unsigned i(1); i <= n; ++i)
      printf("(%lf,%lf) %u\n", Pnt[i].first.Rel, Pnt[i].first.Vir,
             Pnt[i].second);
  }
  inline void Init() {
    sort(Pnt + 1, Pnt + n + 1);
    // Print();
  }
  inline char Find(Comp x, Word& y) {
    unsigned L, R;
    pair<Comp, unsigned> Fd({x, 0});
    L = lower_bound(Pnt + 1, Pnt + n + 1, Fd) - Pnt;
    R = min(L + 100, n), L = ((L <= 100) ? 1 : (L - 100));
    for (unsigned i(L); i <= R; ++i)
      if (y.Diff(Wd[Pnt[i].second]) <= C) {
        // if (Pnt[i].second == 470) Debug = 1;
        // if (Debug) {
        //   printf("%u With %u\n", y.Diff(Wd[Pnt[i].second]), Pnt[i].second);
        //   Debug = 0;
        // }
        return 1;
      }
    return 0;
  }
} P[2];
inline Comp DFT(unsigned Fre, char* Ori) {
  Comp Rt;
  Rt = {0, 0};
  for (unsigned i(0), j(0); i < 256; ++i, Mn(j += Fre))
    if (Ori[i]) Rt += W[j];
  return Rt;
}
void gen(int n, unsigned long long a1, unsigned long long a2) {}
unsigned Cnt(0), Ans(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  // freopen("Test.in", "r", stdin);
  // freopen("P7738_-2.in", "r", stdin);
  // freopen("P7738.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  for (unsigned i(0); i < 65536; ++i) Pp[i] = Pp[i >> 1] + (i & 1);
  // for (unsigned i(0); i < 65536; ++i) printf("%u ", Pp[i]);
  // putchar(0x0A);
  for (unsigned i(0); i < 16; ++i) Hex[HexList[i]] = i;
  for (unsigned i(0); i < 256; ++i)
    W[i] = {cos(i * Pie / 128), sin(i * Pie / 128)};
  n = RD(), m = RD(), A = RDll(), B = RDll();
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(0); j < 256; ++j)
      a[j] = (myRand(A, B) & ((unsigned long long)1 << 32)) ? 1 : 0;
    for (unsigned j(255); ~j; --j)
      Wd[i].Val[j >> 6] <<= 1, Wd[i].Val[j >> 6] |= a[j];
    // if (i == 470) {
    //   for (unsigned j(0); j < 256; ++j) printf("%u", a[j]);
    //   putchar(0x0A);
    // }
    for (unsigned j(0); j < 2; ++j) P[j].Pnt[i] = {DFT(255 - j, a), i};
  }
  for (unsigned i(0); i < 2; ++i) P[i].Init();
  for (unsigned i(1); i <= m; ++i) {
    Q.Rd(), Flg = 0;
    // if (i == 6) {
    //   for (unsigned j(0); j < 256; ++j) printf("%u", a[j]);
    //   putchar(0x0A);
    //   for (unsigned j(0); j < 256; ++j)
    //     printf("%u", (Q.Val[j >> 6] >> (j & 63)) & 1);
    //   putchar(0x0A);
    //   for (unsigned j(0); j < 256; ++j)
    //     printf("%u", (Wd[470].Val[j >> 6] >> (j & 63)) & 1);
    //   putchar(0x0A);
    // }
    for (unsigned j(0); j < 2; ++j)
      if (P[j].Find(DFT(255 - j, a), Q)) {
        Flg = 1;
        break;
      }
    printf("%u\n", Flg);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}
// g++ P7738_FFT.cpp -o faq -std=c++14 -O2 -Wl,--stack=1024000000
// 0010000000100110100
// 0010000000100110100
// 111100010011100101101111100111110101111001101101101101111000110010101100010011001011000101101100000101111111001100011010101011111110011010110001001101010000111001001101111110010110010110110010011001101110000000001010010011000111110101111
// 111100010011100101101111100111110101111011101101101101111000110010101100010011001111000101111100110101111111001100011010101011011110011010110011000101010000111001001101111110010110010101110010011001101110000000001010011011000111110101111