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
//  inline void Clr() {}
struct Lst {
  map<unsigned, unsigned> Dat;
  unsigned Max, Sum;
} L[200005];
Lst *Merge(Lst *x, Lst *y) {
  if (x->Dat.size() < y->Dat.size()) swap(x, y);
  x->Sum += y->Sum;
  for (auto i : y->Dat) { x->Max = max(x->Max, (x->Dat[i.first] += i.second)); }
  return x;
}
struct Node {
  vector<Node *> Sons;
  Lst *List;
  Node *Fa;
  unsigned Col, CntS;
} N[200005], *Que[200005], **Hd(Que), **Tl(Que);
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), N[0].CntS = 0x3f3f3f3f;
  for (unsigned i(1); i <= n; ++i) {
    (N[i].List = L + i)->Dat[N[i].Col = RD()] = 1;
    (N[i].Fa = N + RD())->Sons.push_back(N + i);
    N[i].List->Max = 1, N[i].List->Sum = 1;
  }
  for (unsigned i(1); i <= n; ++i)
    if (!(N[i].CntS = N[i].Sons.size())) *(++Tl) = N + i;
  while (Hd < Tl) {
    Node *Cur(*(++Hd));
    for (auto i : Cur->Sons) Cur->List = Merge(Cur->List, i->List);
    Ans += (Cur->List->Sum == Cur->List->Dat.size() * Cur->List->Max);
    // printf("N %u Sum %u Max %u Size %u\n", Cur - N, Cur->List->Sum,
    //  Cur->List->Max, Cur->List->Dat.size());
    if (!(--(Cur->Fa->CntS))) *(++Tl) = Cur->Fa;
  }
  printf("%u\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}