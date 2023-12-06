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
#define foreplay for
#define wild while
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
inline unsigned char gHEX(char x) {
  if (x <= '9' && x >= '0') return x - '0';
  return 10 + x - 'a';
}
inline char bHEX(unsigned char x) {
  if (x < 10) return '0' + x;
  return 'a' + x - 10;
}
inline void Prt(unsigned char x) {
  putchar(bHEX(x >> 4)), putchar(bHEX(x & 15));
}
unsigned char OriData[2097152], RelData[2097152], *DataDom(OriData - 1),
    *Head(RelData);
unsigned m, n;
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = 0;
  for (unsigned i(0); i < n; i += 8) {
    char ITmp[17];
    scanf("%s", ITmp);
    for (unsigned j(0); j < 8 && i + j < n; ++j)
      OriData[i + j] = ((gHEX(ITmp[j << 1]) << 4) | gHEX(ITmp[(j << 1) ^ 1]));
  }
  unsigned TShi(0);
  do {
    ++DataDom, m |= (((*DataDom) & 127) << (TShi * 7)), ++TShi;
  } while ((*(DataDom)) & 128);
  n -= (++DataDom) - OriData;
  // printf("New %u m %u\n", n, m);
  for (unsigned i(0); i < n;) {
    // Prt(DataDom[i]), putchar(0x0A);
    if (!(DataDom[i] & 3)) {
      unsigned j(0);
      DataDom[i] >>= 2;
      if (DataDom[i] < 60)
        j = DataDom[i] + 1, ++i;
      else {
        // printf("Type 2\n");
        for (unsigned k(DataDom[i] - 60); ~k; --k)
          j = ((j << 8) | DataDom[i + k + 1]);
        i += DataDom[i] - 58, ++j;
      }
      // printf("Raw %u\n", j);
      memcpy(Head, DataDom + i, j), i += j, Head += j;
      continue;
    }
    unsigned l(0), o(0);
    if (DataDom[i] & 1) {
      l = ((DataDom[i] >> 2) & 7) + 4;
      o = (((DataDom[i] & 224) << 3) | DataDom[i + 1]);
      i += 2;
    } else {
      l = (DataDom[i] >> 2) + 1;
      o = ((DataDom[i + 2] << 8) | DataDom[i + 1]);
      i += 3;
    }
    // printf("Roll %u %u\n", o, l);
    unsigned char *Back(Head - o);
    unsigned Tms(l / o);
    for (unsigned j(0); j < Tms; ++j) memcpy(Head, Back, o), Head += o;
    Tms = l % o;
    memcpy(Head, Back, Tms), Head += Tms;
  }
  for (unsigned i(0); i < m; i += 8) {
    for (unsigned j(0); j < 8 && i + j < m; ++j) Prt(RelData[i + j]);
    putchar(0x0A);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}