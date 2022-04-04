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
#include <set>
#include <string>
#include <unordered_map>
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
unsigned Li[2000005], a[1000005], b[1000005], At[2000005], Suf[1000005], Pre[1000005], m, n;
unsigned A, B, C, D, t, K, End, Emp;
unsigned Cnt(0), Ans(0x3f3f3f3f), Tmp(0), Top(0x3f3f3f3f);
//  inline void Clr() {}
signed main() {
  freopen("P7514_2.in", "r", stdin);
//  freopen("P7514.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  m = ((n = RD()) << 1), Emp = K = RD();
  for (unsigned i(1); i <= n; ++i) Li[i] = a[i] = RD();
  for (unsigned i(1); i <= n; ++i) Li[i + n] = b[i] = RD();
  sort(Li + 1, Li + m + 1);
  for (unsigned i(1); i <= n; ++i) a[i] = lower_bound(Li + 1, Li + m + 1, a[i]) - Li;
  for (unsigned i(1); i <= n; ++i) b[i] = lower_bound(Li + 1, Li + m + 1, b[i]) - Li;
  for (unsigned i(1); i <= n; ++i) Top = min(Top, max(a[i], b[i]));
  for (unsigned i(1); i <= n; ++i) At[a[i]] = At[b[i]] = i;
  for (unsigned i(1); i <= n; ++i) Pre[i] = max(Pre[i - 1], a[i]);
  for (unsigned i(n); i; --i) Suf[i] = max(Suf[i + 1], min(a[i], b[i]));
  for (unsigned i(n), j(K); i; --i) {
    if(j) End = i; 
    if((a[i] > b[i]) && j) --j, --Emp, Tmp = max(b[i], Tmp);
    else Tmp = max(a[i], Tmp);
  }
  Ans = Li[max(Pre[End - 1], Suf[End])] - Li[1];
//  printf("End %u Have %u, %u - %u\n", End, Emp, Li[max(Pre[End - 1], Suf[End])], Li[1]);
  for (unsigned i(1); i < Top; ++i) {
    unsigned Pos(At[i]);
//    printf("%u Pos %u\n", i, Pos);
    if(a[Pos] == i) {
      Tmp = max(Tmp, b[Pos]);
      if(Pos < End) {
        while ((!Emp) && (End <= n)) {if(a[End] > b[End]) ++Emp; ++End;}
        --Emp;
      }
    }
    else {
      Tmp = max(Tmp, a[Pos]);
      while (End <= Pos) {if(a[End] > b[End]) ++Emp; ++End;}
    }
    Ans = min(Ans, Li[max(Tmp, max(Pre[End - 1], Suf[End]))] - Li[i + 1]);
//    printf("End %u Have %u, %u - %u\n", End, Emp, Li[max(Tmp, max(Pre[End - 1], Suf[End]))], Li[i + 1]); 
  }
  printf("%u\n", Ans);
//  }
  return Wild_Donkey;
}

