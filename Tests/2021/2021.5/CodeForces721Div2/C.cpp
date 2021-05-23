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
unsigned a[100005], b[100005], m, n, Cnt[100005], CntNum(0), t, Tmp(0), List[100005];
unsigned long long Sum[100005], Ans[100005];
inline void Clr() {
//  printf("CntNum %u\n", CntNum);
  memset(a, 0, sizeof(unsigned) * (n + 1));
  memset(b, 0, sizeof(unsigned) * (n + 1));
  memset(List, 0, sizeof(unsigned) * (CntNum + 1));
  memset(Ans, 0, (CntNum + 1) << 3);
  memset(Sum, 0, (CntNum + 1) << 3);
  CntNum = 0;
  return; 
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned T(1); T <= t; ++T){
    n = RD();
    for (register unsigned i(1); i <= n; ++i) {
      a[i] = RD();
    }
//    printf("n = %u\n", n);
    memcpy(b, a, (n + 1) << 2);
    sort(b + 1, b + n + 1);
    for (register unsigned i(1); i <= n; ++i) {
//      printf("%u %u %u\n", i, b[i], a[i]);
      if(b[i] ^ b[i - 1]) {
        List[++CntNum] = b[i];
      }
    }
//    printf("Sorted\111n");
//    printf("\n%u %u\n\n", CntNum, n);
    for (register unsigned i(1); i <= n; ++i) {
      a[i] = lower_bound(List + 1, List + CntNum + 1, a[i]) - List;
    }
    for (register unsigned i(1); i <= n; ++i) {
      Ans[a[i]] += (n - i + 1) * Sum[a[i]];
      Sum[a[i]] += i;
//      printf("%u %u %llu %llu\n", i, a[i], Ans[a[i]], Sum[a[i]]);
    }
    for (register unsigned i(1); i <= CntNum; ++i) {
      Ans[0] += Ans[i];
    }
    printf("%llu\n", Ans[0]);
    Clr();
  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
3
4
1 2 1 1
4
1 2 3 4
5
1 1 2 2 1
*/
