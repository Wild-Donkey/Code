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
unsigned a[10005], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
bool b[10005];
inline void Clr() {}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  //  n = RD();
  for (register unsigned i(1); i <= 1000; ++i) {
    for (register unsigned j(1); j <= 1000000000; ++j) {
    }
    printf("%llu\n", i * (unsigned long long)1000000000);
  }
  //  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
//sect 51893847 
//ais 25125, 15706, 24001, 24019, 20447[1, 1253] And [1257, 1257]
//Mozak 2890, 2838, 2496, 3102, 2933
//ZidWrap 10641,  
//MatterTorz 2786(85, )
// Luogu Online IDE with O2 0.062s
// 2021 ASUS vivobook with r7-5800H at Quiet Mode with AC power c++11 -O2 1.243s
// 2021 ASUS vivobook with r7-5800H at Quiet Mode with AC power -O2 1.262s
// LCEZ's Lenovo Computer with i3-4170 O2 1.361s
// 2012 ASUS -O2 2.326s

// Wild_Donkey's Main PC with r7-3700X 233.7s
// 2021 ASUS vivobook with r7-5800H at Quiet Mode with AC power 241.9s
// LCEZ's Lenovo Computer with i3-4170 294.4s
// SDSY's Huawei Laptop with i7-4790H 303s
// Actinoi MAC Book 1116.4s
