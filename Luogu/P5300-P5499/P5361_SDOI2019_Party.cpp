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
struct Node {
  vector<Node*> E;
  Node**Pos; 
  unsigned Deg, Ava;
}N[10005], *Stack[10005], **Head[10005];
vector <Node*> Buck[10005];
unsigned Arr[10005], Cnt(0);
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Ans(0), Tmp(0);
inline void Clr() {
  for (unsigned i(1); i <= n; ++i) N[i].E.clear(), N[i].Ava = 0;
  for (unsigned i(1); i <= n; ++i) Buck[i].clear();
  n = RD(), m = RD(), Head[0] = Stack;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(1); i <= m; ++i) 
      A = RD(), B = RD(), N[A].E.push_back(N + B), N[B].E.push_back(N + A);
    for (unsigned i(1); i <= n; ++i) Buck[N[i].Deg = N[i].E.size()].push_back(N + i);
    for (unsigned i(1); i <= n; ++i) {
      Head[i] = Head[i - 1]; 
      for (auto j:Buck[i]) *(++Head[i]) = j, j->Pos = Head[i];
    }
    Ans = 0, A = 1, Cnt = 0;
//    printf("Done\n");
    for (unsigned i(1); i <= n; ++i) {
      Node* Cur(Stack[i]);
//      printf("Del %u\n", Cur - N);
      if(Ans < Cur->Deg) A = i, Ans = Cur->Deg;
      if(!(Cur->Ava)) Arr[++Cnt] = Cur - N;
//      for (unsigned j(1); j <= n; ++j) printf("%u ", Head[j] - Stack); putchar(0x0A);
//      for (unsigned j(1); j <= n; ++j) printf("%u ", Stack[j] - N); putchar(0x0A); 
//      for (unsigned j(1); j <= n; ++j) printf("%u ", N[j].Pos - Stack); putchar(0x0A); 
      for (auto j:Cur->E) if(j->Deg) {
//        printf("To %u\n", j - N);
        j->Ava |= (Cur->Ava ^ 1);
        swap(*(++Head[--(Cur->Deg)]), *(Cur->Pos));
        swap(Cur->Pos, (*(Cur->Pos))->Pos);
        swap(*(++Head[--(j->Deg)]), *(j->Pos));
        swap(j->Pos, (*(j->Pos))->Pos);
      }
    }
//    for (unsigned i(1); i <= n; ++i) printf("%u ", Head[i] - Stack); putchar(0x0A);
//    for (unsigned i(1); i <= n; ++i) printf("%u ", Stack[i] - N); putchar(0x0A); 
    printf("%u", n - A + 1);
    for (unsigned i(A); i <= n; ++i) printf(" %u", Stack[i] - N); putchar(0x0A);
    printf("%u", Cnt);
    for (unsigned i(1); i <= Cnt; ++i) printf(" %u", Arr[i]); putchar(0x0A);
  }
  return Wild_Donkey;
}

