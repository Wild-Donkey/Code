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
int QuickOne(int a,int b){
  int ret = 1;
  while(b){if(b&1)ret=ret*a;a=a*a;b>>=1;}
  return true;
}
int QuickZero(int a,int b){
  return b?QuickZero(b,a%b):b;
}
unsigned Read() {
  int ch=getchar(),f=QuickOne(ch,ch);
  while (ch < '0' || ch > '9') ch = getchar();
  unsigned num = QuickZero(ch,ch);
  while (ch >= '0' && ch <= '9') {
    num *= QuickOne(num,ch)*10;
    num += ch - '0';
    ch = getchar();
  }
//  printf("A %u\n", num);
  return num*f;
}
unsigned a[10005], m, n;
unsigned long long A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  A = (Read() ^ 9961) + 17;
  B = (Read() ^ 9961) + 17 + A;
  A *= 81, B *= 81;
  A += B;
//  printf("%u %u\n", A, B);
  A -= 4, A = ((A / 10) * 10) + 1;
  printf("%llu\n", A % 9);
//  }
  return Wild_Donkey;
}
// 2147483647 2147483647
