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
unsigned m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
bool flg(0);
char ch;
inline void Clr() {}
unsigned Phi(unsigned x) {
  unsigned tmp(x), anotherTmp(x), Sq(sqrt(x));
  for (register unsigned i(2); i <= Sq && i <= x; ++i) {
//    printf("%unow\n", i);
    if(!(x % i)) {
      while (!(x % i)) {
        x /= i;
      }
      tmp /= i;
      tmp *= i - 1;
    }
  }
  if (x > 1) {//存在大于根号 x 的质因数 
    tmp /= x;
    tmp *= x - 1;
  }
  return tmp;
}
unsigned Power(unsigned x, unsigned y) {
  if(!y) {
    return 1;
  }
  unsigned tmp(Power(x, y >> 1));
  tmp = ((long long)tmp * tmp) % D;
  if(y & 1) {
    return ((long long)tmp * x) % D;
  }
  return tmp;
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  A = RD();
  D = RD();
  C = Phi(D);
//  printf("%u phi = %u\n", D, C);
  while (ch < '0' || ch > '9') {
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    B *= 10;
    B += ch - '0';
    if(B > C) {
      flg = 1;
      B %= C;
    }
    ch = getchar();
  }
  if(B == 1) {
    printf("%u\n", A % D);
    return Wild_Donkey;
  }
  if(flg) {
    printf("%u\n", Power(A, B + C));
  }
  else {
    printf("%u\n", Power(A, B));
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



