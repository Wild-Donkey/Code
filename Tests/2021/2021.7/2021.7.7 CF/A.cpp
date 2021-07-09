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
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
unsigned t;
unsigned long long A, B, C;
inline void Clr() {
  A = RD(), B = RD(); 
}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned T(1); T <= t; ++T){
    Clr();
    if(A > B) {
      C = A - B;
      A = B;
      B = A + C;
    } else {
      C = B - A;
    }
    if(!C) {
      printf("0 0\n");
      continue;
    }
//    if(A < C) {
//      printf("%llu %llu\n", C, C - A);
//      continue;
//    }
    A %= C;
    printf("%llu %llu\n", C, min(A, C - A)); 
  }
  return Wild_Donkey;
}

