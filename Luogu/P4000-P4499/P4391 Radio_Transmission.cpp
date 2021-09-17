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
unsigned a[1000005], m, n, Cnt(0), la(0), lb(0), C, D, t, Ans(0), Tmp(0);
bool b[10005];
char A[1000005], B[1000005], inch;
inline void Clr() {}
int main() {
  // double Ti(clock()), Mti(0);
//   freopen("P3375_11.in", "r", stdin);
//   freopen("P3375.out", "w", stdout);
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
  unsigned k(1);
  for (register unsigned i(2); i <= lb; ++i)  { // Origin_Len
    while ((B[k] != B[i] && k > 1) || k > i) {
      k = a[k - 1] + 1;
//      printf("%u\n", k);
    }
    if(B[k] == B[i]) {
      a[i] = k;
  //    printf("%u %u\n", i, k);
      ++k;
    }
    continue;
  }
  k = 1;
  for (register unsigned i(1); i + lb <= la + 1;) {  // Origin_Address
    while (A[i + k - 1] == B[k] && k <= lb) {
      ++k;
    }
    if(k == lb + 1) {
      printf("%u\n", i);
    }
//    printf("%u %u %u\n", i, k, a[k - 1]);
    if(a[k - 1] == 0) {
      ++i;
      k = 1;
      continue;
    }
    --k;
    i += k - a[k];  // Substring of Len(k - 1) has already paired, so the next time, start with the border of the (k - 1) length substring
    k = a[k] + 1;
  }
  for (register unsigned i(1); i <= lb; ++i) { // Origin_Len
    printf("%u ", a[i]);
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
ABCABCDABABCDABCDABDE
ABCDABD
*/
