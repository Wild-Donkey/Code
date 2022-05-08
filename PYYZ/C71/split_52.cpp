#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned long long RD() {
  unsigned long long intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
unsigned long long a[10000005], b[30];
unsigned long long n, A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
//  inline void Clr() {}
signed main() {
//  freopen("split.in", "r", stdin);
//  freopen("split.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  b[0] = a[0] = 1;
  for (unsigned i(1); i <= 10000000; ++i) a[i] = a[i - 1] + i;
//  printf("a:"); for (unsigned i(0); i <= 100; ++i) printf("%llu ", a[i]); putchar(0x0A);
  for (unsigned i(1); i <= 19; ++i) b[i] = b[i - 1] * i;
//  printf("b:"); for (unsigned i(0); i <= 19; ++i) printf("%llu\n", b[i]); putchar(0x0A);
  n = RD();
  for (unsigned i(1); i <= n; ++i) {
    A = RD();
    if(A == 3 || A == 5 || A == 8) {printf("-1\n"); continue;} 
    B = lower_bound(b + 1, b + 19, A) - b;
    if(A == b[B]) {printf("1\n%u %llu\n", B, A); continue;}
    B = upper_bound(a + 0, a + 10000001, A) - a - 1;
//    printf("B = %u a[B] = %u\n", B, a[B]);
    if(A == a[B] + 1) {
      if(A == 12) {printf("2\n3 4\n4 8\n"); continue;}
      printf("%u\n3 5\n", B - 2);
      for (unsigned i(4); i <= B - 2; ++i) printf("%u %u\n", i, i - 1);
      printf("%u %u\n%u %u\n", B - 1, B - 3, B, B << 1);
      continue;
    }
    if(A == a[B] + 2) {
      printf("%u\n3 5\n", B - 1);
      for (unsigned i(3); i < B; ++i) printf("%u %u\n", i + 1, i);
      printf("%u %u\n", B + 1, B + 1); continue;
    }
    printf("%u\n", B);
    if(A == a[B]) {
      for (unsigned i(1); i < B; ++i) printf("%u %u\n", i + 1, i);
      printf("%u %u\n", B + 1, B + 1); continue;
    }
    C = A - a[B];
    for (unsigned i(1); i + 2 <= C; ++i) printf("%u %u\n", i + 1, i);
    if(C == B) {printf("%u %u\n%u %u\n", B, B - 2, B + 1, (B + 1) << 1);continue;}
    printf("%u %u\n%u %u\n", C, C - 2, C + 1, 1 + (C << 1));
    for (unsigned i(C + 1); i < B; ++i) printf("%u %u\n", i + 1, i);
    printf("%u %u\n", B + 1, B + 1);
  }
//  }
  return Wild_Donkey;
}

