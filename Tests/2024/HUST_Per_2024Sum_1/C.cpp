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
const unsigned long long Mod(1000000007);
unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) {
    if (y & 1) Rt = Rt * x % Mod;
    x = x * x % Mod, y >>= 1;
  }
  return Rt;
}
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
void Mn(unsigned& x) { x -= (x >= Mod ? Mod : 0); }
void Mn(unsigned long long& x) { x -= (x >= Mod ? Mod : 0); }
unsigned long long Fac[1000006], Inv[1000006], I3[1000006], I2[1000006], P2[1000006], P3[1000006];
unsigned long long SumJ[1000006], SumI[1000006];
unsigned long long  m, n;
unsigned long long Ans(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = (RD() + 2) / 3, m = n * 3, Fac[0] = 1, P3[0] = P2[0] = 1;
  for (unsigned i(1); i <= m; ++i) Fac[i] = (unsigned long long)Fac[i - 1] * i % Mod;
  for (unsigned i(1); i <= m; ++i) P3[i] = ((P3[i - 1] << 1) + P3[i - 1]), Mn(P3[i]), Mn(P3[i]);
  for (unsigned i(1); i <= m; ++i) P2[i] = (P2[i - 1] << 1), Mn(P2[i]);
  Inv[m] = Pow(Fac[m], Mod - 2), I2[m] = Pow(P2[m], Mod - 2), I3[m] = Pow(P3[m], Mod - 2);
  for (unsigned i(m); i; --i) Inv[i - 1] = (unsigned long long)Inv[i] * i % Mod;
  for (unsigned i(m); i; --i) I2[i - 1] = (I2[i] << 1), Mn(I2[i - 1]);
  for (unsigned i(m); i; --i) I3[i - 1] = ((I3[i] << 1) + I3[i]), Mn(I3[i - 1]), Mn(I3[i - 1]);
  SumI[n - 1] = 0, SumJ[(n << 1) - 1] = 0;
  for (unsigned i(n); i <= m; ++i)
    SumI[i] = (SumI[i - 1] + ((Fac[i - 1] * Inv[n - 1] % Mod) * (Inv[i - n] * I3[i] % Mod) % Mod) * P2[i]) % Mod;
  for (unsigned j(n << 1); j <= m; ++j)
    SumJ[j] = (SumJ[j - 1] + ((Fac[j - n - 1] * Inv[n - 1] % Mod) * (Inv[j - (n << 1)] * I2[j] % Mod))) % Mod;
  // for (unsigned i(0); i <= m; ++i) printf("I3 %u %u\n", i, I3[i]);
  // for (unsigned i(0); i <= m; ++i) printf("I2 %u %u\n", i, I2[i]);
  // for (unsigned i(0); i <= m; ++i) printf("Inv %u %u\n", i, Inv[i]);
  // for (unsigned i(0); i <= m; ++i) printf("SumI %u %u\n", i, SumI[i]);
  // for (unsigned i(0); i <= m; ++i) printf("SumJ %u %u\n", i, SumJ[i]);
  for (unsigned long long i(n); i < m - 1; ++i) {
    Tmp = Mod + SumJ[m - 1] - SumJ[max(i + 1, n << 1) - 1], Mn(Tmp);
    // printf("Tmp %llu\n", Tmp);
    Ans = (Ans + (((m + i - 3) * Fac[i - 1] % Mod) * (Inv[n - 1] * Inv[i - n] % Mod) % Mod) * ((P2[i] * I3[i] % Mod) * Tmp % Mod)) % Mod;
  }
  // printf("%llu\n", Ans);
  for (unsigned j(n << 1); j < m; ++j) {
    Tmp = Mod + SumI[j - 1] - SumI[n - 1], Mn(Tmp);
    Ans = (Ans + ((j * Fac[j - n - 1] % Mod) * (Inv[n - 1] * Inv[j - (n << 1)] % Mod) % Mod) * (I2[j] * Tmp % Mod)) % Mod;
  }
  printf("%llu\n", Ans * 6 % Mod);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
55324509
490509698
*/