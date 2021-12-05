#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
inline unsigned RD() {
  unsigned RTmp(0);
  char Rch(getchar());
  while (Rch < '0' || Rch > '9') Rch = getchar();
  while (Rch >= '0' && Rch <= '9') RTmp = (RTmp << 3) + (RTmp << 1) + Rch - '0', Rch = getchar();
  return RTmp;
}
const unsigned Mod(998244353);
unsigned n, m, t, Ans(0), a[1000005];
unsigned STop(0), Fist[1000005], HTop(0);
unsigned His[10000005], HisP[10000005];
unsigned A, B, C, D;
signed main() {
  freopen("B.in", "w", stdout);
  srand(time(0));
  n = 10000, m = 10000;
  printf("%u %u\n", n, m);
  for (unsigned i(1); i <= n; ++i) printf("%u ", 1 + rand() % 16);
  putchar(0x0A);
  for (unsigned i(1); i <= m; ++i) {
    D = 1 + rand() % 2;
    if(D == 3 && (!STop)) D = 1;
    switch (D) {
      case(1): {
        A = 1 + rand() % n, B = 1 + rand() % n, ++STop;
        printf("%u %u %u\n", 1, min(A, B), max(A, B));
        break;
      }
      case(2): {
        A = 1 + rand() % n, B = 1 + rand() % n;
        printf("%u %u %u\n", 2, min(A, B), max(A, B));
        break;
      }
      case(3): {
        printf("3\n"), --STop;
        break;
      }
    }
  }
  return 0;
}
/*
10 2
1 2 3 4 5 6 7 8 9 10
1 5 10
2 1 5
3
1 2 10
3
*/
