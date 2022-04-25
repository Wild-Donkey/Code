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
unsigned C[2505][2505], *CC, m, n;
unsigned PreAns[2505];
unsigned A, B, D, t;
unsigned long long Ans(0);
struct Node {
  vector<pair<Node*, unsigned> > E;
  inline unsigned DFS(Node* Fa) {
    unsigned Size(1), Val(0);
    for (auto i:E) if((i.first) != Fa) Size += i.first->DFS(this); else Val = i.second;
    Ans = (Ans + (unsigned long long)PreAns[Size] * Val) % Mod;
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
  for (unsigned i(1); i <= n; ++i) {
    unsigned long long CnC(i * Inver(n - i) % Mod), CnCI((n - i) * Inver(i) % Mod);
    unsigned long long CnCm(Pow(CnC, m)), CnCIm(Pow(CnCI, m));
    unsigned long long CnC2(Pow((unsigned long long)i * (n - i) % Mod, m));
    unsigned long long CnCPow(CnCm), CnCInv(CnCIm), SumAf(0); 
    for (unsigned j(m); ~j; --j) {
      SumAf = (SumAf + CnCInv * CC[j]) % Mod, CnCInv = CnCInv * CnC % Mod;
      PreAns[i] = (PreAns[i] + ((j * CnCPow % Mod) * (CC[j] % Mod) % Mod) * SumAf) % Mod;
      CnCPow = CnCPow * CnCI % Mod;
    }
    CnCPow = CnCm * CnCI % Mod, CnCInv = CnCIm * CnC % Mod, SumAf = CnCm * CC[m] % Mod;
    for (unsigned j(m - 1); ~j; --j) {
      PreAns[i] = (PreAns[i] + ((j * CnCInv % Mod) * (CC[j] % Mod) % Mod) * SumAf) % Mod;
      SumAf = (SumAf + CnCPow * CC[j]) % Mod;
      CnCPow = CnCPow * CnCI % Mod, CnCInv = CnCInv * CnC % Mod;
    }
    PreAns[i] = PreAns[i] * CnC2 % Mod;
//    printf("PreAns %u = %u\n", i, PreAns[i]);
  }
//  printf("Done\n");
  N[1].DFS(NULL), Ans <<= 1, Mn(Ans);
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}

