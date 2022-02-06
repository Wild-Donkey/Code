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
const unsigned long long Mod(1000003), Base(41);
unsigned Q[105], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0), Mn(0), Total;
unsigned Hash[1010005], Stack[10005], STop(0);
unsigned Buffer[10005], BTop(0);
bitset<105> Ans;
struct Node {
  vector <pair<Node*, unsigned> > To;
  unsigned Size, MxSize, Dep;
  char NAva;
}N[10005], * Heavy;
inline unsigned Find(unsigned x) {
  unsigned Pos(x * Base % Mod);
  while (Hash[Pos] && (Hash[Pos] ^ x)) ++Pos;
  return Pos;
}
inline void DFS1(Node* x, Node* Fa) {
  x->Size = 1, x->MxSize = 0;
  for (auto i : x->To) if ((i.first != Fa) && (!(i.first->NAva)))
    DFS1(i.first, x), x->Size += i.first->Size, x->MxSize = max(x->MxSize, i.first->Size);
}
inline void DFS2(Node* x, Node* Fa) {
  unsigned MnMx(max(x->MxSize, Total - x->Size));
  if (MnMx < Mn) Mn = MnMx, Heavy = x;
  for (auto i : x->To) if ((i.first != Fa) && (!(i.first->NAva))) DFS2(i.first, x);
}
inline void DFS3(Node* x, Node* Fa) {
  unsigned Pos;
  for (auto i : x->To) if ((i.first != Fa) && (!(i.first->NAva))) {
    Buffer[++BTop] = (i.first->Dep = x->Dep + i.second);
    for (unsigned j(1); j <= m; ++j) if ((!Ans[j]) && (Q[j] >= i.first->Dep)) {
      if (i.first->Dep == Q[j]) { Ans[j] = 1; continue; }
      Pos = Find(Q[j] - i.first->Dep); if (Hash[Pos] == (Q[j] - i.first->Dep)) Ans[j] = 1;
    }
    DFS3(i.first, x);
  }
}
inline void Solve(Node* x) {
  DFS1(x, NULL), Heavy = NULL, Mn = 0x3f3f3f3f, Total = x->Size, DFS2(x, NULL);
  unsigned Pos;
  Heavy->Dep = 0;
  for (auto i : Heavy->To) if (!(i.first->NAva)) {
    Buffer[++BTop] = (i.first->Dep = Heavy->Dep + i.second);
    for (unsigned j(1); j <= m; ++j) if ((!Ans[j]) && (Q[j] >= i.first->Dep)) {
      if (i.first->Dep == Q[j]) { Ans[j] = 1; continue; }
      Pos = Find(Q[j] - i.first->Dep); if (Hash[Pos] == (Q[j] - i.first->Dep)) Ans[j] = 1;
    }
    DFS3(i.first, Heavy);
    while (BTop) { Pos = Find(Buffer[BTop]); if (!Hash[Pos]) Hash[Pos] = Buffer[BTop], Stack[++STop] = Pos; --BTop; }
  }
  Heavy->NAva = 1;
  while (STop) Hash[Stack[STop--]] = 0;
  for (auto i : Heavy->To) if (!(i.first->NAva)) Solve(i.first);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i < n; ++i) {
    A = RD(), B = RD(), C = RD();
    N[A].To.push_back(make_pair(N + B, C));
    N[B].To.push_back(make_pair(N + A, C));
  }
  for (unsigned i(1); i <= m; ++i) Q[i] = RD();
  Solve(N + 1);
  for (unsigned i(1); i <= m; ++i)printf(Ans[i] ? "AYE\n" : "NAY\n");
  //  }
  // system("pause");
  return Wild_Donkey;
}