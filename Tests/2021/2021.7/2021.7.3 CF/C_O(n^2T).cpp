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
unsigned long long f[10005], n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
bool b[10005];
inline void Clr() {
  n = RD(), Ans = 0;
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
  t = RD();
  for (register unsigned T(1); T <= t; ++T){
    Clr();
    for (register unsigned i(1); i <= n; ++i) {
//      printf("F(%u) = %llu\n", i, F(i));
      Ans += F(i);
    }
    printf("\nFAQ %llu\n", Ans);
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



