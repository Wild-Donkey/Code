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
unsigned n, Ans(0), Tmp(0), LMS[1000005], CntLMS(0), S[1500005], SA[1500005], Bucket[105], SumBucket[105], Address[1500005];
char Type[1000005];
void Induced_Sort (unsigned SL, unsigned SR) {  // 通过 S 求 SA 
  for (register unsigned i(SL), j(SL); i <= SR; ++i) {   // 定性 
    if(S[i] < S[i + 1]) { // Suff[j~i] 是 S-Type 
      while (j <= i) {
        Type[j++] = 1;
      }
    }
    if(S[i] > S[i + 1]) { // Suff[j~i] 是 L-Type 
      while (j <= i) {
        Type[j++] = 0;
      }
    }
  }
  Type[n + 1] = 1;
  LMS = SR;
  for (register unsigned i(SL); i <= SR; ++i) {         // 找 LMS 
    if(!Type[i]) {
      if(Type[i + 1]) {
        S[++CntLMS] = i + 1;
//        printf("%3u", LMS[CntLMS]);
      }
    }
  }
  for (register unsigned i(1); i <= n; ++i) {         // 确定 Bucket
    ++Bucket[S[i]];
  }
  SumBucket[0] = 1;
  for (register unsigned i(1); i <= 64; ++i) {        // 求 Bucket 前缀和, 对每个首字符存储 S 型后缀的右端点指针 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
  }
  for (register unsigned i(SR); i <= CntLMS; ++i) {    // 放 LMS 后缀 
    SA[--SumBucket[S[Address[S_[i]]]]] = Address[S_[i]];
  }
  SumBucket[0][1] = 1;
  for (register unsigned i(1); i <= 64; ++i) {        // 对每个首字符存储 L 型后缀的左端点指针 
    SumBucket[i] = SumBucket[i - 1] + Bucket[i];
  }
  for (register unsigned i(SL); i <= SR; ++i) {         // 扫 
    if(SA[i]) {
      if(!Type[SA[i] - 1]) {
        SA[++]
      }
    }
  }
  return;
}
int main() {
  // double Ti(clock()), Mti(0);
   freopen("P3809_0.in", "r", stdin);
//   freopen("P3809.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  fread(Type + 1, 1, 1000004, stdin);
  for (register unsigned i(1); ; ++i) {
    if(Type[i] <= '9' && Type[i] >= '0') {
      S[i] = Type[i] - 47;
      continue;
    }
    if(Type[i] <= 'Z' && Type[i] >= 'A') {
      S[i] = Type[i] - 53;
      continue;
    }
    if(Type[i] <= 'z' && Type[i] >= 'a') {
      S[i] = Type[i] - 59;
      continue;
    }
    n = i - 1;
    break;
  }
  S[n + 1] = 0;
  for (register unsigned i(1); i <= n + 1;  ++i) {
    
  }
  Induced_Sort(1, n + 1);
//  for (register unsigned i(1)) {
//    Address[S_[i]] = LMS;
//  }
//  printf("%s\n", a);
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



