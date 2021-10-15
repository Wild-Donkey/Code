#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
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
unsigned m, n, n3;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0x3f3f3f3f);
multiset<unsigned> Anc, Bro;
inline void Udt (unsigned x, unsigned y) {
  unsigned z(n - x - y), xx(min(min(x, y), z)), yy(max(max(x, y), z));
  Ans = min(Ans, yy - xx);
}
struct Node {
  vector<Node*> E;
  Node* Fa;
  unsigned Size;
  void PreDFS() {
    Size = 1;
    for (auto i:E) if(i != Fa) i->Fa = this, i->PreDFS(), Size += i->Size;
  }
  void DFS() {
    unsigned Need((n - Size) >> 1);
    multiset<unsigned>::iterator It(Anc.lower_bound(Need + Size));
    if(It != Anc.begin()) Udt(Size, *(--It) - Size), ++It;
    if(It != Anc.end()) {Udt(Size, *It - Size); if(++It != Anc.end()) Udt(Size, *It - Size);}
    It = Bro.lower_bound(Need);
    if(It != Bro.begin()) Udt(Size, *(--It)), ++It;
    if(It != Bro.end()) {Udt(Size, *It); if(++It != Bro.end()) Udt(Size, *It);}
    Anc.insert(Size);
    for (auto i:E) if(i != Fa) i->DFS();
    It = Anc.find(Size);
    Anc.erase(It), Bro.insert(Size);
  } 
}N[200005], *Now;
signed main() {
  n = RD(), n3 = n / 3;
  for (unsigned i(1); i < n; ++i) {
    A = RD(), B = RD();
    N[A].E.push_back(N + B);
    N[B].E.push_back(N + A);
  }
  N[1].PreDFS(), N[1].DFS();
  printf("%u\n", Ans);
  return Wild_Donkey;
}

