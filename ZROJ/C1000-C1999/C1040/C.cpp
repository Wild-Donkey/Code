#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#define Wild_Donkey 0
#define INFi 0x3f3f3f3f3f3f3f3f
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
unsigned a[3000005], List[2005], m, n, Mx;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
char Flg(0);
inline void Clr() {
  Cnt = 0, Flg = 0, n = RD(), Mx = sqrt(m = RD());
}
signed main() {
//  freopen("C.in", "r", stdin);
//  freopen("C.out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(1); i <= Mx; ++i) if(!(m % i))
      List[++Cnt] = i, List[++Cnt] = m / i;
    sort(List + 1, List + Cnt + 1);
    Cnt = unique(List + 1, List + Cnt + 1) - List - 1;
    List[Cnt + 1] = 0x3f3f3f3f;
//    for (unsigned i(1); i <= Cnt; ++i) printf("List %u = %u\n", i, List[i]);
    for (unsigned i(1), M, j, k; i <= Cnt; ++i) {
      a[n] = List[i] + n - 1, M = m / List[i];
      for (j = n - 1, k = i; j; --j) {
        ++k; while ((M % List[k]) || (List[k] + j > a[j + 1] + 1)) --k;
        a[j] = List[k] + j - 1, M /= List[k];
//        printf("M %u List k %u = %u\n", M, k, List[k]);
        if (M == 1) {--j; break;}
      }
//      printf("Tail %u, Lef %u\n", a[n], M);
      if(M > 1) continue;
      for (; j; --j) a[j] = j;
      break;
    }
    for (unsigned i(1); i < n; ++i) printf("%u ", a[i]);
    printf("%u\n", a[n]);
  }
  //  system("pause");
  return Wild_Donkey;
}
/*
1
2 12
*/
