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
unsigned a[1000005], m, n, Cnt(0), la(0), lb(0), C, D, t, Ans(0), Tmp(0);
bool b[10005];
char A[1000005], B[1000005], inch;
inline void Clr() {}
int main() {
  // double Ti(clock()), Mti(0);
//   freopen("P3375_11.in", "r", stdin);
//   freopen("P3375.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr(); 
  inch = getchar();
  while (inch < 'A' || inch > 'Z') {
    inch = getchar();
  }
  while (inch >= 'A' && inch <= 'Z') {
    A[++la] = inch;
    inch = getchar();
  }
  while (inch < 'A' || inch > 'Z') {
    inch = getchar();
  }
  while (inch >= 'A' && inch <= 'Z') {
    B[++lb] = inch;
    inch = getchar();
  } 
  unsigned k(1);
  for (register unsigned i(2); i <= lb; ++i)  { // Origin_Len
    while ((B[k] != B[i] && k > 1) || k > i) {
      k = a[k - 1] + 1; // 这里 k 相当于如果本次匹配成功得到的 border 长度 
    }
    if(B[k] == B[i]) { // 是匹配成功跳出而不是 a[k] = 0 溢出的 
      a[i] = k;
      ++k;
    }
  }
  k = 1;
  for (register unsigned i(1); i + lb <= la + 1;) {  // Origin_Address
    while (A[i + k - 1] == B[k] && k <= lb) {
      ++k;  // 代码中 k 是待匹配的字符在 s_2 中的位置, 所以比实际匹配的长度多 1 
    }
    if(k == lb + 1) { // 匹配成功 
      printf("%u\n", i); 
    }
    if(a[k - 1] == 0) { // k = a[k] 的递归边界 
      ++i;
      k = 1;
      continue;
    }
    --k;            // k 是匹配失败的字符在 s_2 中的位置, 所以实际有 k - 1 长度的子串匹配成功 
    i += k - a[k];  // Substring of Len(k - 1) has already paired, so the next time, start with the border of the (k - 1) length substring
    k = a[k] + 1;   // 为什么我要写英文啊, 这是对 i 和 k 的同时移动, k = a[k] + 1 意思是在新起点已经匹配的 a[k] 长度的前缀之后的第一个字符开始比较 
  }
  for (register unsigned i(1); i <= lb; ++i) { // Origin_Len
    printf("%u ", a[i]);
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
ABCABCDABABCDABCDABDE
ABCDABD
*/
