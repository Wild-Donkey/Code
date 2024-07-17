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
bitset<100005> NO;
unsigned a[761000][3], Mu[100005], Dev[100005];
unsigned Deg[100005], Pri[10005], CntP(0);
vector<pair<unsigned, unsigned> > E[100005];
unsigned g[100005];
unsigned CntE(0), A, B, C, t;
unsigned n, m, Ans(0);
unsigned Lcm1, Lcm2, Lcm3, MulMu;
unsigned Lcm, Cur1(1), Cur2(1);
inline void Clr() {
  for(unsigned i(1); i <= n; ++i) E[i].clear();
  memset(Deg, 0, (n + 1) << 2);
  A = RD(), B = RD(), C = RD();
  n = max(A, max(B, C)), Ans = m = 0;
}
inline void DFS2(unsigned x) {
  if(x == 1) {
    unsigned To((Lcm / Cur1) * Cur2);
    if(Cur1 >= To) return;
    ++Deg[a[++m][0] = Cur1];
    ++Deg[a[m][1] = To];
    a[m][2] = Lcm;
    return;
  }
  Cur2 *= Dev[x];
  DFS2(x / Dev[x]);
  Cur2 /= Dev[x];
  DFS2(x / Dev[x]);
}
inline void DFS(unsigned x) {
  if(x == 1) {return DFS2(Cur1);}
  Cur1 *= Dev[x];
  DFS(x / Dev[x]);
  Cur1 /= Dev[x];
  DFS(x / Dev[x]);
}
inline unsigned long long Calc() {
//  printf("Calc %u %u %u\n", Lcm1, Lcm2, Lcm3);
  unsigned long long A1(g[A / Lcm1]), A2(g[A / Lcm2]), A3(g[A / Lcm3]);
  unsigned long long B1(g[B / Lcm1]), B2(g[B / Lcm2]), B3(g[B / Lcm3]);
  unsigned long long C1(g[C / Lcm1]), C2(g[C / Lcm2]), C3(g[C / Lcm3]);
  return (A1 * ((B2 * C3 + B3 * C2) % Mod)
        + A2 * ((B1 * C3 + B3 * C1) % Mod)
        + A3 * ((B1 * C2 + B2 * C1) % Mod)) % Mod;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  Mu[1] = 1;
  for (unsigned i(2); i <= 100000; ++i) {
    if(!NO[i]) Mu[i] = 1000000006, Dev[i] = Pri[++CntP] = i;
    for (unsigned j(1), k(2); (k * i <= 100000) && (j <= CntP); k = Pri[++j]) {
      NO[k * i] = 1, Dev[k * i] = k;
      if(Mu[i]) Mu[k * i] = ((Mu[i] ^ 1) ? 1 : 1000000006);
      if(!(i % k)) {Mu[i * k] = 0; break;}
    }
  }
//  for (unsigned i(1); i <= 100; ++i) printf("%u ", Mu[i]); putchar(0x0A);
//  for (unsigned i(1); i <= 100; ++i) printf("%u ", Dev[i]); putchar(0x0A);
  for (unsigned i(1); i <= 100000; ++i) {
    unsigned &Tmp(g[i]);
//    printf("%u\n", i);
    for (unsigned long long L, R(Tmp = 0), Cur; R < i; ) {
      L = R + 1, Cur = i / L, R = i / Cur;
//      printf("[%u, %u]\n", L, R);
      Tmp = (Tmp + (R - L + 1) * Cur) % Mod;
    }
  }
//  for (unsigned i(1); i <= 100; ++i) printf("%u ", g[i]); putchar(0x0A);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (Lcm = 1; Lcm <= n; ++Lcm) if(Mu[Lcm]) Cur1 = 1, DFS(Lcm);// printf("Done %u %u\n", Lcm, m);
//    printf("CntE %u\n", m); 
//    for (unsigned i(1); i <= m; ++i) printf("Edge From %u %u Lcm %u\n", a[i][0], a[i][1], a[i][2]);
    for (unsigned i(1); i <= m; ++i) {
      unsigned Ta(a[i][0]), Tb(a[i][1]);
      if(Deg[Ta] < Deg[Tb]) {E[Ta].push_back({Tb, a[i][2]}); continue;}
      if(Deg[Ta] > Deg[Tb]) {E[Tb].push_back({Ta, a[i][2]}); continue;}
      if(Ta > Tb) E[Tb].push_back({Ta, a[i][2]});
      else E[Ta].push_back({Tb, a[i][2]});
    }
    for (unsigned i(1); i <= n; ++i) sort(E[i].begin(), E[i].end());
//    printf("Single %u\n", Ans);
    for (unsigned i(1); i <= n; ++i) if(Mu[i]) {
      Ans = (Ans + ((((unsigned long long)Mu[i] * g[A / i] % Mod) * g[B / i] % Mod) * g[C / i])) % Mod;
      unsigned long long Ai(g[A / i]), Bi(g[B / i]), Ci(g[C / i]);
      for (auto j:E[i]) {
        unsigned long long Aj(g[A / j.second]), Bj(g[B / j.second]), Cj(g[C / j.second]);
        unsigned long long Tmp((Aj * Bj % Mod) * Ci % Mod);
        Tmp = (Tmp + (Aj * Cj % Mod) * Bi) % Mod;
        Tmp = (Tmp + (Bj * Cj % Mod) * Ai) % Mod;
//        printf("Add %u %u\n", Mu[j.first], Tmp);
        Ans = (Ans + Mu[j.first] * Tmp) % Mod;
        Tmp = ((Aj * Bj % Mod) * g[C / j.first] + (Aj * Cj % Mod) * g[B / j.first]) % Mod;
        Tmp = (Tmp + (Bj * Cj % Mod) * g[A / j.first]) % Mod;
//        printf("Add %u %u\n", Mu[i], Tmp); 
        Ans = (Ans + Mu[i] * Tmp) % Mod;
      }
    }
//    printf("Double %u\n", Ans);
    for (unsigned i(1); i <= n; ++i) if(Mu[i]) {
      unsigned Lim(E[i].size() - 1);
      for (auto j:E[i]) {
        unsigned l(0);
        Lcm1 = j.second, MulMu = Mu[i];
        if(Mu[j.first] ^ 1) MulMu = ((MulMu ^ 1) ? 1 : 1000000006);
//        printf("%u -> %u\n", i, j.first);
        for (auto k:E[j.first]) {
          while ((l < Lim) && (E[i][l].first < k.first)) ++l;
          if((E[i][l].first) ^ (k.first)) continue;
          unsigned MulMuk(MulMu);
          if(Mu[k.first] ^ 1) MulMuk = ((MulMuk ^ 1) ? 1 : 1000000006);
//          printf("l %u Eil %u k %u\n", l, E[i][l].first, k.first);
          Lcm2 = k.second, Lcm3 = E[i][l].second;
//          printf("(%u, %u, %u) Mul %u\n", i, j.first, k.first, MulMu);
          Ans = (Ans + MulMuk * Calc()) % Mod;
        }
      }
    }
    printf("%u\n", Ans);
//    printf("%u %u\n", Ans, m);
  }
  return Wild_Donkey;
}
/*
1
10 10 10
*/
