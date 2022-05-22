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
unsigned m, n, A, B;
char Flg;
struct Node {
  vector<pair<Node*, int> > E;
  int Dis, Tms;
  char Iq;
}N[5005], *Que[25000005], **Hd(Que), **Tl(Que);
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) N->E.push_back({N + i, 0x3f3f3f3f});
  for (unsigned i(1); i <= n; ++i) N[i].Dis = 0x7f7f7f7f;
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD();
    N[B].E.push_back({N + A, RDsg()});
  }
  *(++Tl) = N;
  while (Hd < Tl) {
    Node* Cur(*(++Hd));
    Cur->Iq = 0;
    for (auto i:Cur->E) {
      int To(i.second + Cur->Dis);
      if((i.first)->Dis > To) {
        (i.first)->Dis = To;
        if(!((i.first)->Iq)) {
          ((i.first)->Iq) = 1, *(++Tl) = i.first;
          if(++((i.first)->Tms) > n) {Flg = 1; break;}
        }
      }
    }
    if(Flg) break;
  }
  if(Flg) {printf("NO\n"); return 0;}
  for (unsigned i(1); i <= n; ++i) printf("%d ", N[i].Dis); putchar(0x0A);
//  }
  return Wild_Donkey;
}

