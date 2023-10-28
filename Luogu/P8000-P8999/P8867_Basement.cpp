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
const unsigned long long Mod(1000000007);
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
unsigned Two[500005], ITw[500005];
unsigned long long Ans(0), Tmp(0);
unsigned m, n, M;
unsigned A, B, C, D, t;
unsigned DFSR(0);
inline void Mn(unsigned long long& x) { x -= (x >= Mod) ? Mod : 0; }
inline void Mn(unsigned& x) { x -= (x >= Mod) ? Mod : 0; }
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) {
    if (y & 1) Rt = Rt * x % Mod;
    y >>= 1, x = x * x % Mod;
  }
  return Rt;
}
struct Tree {
  unsigned Cnt, f, Size;  // f 子树存在标记点且可以连出去
  vector<Tree*> Edge;
  inline void DFS(Tree* Fa) {
    // printf("Tree %u\n", this);
    Size = f = 1;
    for (auto i : Edge)
      if (i != Fa) {
        i->DFS(this);
        f = (unsigned long long)f * (i->f + Two[i->Size]) % Mod;
        Size += i->Size;
      }
    f = (unsigned long long)f * Two[Cnt] % Mod;
    Mn(f += Mod - Two[Size - 1]);
    Tmp = (Tmp + (unsigned long long)f * ITw[Fa ? (Size + 1) : Size]) % Mod;
  }
} T[500005], *CntT(T);
struct Node {
  unsigned DFSr, Low;
  Tree* Tr;
  vector<Node*> Edge;
  void DFS(Node* Fa);
} N[500005], *Stack[500005], **STop(Stack);
void Node::DFS(Node* Fa) {
  // printf("DFS %u\n", this - N);
  *(++STop) = this, Low = DFSr = ++DFSR;
  for (auto i : Edge)
    if (i != Fa) {
      if (i->DFSr) {
        Low = min(Low, i->DFSr);
      } else {
        i->DFS(this);
        Low = min(Low, i->Low);
      }
    }
  if (Low == DFSr) {
    ++CntT;
    do {
      ++(((*STop)->Tr = CntT)->Cnt);
    } while (*(STop--) != this);
  }
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), M = m = RD(), Two[0] = 1;
  for (unsigned i(1); i <= n; ++i) Mn(Two[i] = (Two[i - 1] << 1));
  ITw[n] = Pow(Two[n], Mod - 2);
  for (unsigned i(n - 1); ~i; --i) Mn(ITw[i] = (ITw[i + 1] << 1));
  // for (unsigned i(0); i <= n; ++i) printf("%u ", Two[i]);
  // putchar(0x0A);
  // for (unsigned i(0); i <= n; ++i) printf("%u ", ITw[i]);
  // putchar(0x0A);
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD();
    N[A].Edge.push_back(N + B);
    N[B].Edge.push_back(N + A);
  }
  for (unsigned i(1); i <= n; ++i)
    if (!N[i].DFSr) N[i].DFS(NULL);
  for (unsigned i(1); i <= n; ++i)
    for (auto j : N[i].Edge)
      if (N[i].Tr != j->Tr) N[i].Tr->Edge.push_back(j->Tr);
  for (unsigned i(1); i <= n; ++i)
    if (!N[i].Tr->Size) {
      Tmp = 0, N[i].Tr->DFS(NULL), m -= N[i].Tr->Size - 1;
      Ans = (Ans + (Tmp + ITw[1]) * Two[N[i].Tr->Size]) % Mod;
    }
  // for (Tree* i(T); i <= CntT; ++i) printf("%u ", i->f);
  // putchar(0x0A);
  // printf("%u %u\n", m, Ans);
  Ans = Ans * Pow(2, m) % Mod, Mn(Ans += Mod - Pow(2, M));
  printf("%u\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
4 4
1 2
2 3
3 1
1 4
*/