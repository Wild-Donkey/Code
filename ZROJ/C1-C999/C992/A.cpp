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
inline int RD() {
  int intmp(0);
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
int m, n, Sum;
int A, B, C, D, t;
int Cnt(0), Ans(0), Tmp(0);
char a[100005];
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (int T(1); T <= t; ++T){
//  Clr();
  fread(a + 1, 1, 100002, stdin);
  while (a[n + 1] >= '0') ++n;
  sort(a + 1, a + n + 1, greater<char>());
  for (int i(1); i <= n; ++i) Sum += a[i] - '0';
  if(Sum % 3) {printf("-1\n");return 0;}
  if(a[n] != '0') {printf("-1\n");return 0;}
  for (int i(1); i <= n; ++i) putchar(a[i]);
//  }
//  system(\"pause\");
  return Wild_Donkey;
}

