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
/*
And the game was over and the player woke up
And the player began a new dream
And the player dreamed again, dreamed better
And the player was the universe
And the player was love
*/
using namespace std;
int n, m, ans(0), bi;
/*int f_old[1005][205][205]; S2前k位中选i段,匹配S1中前j位,
 * S2第k位不选(0)或被选入(1)*/
int f[205][205];   // S1 当前位选 j 段, 匹配 S2 前 i 位
int Su[205][205];  // Su[l][k] = sum(f_old[i - l][j - l][k])
bool flg;
string stmp1, stmp2;
char S1[1005], S2[205];
const int Mod = 1000000007;
inline int In() {
  char ich = getchar();
  int intmp = 0, insign = 1;
  while (((ich < '0') || (ich > '9')) && ((ich != '-'))) {
    ich = getchar();
  }
  if (ich == '-') {
    insign = -1;
    ich = getchar();
  }
  while ((ich <= '9') && (ich >= '0')) {
    intmp *= 10;
    intmp += ich - '0';
    ich = getchar();
  }
  return intmp * insign;
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  n = In();
  m = In();
  bi = In();
  cin >> stmp1;
  for (register int i(0); i < n; ++i) {
    S1[i + 1] = stmp1[i];
  }
  cin >> stmp2;
  for (register int i(0); i < m; ++i) {
    S2[i + 1] = stmp2[i];
  }
  memset(f, 0, sizeof(f));
  memset(Su, 0, sizeof(Su));
  /*for (register int i(1); i <= n; ++i) {
    cout << S1[i];
  }
  printf("\n");
  for (register int i(1); i <= m; ++i) {
    cout << S2[i];
  }
  printf("\n");*/
  f[0][0] = 1;
  /*while ()  {
    Su[1][1] = 1;
  }*/
  /*for (register int i(1); i <= n; ++i) {            // S1 的前 i 位
    for (register int j(1); j <= min(i, m); ++j) {  //凑出 S2 串的前 j 位
      for (register int k(1); k <= bi; ++k) {       //分了 k 段
        f[i][j][k] = f[i - 1][j][k];                //不选 S1[i]
        register int l(1);
        while ((i - l + 1 > 0) &&
               (j - l + 1 > 0)) {                // S1[i - l, i] 构成第 k 段
          if (S1[i - l + 1] != S2[j - l + 1]) {  //保证末 l 位相同
            break;
          }
          f[i][j][k] += f[i - l][j - l][k - 1] 末 l 位做第 k 段;
          f[i][j][k] %= Mod;
          // printf("j=%d k=%d f=%d\n", i, j, k, f[1][j][k]);
          ++l;
        }
      }
    }
  }*/
  for (register int i(1); i <= n; ++i) {  // S1 的前 i 位
    for (register int j(min(i, m)); j >= 1;
         --j) {  //凑出 S2 串的前 j 位 (为了保证处理 Su 时用到的 Su 和 f 是 i =
                 // i - 1 时的值, 倒着枚举)
      for (register int k(bi); k >= 1; --k) {  //分了 k 段 (倒着枚举原因同上)
        register int l(0);
        Su[j][k] = (Su[j - 1][k] /*上一轮(i = i - 1)时的Su[j - 1][k]*/ +
                    f[j - 1][k - 1] /*上一轮的 f[j - 1][k - 1]*/) %
                   Mod;
        // while (l < min(i, j)) {          // S1[i - l, i] 构成第 k 段
        if (S1[i] != S2[j]) {  //保证末 l 位相同
          Su[j][k] = 0; /*本轮的 Su[j - l][k] 失效 即 f_old[i - l - 1][j
                       - l - 1][k - 1] +...+ f_old[i - min(i,j)][j
                       - min(i,j)][k - 1]*/
          //  break;
        }
        // Su[j][k] += f[j - l][k - 1];
        // ++l;
        // }
        f[j][k] += Su[j][k];  ///末 l 位分别做第 k 段;
        f[j][k] %= Mod;
        // printf("j=%d k=%d f=%d  ", j, k, f[j][k]);
      }
    }
    // printf("\n");
  }
  printf("%d\n", f[m][bi]);
  // fclose(stdin);
  // fclose(stdout);
  system("pause");
  return 0;
}