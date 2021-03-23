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
unsigned Lst[10005], m, n, Cnt(0), la(0), lb(0), C, D, t, Ans(0), Tmp(0);
bool b[10005];
char A[1000005], B[1000005], inch;
inline void Clr() {}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr(); 
  inch = getchar();
  while (inch < 'A' || inch > 'Z') {
    inch = getchar();
  }
  while (inch >= 'A' && inch <= 'Z') {
    A[++la] = inch;
    inch = getchar();
  }
  while (inch < 'A' || inch > 'Z') {
    inch = getchar();
  }
  while (inch >= 'A' && inch <= 'Z') {
    B[++lb] = inch;
    inch = getchar();
  } 
//  for (register unsigned i(1); i <= la; ++i) {
//    putchar(A[i]);
//  }
//  for (register unsigned i(1); i <= lb; ++i) {
//    putchar(B[i]);
//  }
  for (register unsigned i(1); i <= la; ++i) {
    unsigned k(0);
    while (A[i + k] == B[1 + k] && k < lb) {
      ++k;
    }
//    printf("k=%u\n", k);
    if(k == lb) {
      printf("%u\n", i);
    }
  }
  for (register unsigned i(1); i <= lb; ++i) { // Origin_Len
    for (register unsigned j(i - 1); j < 0x3f3f3f3f; --j) { // Sub_Len
      unsigned k(1);
      while (B[k] == B[i - j + k] && k <= j) {
        ++k;
      }
      if (k == j + 1) {
        printf("%u ", j);
        break;
      }
    }
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



