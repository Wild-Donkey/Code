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
unsigned m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
bool b[1000005];
char a[1000005], Mx(0);
inline void Clr() {}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  scanf("%s", a);
  A = 0x3f3f3f3f;
  for (register unsigned i(n - 1); i < 0x3f3f3f3f; --i) {
    if(a[i] < Mx) {// 可以做二元组前面的一个 
      A = i;
      break; 
    }
    Mx = max(a[i], Mx);
  }
  if(A == 0x3f3f3f3f) {
    printf("-1");
    return 0;
  }
  B = 0x3f3f3f3f;
  for (register unsigned i(A + 1); i < n; ++i) {
    if(a[i] > a[A]) {
      B = i;
    }
  }
  if(B == 0x3f3f3f3f) {
    printf("-1");
    return 0;
  }
  printf("%u %u", A + 1, B + 1);
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



