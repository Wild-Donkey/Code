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
unsigned m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0), List[1000005], Pos(0);
char Character;
int Bucket[1000005], Lend[1000005];
struct DNA {
  unsigned Number;
  int SE;
}a[2000005];
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
//  printf("FAQ\n");
  Cnt = 0; 
  for (register unsigned i(1); i <= n; ++i) {
    Character = getchar();
    while (Character != 's' && Character != 'e') {
      Character = getchar();
    }
    if(Character == 's') {
      a[i].SE = 1;
    }
    else {
      a[i].SE = -1;
    }
    a[i].Number = RD();
    if(!Lend[a[i].Number]) {
      Lend[a[i].Number] = 1;
      List[++Cnt] = a[i].Number;
    }
  }
  for (register unsigned i(1); i <= n; ++i) {
//    printf("%u %u %d\n", i, a[i].Number, a[i].SE);
    a[i + n] = a[i];
  }
  Ans = 0;
  Pos = 1;
  for (register unsigned j(0); j < n; ++j) {
    memset(Lend, 0x3f, sizeof(Lend));
    memset(Bucket, 0, sizeof(Bucket));
    Tmp = 0; 
    for (register unsigned i(1); i <= n; ++i) {
      Bucket[a[i + j].Number] += a[i + j].SE;
      Lend[a[i + j].Number] = min(Lend[a[i + j].Number], Bucket[a[i + j].Number]);
    }
    for (register unsigned i(1); i <= Cnt; ++i) {
//      printf("Try %u %u\n", i, Lend[i]);
      if(Lend[List[i]] == 0 && Bucket[List[i]] == 0) {
        ++Tmp;
      }
    }
    if(Tmp > Ans) {
      Pos = j + 1;
      Ans = Tmp;
    }
  }
  if (Pos == 0) {
    printf("WDNMD\n");
    return Wild_Donkey;
  }
  printf("%u %u", Pos, Ans);
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
