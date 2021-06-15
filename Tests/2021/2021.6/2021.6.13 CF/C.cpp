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
const unsigned MOD(1000000007);
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
unsigned Out[400005], a[400005], Bin[400005], m, n(0), Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
char Ava[400005];
inline void Clr() {
  Cnt = 0;
  memset(Ava, 0, n + 2);
  n = RD();
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  t = RD();
  Bin[0] = 1;
  for (register unsigned i(1); i <= 400000; ++i) {
    Bin[i] = Bin[i - 1] << 1;
    if(Bin[i] >= MOD) Bin[i] -= MOD; 
  }
  for (register unsigned T(1); T <= t; ++T){
    Clr();
    for (register unsigned i(1); i <= n; ++i) {
      a[i] = RD();
    }
    for (register unsigned i(1); i <= n; ++i) {
      Out[a[i]] = RD();
    }
//    for (register unsigned i(1); i <= n; ++i) {
//      printf("%u %u\n", i, Out[i]);
//    }
    for (register unsigned i(1); i <= n; ++i) {
      if(Ava[i]) continue;
//      printf("++Cnt %u\n", i);
      ++Cnt, A = i;
      while (!Ava[A]) {
        Ava[A] = 1, A = Out[A];
      }
    }
    printf("%u\n", Bin[Cnt]);
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
8
2 6 5 1 4 3 7 8
3 8 7 5 1 2 4 6
4
1 4 2 3
3 2 1 4
2
1 2
2 1

8
2
2
*/
