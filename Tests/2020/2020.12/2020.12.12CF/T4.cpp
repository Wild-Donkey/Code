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
using namespace std;
inline int RD() {
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
int n, m, k, t, cnt1, cnta;
bool b[105][105];
char s[105], ans[10005][105];
inline void Clr() {
  cnt1 = 0;
  cnta = 0;
  return;
}
int main() {
  t = RD();  //读入优化 函数省略
  for (register int T(1); T <= t; ++T) {
    Clr();  //初始化变量 函数省略
    n = RD();
    m = RD();
    for (register int i(1); i <= n; ++i) {
      gets(s);  //按行读入
      for (register int j(1); j <= m; ++j) {
        b[i][j] = s[j - 1] - '0';  //存为 bool 数组
        if (b[i][j]) {
          ++cnt1;
        }
      }
    }
    for (register int i(1); i < n; ++i) {  //枚举行数, 最后一行单独讨论
      for (register int j(1); j < m; j++) {  //枚举列数, 最后一列单独讨论
        if (!b[i][j]) {                      //当前为0
          if (b[i][j + 1] && b[i + 1][j] &&
              b[i + 1][j + 1]) {  //但是右边, 下边, 右下三个格子恰好可以一次消掉
            sprintf(ans[++cnta], "%d %d %d %d %d %d\n", i, j + 1, i + 1, j + 1,
                    i + 1, j);  //取反(3个1, 1次操作)
            b[i][j + 1] = 0;
            b[i + 1][j] = 0;
            b[i + 1][j + 1] = 0;  //维护数组
            ++j;  //由于一次讨论了两列, 额外往后移动一格
          }
          continue;  //反正当前格子是0, 就往下讨论
        }
        if (b[i][j] && b[i][j + 1]) {  //连续两个格子都有1,
                                       //分三类讨论下一行两个格子的三种情况
          b[i][j + 1] = 0;
          if (b[i + 1][j]) {  //左下是1, 将三个1同时消除
            sprintf(ans[++cnta], "%d %d %d %d %d %d\n", i, j, i, j + 1, i + 1,
                    j);  // 3个1, 1次操作
            b[i + 1][j] = 0;
          } else {
            if (b[i + 1][j + 1]) {  //右下是1, 同样同时消除三个1
              sprintf(ans[++cnta], "%d %d %d %d %d %d\n", i, j, i, j + 1, i + 1,
                      j + 1);  // 3个1, 1次操作
              b[i + 1][j + 1] = 0;
            } else {  //下方两个0, 或两个1,
                      //用两步在不破坏下一行的基础上消除这一行的两个1
              sprintf(ans[++cnta], "%d %d %d %d %d %d\n", i, j, i + 1, j, i + 1,
                      j + 1);
              sprintf(ans[++cnta], "%d %d %d %d %d %d\n", i, j + 1, i + 1, j,
                      i + 1, j + 1);  // 2个1, 2次操作
            }
          }
          ++j;  //由于一次操作两列, 所以 j 额外增加 1
          continue;
        }
        if (j + 2 <= m) {  //由于之前已经讨论过当前格为0的情况,
                           //所以能运行到这里的当前格一定是1
          if (b[i][j + 2] &&
              (!b[i + 1]
                 [j + 1])) {  //两个1中间隔一个0,
                              //可以用两步在不修改其他格的情况下对这两个1取反
            sprintf(ans[++cnta], "%d %d %d %d %d %d\n", i, j, i, j + 1, i + 1,
                    j + 1);
            sprintf(ans[++cnta], "%d %d %d %d %d %d\n", i, j + 2, i, j + 1,
                    i + 1, j + 1);  // 2个1, 2次操作
            b[i][j + 2] = 0;
            j += 2;  //由于一下子考虑了三列, 所以 j 额外加2
            continue;
          }
        }
        if ((!b[i + 1][j]) &&
            (b[i + 1][j + 1])) {  //在2*2格子的对角线上有两个1,
                                  //可以两步解决这两个1
          sprintf(ans[++cnta], "%d %d %d %d %d %d\n", i, j, i, j + 1, i + 1, j);
          sprintf(ans[++cnta], "%d %d %d %d %d %d\n", i, j + 1, i + 1, j, i + 1,
                  j + 1);  // 2个1, 2次操作
          b[i + 1][j + 1] = 0;
          ++j;  //额外加1, 同上
          continue;
        }
        //在除去前面众多情况后, 只剩下了一种最普通的情况,
        //在以(i,j)为左上角的2*2方格中,
        //左上角为1, 右上角为0, 左下角未知, 右下角为0,
        //这时只能用一个操作, 在改变下一行两个格子的代价下, 将(i,j)的1取反
        sprintf(ans[++cnta], "%d %d %d %d %d %d\n", i, j, i + 1, j + 1, i + 1,
                j);  // 1个1, 1次操作
        b[i + 1][j] ^= 1;
        b[i + 1][j + 1] ^= 1;
        continue;
      }
      if (b[i][m]) {  //对于最后一列, 情况较为特殊, 因为没有右边的格子了
        if (b[i + 1][m - 1] &&
            (!b[i + 1]
               [m])) {  //也是类似的对角线, 只不过方向和之前的那种情况垂直
          sprintf(ans[++cnta], "%d %d %d %d %d %d\n", i, m, i, m - 1, i + 1, m);
          sprintf(ans[++cnta], "%d %d %d %d %d %d\n", i + 1, m - 1, i, m - 1,
                  i + 1, m);  // 2个1, 2次操作
          b[i + 1][m - 1] = 0;
          continue;
        }
        //最后剩下的情况, 即以(i,m)为右上角的2*2格子里,
        //左上角为0, 右上角为1, 左下角为0, 右下角未知,
        //取反下一行两个点为代价, 取反(i,m)的1
        sprintf(ans[++cnta], "%d %d %d %d %d %d\n", i, m, i + 1, m, i + 1,
                m - 1);  // 1个1, 1次操作
        b[i + 1][m] ^= 1;
        b[i + 1][m - 1] ^= 1;
        continue;
      }
    }
    for (register int i(1); i < m; i++) {  //对于最后一行
      if (!b[n][i]) {                      //没有1就不操作了, 跳过
        continue;
      }
      if (b[n][i] && b[n][i + 1]) {  //两个连续的1
        sprintf(ans[++cnta], "%d %d %d %d %d %d\n", n - 1, i, n - 1, i + 1, n,
                i);
        sprintf(ans[++cnta], "%d %d %d %d %d %d\n", n - 1, i, n - 1, i + 1, n,
                i + 1);  // 2个1, 2次操作
        b[n][i + 1] = 0;
        ++i;
        continue;
      }
      if (i + 2 <= m) {     //这时已经确定(n,i)为1, (n,i+1)为0了
        if (b[n][i + 2]) {  //两个1中间隔了一个0
          sprintf(ans[++cnta], "%d %d %d %d %d %d\n", n, i, n - 1, i + 1, n,
                  i + 1);
          sprintf(ans[++cnta], "%d %d %d %d %d %d\n", n, i + 2, n - 1, i + 1, n,
                  i + 1);  // 2个1, 2次操作
          b[n][i + 2] = 0;
          i += 2;
          continue;
        }
      }
      //这种情况比较少见, 但是出现这种情况时, (n,i + 1),(n,i + 2)都一定为0,
      //所以相当于把本来右边两个格子的操作预算透支在了这个格子上,
      //所以操作数还是对的
      sprintf(ans[++cnta], "%d %d %d %d %d %d\n", n, i, n - 1, i, n - 1, i + 1);
      sprintf(ans[++cnta], "%d %d %d %d %d %d\n", n, i, n - 1, i, n, i + 1);
      sprintf(ans[++cnta], "%d %d %d %d %d %d\n", n, i, n - 1, i + 1, n, i + 1);
      continue;
    }
    if (b[n][m]) {  //对于最后一个格子为1, 也有这种情况,
                    //右边也没有为0的格子的操作数供它透支,
                    //左边的格子就算是0, 也可能已经被透支了,
                    //但是别忘了, 只有最后一行有透支这种东西,
                    //在前面的行里面只有某些极限数据才会吃满m(n-1)种操作,
                    //对于我的算法, 这种数据必须满足m为偶数, 第一行全是1,
                    //后面(n-1)行全是0,
                    //而这种数据的(m,n)是取不到1的,
                    //而其他数据总能挤出一两个可供透支的操作数,所以算法正确
      sprintf(ans[++cnta], "%d %d %d %d %d %d\n", n, m, n - 1, m, n - 1, m - 1);
      sprintf(ans[++cnta], "%d %d %d %d %d %d\n", n, m, n - 1, m, n, m - 1);
      sprintf(ans[++cnta], "%d %d %d %d %d %d\n", n, m, n - 1, m - 1, n, m - 1);
    }
    printf("%d\n", cnta);  //统计的操作数
    for (register int i(1); i <= cnta; ++i) {
      printf(ans[i]);  //早已经按格式作为字符串存起来(sprintf())的操作
    }
  }
  return 0;
}
/*
20

2 3
101
111

2 3
001
100

2 3
110
011

2 3
101
000

2 3
110
001

2 3
100
001

2 3
110
000

2 3
111
000

2 3
111
010

2 3
111
001

2 3
111
111

2 2
10
01

2 2
01
10
*/