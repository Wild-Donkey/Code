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
#define Inver(x) Pow(x,1000000005)
using namespace std;
const unsigned long long Mod(1000000007);
inline void Mn(unsigned long long& x) {x -= ((x >= Mod) ? Mod : 0);}
inline void Mn(unsigned& x) {x -= ((x >= Mod) ? Mod : 0);}
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) { if(y & 1) Rt = Rt * x % Mod; x = x * x % Mod, y >>= 1; }
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
unsigned C[2505][2505], *CC, CnC2[2505], CnC[2505], CnCI[2505], m, n;
unsigned A, B, D, t;
unsigned long long Ans(0);
inline unsigned long long Calc(unsigned x) {
//  printf("Calc %u\n", x);
  unsigned long long CnCPow(1), CnCInv(1), TmpA(0);
  for (unsigned i(0); i <= m; ++i) {
    CnCInv = 1;
    for (unsigned j(0); j <= m; ++j) {
      TmpA = (TmpA + ((min(i, j) * CnCPow % Mod) * CnCInv % Mod) * ((unsigned long long)CC[i] * CC[j] % Mod)) % Mod;
      CnCInv = CnCInv * CnCI[x] % Mod;
    }
    CnCPow = CnCPow * CnC[x] % Mod;
  }
//  printf("%u Ans")
  return (TmpA << 1) * CnC2[x] % Mod;
}
struct Node {
  vector<pair<Node*, unsigned> > E;
  inline unsigned DFS(Node* Fa) {
    unsigned Size(1), Val(0);
    for (auto i:E) if((i.first) != Fa) Size += i.first->DFS(this); else Val = i.second;
    if(Val) Ans = (Ans + Calc(Size) * Val) % Mod;
//    printf("Size %u\n", Size);
    return Size;
  }
}N[2505];
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i < n; ++i) {
    A = RD(), B = RD(), D = RD();
    N[A].E.push_back({N + B, D});
    N[B].E.push_back({N + A, D});
  }
  for (unsigned i(0); i <= m; ++i) {
    C[i][0] = 1;
    for (unsigned j(1); j <= i; ++j) 
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1], Mn(C[i][j]);
  }
  CC = C[m];
  for (unsigned i(1); i <= n; ++i) CnC[i] = i * Inver(n - i) % Mod;
  for (unsigned i(1); i <= n; ++i) CnCI[i] = (n - i) * Inver(i) % Mod;
  for (unsigned i(1); i <= n; ++i) CnC2[i] = Pow((unsigned long long)i * (n - i) % Mod, m);
//  printf("Done\n");
  N[1].DFS(NULL);
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}

