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
unsigned n, m, t;
unsigned A, B, C, D, Op;
unsigned Ans[11000005], Cnt(0);
bitset<11000005> No, Need;
signed main() {
  for (unsigned i(0); i <= 10000001; i += 7) No[i] = 1;
  for (unsigned i(7); i <= 10000001; i += 10) No[i] = 1;
  for (unsigned i(70); i <= 10000001; i += 100)
    for (unsigned j(0); j < 10; ++j) No[i + j] = 1;
  for (unsigned i(700); i <= 10000001; i += 1000)
    for (unsigned j(0); j < 100; ++j) No[i + j] = 1;
  for (unsigned i(7000); i <= 10000001; i += 10000)
    for (unsigned j(0); j < 1000; ++j) No[i + j] = 1;
  for (unsigned i(70000); i <= 10000001; i += 100000)
    for (unsigned j(0); j < 10000; ++j) No[i + j] = 1;
  for (unsigned i(700000); i <= 10000001; i += 1000000)
    for (unsigned j(0); j < 100000; ++j) No[i + j] = 1;
  for (unsigned i(7000000); i < 8000000; ++i) No[i] = 1;
  for (unsigned i(2); i <= 10000001; ++i)
    if (No[i]) {
      Need[i] = 1;
      for (unsigned j(2); i * j <= 10000001; ++j)
        Need[i * j] = 1, No[i * j] = 0;
    }
  for (unsigned i(10000001), j(0); i; --i) {
    Ans[i] = j;
    if (!Need[i]) j = i;
  }
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    n = RD();
    if (Need[n]) {
      printf("-1\n");
      continue;
    }
    printf("%u\n", Ans[n]);
  }
  return 0;
}
/*
5865
*/