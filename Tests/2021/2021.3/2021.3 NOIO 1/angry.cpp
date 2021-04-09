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
const unsigned MOD(1000000007);
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
unsigned a[10005], n(0), m, Cnt(0), A, B, C, D, t, Ans[500], Tmp(0), Sum[500005], Sumx[500005], Number[500005], K_1(0), Cnt1(0);
bool b[500005];
char inputCharacter;
inline void Clr() {}
bool Judge() {
  
}
int main() {
  // double Ti(clock()), Mti(0);
   freopen("angry.in", "r", stdin);
   freopen("angry.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  inputCharacter = getchar();
  while (inputCharacter != '0' && inputCharacter != '1') {
    inputCharacter = getchar(); 
  }
  while (inputCharacter == '0' || inputCharacter == '1') {
    b[++n] = inputCharacter - '0';
    inputCharacter = getchar();
  }
  m = RD();
  for (register unsigned i(0); i < m; ++i) {
    a[i] = RD();
  }
  Sum[0] = 0;
  for (register unsigned i(1); i <= n; ++i) {
    Sum[i] = (Sum[i - 1] << 1) + (1 << ((i - 1) << 1));
  }
  Sumx[0] = 0;
  Sumx[1] = 1;
  for (register unsigned i(2); i <= n; ++i) {
    Sumx[i] = (Sum[i - 1]) + ((1 << ((i - 2) << 1)) << 1);
//    printf("%u %u\n", i, Sumx[i]);
  }
  Number[1] = 1;
  for (register unsigned i(2); i <= n; ++i) {
    Number[i] = (unsigned long long)(Number[i - 1] << 1) % MOD;
  }
  if(m <= 2) {
    for (register unsigned i(1); i <= n; ++i) {
      if(b[i]) {
        ++Cnt1;
        K_1 = (K_1 + Number[n - i]) % MOD;
      }
    }
    if(((!b[n]) && (Cnt1 & 1)) || b[n]) {
      ++K_1;
      K_1 %= MOD;
    }
    if(m == 1) {
      printf("%u\n", (long long)K_1 * a[0] % MOD);
      return 0;
    }
    for (register unsigned i(1); i <= n; ++i) {
      if(b[i]) {
        if(Cnt1)
        ++Cnt1;
        K_1 = (K_1 + Sumx[n - i]) % MOD;
      }
    }
    Ans[0] = (long long)K_1 * a[0] % MOD;
//    printf("", ());
  }
//  Power[0] = 1;
  for (register unsigned i(1); i <= n; ++i) {
    for (register unsigned i(1); i < m; ++i) {
//      Power[i] = (long long)Power[i - 1] * Sumx[n] % MOD;
//      printf("%u %u\n", i, Power[i]);
    }
  }
//  Sum = 14;
  for (register unsigned i(m - 1); i < 0x3f3f3f3f; --i) {
//    Ans = (unsigned long long)Sum * Ans % MOD;
//    Ans += a[i];
  }
  printf("%u\n", Ans);
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
1000
3
3 2 1
1001011001101001
1
1
*/
