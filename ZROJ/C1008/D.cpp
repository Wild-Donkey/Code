#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
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
unsigned C, D, m, n, k, q, Tmp(0), Ans[200005];
unsigned Fa[200005], Size[200005], Stack[200005], Calc[200005], Top(0);
multiset <unsigned> Have[200005], Sit;
vector<unsigned> Del[200005];
struct Node {
  vector<Node*> To;
  unsigned A, B;
}N[200005];
struct Ask {
  unsigned V, Num;
  inline const char operator < (const Ask& x) const {return V < x.V;} 
}Ak[200005];
struct ToA {
  Node* Pnt;
  inline const char operator < (const ToA& x) const {return Pnt->A < x.Pnt->A;} 
}Ta[200005];
inline unsigned Find (unsigned x) {
  while (Fa[x] ^ x) Stack[++Top] = x, x = Fa[x];
  while (Top) Fa[Stack[Top--]] = x;
  return x;
}
inline void Merge(unsigned x, unsigned y) {
  x = Find(x), y = Find(y);
  if(x == y) return;
  if(Size[x] < Size[y]) swap(x, y);
  Size[x] += Size[y], Fa[y] = x;
  multiset<unsigned>::iterator It(Sit.find(Calc[y]));
  Sit.erase(It), It = Sit.find(Calc[x]), Sit.erase(It);
  unsigned Last(0);
  for (auto i:Have[y]) {
    if(i ^ Last) {
      if((Have[x].count(i)) && (!(Have[x].count(i) % k))) --Calc[x];
      if(!((Have[x].count(i) + Have[y].count(i)) % k)) ++Calc[x];
    }
    Have[x].insert(i), Last = i;
  }
  Sit.insert(Calc[x]), Have[y].clear();
  return;
}
signed main() {
  n = RD(), m = RD(), k = RD();
  for (unsigned i(1); i <= n; ++i) N[i].A = RD();
  for (unsigned i(1); i <= n; ++i) N[i].B = RD();
  for (unsigned i(1); i <= n; ++i) Ta[i].Pnt = N + i;
  sort(Ta + 1, Ta + n + 1), (Ta[n + 1].Pnt = N + n + 1)->A = 0x3f3f3f3f;
  for (unsigned i(1); i <= m; ++i) {
    C = RD(), D = RD();
    N[C].To.push_back(N + D);
    N[D].To.push_back(N + C);
  }
  q = RD();
  for (unsigned i(1); i <= q; ++i) {
    Ak[i].V = RD(), Ak[i].Num = i;
    for (unsigned j(RD()); j; --j) Del[i].push_back(RD());
  }
  sort(Ak + 1, Ak + q + 1);
  for (unsigned i(1), j(1); i <= q; ++i) {
    while (Ta[j].Pnt->A <= Ak[i].V) {
      Node* Cur(Ta[j].Pnt);
      Fa[Cur - N] = Cur - N, Size[Cur - N] = 1, Have[Cur - N].insert(Cur->B);
      if(k == 1) Calc[Cur - N] = 1;
      Sit.insert(Calc[Cur - N]);
      for (auto k:Ta[j].Pnt->To) if(Fa[k - N]) Merge(Ta[j].Pnt - N, k - N);
      ++j;
    }
    multiset<unsigned>::iterator It;
    set<unsigned> ToD;
    for (auto j:Del[Ak[i].Num]) if(Fa[j]) ToD.insert(Find(j));
    for (auto j:ToD) It = Sit.find(Calc[j]), Sit.erase(It);
    It = Sit.end();
    if(It != Sit.begin()) Ans[Ak[i].Num] = *(--It);
    for (auto j:ToD) Sit.insert(Calc[j]);
  }
  for (unsigned i(1); i <= q; ++i) printf("%u\n", Ans[i]);
  return Wild_Donkey;
}
