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
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node {
  unsigned Val;
  Node* Nxt;
}Chain[105];
void Go(Node* x, Node* Pre) {
  if (x->Nxt == x) {
    printf("%u ", x->Val);return;
  }
  if (!(--Cnt)) {
    printf("%u ", x->Val);
    Pre->Nxt = x->Nxt;
    Cnt = m;
    return Go(x->Nxt, Pre);
  }
  return Go(x->Nxt, x);
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), Cnt = m = RD();
  for (unsigned i(1); i <= n; ++i)
    Chain[i] = { i, Chain + i + 1 };
  Chain[n].Nxt = Chain + 1;
  Go(Chain + 1, Chain + n);
  //  }
  //  system("pause");
  return Wild_Donkey;
}