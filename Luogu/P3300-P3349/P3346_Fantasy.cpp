#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned m, n, Cnt(0), A, B, t, Tmp(0);
unsigned Tl(0), Hd(0), Cls;
unsigned long long Ans;
struct Tr;
struct Edge {
  Tr* To;
  Edge* Nxt;
}E[200005], * CntE(E);
struct Tr {
  Edge* Fst;
  unsigned Deg;
  char Cr;
}IT[100005];
struct Node {
  Node* To[10], * Fail;
  unsigned Len;
}N[4000005], * CntN(N), * Last(N);
struct Trie {
  Trie* To[10];
  Node* Am;
}T[2000005], * Q[2000005], * CntT(T);
void Link(Tr* x, Tr* y) { (++CntE)->Nxt = x->Fst, x->Fst = CntE, CntE->To = y, ++(x->Deg); }
void DFS(Tr* x, Tr* y, Trie* z) {
  // printf("DFS %u From %u Trie %u\n", x - IT, y - IT, z - T);
  Edge* Sid(x->Fst);
  if (!(z->To[x->Cr])) z->To[x->Cr] = ++CntT; z = z->To[x->Cr];
  while (Sid) {
    if (Sid->To != y) {
      DFS(Sid->To, x, z);
    }
    Sid = Sid->Nxt;
  }
}
Node* Add(char x) {
  Node* Back(Last), * Cur(++CntN);
  Cur->Len = Last->Len + 1;
  while (Back) {
    if (!(Back->To[x])) Back->To[x] = Cur;
    else break;
    Back = Back->Fail;
  }
  if (Back) {
    if (Back->To[x]->Len == Back->Len + 1) {
      Cur->Fail = Back->To[x];
    }
    else {
      Node* Bfr(Back->To[x]);
      *(++CntN) = *(Back->To[x]);
      CntN->Len = Back->Len + 1, Bfr->Fail = Cur->Fail = CntN;
      while (Back && (Back->To[x] == Bfr)) Back->To[x] = CntN, Back = Back->Fail;
    }
  }
  else {
    Cur->Fail = N;
  }
  return Cur;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), Cls = RD();
  for (unsigned i(1); i <= n; ++i) IT[i].Cr = RD();
  for (unsigned i(1); i < n; ++i)
    A = RD(), B = RD(), Link(IT + A, IT + B), Link(IT + B, IT + A);
  for (unsigned i(1); i <= n; ++i) if (IT[i].Deg == 1) DFS(IT + i, NULL, T);
  Q[++Tl] = T, T->Am = N;
  while (Tl ^ Hd) {
    Trie* Now(Q[++Hd]);
    // printf("Here %u\n", Now - T);
    Last = Now->Am;
    for (unsigned i(0); i < Cls; ++i) if (Now->To[i]) Now->To[i]->Am = Add(i), Q[++Tl] = Now->To[i];
  }
  for (Node* i(N + 1); i <= CntN; ++i) Ans += i->Len - i->Fail->Len;
  printf("%llu\n", Ans);
  // system("pause");
  return Wild_Donkey;
}