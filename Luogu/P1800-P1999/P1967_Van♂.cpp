#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned Fa[10005], m, n, Cnt(0), C, D, t, Ans(0x3f3f3f3f), Tmp(0), q;
bool b[10005];
struct Edge;
struct Node {
  Edge *Fst;
  Node *Fa[15];
  unsigned Value[15], Dep;
}N[10005], *A, *B;
struct Edge {
  Node *To;
  Edge *Nxt;
  unsigned Value;
}E[100005], *CntE(E - 1);
struct Side {
  unsigned From, To, Value;
  inline const char operator<(const Side &x) const{
    return this->Value > x.Value;
  }
}S[50005];
inline unsigned Find (unsigned x) {
  register unsigned now(x);
  while (now ^ Fa[now]) {
    now = Fa[now];
  }
  return Fa[x] = now;
}
void DFS(Node *x) {
//  printf("DFS %u\n", x - N);
  register Edge *Sid(x->Fst);
  while (Sid) {
    if(!(Sid->To->Dep)) {
      Sid->To->Dep = x->Dep + 1;
      Sid->To->Fa[0] = x;
      Sid->To->Value[0] = Sid->Value;
      for(register unsigned i(0); Sid->To->Fa[i]->Fa[i]; ++i) {
        Sid->To->Fa[i + 1] = Sid->To->Fa[i]->Fa[i];
        Sid->To->Value[i + 1] = min(Sid->To->Value[i], Sid->To->Fa[i]->Value[i]);
      }
      DFS(Sid->To);
    }
    Sid = Sid->Nxt;
  }
  return;
}
void LCA(Node *x, Node *y) {
  if(x->Dep < y->Dep) {
    swap(x, y);
  }
  for (register unsigned i(13); i < 0x3f3f3f3f; --i) {
    if(x->Fa[i] && x->Fa[i]->Dep >= y->Dep) {
      Ans = min(Ans, x->Value[i]);
      x = x->Fa[i];
    }
  }
  if(x == y) return;
  for (register unsigned i(13); i < 0x3f3f3f3f; --i) {
    if(x->Fa[i] && x->Fa[i] != y->Fa[i]) {
      Ans = min(Ans, min(x->Value[i], y->Value[i]));
      x = x->Fa[i];
      y = y->Fa[i];
    }
  }
  Ans = min(Ans, min(x->Value[0], y->Value[0]));
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (register unsigned i(1); i <= m; ++i) {
    S[i].From = RD(), S[i].To = RD(), S[i].Value = RD();
  }
  sort(S + 1, S + m + 1);
  for (register unsigned i(1); i <= n; ++i) {
    Fa[i] = i;
  }
  for (register unsigned i(1); i <= m; ++i) {
    if(Find(S[i].From) ^ Find(S[i].To)) {
      Fa[Fa[S[i].From]] = Fa[S[i].To];
      (++CntE)->Nxt = N[S[i].From].Fst;
      N[S[i].From].Fst = CntE;
      CntE->To = N + S[i].To;
      CntE->Value = S[i].Value;
      (++CntE)->Nxt = N[S[i].To].Fst;
      N[S[i].To].Fst = CntE;
      CntE->To = N + S[i].From;
      CntE->Value = S[i].Value;
    }
  }
  for (register unsigned i(1); i <= n; ++i) {
    if(!(N[i].Dep)) N[i].Dep = 1, DFS(N + i);
  }
  q = RD();
  for (register unsigned i(1); i <= q; ++i) {
    A = N + RD(), B = N + RD();
    if(Find(A - N) ^ Find(B - N)) {
      printf("-1\n");
    } else {
      Ans = 0x3f3f3f3f, LCA(A, B), printf("%u\n", Ans);
    }
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



