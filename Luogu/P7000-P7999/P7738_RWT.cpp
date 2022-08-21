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
const double Pie(3.141592653589793238462643383279502884197169399);
const unsigned Num(6), Side(10);
const char HexList[17] = "084C2A6E195D3B7F";
unsigned long long A, B;
unsigned Blc(1), BlcLen[512];
char Debug(0);
char Pp[65536], Hex[256];
inline void Mn(unsigned& x) { x -= ((x >= 256) ? 256 : 0); }
inline const double Sqr(const double& x) { return x * x; }
inline unsigned long long myRand() {
  unsigned long long k3(A), k4(B);
  A = k4, k3 ^= (k3 << 23);
  B = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
  return B + k4;
}
inline double RandomAng() { return ((myRand() % 1048576) * Pie) / 524288; }
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
  inline double Angle() {
    double Rt(atan(Vir / Rel));
    return Rt + ((Vir < 0) ? Pie : ((Rel < 0) ? (Pie * 2) : 0));
  }
  inline double Model() { return sqrt(Sqr(Vir) + Sqr(Rel)); }
};
char a[256], Flg(0);
unsigned n, m;
inline void Build(unsigned L, unsigned R, unsigned x, unsigned y) {
  BlcLen[x] = L;
  if (y == 1) return;
  unsigned Mid((L + R) >> 1);
  Build(L, Mid, x, y >> 1);
  Build(Mid + 1, R, x + (y >> 1), y >> 1);
}
unsigned C, D, t;
pair<double, double> List[400005];
pair<unsigned short, unsigned short> Bel[400005];
struct Word {
  unsigned long long Val[4];
  inline void Rd() {
    scanf("%s", a), C = RD();
    for (unsigned i(63); ~i; --i) Val[i >> 4] <<= 4, Val[i >> 4] |= Hex[a[i]];
    if (Flg)
      for (unsigned i(0); i < 4; ++i) Val[i] ^= 0xFFFFFFFFFFFFFFFF;
    for (unsigned i(0); i < 256; ++i) a[i] = ((Val[i >> 6] >> (i & 63)) & 1);
  }
  inline pair<double, double> RWT(Comp* W) {
    Comp Rt;
    Rt = {0, 0};
    for (unsigned i(0); i < 256; ++i)
      if ((Val[i >> 6] >> (i & 63)) & 1) Rt += W[i];
    return {Rt.Angle(), Rt.Model()};
  }
  inline const unsigned Diff(const Word& x) const {
    unsigned Rt(0);
    for (unsigned i(0); i < 4; ++i) Rt += PopC(Val[i] ^ x.Val[i]);
    return Rt;
  }
} Wd[400005], Q;
struct Plane {
  Comp Ang[256];
  double ALi[512], BLi[512];
  vector<unsigned> Table[512][512];
  inline void Print() {
    // for (unsigned i(1); i <= n; ++i);
  }
  inline void Init() {
    double TmpA;
    pair<double, unsigned> TmpB[n + 1];
    for (unsigned i(0); i < 256; ++i)
      TmpA = RandomAng(), Ang[i] = {cos(TmpA), sin(TmpA)};
    for (unsigned i(1); i <= n; ++i) List[i] = Wd[i].RWT(Ang);
    for (unsigned i(1); i <= n; ++i) TmpB[i] = {List[i].first, i};
    sort(TmpB + 1, TmpB + n + 1), ALi[0] = 0;
    for (unsigned i(1), j(0); i <= n; ++i) {
      if (i >= BlcLen[j + 1]) ALi[++j] = TmpB[i].first;
      Bel[TmpB[i].second].first = j;
    }
    for (unsigned i(1); i <= n; ++i) TmpB[i] = {List[i].second, i};
    sort(TmpB + 1, TmpB + n + 1), BLi[0] = 0;
    for (unsigned i(1), j(0); i <= n; ++i) {
      if (i >= BlcLen[j + 1]) BLi[++j] = TmpB[i].first;
      Bel[TmpB[i].second].second = j;
    }
    for (unsigned i(1); i <= n; ++i)
      Table[Bel[i].first][Bel[i].second].push_back(i);
  }
  inline char Find() {
    pair<double, double> Fd(Q.RWT(Ang));
    unsigned Mid1(lower_bound(ALi, ALi + Blc, Fd.first) - ALi);
    unsigned L2, Mid2(lower_bound(BLi, BLi + Blc, Fd.first) - BLi), R2;
    Mid1 = min(Blc - 1, Mid1), Mid2 = min(Blc - 1, Mid2);
    L2 = ((Mid2 >= Side) ? (Mid2 - Side) : 0),
    R2 = ((Mid2 + Side < Blc) ? (Mid2 + Side) : Blc - 1);
    for (unsigned k(0), K(Mid1); k <= Side;
         ++k, K = ((K == Blc - 1) ? 0 : (K + 1)))
      for (unsigned j(L2); j <= R2; ++j)
        for (auto i : Table[k][j])
          if (Q.Diff(Wd[i]) <= C) return 1;
    for (unsigned k(1), K(Mid1 - 1); k <= Side; ++k, --K) {
      K = ((K > 0x3f3f3f3f) ? (Blc - 1) : K);
      for (unsigned j(L2); j <= R2; ++j)
        for (auto i : Table[k][j])
          if (Q.Diff(Wd[i]) <= C) return 1;
    }
    return 0;
  }
} P[Num];
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
  n = RD(), m = RD(), A = RDll(), B = RDll();
  while ((Blc * Blc) <= n) Blc <<= 1;
  Blc >>= 1, Build(1, n, 0, Blc);
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(0); j < 256; ++j)
      a[j] = (myRand() & ((unsigned long long)1 << 32)) ? 1 : 0;
    for (unsigned j(255); ~j; --j)
      Wd[i].Val[j >> 6] <<= 1, Wd[i].Val[j >> 6] |= a[j];
  }
  for (unsigned i(0); i < Num; ++i) P[i].Init();
  // printf("FAq");
  for (unsigned i(1); i <= m; ++i) {
    Q.Rd(), Flg = 0;
    for (unsigned j(0); j < Num; ++j)
      if (P[j].Find()) {
        Flg = 1;
        break;
      }
    printf("%u\n", Flg);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}
// g++ P7738_RWT.cpp -o faq -std=c++14 -O2 -Wl,--stack=1024000000