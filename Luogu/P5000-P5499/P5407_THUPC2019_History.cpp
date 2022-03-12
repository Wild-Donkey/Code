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
const unsigned Ans[120] = {11, 10, 9, 14, 13, 12, 11, 9, 8, 14, 13, 11, 10, 9, 8, 13, 12, 11, 10, 8, 14, 13, 12, 10, 9, 8, 14, 12, 11, 10, 9, 14, 13, 12, 11, 9, 8, 14, 13, 11, 10, 9, 8, 13, 12, 11, 10, 8, 14, 13, 12, 10, 9, 8, 14, 12, 11, 10, 9, 14, 13, 12, 11, 9, 8, 14, 13, 11, 10, 9, 8, 13, 12, 11, 10, 8, 14, 13, 12, 10, 9, 8, 14, 12, 11, 10, 9, 14, 13, 12, 11, 9, 8, 14, 13, 11, 10, 9, 8, 13, 12, 11, 10, 8, 14, 13, 12};
const unsigned Mth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const unsigned BC(2305448), year4(1461), year100(36524), year400(146097), May8_2019(2458612);
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
unsigned Q, R, tmpy4, tmpy, tmpy100, tmpy400;
inline void Gtmd (int x) {
  for (register int i(1); i <= 12; ++i){
    if(x <= Mth[i]){A = x, B = i; return;}
    x -= Mth[i];
  }
}
inline void Qry(unsigned R) {
  ++R, R -= BC, C = 1600;
  tmpy400 = (R - 1) / year400, R -= tmpy400 * year400, tmpy100 = (R - 2) / year100, R -= tmpy100 * year100;
  if(tmpy100)R--;
  tmpy4 = R / year4,R -= tmpy4 * year4;
  if (tmpy4 && tmpy100)R++;
  tmpy = (R - 2) / 365,R -= tmpy * 365;
  if((tmpy) && (tmpy100) && (!tmpy4))R++;
  if((tmpy100) && (!tmpy4) && (!tmpy))R++;
  C += tmpy + 4 * tmpy4 + 100 * tmpy100 + 400 * tmpy400;
  if(R == 0){--C, A = 12, B = 31; return;}
  if (tmpy100 == 0 && tmpy4 == 0 && tmpy == 0) {
    if(R < 60)Gtmd(R);
    if (R == 60)A = 29, B = 2;
    if(R > 60){if(R == 1){--C,A = 31, B = 12; return;}Gtmd(R - 1);}
    return;
  }
  if(tmpy4 == 0 && tmpy == 0) {R--;if(R == 366){A = B = 1, ++C;return;}Gtmd(R);return;}
  if(tmpy == 0) {
    if (R < 60)Gtmd(R);
    if (R == 60)A = 29, B = 2;
    if(R > 60) {if(R == 1) {--C,A = 31, B = 12;return;} Gtmd(R - 1); }
    return;
  }
  R--;
  if(R == 366){A = B = 1, ++C;return;}
  Gtmd(R);
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
//  n = RD();
//  printf("BC %u\n", BC);
  printf("%u\n", Ans[RD() - 1913]);
//  }
//  system("pause");
  return Wild_Donkey;
}

