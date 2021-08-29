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
#define Lowbit(x) ((x)&(~((x)-1)))
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
long long a[10000005], Tree[10000005], C, Ans(0);
char Flg(0);
void Add(unsigned x) {
  while (x <= n) {
    Tree[x] += C;
    // printf("Add %u\n", x);
    x += Lowbit(x);
  }
}
void Qry(unsigned x) {
  while (x) {
    Ans += Tree[x];
    x -= Lowbit(x);
  }
}
signed main() {
  // freopen("B.in", "r", stdin);
  // freopen("B.ans", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  m = RD(), n = RD() + 1;
  for (register unsigned i(1); i < n; ++i) {
    a[i] = RD();
  }
  for (register unsigned i(1); i <= m; ++i) {
    Flg = 0;
    // for (register unsigned j(1); j < n; ++j) {
    //   printf("%d ", a[j]);
    // }
    // putchar('\n');
    for (register unsigned j(1); j < n; ++j) {
      if (a[j] == j) {
        Flg = 1;
        break;
      }
    }
    printf(Flg ? "YES\n" : "NO\n");
    if (i == m) { system("pause"); return 0; }
    A = RD(), B = RD(), C = RDsg();
    for (register unsigned j(A); j <= B; ++j) {
      a[j] += C;
    }
  }

  return Wild_Donkey;
}