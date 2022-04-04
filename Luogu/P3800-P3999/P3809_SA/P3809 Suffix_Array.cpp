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
unsigned m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0), Bucket[1000005], sumBucket[1000005], Tmpch[64], a[1000005], b[1000005];
char Inch[1000005];
struct Suffix {
  unsigned RK, SubRK;
}S[1000005], Stmp[1000005];
void RadixSort () {
  unsigned MX(0);                                     // 记录最大键值 
  for (register unsigned i(1); i <= n; ++i) {
    ++Bucket[S[i].SubRK];                             // 第二关键字入桶
    MX = max(S[i].SubRK, MX);
  }
  sumBucket[0] = 0;
  for (register unsigned i(1); i <= MX; ++i) {        // 求前缀和以确定在排序后的序列中的位置
    sumBucket[i] = sumBucket[i - 1] + Bucket[i - 1];  // 求桶前缀和, 前缀和右边界是开区间, 所以计算的是比这个键值小的所有元素个数 
    Bucket[i - 1] = 0;                                // 清空桶 
  }
  Bucket[MX] = 0;
  for (register unsigned i(1); i <= n; ++i) {         // 排好的下标存到 b 中, 即 b[i] 为第 i 小的后缀编号 
    b[++sumBucket[S[i].SubRK]] = i;                   // 前缀和自增是因为 
  }
  b[0] = 0;                                           // 边界 (第 0 小的不存在) 
  for (register unsigned i(1); i <= n; ++i) {
    a[i] = b[i];
  }
  MX = 0; 
  for (register unsigned i(1); i <= n; ++i) {
    ++Bucket[S[i].RK];                                // 第一关键字入桶
    MX = max(S[i].RK, MX);
  }
  sumBucket[0] = 0;
  for (register unsigned i(1); i <= MX; ++i) {
    sumBucket[i] = sumBucket[i - 1] + Bucket[i - 1];
    Bucket[i - 1] = 0;
  }
  Bucket[MX] = 0;
  for (register unsigned i(1); i <= n; ++i) {
    b[++sumBucket[S[a[i]].RK]] = a[i];                // 由于 a[i] 是 b[i] 的拷贝, 表示第 i 小的后缀编号, 所以枚举 i 一定是从最小的后缀开始填入新意义下的 b 
  }
  b[0] = 0;
  Cnt = 0;                                            // 使 RK 不那么分散 
  for (register unsigned i(1); i <= n; ++i) {
    if(S[b[i]].SubRK != S[b[i - 1]].SubRK || S[b[i]].RK != S[b[i - 1]].RK) {
      a[b[i]] = ++Cnt;                                // 第 i 小的后缀和第 i - 1 小的后缀不等排名不等 
    }
    else {
      a[b[i]] = Cnt;                                  // 第 i 小的后缀和第 i - 1 小的后缀相等排名也相等 
    }
  }
  for (register unsigned i(1); i <= n; ++i) {
    S[i].RK = a[i];                                   // 将 a 中暂存的新次序拷贝回来 
  }
  return;
}
int main() {
  // double Ti(clock()), Mti(0);
//   freopen("P3809_2.in", "r", stdin);
//   freopen("P3809.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  cin.getline(Inch, 1000001);
  n = strlen(Inch);
  for (register unsigned i(0); i < n; ++i) {
    if(Inch[i] <= '9' && Inch[i] >= '0') {
      Inch[i] -= 47;
      continue;
    }
    if(Inch[i] <= 'Z' && Inch[i] >= 'A') {
      Inch[i] -= 53;
      continue;
    }
    if(Inch[i] <= 'z' && Inch[i] >= 'a') {
      Inch[i] -= 59;
      continue;
    }
  }
  for (register unsigned i(0); i < n; ++i) {
    Bucket[Inch[i]] = 1;
  }
  for (register unsigned i(0); i < 64; ++i) {
    if(Bucket[i]) {
      Tmpch[i] = ++Cnt;                               // 让桶从 1 开始, 空出 0 的位置
      Bucket[i] = 0;
    }
  }
  for (register unsigned i(0); i < n; ++i) {          // 将字符串离散化成整数序列
      S[i + 1].RK = Tmpch[Inch[i]];                   // 字符串读入是 [0, n) 的, 题意中字符串是 (0, n] 的 
  }
  for (register unsigned i(1); i <= n; i <<= 1) {     // 当前按前 i 个字符排完了, 每次 i 倍增
    for (register unsigned j(1); j + i <= n; ++j) {   // 针对第二关键字不为 0 的 
      S[j].SubRK = S[j + i].RK;
    }
    for (register unsigned j(n - i + 1); j <= n; ++j) {  
      S[j].SubRK = 0;                                 // 第二关键字为 0 
    }
    RadixSort();
  }
  for (register unsigned i(1); i <= n; ++i) {
    b[S[i].RK] = i;
  }
  for (register unsigned i(1); i <= n; ++i) {
    printf("%u ", b[i]);
  }
//  printf("%s\n", a);
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



