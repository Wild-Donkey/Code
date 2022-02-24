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
const unsigned long long Mod(1000000007);
struct Matrix {
  unsigned V[2][2];
  inline Matrix operator* (Matrix& x) {
    Matrix Rt;
    Rt.V[0][0] = ((unsigned long long)V[0][0] * x.V[0][0] + (unsigned long long)V[0][1] * x.V[1][0]) % Mod;
    Rt.V[0][1] = ((unsigned long long)V[0][0] * x.V[0][1] + (unsigned long long)V[0][1] * x.V[1][1]) % Mod;
    Rt.V[1][0] = ((unsigned long long)V[1][0] * x.V[0][0] + (unsigned long long)V[1][1] * x.V[1][0]) % Mod;
    Rt.V[1][1] = ((unsigned long long)V[1][0] * x.V[0][1] + (unsigned long long)V[1][1] * x.V[1][1]) % Mod;
    return Rt;
  }
  inline Matrix Pow(unsigned x) {
    Matrix PTmp(*this), Rt;
    Rt.V[0][0] = Rt.V[1][1] = 1, Rt.V[0][1] = Rt.V[1][0] = 0;
    while (x) { if (x & 1) Rt = Rt * PTmp; PTmp = PTmp * PTmp, x >>= 1; }
    return Rt;
  }
}Ori, fT[132005];
unsigned long long Ans(0), f[132005], a[20];
unsigned A, B, C, D, t, P[20], m, n;
unsigned Cnt(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  m = (1 << (n = RD())), Ori.V[0][0] = 0, Ori.V[1][0] = 1, Ori.V[1][1] = RD(), Ori.V[0][1] = RD();
  for (unsigned i(0); i < n; ++i) P[i] = RD(), a[i] = RD();
  fT[0] = Ori;//fT[0].V[1][1] = fT[0].V[0][0] = 1, fT[0].V[1][0] = fT[0].V[0][1] = 0;
  // for (unsigned i(1); i <= 10; ++i) {
  //   printf("%u:\n", i);
  //   Matrix AM(Ori.Pow(i)), BM(fT[0]), CM(BM * AM);
  //   printf("%u %u\n%u %u\n", BM.V[0][0], BM.V[0][1], BM.V[1][0], BM.V[1][1]);
  //   printf("%u %u\n%u %u\n", AM.V[0][0], AM.V[0][1], AM.V[1][0], AM.V[1][1]);
  //   printf("%u %u\n%u %u\n", CM.V[0][0], CM.V[0][1], CM.V[1][0], CM.V[1][1]);
  // }
  for (unsigned i(0), k(1); i < n; ++i, k <<= 1)
    for (unsigned j(k - 1); ~j; --j) fT[j ^ k] = fT[j].Pow(P[i]);
  for (unsigned i(0); i < m; ++i) f[i] = 1;
  for (unsigned i(0), k(1); i < n; ++i, k <<= 1)
    for (unsigned j(k - 1); ~j; --j) f[j ^ k] = f[j] * a[i] % Mod;
  Ori.V[0][1] = Ori.V[0][0] = 1, Ori.V[1][0] = Ori.V[1][1] = 0;
  for (unsigned i(0); i < m; ++i) fT[i] = Ori * fT[i];
  // for (unsigned i(0); i < m; ++i) printf("%llu ", f[i]); putchar(0x0A);
  // for (unsigned i(0); i < m; ++i) printf("%u ", fT[i].V[0][1]); putchar(0x0A);
  for (unsigned i(0); i < m; ++i) Ans = (Ans + f[i] * fT[i].V[0][0]) % Mod;
  printf("%llu\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}