#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
inline unsigned RD() {
  unsigned TmpRD(0);
  char RChr(getchar());
  while ((RChr < '0') || (RChr > '9')) RChr = getchar();
  while ((RChr >= '0') && (RChr <= '9'))
    TmpRD = (TmpRD << 3) + (TmpRD << 1) + RChr - '0', RChr = getchar();
  return TmpRD;
}
inline int RDsg() {
  int TmpRD(0), TmpSg(1);
  char RChr(getchar());
  while (((RChr < '0') || (RChr > '9')) && (RChr ^ '-')) RChr = getchar();
  if (RChr == '-') TmpSg = -1, RChr = getchar();
  while ((RChr >= '0') && (RChr <= '9'))
    TmpRD = (TmpRD << 3) + (TmpRD << 1) + RChr - '0', RChr = getchar();
  return TmpRD * TmpSg;
}
unsigned n, m;
unsigned Ans[10000005], Cnt(0);
bitset<10000005> No, NO;
signed main() {
  for (unsigned i(7); i <= 10000000; i += 10) No[i] = 1;
  for (unsigned i(70); i <= 10000000; i += 100)
    for (unsigned j(0); j < 10; ++j) No[i + j] = 1;
  for (unsigned i(700); i <= 10000000; i += 1000)
    for (unsigned j(0); j < 100; ++j) No[i + j] = 1;
  for (unsigned i(7000); i <= 10000000; i += 10000)
    for (unsigned j(0); j < 1000; ++j) No[i + j] = 1;
  for (unsigned i(70000); i <= 10000000; i += 100000)
    for (unsigned j(0); j < 10000; ++j) No[i + j] = 1;
  for (unsigned i(700000); i <= 10000000; i += 1000000)
    for (unsigned j(0); j < 100000; ++j) No[i + j] = 1;
  for (unsigned i(7000000); i < 8000000; ++i) No[i] = 1;
  NO = No;
  for (unsigned i(7); i <= 5000000; ++i)
    if (No[i]) {
      for (unsigned j(i << 1); j <= 10000000; j += i)
        No[j] = 0, NO[j] = (NO[j] | No[i]);
    }
  for (unsigned i(10000000), j(10000001); i; --i) {
    Ans[i] = j;
    if (!NO[i]) j = i;
  }
  m = RD();
  for (unsigned T(1); T <= m; ++T) {
    n = RD();
    if (NO[n]) {
      printf("-1\n");
      continue;
    }
    printf("%u\n", Ans[n]);
  }
  return 0;
}
/*
1
515
*/