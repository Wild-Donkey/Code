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
unsigned m, n, Cnt(0), A, B, D, t, Ans(0), Tmp(0);
long long a[100005], C;
//  inline void Clr() {}
signed main() {
  freopen("B.in", "w", stdout);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  srand(time(0));
  n = 1 + rand() % 2000, m = 1 + rand() % 2000;
  printf("%u %u\n", m + 1, n);
  for (register unsigned i(1); i <= n; ++i) {
    a[i] = a[i - 1] + 1 + rand() % 3;
    printf("%u ", a[i]);
  }
  a[n + 1] = a[n] + 1 + rand() % 500;
  putchar('\n');
  for (register unsigned i(1); i <= m; ++i) {
    A = 1 + rand() % (n); B = A + rand() % (n - A + 1);
    if (rand() % 2) {
      // printf("Plus ");
      C = (long long)rand() % (a[B + 1] - a[B]);
      for (register unsigned j(A); j <= B; ++j) {
        a[j] += C;
      }
      printf("%u %u %d\n", A, B, C);
    }
    else {
      C = (long long)rand() % (a[A] - a[A - 1]);
      for (register unsigned j(A); j <= B; ++j) {
        a[j] -= C;
      }
      printf("%u %u %d\n", A, B, -C);
    }
    // for (register unsigned j(1); j <= n; ++j) {
    //   printf("%d ", a[j]);
    // }
    // putchar('\n');
  }
  fclose(stdout);
  // system("B_Force.exe");
  // system("pause");
  return Wild_Donkey;
}
