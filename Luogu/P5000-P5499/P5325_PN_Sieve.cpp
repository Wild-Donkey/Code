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
inline unsigned long long RD() {
  unsigned long long intmp(0);
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
unsigned G[5000005], GM[1000005];
unsigned Pri[500005], CntP(0), m;
const unsigned long long Mod(1000000007), INV6(166666668), INV2(500000004);
unsigned long long Ans(0), n, Now(1), H(1);
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
bitset<5000005> Ava;
inline unsigned GS(unsigned long long x) {
  // printf("Find %llu m = %u\n", x, m);
  if (x <= m) return G[x];
  if (GM[n / x]) return GM[n / x];
  unsigned long long X(x % Mod), GTmp((((X * X % Mod) * X) << 1) % Mod);
  GTmp = (GTmp + (3 * (X * X))) % Mod;
  GTmp = (GTmp + X) * INV6 % Mod;
  // printf("GTMp %llu\n", GTmp);
  for (unsigned long long L, R(1), Cur; R < x; ) {
    L = R + 1, Cur = x / L, R = x / Cur;
    unsigned long long RL((R + L) % Mod), LR((R - L + 1) % Mod);
    GTmp += Mod - (((RL * LR % Mod) * INV2 % Mod) * GS(Cur) % Mod);
  }
  // printf("G %llu = %u\n", x, GM[x]);
  return GM[n / x] = GTmp % Mod;
}
inline void DFS(unsigned Dep) {
  // printf("Dep %u Num %llu\n", Dep, Now);
  if ((Dep > CntP) || ((n / Now) < (unsigned long long)Pri[Dep] * Pri[Dep])) {
    unsigned long long Cur(n / Now);
    // printf("PN = %llu %llu %u\n", Now, H, GS(n / Now));
    Ans = (Ans + H * ((Cur <= m) ? G[Cur] : GM[n / Cur])) % Mod;
    // printf("Done\n");
    return;
  }
  unsigned long long Cur(Pri[Dep]), PriP(1), LaH(H), HPA(0), LaN(Now);
  unsigned Poi(0);
  DFS(Dep + 1);
  // printf("%llu / %llu %u\n", n, Now, Cur);
  while ((n / Now) >= Cur) {
    Now *= Pri[Dep], PriP *= Pri[Dep], ++Poi, H = LaH * (HPA * PriP % Mod) % Mod, HPA += Cur - 1;
    // printf("Poi %u Num %llu H %llu PA %llu HPA %llu\n", Poi, Now, H, PriP, HPA);
    if (Poi ^ 1) DFS(Dep + 1);
  }
  H = LaH, Now = LaN;
  return;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = min(n, (unsigned long long)5000000), G[1] = 1;
  if (n == 1) { printf("1\n"); return 0; }
  for (unsigned i(2); i <= m; ++i) {
    if (!Ava[i]) { Pri[++CntP] = i, G[i] = (unsigned long long)i * (i - 1) % Mod; }
    for (unsigned j(1); (i * Pri[j] <= m) && (j <= CntP); ++j) {
      unsigned CP(Pri[j]), Cur(i * CP);
      Ava[Cur] = 1, G[Cur] = (unsigned long long)G[i] * G[CP] % Mod;
      if (!(i % CP)) { G[Cur] = ((unsigned long long)G[i] * CP % Mod) * CP % Mod; break; }
    }
  }
  while ((unsigned long long)Pri[CntP] * Pri[CntP] > n) --CntP; ++CntP;
  // for (unsigned i(1); i <= m; ++i) printf("%u ", G[i]); putchar(0x0A);
  for (unsigned i(2); i <= m; ++i) G[i] += G[i - 1], G[i] -= ((G[i] >= Mod) ? Mod : 0);
  // for (unsigned i(1); i <= m; ++i) printf("%u ", G[i]); putchar(0x0A);
  GS(n), DFS(1);
  printf("%llu\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}