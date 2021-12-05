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
  do {
    printf("Case %u\n", ++Ans);
    A = clock();
    system("B_Ma.exe");
    B = clock();
    system("B_Fc.exe");
    C = clock();
    system("B.exe");
    D = clock();
    printf("Time %u %u %u (ms)\n", B - A, C - B, D - C);
  }while(!system("fc B.out B.ans"));
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
