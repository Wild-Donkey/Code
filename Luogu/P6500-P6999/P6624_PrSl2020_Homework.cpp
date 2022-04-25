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
const unsigned long long Mod(998244353), InTwo(499122177);
bitset<153000> No;
unsigned P[20000], CntP(0), Mu[153000];
unsigned E[455][3];
vector<unsigned> Edge[153000];
unsigned f[153000];
unsigned Pool[900], *Mat[30];
unsigned Fa[31], Stack[31], *STop(Stack), m, n, N, Size, A, B, C, D;
unsigned long long Ans(0), Tmp(0);
inline void Mn(unsigned& x) {x -= (x >= Mod) ? Mod : 0;}
inline unsigned Find (unsigned x) {
  while (x ^ Fa[x]) *(++STop) = x, x = Fa[x];
  while (STop > Stack) Fa[*(STop--)] = x;
  return x;
}
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) { if(y & 1) Rt = Rt * x % Mod; x = x * x % Mod, y >>= 1; }
  return Rt;
}
inline unsigned long long Calc () {
//  for (unsigned i(0); i < N; ++i) {
//    for (unsigned j(0); j < N; ++j) printf("%u ", Mat[i][j]); putchar(0x0A);
//  }
  unsigned long long Rt(1);
  for (unsigned i(1); i < N; ++i) {
    unsigned Wr(i);
    while ((Wr < N) && (!Mat[Wr][i])) ++Wr;
    if(Wr == N) return 0;
    if(Wr ^ i) swap(Mat[Wr], Mat[i]), Rt = Mod - Rt;
    Rt = Rt * Mat[i][i] % Mod;
    unsigned long long Mul(Pow(Mat[i][i], 998244351));
    for (unsigned j(i); j < N; ++j) Mat[i][j] = Mat[i][j] * Mul % Mod;
    for (unsigned j(i + 1); j < N; ++j) {
      Mul = Mod - Mat[j][i];
      for (unsigned k(i); k < N; ++k) Mat[j][k] = (Mat[j][k] + Mul * Mat[i][k]) % Mod;
    }
  }
//  printf("%u\n", Rt);
  return Rt;
}
signed main() {
//  freopen("count2.in", "r", stdin);
//  freopen(".out", "w", stdout);
  N = (n = RD()) - 1, m = RD(), Mu[1] = 1, Mat[0] = Pool, Size = ((N * N) << 2);
  for (unsigned i(2); i <= 152501; ++i) {
    if(!No[i]) P[++CntP] = i, Mu[i] = 998244352;
    for (unsigned j(1), k(2); (j <= CntP) && (k * i <= 152501); k = P[++j]) {
      No[i * k] = 1;
      if(!(i % k)) { Mu[i * k] = 0; break; }
      Mu[i * k] = (unsigned long long)Mu[i] * Mu[k] % Mod;
    }
  }
  for (unsigned i(1); i < N; ++i) Mat[i] = Mat[i - 1] + n - 1;
//  for (unsigned i(1); i <= 100; ++i) printf("%u ", Mu[i]); putchar(0x0A);
  for (unsigned i(1); i <= m; ++i) {
    E[i][0] = A = RD(), E[i][1] = B = RD(), D = sqrt(E[i][2] = C = RD());
    if(!(C % D)) {Edge[D].push_back(i); if((D * D) ^ C) Edge[C / D].push_back(i);}
    for (unsigned j(D - 1); j; --j) if(!(C % j))
      Edge[j].push_back(i), Edge[C / j].push_back(i);
  }
  for (unsigned i(1); i <= 152501; ++i) {
//    printf("%u : %u\n", i, Mu[i]);
//    printf("Size of %u = %u\n", i, Edge[i].size());
    if(Edge[i].size() < N) continue;
    for (unsigned j(1); j <= n; ++j) Fa[j] = j;
    C = n;
    for (auto j:Edge[i]) {
      A = Find(E[j][0]), B = Find(E[j][1]);
      if(A ^ B) Fa[A] = B, --C;
    }
    if(C > 1) continue;
    Tmp = 0;
//    printf("%u:", i); for (auto j:Edge[i]) printf("%u ", j); putchar(0x0A);
    for (auto j:Edge[i]) {
//      printf("Contr of %u\n", j);
      memset(Pool, 0, Size), A = E[j][0], B = E[j][1];
      for (auto k:Edge[i]) if(k ^ j) {
        C = E[k][0], D = E[k][1];
        if((C == A) || (C == B)) C = 0; else C -= (C > A) + (C > B); 
        if((D == A) || (D == B)) D = 0; else D -= (D > A) + (D > B);
//        printf("Link %u %u %u\n", k, C, D);
        Mn(Mat[D][C] += 998244352), Mn(Mat[C][D] += 998244352), ++Mat[C][C], ++Mat[D][D];
      }
      Tmp += Calc() * E[j][2];
    }
    f[i] = Tmp % Mod;
  }
//  for (unsigned i(1); i <= 100; ++i) printf("%u ", f[i]); putchar(0x0A);
//  for (unsigned i(1); i <= 152501; ++i) if(f[i]) printf("(%u, %u)", i, f[i]); putchar(0x0A);
  for (unsigned i(1); i <= 152501; ++i) {
    Tmp = 0;
//     D = sqrt(C = i);
//    Tmp = (Tmp + (unsigned long long)f[D] * Mu[C / D]) % Mod;
//    if((D * D) ^ C) Tmp = (Tmp + (unsigned long long)f[C / D] * Mu[D]) % Mod;
//    for (unsigned j(D - 1); j; --j) if(!(C % j)) {
//      Tmp = (Tmp + (unsigned long long)f[j] * Mu[C / j]) % Mod;
//      Tmp = (Tmp + (unsigned long long)f[C / j] * Mu[j]) % Mod;
//    }
//    for (unsigned j(152501 / i), k(i * j); j; --j, k -= i) Tmp = (Tmp + (unsigned long long)f[k] * Mu[j]) % Mod;
    for (unsigned j(152501 / i), k(i * j); j; --j, k -= i) {
      Tmp = (Tmp + (unsigned long long)f[k] * Mu[j]) % Mod;
//      if((i == 2) && (f[k])) printf("%llu j, k (%u, %u) %u %u\n", Tmp, j, k, Mu[j], f[k]);
    }
//    if(Tmp) printf("Gcd %u = %llu\n", i, Tmp);
    Ans = (Ans + (Tmp * i)) % Mod;
  }
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}
/*
4 6
1 2 100000
2 3 100000
1 3 100000
2 4 100000
3 4 100000
1 4 100000

4 6
1 2 10000
2 3 10000
1 3 10000
2 4 10000
3 4 10000
1 4 10000

4 6
1 2 113400
2 3 131040
1 3 126000
2 4 90720
3 4 95760
1 4 131040

4 6
1 2 11340
2 3 13104
1 3 12600
2 4 9072
3 4 9576
1 4 13104

4 6
1 2 11340
2 3 13104
1 3 12600
2 4 9072
3 4 9576
1 4 13104
*/
