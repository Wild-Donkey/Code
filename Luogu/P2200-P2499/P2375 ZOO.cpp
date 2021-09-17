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
unsigned a[1000005], b[1000005], len, k, Mx, Cnt(0), A, B, C, D, t, Ans, Tmp(0);
char inch, s[1000005];
inline void Clr() {
  Ans = 1;
  len = 0;
  memset (b, 0, sizeof(b));
  while (inch < 'a' || inch > 'z') {
    inch = getchar();
  }
  while (inch >= 'a' && inch <= 'z') {
    s[++len] = inch;
    inch = getchar();
  }
  k = 1;
  return;
}
int main() {
  // double Ti(clock()), Mti(0);
//   freopen("P2375_2.in", "r", stdin);
//   freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned T(1); T <= t; ++T){
    Clr();
//    for (register unsigned i(1); i <= len; ++i) {
//      putchar(s[i]);
//    }
//    putchar('\n');
    for (register unsigned i(2); i <= len; ++i) {
      while (s[i] != s[k] && k > 1) {
        k = a[k - 1] + 1;
      }
      if (s[i] ==   s[k]) {
        a[i] = k;
        b[i] = b[k] + 1;
        ++k;
        continue;
      }
      a[i] = 0; 
//      k = 1
    }
    Mx = 1;
    for (register unsigned i(2); i <= len; ++i) {
//      if(!(i % 100))
//        printf("%u %u %u\n", k, i);
//      k = a[i - 1] + 1;
      while ((s[k] != s[i] && k > 1) || (k << 1) > i) {
        k = a[k - 1] + 1;
      }
      if (s[i] == s[k]) {
//        printf("i%u k%u\n", i, k);
//        a[i] = k;
        Ans = (long long)Ans * (b[k] + 2) % 1000000007;
//        printf("%u %u %u %u\n", i, b[i], k, b[k] + 1);
        ++k;
        continue;
      }
      k = a[i] + 1;
    }
    printf("%u", Ans);
    if(T < t) {
      putchar('\n');
    }
  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



