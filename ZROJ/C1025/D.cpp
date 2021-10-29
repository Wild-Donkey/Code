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
#include <string>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
const unsigned long long Mod(1000000007);
const char CanDo[10] = {5, 6, 7, 9, 10, 11, 13, 14, 15};
unsigned long long f[50005][16];
unsigned m, n, n2;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char a[100005], Rule[10], Now(0);
char To0, To1;
char Pre;
inline void Clr() {
  memset(a, 0, n + 2);
  memset(f, 0, sizeof(f));
  scanf("%s", Rule), scanf("%s", a + 1);
  for (char i(0); i < 8; ++i) Rule[i] -= '0';
  n = strlen(a + 1);
  n2 = n >> 1;
  f[0][9] = 1;
  Ans = 0;
}
inline void Calc(unsigned Pos, char Sit) {
  unsigned StP(Pos << 1);
//  printf("f[%u, %u] -> a %u %u\n", Pos, Sit, a[StP + 1] - '0', a[StP + 2] - '0');
  char Nxt(0);
  Now = ((a[StP + 2] - '0') << 1) | (a[StP + 1] - '0');
  To0 = Rule[Now], To1 = Rule[Now ^ 4];
//  printf("To %u %u\n", To0, To1);
  if(To0 == To1) {
    if(To0) Tmp = (Sit & 3);
    else Tmp = (Sit & 12) >> 2;
    Nxt |= Tmp | (Tmp << 2);
  } else {
    if(To0) {
      Tmp = (Sit >> 2) | ((Sit & 3) << 2);
    } else Tmp = Sit;
    Nxt |= Tmp;
  }
  if(a[StP + 1] ^ '0') Pre = (Sit & 3);
  else Pre = (Sit & 12) >> 2;
//  printf("Pre %u\n", Pre, Nxt);
  if(Pre & 2) {
    Now = (a[StP + 2] - '0') << 1;
    if(Rule[Now]) Nxt |= 4;
    else Nxt |= 8;
    Now ^= 4;
    if(Rule[Now]) Nxt |= 1;
    else Nxt |= 2;
  }
  if(Pre & 1) {
    Now = 1 | ((a[StP + 2] - '0') << 1);
    if(Rule[Now]) Nxt |= 4;
    else Nxt |= 8;
    Now ^= 4;
    if(Rule[Now]) Nxt |= 1;
    else Nxt |= 2;
  }
//  printf("To f[%u][%u]\n", Pos + 1, Nxt);
  f[Pos + 1][Nxt] += f[Pos][Sit];
  if(f[Pos + 1][Nxt] >= Mod) f[Pos + 1][Nxt] -= Mod; 
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
//    printf("n = %u\n", n);
    for (unsigned i(1); i <= n2; ++i) {
      if(a[(i << 1) - 1] == '?') {
        if(a[i << 1] == '?') {
          a[(i << 1) - 1] = '0';
          a[i << 1] = '0';
          for (unsigned j(0); j < 9; ++j) Calc(i - 1, CanDo[j]);
          a[i << 1] = '1';
          for (unsigned j(0); j < 9; ++j) Calc(i - 1, CanDo[j]);
          a[(i << 1) - 1] = '1';
          a[i << 1] = '0';
          for (unsigned j(0); j < 9; ++j) Calc(i - 1, CanDo[j]);
          a[i << 1] = '1';
          for (unsigned j(0); j < 9; ++j) Calc(i - 1, CanDo[j]);
        } else {
          a[(i << 1) - 1] = '0';
          for (unsigned j(0); j < 9; ++j) Calc(i - 1, CanDo[j]);
          a[(i << 1) - 1] = '1';
          for (unsigned j(0); j < 9; ++j) Calc(i - 1, CanDo[j]);
        }
      } else {
        if(a[i << 1] == '?') {
          a[i << 1] = '0';
          for (unsigned j(0); j < 9; ++j) Calc(i - 1, CanDo[j]);
          a[i << 1] = '1';
          for (unsigned j(0); j < 9; ++j) Calc(i - 1, CanDo[j]);
        } else for (unsigned j(0); j < 9; ++j) Calc(i - 1, CanDo[j]);
      }
//      for (unsigned j(0); j < 9; ++j) printf("f[%u][%u] = %llu\n", i, CanDo[j], f[i][CanDo[j]]);
    }
    if(a[n] ^ '0') Ans += f[n2][5] + f[n2][7] + f[n2][9] + f[n2][11] + f[n2][13] + f[n2][15];
    if(a[n] ^ '1') Ans += f[n2][5] + f[n2][6] + f[n2][7] + f[n2][13] + f[n2][14] + f[n2][15];
//    if(a[n] == '?') Ans -= f[n2][5] + f[n2][7] + f[n2][13] + f[n2][15];
    Ans %= Mod;
    printf("%llu\n", Ans);
  }
  return Wild_Donkey;
}
/*
2
10001100
000
10111010
??01?
*/
