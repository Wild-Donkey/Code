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
unsigned a[10005], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
char b[10005];
struct Node {
  Node *Son, *Bro;
  unsigned f[5];
}N[1005];
void DFS(Node *x) {
//  printf("DFS %u\n", x - N);
  register Node *Now(x->Son);
  if(!Now) {
    x->f[0] = x->f[1] = 0;
    x->f[2] = x->f[3] = x->f[4] = 1;
    return;
  }
  register unsigned Sum2(0), Sum1(0);
  while (Now) {
    DFS(Now);
    x->f[4] += Now->f[0];
    x->f[0] += Now->f[1];
    x->f[1] += Now->f[2];
    Sum2 += Now->f[2];
    Sum1 += Now->f[1];
    Now = Now->Bro;
  }
  x->f[2] = x->f[3] = 0x3f3f3f3f;
  Now = x->Son;
  while (Now) {
    x->f[2] = min(x->f[2], Sum2 - Now->f[2] + Now->f[3]);
    x->f[3] = min(x->f[3], Sum1 - Now->f[1] + Now->f[4]);
    Now = Now->Bro;
  }
  register unsigned Min(0x3f3f3f3f);
  ++(x->f[4]);
  for (register char i(4); i >= 0; --i) {
    x->f[i] = min(x->f[i], Min);
    Min = min(x->f[i], Min);
  }
  return;
}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (register unsigned i(2), j; i <= n; ++i) {
    j = RD();
    N[i].Bro = N[j].Son;
    N[j].Son = N + i;
  }
  DFS(N + 1);
//  printf("%u %u %u %u %u\n", N[1].f[0], N[1].f[1], N[1].f[2], N[1].f[3], N[1].f[4]);
  printf("%u\n", min(min(N[1].f[2], N[1].f[3]), N[1].f[4]));
//  }
  return Wild_Donkey;
}
/*
6 1 2 2 4 4
6 1 2 2 6 4
*/
