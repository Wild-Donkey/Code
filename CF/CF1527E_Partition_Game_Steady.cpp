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
unsigned a[35005], f[105][35005], Chs[105][35005], Pre[35005], Pos[35005], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
struct Node {
  Node *LS, *RS;
  unsigned Val, Tag;
}N[1000005], *Root[35005], *CntN(N);
void Chg(Node *x, Node *y, unsigned L, unsigned R) {
  if(!x) y->Val = B;
  else y->Val = x->Val + B;
  if(L == R) return;
  register unsigned Mid((L + R) >> 1);
  if(Mid < A) {
    if(!x) y->LS = NULL, Chg(NULL, y->RS = ++CntN, Mid + 1, R); 
    else y->LS = x->LS, Chg(x->RS, y->RS = ++CntN, Mid + 1, R);
  } else {
    if(!x) y->RS = NULL, Chg(NULL, y->LS = ++CntN, L, Mid); 
    else y->RS = x->RS, Chg(x->LS, y->LS = ++CntN, L, Mid);
  }
}
void Qry(Node *x, unsigned L, unsigned R) {
  if(A <= L) {
    Ans += x->Val;
    return;
  }
  register unsigned Mid((L + R) >> 1);
  if(x->RS) Qry(x->RS, Mid + 1, R);
  if((x->LS) && (Mid >= A)) Qry(x->LS, L, Mid);
}
int main() {
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  memset(f, 0x3f, sizeof(f));
  for (register unsigned i(1); i <= n; ++i) a[i] = RD();
  for (register unsigned i(1); i <= n; ++i) {
    if(!Pos[a[i]]) Pos[a[i]] = i;
    Pre[i] = Pos[a[i]];
    Pos[a[i]] = i;
  }
  for (register unsigned i(1); i <= n; ++i) {
    A = Pre[i], B = i - Pre[i];
    Chg(Root[i - 1], Root[i] = ++CntN, 1, n);
  }
  f[1][0] = 0;
  for (register unsigned i(1); i <= n; ++i) {
    Chs[1][i] = 1;
    f[1][i] = f[1][i - 1] + i - Pre[i];
  }
  for (register unsigned i(2); i <= m; ++i) {
    Chs[i][n + 1] = n - 1;
    for (register unsigned j(n); j >= i; --j) {
      for (register unsigned k(Chs[i - 1][j]); k <= Chs[i][j + 1]; ++k) {
        A = k + 1, Ans = 0, Qry(Root[j], 1, n);
        if(f[i - 1][k] + Ans <= f[i][j]) {
          f[i][j] = f[i - 1][k] + Ans;
          Chs[i][j] = k;
        }
      }
//      printf("%u %u %u <- %u\n", i, j, f[i][j], Chs[i][j]); 
    }
  }
  printf("%u\n", f[m][n]);
  //  }
  return Wild_Donkey;
}


