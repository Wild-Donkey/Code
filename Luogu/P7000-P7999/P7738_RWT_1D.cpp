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
const char HexList[17] = "084C2A6E195D3B7F";
unsigned long long A, B;
unsigned Blc(1), BlcLen[512];
unsigned C, D, t;
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
inline unsigned PopC(unsigned long long x) {
  if (Debug) printf("Popc %llu\n", x);
  return Pp[x >> 48] + Pp[(x >> 32) & 65535] + Pp[(x >> 16) & 65535] +
         Pp[x & 65535];
}
char a[256], Ang[256], Flg(0);
unsigned n, m, N;
struct Word {
  unsigned long long Val[4];
  inline void Rd() {
    scanf("%s", a), C = RD();
    for (unsigned i(63); ~i; --i) Val[i >> 4] <<= 4, Val[i >> 4] |= Hex[a[i]];
    if (Flg)
      for (unsigned i(0); i < 4; ++i) Val[i] ^= 0xFFFFFFFFFFFFFFFF;
    for (unsigned i(0); i < 256; ++i) a[i] = ((Val[i >> 6] >> (i & 63)) & 1);
  }
  inline unsigned RWT() {
    unsigned Rt(256);
    for (unsigned i(0); i < 256; ++i)
      if ((Val[i >> 6] >> (i & 63)) & 1) Rt = (Ang[i] ? (Rt + 1) : (Rt - 1));
    return Rt;
  }
  inline const unsigned Diff(const Word& x) const {
    unsigned Rt(0);
    for (unsigned i(0); i < 4; ++i) Rt += PopC(Val[i] ^ x.Val[i]);
    return Rt;
  }
} Wd[400005], Q;
vector<unsigned> List[513];
inline char Find() {
  unsigned L(Q.RWT()), R(L + C);
  L = ((L >= C) ? (L - C) : 0), R = ((R < 513) ? R : 512);
  for (unsigned j(L); j <= R; ++j)
    for (auto i : List[j])
      if (Q.Diff(Wd[i]) <= C) return 1;
  return 0;
}
//  inline void Clr() {}
signed main() {
  // freopen("Test.in", "r", stdin);
  // freopen("P7738_-2.in", "r", stdin);
  // freopen("P7738.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  for (unsigned i(0); i < 65536; ++i) Pp[i] = Pp[i >> 1] + (i & 1);
  for (unsigned i(0); i < 16; ++i) Hex[HexList[i]] = i;
  N = n = RD(), N += ((m = RD()) << 1), A = RDll(), B = RDll();
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(0); j < 256; ++j)
      a[j] = (myRand() & ((unsigned long long)1 << 32)) ? 1 : 0;
    for (unsigned j(255); ~j; --j)
      Wd[i].Val[j >> 6] <<= 1, Wd[i].Val[j >> 6] |= a[j];
  }
  for (unsigned j(0); j < 256; ++j)
    Ang[j] = (myRand() & ((unsigned long long)1 << 32)) ? 1 : 0;
  for (unsigned i(1); i <= n; ++i) List[Wd[i].RWT()].push_back(i);
  for (unsigned i(1); i <= m; ++i) {
    Q.Rd(), Flg = 0, Flg = Find();
    printf("%u\n", Flg);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}
// g++ P7738_RWT_1D.cpp -o faq -std=c++14 -O2 -Wl,--stack=1024000000