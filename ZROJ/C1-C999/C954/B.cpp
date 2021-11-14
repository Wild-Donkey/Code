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
int Pre[1000005][21];
unsigned m, n(1), Sum[1000005], Log[1000005], Bin[25], Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
char a[1000005];
int Find(unsigned L, unsigned R) {
  register unsigned TmpF(Log[R - L + 1]);
//  printf("Find %u %u %u\n", TmpF, L, R);
  return min(Pre[L][TmpF], Pre[R - Bin[TmpF] + 1][TmpF]);
}
int main() {
//  freopen("B.in", "r", stdin);
//  freopen("B.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  fread(a + 2, 1, 1000001, stdin);
  for (; a[n + 1] >= 'A'; ++n) a[n] -= 'A';
  a[n] -= 'A';
//  printf("%u\n", n);
  if(n == 1) {
    if(a[1] == 0) Ans = 1;
    printf("%u\n", Ans);
    return 0;
  }
  for (register unsigned i(1), j(0); i <= n; ++j, i <<= 1) {
    Log[i] = j, Bin[j] = i;
  }
  for (register unsigned i(1); i <= n; ++i) {
    Log[i] = max(Log[i], Log[i - 1]);
  }
  Pre[0][0] = 0x3f3f3f3f, Pre[1][0] = 1, Sum[0] = 0;
  for (register unsigned i(2); i <= n; ++i) {
    Sum[i] = Sum[i - 1];
    Pre[i][0] = Pre[i - 1][0];
    if(!a[i]) ++Sum[i];
    else {
      if(a[i] ^ 1) ++Pre[i][0];
      else --Pre[i][0];
    }
    printf("%d %u\n", Pre[i][0], Sum[i]);
  }
//  printf("%u Sum %u %u\n", n, Sum[n], Sum[n - 1]);
//  Pre[0][0] = 0x3f3f3f3f;
//  printf("%u Sum %u %u\n", n, Sum[n], Sum[n - 1]);
  for (register unsigned i(1), j(0); i < n; i <<= 1, ++j) {
    for (register unsigned k(1); k + i <= n; ++k) {
      Pre[k][j + 1] = min(Pre[k][j], Pre[k + i][j]);
//      printf("%u %u %d\n", k, j + 1, Pre[k][j + 1]);
    }
  }
//  printf("%u Sum %u %u\n", n, Sum[n], Sum[n - 1]);
  for (register unsigned i(1); i + 2 <= n; ++i) {
    if((Pre[i][0] < Pre[i - 1][0]) && (Pre[i][0] <= Pre[i + 1][0])) {
//      printf("From %u\n", i);
      register unsigned L(i + 2), R(n), Mid;
      while (L < R) {
        Mid = ((L + R + 1) >> 1);
        printf("[%u, %u] %d\n", i, Mid, Find(i, Mid));
        if(Pre[i][0] > Find(i, Mid)) {
          R = Mid - 1;
        } else {
          L = Mid;
        }
      }
      printf("To %u\n", L);
      Ans = max(Ans, Sum[L] - Sum[i - 1]);
//      printf("Got %u\n", Sum[L] - Sum[i - 1]);
    }
  }
//  printf("%u Sum %u %u\n", n, Sum[n], Sum[n - 1]);
  if(Sum[n - 1] - Sum[n - 2]) Ans = max(Ans, (unsigned)1);
  if(Sum[n] - Sum[n - 1]) {
    Ans = max(Ans, (unsigned)1);
    if(Sum[n - 1] - Sum[n - 2]) Ans = max(Ans, (unsigned)2);
  }
  printf("%u\n", Ans);
//  }
  return Wild_Donkey;
}

