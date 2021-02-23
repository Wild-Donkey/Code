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
inline unsigned int RD() {
  char ich(getchar());
  unsigned int intmp(0);
  while ((ich < '0') || (ich > '9')) {
    ich = getchar();
  }
  while ((ich <= '9') && (ich >= '0')) {
    intmp *= 10;
    intmp += ich - '0';
    ich = getchar();
  }
  //  printf("RD %d\n", intmp);
  return intmp;
}
unsigned int m, n, a[40005], b[40005], Ar[40005], Cnta(0), L, R, Lr, Rr,
    Lst(0), Rg, NmR, Tmp(0), Tmpp[40005];
unsigned int f[205][205], Ap[205][40005];
int main() {
  n = RD();
  m = RD();
  memset(Ap, 0, sizeof(Ap));
  Rg = max(int(sqrt(n)), 1);  //确定Rg
  NmR = (n + Rg - 1) / Rg;    //推得NmR
  for (register int i(1); i <= n; ++i) {
    a[i] = RD();
    b[i] = a[i];  //创建 a[]副本
  }
  sort(b + 1, b + n + 1);
  for (register int i(1); i <= n; ++i) {
    if (b[i] != b[i - 1]) {
      Ar[++Cnta] = b[i];  // Ar 存严格次序中第 k 小的数
    }
  }
  for (register int i(1); i <= n; ++i) {  //离散化
    a[i] = lower_bound(Ar + 1, Ar + Cnta + 1, a[i]) -
           Ar;  //将每个a[i]变成小于等于n的数
  }
  for (register int i(1); i < NmR; ++i) {  //处理Ap[][]
    for (register int j(Rg * (i - 1) + 1); j <= Rg * i; ++j) {
      ++Ap[i][a[j]];
    }
    for (register int j(1); j <= Cnta; ++j) {  //继承给下一块
      Ap[i + 1][j] = Ap[i][j];
    }
  }
  //最后一行
  for (register int i(Rg * (NmR - 1) + 1); i <= n; ++i) {  //最后一行特殊处理
    ++Ap[NmR][a[i]];
  }
  for (register int i(1); i < NmR; ++i) {  //处理长度为 1 块的区间的 f[][]
    Tmp = 0;
    for (register int j(Rg * (i - 1) + 1); j <= Rg * i;
         ++j) {  //枚举每一个出现过的数字
      if (Ap[i][Tmp] - Ap[i - 1][Tmp] <= Ap[i][a[j]] - Ap[i - 1][a[j]]) {
        if (Ap[i][Tmp] - Ap[i - 1][Tmp] == Ap[i][a[j]] - Ap[i - 1][a[j]]) {
          if (Tmp > a[j]) {
            Tmp = a[j];
          }
        } else {
          Tmp = a[j];
        }
      }
    }
    f[i][i] = Tmp;
  }
  Tmp = 0;
  for (register int i(Rg * (NmR - 1) + 1); i <= n; ++i) {  //最后一行特殊处理
    if (Ap[NmR][Tmp] - Ap[NmR - 1][Tmp] <= Ap[NmR][a[i]] - Ap[NmR - 1][a[i]]) {
      if (Ap[NmR][Tmp] - Ap[NmR - 1][Tmp] ==
          Ap[NmR][a[i]] - Ap[NmR - 1][a[i]]) {
        if (Tmp > a[i]) {
          Tmp = a[i];
        }
      } else {
        Tmp = a[i];
      }
    }
    f[NmR][NmR] = Tmp;
  }
  for (register int i(1); i <= NmR; ++i) {
    for (register int j(i + 1); j <= NmR; ++j) {  //处理全部f[][]
      if (f[i][j - 1] == f[j][j]) {               //共同众数无需处理
        f[i][j] = f[j][j];
      } else {
        Tmp = f[i][j - 1];
        for (register int k(Rg * (j - 1) + 1); k <= min(Rg * j, n);
             ++k) {  //枚举出现过的数字
          if (Ap[j][Tmp] - Ap[i - 1][Tmp] <= Ap[j][a[k]] - Ap[i - 1][a[k]]) {
            if (Ap[j][Tmp] - Ap[i - 1][Tmp] == Ap[j][a[k]] - Ap[i - 1][a[k]]) {
              if (Tmp > a[k]) {  //数字小的优先
                Tmp = a[k];
              }
            } else {
              Tmp = a[k];  //更新众数
            }
          }
        }
        f[i][j] = Tmp;  //众数以确定
      }
    }
  }
  for (register int i(1); i <= m; ++i) {  //处理询问
    L = (RD() + Lst - 1) % n + 1;
    R = (RD() + Lst - 1) % n + 1;  //区间生成(强制在线)
    if (L > R) {                   //判左大右小
      swap(L, R);
    }
    Lr = (L + Rg - 1) / Rg + 1;
    Rr = R / Rg;    //处理包含的最左块和最右块
    if (Lr > Rr) {  //整块不存在
      for (register int j(L); j <= R; ++j) {  //直接朴素
        Tmpp[a[j]] = 0;                       //清空计数器(下同)
      }
      for (register int j(L); j <= R; ++j) {
        ++Tmpp[a[j]];
      }
      Tmp = 0;
      for (register int j(L); j <= R; ++j) {
        if (Tmpp[Tmp] <= Tmpp[a[j]]) {
          if (Tmpp[Tmp] == Tmpp[a[j]]) {
            if (Tmp > a[j]) {
              Tmp = a[j];
            }
          } else {
            Tmp = a[j];
          }
        }
      }
      Lst = Tmp;
    } else {            //有整块
      Tmp = f[Lr][Rr];  //先和判整块众数出现次数比较
      Tmpp[Tmp] = 0;    //别忘了这里
      for (register int j(L); j <= Rg * (Lr - 1); ++j) {  //掐头
        Tmpp[a[j]] = 0;
      }
      for (register int j(Rg * Rr + 1); j <= R; ++j) {  //去尾
        Tmpp[a[j]] = 0;
      }
      for (register int j(L); j <= Rg * (Lr - 1); ++j) {
        ++Tmpp[a[j]];
      }
      for (register int j(Rg * Rr + 1); j <= R; ++j) {
        ++Tmpp[a[j]];
      }
      for (register int j(L); j <= Rg * (Lr - 1); ++j) {  //开始迭代
        if (Tmpp[Tmp] + Ap[Rr][Tmp] - Ap[Lr - 1][Tmp] <=
            Tmpp[a[j]] + Ap[Rr][a[j]] -
                Ap[Lr - 1][a[j]]) {  //当前数字出现次数和当前已知众数出现次数
          if (Tmpp[Tmp] + Ap[Rr][Tmp] - Ap[Lr - 1][Tmp] ==
              Tmpp[a[j]] + Ap[Rr][a[j]] - Ap[Lr - 1][a[j]]) {
            if (Tmp > a[j]) {
              Tmp = a[j];
            }
          } else {
            Tmp = a[j];
          }
        }
      }
      for (register int j(Rg * Rr + 1); j <= R; ++j) {  //尾操作同头
        if (Tmpp[Tmp] + Ap[Rr][Tmp] - Ap[Lr - 1][Tmp] <=
            Tmpp[a[j]] + Ap[Rr][a[j]] - Ap[Lr - 1][a[j]]) {
          if (Tmpp[Tmp] + Ap[Rr][Tmp] - Ap[Lr - 1][Tmp] ==
              Tmpp[a[j]] + Ap[Rr][a[j]] - Ap[Lr - 1][a[j]]) {
            if (Tmp > a[j]) {
              Tmp = a[j];
            }
          } else {
            Tmp = a[j];
          }
        }
      }
      Lst = Tmp;
    }
    Lst = Ar[Lst];  //离散化后的值转化为原始值
    printf("%d\n", Lst);
  }
  return 0;
}