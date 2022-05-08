#include<algorithm>
#include<bitset> 
#include<cstdio>
#include<iostream> 
#include<vector>
using namespace std;
const unsigned long long Mod(998244353);
inline void Mn(unsigned &x) {x -= ((x >= Mod) ? Mod : 0);}
inline void Mn(unsigned long long &x) {x -= ((x >= Mod) ? Mod : 0);}
inline unsigned RD() {
  unsigned RTmp(0);
  char ch(getchar()); 
  while (ch < '0' && ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') RTmp = RTmp * 10 + ch - '0', ch = getchar(); 
  return RTmp;
}
bitset<2005> Away[2005], Ava, Cur;
unsigned Two[1000005];
unsigned a[2005], Ask[20005], n, m, Cnt(0), A, B, Mx;
unsigned long long Ans;
inline void DFS (unsigned Dep) {
  if(Dep == Mx) {
    unsigned Sum(0);
    for (unsigned i(1); i <= 2000; ++i) if(Cur[i]) Sum += a[i];
//    for (unsigned i(1); i <= 100; ++i) putchar('0' + Cur[i]); putchar(0x0A);
//    printf("%u %u\n", A, Sum);
    Mn(Ans += ((A & 1) ? (Mod - Two[n - Sum]) : Two[n - Sum]));
    return;
  }
  bitset<2005> Last(Cur);
  DFS(Dep + 1);
  Cur |= Away[Ask[Dep + 1]], ++A;
  DFS(Dep + 1);
  Cur = Last, --A;
}
int main() {
//  freopen("card.in", "r", stdin);
//  freopen("card.out", "w", stdout);
  n = RD(), Two[0] = 1;
  for (unsigned i(1); i <= n; ++i) ++a[RD()];
  for (unsigned i(1); i <= n; ++i) Two[i] = Two[i - 1] + Two[i - 1], Mn(Two[i]);
  for (unsigned i(1); i <= 2000; ++i)
    for (unsigned j(2000 / i); j; --j) if(a[i * j])
      Away[i][i * j] = Ava[i] = 1;
  m = RD();
  for (unsigned i(1); i <= m; ++i) {
    Cnt = RD(), Mx = 0, Ans = 0;
    for (unsigned j(1); j <= Cnt; ++j) {A = RD(); if(Ava[A]) Ask[++Mx] = A;}
    if(!Mx) {printf("0\n"); continue;}
    A = 0, DFS(0);
    printf("%llu\n", Ans);
  }
  return 0;
}
/*
5
10 2 10 5 46
4
2 2 5
2 2 23
1 3
1 23
*/
