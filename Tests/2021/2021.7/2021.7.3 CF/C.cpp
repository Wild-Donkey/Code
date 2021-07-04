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
inline unsigned long long RD() {
  unsigned long long intmp(0);
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
const unsigned long long MOD(1000000007);
unsigned long long Times[50], Val[50], n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
bool b[10005];
inline void Clr() {
  n = RD(), Ans = n % MOD, Tmp = 0;
}
inline unsigned long long F(unsigned x) {
  register unsigned long long Div(1);
  while (!(x % Div)) {
    ++Div;
  }
  return Div;
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  Times[1] = 1;
  for (register unsigned i(2); i <= 43; ++i) {
    Times[i] = Times[i - 1] * i;
    if((!(i % 2)) && (i ^ 2)) Times[i] >>= 1;
    if((!(i % 3)) && (i ^ 3)) Times[i] /= 3;
    if((!(i % 4)) && (i ^ 4)) Times[i] >>= 1;
    if((!(i % 5)) && (i ^ 5)) Times[i] /= 5;
    if((!(i % 7)) && (i ^ 7)) Times[i] /= 7;
    if((!(i % 8)) && (i ^ 8)) Times[i] >>= 1;
    if((!(i % 9)) && (i ^ 9)) Times[i] /= 3;
    if((!(i % 11)) && (i ^ 11)) Times[i] /= 11;
    if((!(i % 13)) && (i ^ 13)) Times[i] /= 13;
    if((!(i % 16)) && (i ^ 16)) Times[i] >>= 1;
    if((!(i % 17)) && (i ^ 17)) Times[i] /= 17;
    if((!(i % 19)) && (i ^ 19)) Times[i] /= 19;
//    printf("%u %llu\n", i, Times[i]);
  }
  t = RD();
  for (register unsigned T(1); T <= t; ++T){
    Clr();
    for (register unsigned i(43); i; --i) {
      Ans += (n / Times[i]) % MOD;
      if(Ans >= MOD) Ans -= MOD;
    }
//    printf("%llu %llu\n", n, Ans);
    printf("%llu\n", Ans);
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
4
10
14
15
16
18
19
20
*/
