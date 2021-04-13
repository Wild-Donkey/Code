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
unsigned n, Frontier(0), Ans(0), Tmp(0), f1[11000005], f2[11000005];
char a[11000005];
inline void Clr() {}
int main() {
	fread(a+1,1,11000000,stdin);        // fread 优化 
  n = strlen(a + 1);                  // 字符串长度 
  a[0] = 'A';
  a[n + 1] = 'B';                     // 哨兵 
  for (register unsigned i(1); i <= n; ++i) {   // 先求 f1 
    if(i + 1 > Frontier + f1[Frontier]) {       // 朴素 
      while (!(a[i - f1[i]] ^ a[i + f1[i]])) {
        ++f1[i];
      }
      Frontier = i;                             // 更新 Frontier 
    }
    else {
      register unsigned Reverse((Frontier << 1) - i), A(Reverse - f1[Reverse]), B(Frontier - f1[Frontier]);
      f1[i] = Reverse - ((A < B) ? B : A);                      // 确定 f1[i] 下界 
      if (!(Reverse - f1[Reverse] ^ Frontier - f1[Frontier])) { // 特殊情况 
        while (!(a[i - f1[i]] ^ a[i + f1[i]])) {
          ++f1[i];
        }
        Frontier = i;                                           // 更新 Frontier 
      }
    }
    Ans = ((Ans < f1[i]) ? f1[i] : Ans);
  }
  Ans = (Ans << 1) - 1;                             // 根据 max(f1) 求长度 
  Frontier = 0;
  for (register unsigned i(1); i <= n; ++i) {
    if(i + 1 > Frontier + f2[Frontier]) {           // 朴素 
      while (!(a[i - f2[i] - 1] ^ a[i + f2[i]])) {
        ++f2[i];
      }
      Frontier = i;                                 // 更新 Frontier 
    }
    else {
      register unsigned Reverse ((Frontier << 1) - i - 1), A(Reverse - f2[Reverse]), B(Frontier - f2[Frontier]);
        f2[i] = Reverse - ((A < B) ? B : A);        // 确定 f2[i] 下界 
      if (A == B) { // 特殊情况, 朴素 
        while (a[i - f2[i] - 1] == a[i + f2[i]]) {
          ++f2[i];
        }
        Frontier = i;                               // 更新 Frontier 
      }
    }
    Tmp = ((Tmp < f2[i]) ? f2[i] : Tmp);
  }
  Tmp <<= 1;                                        // 根据 max(f2) 求长度 
  printf("%u\n", (Ans < Tmp) ? Tmp : Ans);          // 奇偶取其大 
  return Wild_Donkey;
}


