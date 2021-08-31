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
unsigned Bd[500005], Pos1[500005], Pos2[500005], m, n, q, Cnt(0), A, B, C, D, t, Ans(0);
char a[500005], b[500005];
inline void Clr() {}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), q = RD();
  scanf("%s%s", a + 1, b + 1);
  Bd[0] = -1;
//  Pos1[-1] = 0;
  for (register unsigned i(2), Tmp; i <= m; ++i) {
    Tmp = Bd[i - 1];
    while ((b[i] ^ b[Tmp + 1]) &&(Tmp < 0x3f3f3f3f)) {
//      if(Tmp == Bd[Tmp]) Pos1[0x3f3f3f3f] = 0;
      Tmp = Bd[Tmp]; 
    }
    Bd[i] = Tmp + 1;
  }
  for (register unsigned i(1), j(0); i <= n; ++i) {
    while ((a[i] ^ b[j + 1]) && (j < 0x3f3f3f3f)) {
//      if(j == Bd[j]) Pos1[0x3f3f3f3f] = 0;
      j = Bd[j];
    }
    if(j > 0x3f3f3f3f) {
      j = 0;
      continue;
    } else {
      ++j;
      if(Pos1[j] < q){
        Pos1[j] = i;
      }
      if((j == m) && (!A)) {
        A = i;
      }
    }
  }
  for (register unsigned i(m - 1); i; --i) {
    if((Pos1[i + 1] > q) && Pos1[i + 1]) {
      Pos1[i] = min(Pos1[i], Pos1[i + 1] - 1);
    }
  }
  for (register unsigned i(m); i; --i) {
    if(Pos1[i] < q) {Pos1[i] = 0; continue;}
    if(Pos1[Bd[i]] < q) Pos1[Bd[i]] = Pos1[i];
    else Pos1[Bd[i]] = min(Pos1[Bd[i]], Pos1[i]);
  }
//  for (register unsigned i(1); i <= m; ++i) {
//    printf("%u %u\n", i, Pos1[i]);
//  }
  Bd[m + 1] = -1;
  Bd[m] = 0;
  for (register unsigned i(m - 1), Tmp; i; --i) {
    Tmp = Bd[i + 1];
    while ((b[i] ^ b[m - Tmp]) && (Tmp < 0x3f3f3f3f)) {
//      if(Tmp == Bd[Tmp]) Pos1[0x3f3f3f3f] = 0;
      Tmp = Bd[m - Tmp + 1];
    }
    Bd[i] = Tmp + 1;
//    printf("BD %u %u\n", i, Bd[i]);
  }
//  if(m == 19041) Pos1[0x3f3f3f3f] = 0;
  for (register unsigned i(n), j(0); i; --i) {
    while ((j < 0x3f3f3f3f) && (a[i] ^ b[m - j])) {
//      if(j == Bd[m - j + 1]) Pos1[0x3f3f3f3f] = 0;
      j = Bd[m - j + 1];
    }
//    printf("Caonima %u %u\n", i, j);
    if(j > 0x3f3f3f3f) {
      j = 0;
      continue;
    } else {
      if((n - Pos2[m - j] + 1 < q) || (!Pos2[m - j])) {
        Pos2[m - j] = i;
      }
      ++j;
      if((j == m) && (!B)) {
        B = i;
      }
    }
  }
//  for (register unsigned i(1); i <= m; ++i) {
//    printf("%u %u\n", i, Pos2[i]);
//  }
  for (register unsigned i(2); i <= m; ++i) {
    if((n - Pos2[i - 1] + 1 > q) && (Pos2[i - 1])) {
      Pos2[i] = max(Pos2[i], Pos2[i - 1] + 1);
    }
  }
  for (register unsigned i(1); i <= m; ++i) {
    if(n - Pos2[i] + 1 < q) {Pos2[i] = 0; continue;}
    if(n - Pos2[m - Bd[i] + 1] + 1 < q) Pos2[m - Bd[i] + 1] = Pos2[i];
    else Pos2[m - Bd[i] + 1] = max(Pos2[i], Pos2[m - Bd[i] + 1]); 
  }
//  for (register unsigned i(1); i <= m; ++i) {
//    printf("%u %u\n", i, Pos2[i]);
//  }
  if(q >= m) {
    if(A && (n >= q + max(A, q))) {
      printf("Yes\n%u %u\n", max(A, q) - q + 1, max(A, q) + 1);
      return 0;
    }
    if(B && (min(B, n - q + 1) > q)) {
      printf("Yes\n%u %u\n", min(B, n - q + 1) - q, min(B, n - q + 1));
      return 0; 
    }
  }
  for (register unsigned i(m - min(m - 1, q)); i <= min(m - 1, q); ++i) {
    if(Pos1[i] && Pos2[i + 1] && (Pos1[i] < Pos2[i + 1])) {
      printf("Yes\n%u %u\n", Pos1[i] - q + 1, Pos2[i + 1]);
      return 0;
    }
  }
  printf("No\n");
//  }
  return Wild_Donkey;
}
/*
5 3 2
aaaaa
aaa

Yes
1 3
*/
