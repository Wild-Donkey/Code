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
const unsigned long long Mod(1000000007);
unsigned a[1000005], FacInv[1000005], Inv[1000005], Up[1000005], Down[1000005], m, n;
unsigned A, B, C, D, t;
unsigned long long Ans(0);
inline void Mn(unsigned& x) { x -= ((x >= Mod) ? Mod : 0); }
inline void Mn(unsigned long long& x) { x -= ((x >= Mod) ? Mod : 0); }
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) { if (y & 1) Rt = Rt * x % Mod; x = x * x % Mod, y >>= 1; }
  return Rt;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  if (n <= (m + 1)) {
    for (unsigned i(1); i <= n; ++i) Mn(Ans += Pow(i, m));
    printf("%llu\n", Ans);
    return Wild_Donkey;
  }
  for (unsigned i(0); i <= m; ++i) Mn(a[i + 1] = a[i] + Pow(i + 1, m));
  ++m, Up[0] = Down[0] = FacInv[0] = Inv[0] = Inv[1] = 1;
  for (unsigned long long i(0); i < m; ++i) Up[i + 1] = Up[i] * (n - m + i) % Mod;
  for (unsigned long long i(0); i < m; ++i) Down[i + 1] = Down[i] * (n - i) % Mod;
  for (unsigned i(2); i <= m; ++i) Inv[i] = Inv[Mod % i] * (Mod - (Mod / i)) % Mod;
  // printf("Inv:"); for (unsigned i(0); i <= m; ++i) printf("%u ", Inv[i]); putchar(0x0A);
  for (unsigned i(1); i <= m; ++i) FacInv[i] = (unsigned long long)FacInv[i - 1] * Inv[i] % Mod;
  // printf("FacInv:"); for (unsigned i(0); i <= m; ++i) printf("%u ", FacInv[i]); putchar(0x0A);
  // printf("Up:"); for (unsigned i(0); i <= m; ++i) printf("%u ", Up[i]); putchar(0x0A);
  // printf("Down:"); for (unsigned i(0); i <= m; ++i) printf("%u ", Down[i]); putchar(0x0A);
  // printf("a:"); for (unsigned i(0); i <= m; ++i) printf("%u ", a[i]); putchar(0x0A);
  for (unsigned i(m); i < 0x3f3f3f3f; i -= 2)
    Ans = (Ans + ((((unsigned long long)Down[i] * Up[m - i] % Mod) * FacInv[i] % Mod) * FacInv[m - i] % Mod) * a[i]) % Mod;
  for (unsigned i(m - 1); i < 0x3f3f3f3f; i -= 2)
    Ans = (Ans + ((((unsigned long long)Down[i] * Up[m - i] % Mod) * FacInv[i] % Mod) * FacInv[m - i] % Mod) * (Mod - a[i])) % Mod;
  printf("%llu\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}