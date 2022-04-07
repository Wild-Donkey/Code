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
#include <string>
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
const unsigned long long Mod(998244353);
unsigned long long Ans(0), f[2505], C[2505][2505], Fac[2505];
vector<unsigned long long> g[5005];
unsigned m, n;
unsigned A, B, D, t;
unsigned Cnt(0), Tmp(0);
char Bel[5005];
struct Node {
  vector<Node*> To;
  Node* Fa;
  unsigned Size, Size0, Size1, gNum;
}N[5005];
inline void DFS(Node* x) {
  unsigned Mx(0);
  Node* Heavy(NULL);
  for (auto i:x->To) if(i != x->Fa) {
    i->Fa = x, DFS(i);
    if(i->Size > Mx) Heavy = i, Mx = i->Size;
  }
  if(Heavy) {
    x->gNum = Heavy->gNum, x->Size = Heavy->Size, x->Size0 = Heavy->Size0, x->Size1 = Heavy->Size1;
    for (auto i:x->To) if((i != x->Fa) && (i != Heavy)) {
      while (g[x->gNum].size() < ((x->Size + i->Size) >> 1) + 1) g[x->gNum].push_back(0);
      for (unsigned j((x->Size + i->Size) >> 1); j; --j) {
        for (unsigned k(min(i->Size >> 1, j)); k; --k) {
          g[x->gNum][j] = (g[x->gNum][j] + (unsigned long long)g[x->gNum][j - k] * g[i->gNum][k]) % Mod;
        }
      }
      x->Size += i->Size, x->Size0 += i->Size0, x->Size1 += i->Size1;
    }
  } else {
    x->gNum = ++Cnt;
    g[x->gNum].push_back(1);
  }
  if(g[x->gNum].size() < ((x->Size + 1) >> 1) + 1) g[x->gNum].push_back(0);
  if(Bel[x - N] ^ '0') {
    for (unsigned i((x->Size + 1) >> 1); i; --i)
      g[x->gNum][i] = (g[x->gNum][i] + g[x->gNum][i - 1] * (unsigned long long)(x->Size0 - i + 1)) % Mod;
    ++(x->Size1);
  } else {
    for (unsigned i((x->Size + 1) >> 1); i; --i)
      g[x->gNum][i] = (g[x->gNum][i] + g[x->gNum][i - 1] * (unsigned long long)(x->Size1 - i + 1)) % Mod;
    ++(x->Size0);
  }
  ++(x->Size);
//  printf("DFSed %u Size %u Size0 %u Size1 %u\n", x - N, x->Size, x->Size0, x->Size1);
//  for (unsigned i(0); i <= (x->Size >> 1); ++i) {
//    printf("g%u = %u\n", i, x->g[i]);
//  }
}
signed main() {
//  freopen("P6478_15.in", "r", stdin);
//  freopen("P6478.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  scanf("%s", Bel + 1);
  for (unsigned i(1); i < n; ++i) {
    A = RD(), B = RD();
    N[A].To.push_back(N + B);
    N[B].To.push_back(N + A);
  }
  DFS(N + 1);
  n >>= 1;
  Fac[0] = 1;
  for (unsigned i(0); i <= n; ++i) C[i][0] = 1;
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(1); j <= i; ++j) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
      if(C[i][j] >= Mod) C[i][j] -= Mod;
    }
  }
  for (unsigned i(1); i <= n; ++i) Fac[i] = Fac[i - 1] * i % Mod;
  for (unsigned i(0); i <= n; ++i) f[i] = g[N[1].gNum][i] * Fac[n - i] % Mod;
//  for (unsigned i(0); i <= n; ++i) printf("f%u = %llu\n", i, f[i]);
  for (unsigned i(0); i <= n; ++i) {
    Ans = 0;
    for (unsigned j(i); j <= n; ++j) if((i ^ j) & 1) {
      Ans = Mod + Ans - (f[j] * C[j][i] % Mod);
      if(Ans >= Mod) Ans -= Mod;
    } else {
      Ans = (Ans + (f[j] * C[j][i])) % Mod;
    }
    printf("%llu\n", Ans);
  }
  
//  }
  return Wild_Donkey;
}

