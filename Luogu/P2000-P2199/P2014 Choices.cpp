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
inline unsigned int RD() {
  unsigned int intmp = 0;
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
unsigned int a[10005], m, n, Cnt(0), A, B, C, D, t;
bool b[10005];
char s[10005];
inline void Clr() {
  n = RD();
  memset(a, 0, sizeof(a));
}
struct Node{
  unsigned int Val, Siz, f[305];
  Node *Fa, *Fs, *Bro; 
}N[305], *Rt;
inline void Lnk (Node *x, Node *y) {
  y->Bro = x->Fs;
  x->Fs = y;
  y->Fa = x;
  x->Siz += y->Siz;
  return;
}
inline void Fnd_Rt() {
  Node *x;
  while (x->Fa) {
    x = x->Fa;
  }
  Rt = x;
  return;
}
void Bld (Node *x) {
  Node *S(x->Fs);
  x->Siz = 1;
  x->f[1] = x->Val;
  while (S) {
    Bld(S);
    x->Siz += S->Siz; 
    S = S->Bro; 
  }
  return;
} 
void DFS (Node *x) {
//  printf("DFS %u\n", x - N);
  Node *S(x->Fs);
  while (S) {
    DFS(S);
    for (register unsigned int i(x->Siz); i >= 2; --i) {//x
      for (register unsigned int j(0); j < i; ++j) {//S
        x->f[i] = max(x->f[i], x->f[i - j] + S->f[j]);
      }
//      printf("%u.f[%u] %u\n", x - N, i, x->f[i]);
    }
    S = S->Bro; 
  }
//  printf("%u.f[%u] %u\n", x - N, x->Siz, x->f[x->Siz]);
  return;
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  n = RD();
  m = RD();
  memset (N, 0, sizeof(N));
  for (register unsigned int i(1); i <= n; ++i) {
    N[i].Siz = 1;
  }
  for (register unsigned int i(1); i <= n; ++i) {
    Lnk(N + RD(), N + i);
    N[i].Val = RD();
  }
  Bld(N);
  DFS(N);
  printf("%u\n", N[0].f[m + 1]);
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
7  4
2  2
0  1
0  4
2  1
7  1
7  6
2  2
*/
