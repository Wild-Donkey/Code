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
#define foreplay for
#define wild while
const unsigned long long Mod(100000007);
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
inline void Mn(unsigned long long &x) { x -= (x >= Mod) ? Mod : 0; }
inline void Mn(unsigned &x) { x -= (x >= Mod) ? Mod : 0; }
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) {
    if (y & 1) Rt = Rt * x % Mod;
    x = x * x % Mod, y >>= 1;
  }
  return Rt;
}
unsigned A, B, C, D;
unsigned DfsC(0);
struct Node {
  vector<Node *> Sons;
  unsigned long long Val, OprA;
  unsigned DFSr, Size, Dep;
  inline void DFS() {
    DFSr = ++DfsC, Size = 1;
    for (auto i : Sons) { i->Dep = Dep + 1, i->DFS(), Size += i->Size; }
  }
  inline void Push(unsigned long long Up) {
    unsigned long long Opr(OprA);
    Mn(Opr += Up), Mn(Val += Opr), OprA = 0;
    for (auto i : Sons) i->Push(Opr * A % Mod);
  }
} N[100005];
struct Opr {
  Node *Rt;
  unsigned long long d;
} Buffer[2000];
unsigned m, n, Blc;
unsigned Cnt(0);
unsigned long long Ans(1);
void ClBuf() {
  for (unsigned i(1); i <= Cnt; ++i) Mn(Buffer[i].Rt->OprA += Buffer[i].d);
  Cnt = 0, N[1].Push(0);
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  Clr();
  n = RD(), m = RD(), Mn(A = Mod + RDsg());
  for (unsigned i(2); i <= n; ++i) B = RD(), N[B].Sons.push_back(N + i);
  Blc = sqrt(m) * 1.5 + 1, N[1].DFS();
  for (unsigned i(1); i <= m; ++i) {
    if (!(i % Blc)) ClBuf();
    B = RD(), C = RD();
    if (B == 2) {
      Ans = N[C].Val;
      for (unsigned j(1); j <= Cnt; ++j) {
        Node *Cur(Buffer[j].Rt);
        // printf("Cur %u j %u\n", Cur - N, j);
        if (N[C].DFSr >= Cur->DFSr && N[C].DFSr < Cur->DFSr + Cur->Size)
          Ans = (Ans + Buffer[j].d * Pow(A, N[C].Dep - Cur->Dep)) % Mod;
      }
      printf("%llu\n", Ans);
      continue;
    }
    D = Mod + RDsg() - 1, D -= (D >= Mod - 1) ? (Mod - 1) : 0;
    Buffer[++Cnt] = {N + C, Pow(A, D)};
    // printf("Cnt%u C%u", Cnt, C);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}