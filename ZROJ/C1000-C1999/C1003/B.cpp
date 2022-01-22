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
inline unsigned long long RD() {
  unsigned long long intmp(0);
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
const unsigned P(4), PP(16);
unsigned a[1005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char Edge;
struct Node {
  vector<Node*> E;
  unsigned long long Val;
  unsigned Dep;
}N[1005];
signed main() {
//  freopen("B.in", "r", stdin);
//  freopen("B.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) N[i].Val = RD();
  for (unsigned i(1); i < n; ++i)
    for (unsigned j(i + 1); j <= n; ++j) {
      if(!(N[j].Val % N[i].Val)) N[i].E.push_back(N + j);
    }
  for (unsigned i(1); i <= n; ++i)
    for (auto j:N[i].E) j->Dep = max(N[i].Dep + 1, j->Dep);
  for (unsigned i(2); i <= n; ++i) {
    for (unsigned j(1); j < i; ++j) {
      Edge = 0;
      if((N[i].Dep / PP) ^ (N[j].Dep / PP)) Edge = 3;
      else if((N[i].Dep / P) ^ (N[j].Dep / P)) Edge = 2;
      printf("%u ", Edge ? Edge : 1);
    }
    putchar(0x0A);
  }
//  }
  return Wild_Donkey;
}
/*
63
1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288 1048576 2097152 4194304 8388608 16777216 33554432 67108864 134217728 268435456 536870912 1073741824 2147483648 4294967296 8589934592 17179869184 34359738368 68719476736 137438953472 274877906944 549755813888 1099511627776 2199023255552 4398046511104 8796093022208 17592186044416 35184372088832 70368744177664 140737488355328 281474976710656 562949953421312 1125899906842624 2251799813685248 4503599627370496 9007199254740992 18014398509481984 36028797018963968 72057594037927936 144115188075855872 288230376151711744 576460752303423488 1152921504606846976 2305843009213693952 4611686018427387904
*/
