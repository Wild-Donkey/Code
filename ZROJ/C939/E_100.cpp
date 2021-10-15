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
#define Lowbit(x) ((x)&((~(x))+1)) 
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
const unsigned long long Mod(998244353);
unsigned long long f[65][68][68][68];
unsigned long long C1[68], C2[68], C3[68], Ans(0);
unsigned m, n, Cnt(0), A, B, C, D, t;
int main() {
//  freopen("E.in", "r", stdin);
//  freopen("E.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), f[0][0][0][0] = 1;
  for (unsigned i(1); i <= n; ++i)
    C1[i] = i, C2[i] = (C1[i] * (C1[i] - 1)) >> 1, C3[i] = (C2[i] * (C1[i] - 2)) / 3;
  C3[2] = C3[1] = C2[1] = 0;
  for (unsigned i(1); i <= m; ++i) {
    for (unsigned j1(n); ~j1; --j1) {
      for (unsigned j2(n - j1); ~j2; --j2) {
        for (unsigned j3(n - j1 - j2); ~j3; --j3) {
//          printf("f%u %u %u %u\n", i, j1, j2, j3);
//          printf("Choose 1\n");
          f[i][j1][j2][j3] += f[i - 1][j1][j2][j3]; if(f[i][j2][j3][j3] >= Mod) f[i][j1][j2][j3] -= Mod;
          if(j1) f[i][j1][j2][j3] = (f[i][j1][j2][j3] + f[i - 1][j1 - 1][j2 + 1][j3] * C1[j2 + 1]) % Mod;
          if(j2) f[i][j1][j2][j3] = (f[i][j1][j2][j3] + f[i - 1][j1][j2 - 1][j3 + 1] * C1[j3 + 1]) % Mod;
          if(j3) f[i][j1][j2][j3] = (f[i][j1][j2][j3] + f[i - 1][j1][j2][j3 - 1] * C1[n - j1 - j2 - j3 + 1]) % Mod;
//          printf("Choose 2\n");
          if(j1 > 1) f[i][j1][j2][j3] = (f[i][j1][j2][j3] + f[i - 1][j1 - 2][j2 + 2][j3] * C2[j2 + 2]) % Mod;
          if(j2 > 1) f[i][j1][j2][j3] = (f[i][j1][j2][j3] + f[i - 1][j1][j2 - 2][j3 + 2] * C2[j3 + 2]) % Mod;
          if(j3 > 1) f[i][j1][j2][j3] = (f[i][j1][j2][j3] + f[i - 1][j1][j2][j3 - 2] * C2[n - j1 - j2 - j3 + 2]) % Mod;
          if(j1) f[i][j1][j2][j3] = (f[i][j1][j2][j3] + f[i - 1][j1 - 1][j2][j3 + 1] * C1[j2] * C1[j3 + 1]) % Mod;
          if(j1 && j3) f[i][j1][j2][j3] = (f[i][j1][j2][j3] + f[i - 1][j1 - 1][j2 + 1][j3 - 1] * C1[j2 + 1] * C1[n - j1 - j2 - j3 + 1]) % Mod;
          if(j2) f[i][j1][j2][j3] = (f[i][j1][j2][j3] + f[i - 1][j1][j2 - 1][j3] * C1[j3] * C1[n - j1 - j2 - j3 + 1]) % Mod;
//          printf("Choose 3\n");
//          printf("In1:\n");
          if(j1 > 2) f[i][j1][j2][j3] = (f[i][j1][j2][j3] + f[i - 1][j1 - 3][j2 + 3][j3] * C3[j2 + 3]) % Mod;
          if(j2 > 2) f[i][j1][j2][j3] = (f[i][j1][j2][j3] + f[i - 1][j1][j2 - 3][j3 + 3] * C3[j3 + 3]) % Mod;
          if(j3 > 2) f[i][j1][j2][j3] = (f[i][j1][j2][j3] + f[i - 1][j1][j2][j3 - 3] * C3[n - j1 - j2 - j3 + 3]) % Mod;
//          printf("In2:\n");
          if(j1 > 1) f[i][j1][j2][j3] = (f[i][j1][j2][j3] + f[i - 1][j1 - 2][j2 + 1][j3 + 1] * C2[j2 + 1] * C1[j3 + 1]) % Mod;
          if((j1 > 1) && j3) f[i][j1][j2][j3] = (f[i][j1][j2][j3] + f[i - 1][j1 - 2][j2 + 2][j3 - 1] * C2[j2 + 2] * C1[n - j1 - j2 - j3 + 1]) % Mod;
          if(j1 && j2) f[i][j1][j2][j3] = (f[i][j1][j2][j3] + f[i - 1][j1 - 1][j2 - 1][j3 + 2] * C2[j3 + 2] * C1[j2 - 1]) % Mod;
          if(j2 > 1) f[i][j1][j2][j3] = (f[i][j1][j2][j3] + f[i - 1][j1][j2 - 2][j3 + 1] * C2[j3 + 1] * C1[n - j1 - j2 - j3 + 1]) % Mod;
          if(j1 && (j3 > 1)) f[i][j1][j2][j3] = (f[i][j1][j2][j3] + f[i - 1][j1 - 1][j2 + 1][j3 - 2] * C2[n - j1 - j2 - j3 + 2] * C1[j2 + 1]) % Mod;
          if(j2 && j3) f[i][j1][j2][j3] = (f[i][j1][j2][j3] + f[i - 1][j1][j2 - 1][j3 - 1] * C2[n - j1 - j2 - j3 + 2] * C1[j3 - 1]) % Mod;
//          printf("In3:\n");
          if(j1) f[i][j1][j2][j3] = (f[i][j1][j2][j3] + f[i - 1][j1 - 1][j2][j3] * C1[n - j1 - j2 - j3 + 1] * C1[j3] * C1[j2]) % Mod;
        }
      }
    }
  }
  for (unsigned i1(n); ~i1; --i1)
    for (unsigned i2(n - i1); ~i2; --i2)
      for (unsigned i3(n - i1 - i2); ~i3; --i3)
        {Ans += f[m][i1][i2][i3]; if(Ans >= Mod) Ans -= Mod;}
  printf("%u\n", Ans);
  return Wild_Donkey;
}

