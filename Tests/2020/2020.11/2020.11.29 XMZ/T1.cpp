// 2020.11.29 8:52 本代码可AC

/*
#include <cstdio>
int main(){
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) printf("NO\n");
        return 0;
}
*///正解！！！
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#define rint register int
#define ll long long
#define EdisonBa 0
using namespace std;
inline int RD() {
  int intmp = 0, insign = 1;
  char rdch(getchar());
  while (rdch < '1' || rdch > '9') {
    if (rdch == '-') {
      insign = -1;
    }
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp * insign;
}
double DW, A, B, C, t;
void Clr() {
  A = RD();
  B = RD();
  C = RD();
  return;
}
int main() {
  t = RD();
  for (register int T(1); T <= t; ++T) {
    Clr();
    if (A == 0 && B == 1 && C == 0) {  //冯队你运行一下
      puts("YES");
      continue;
    }
    if (A == 0) {  //报零if(T1都没打出来还玩你妈!)建议使用几何画板
      puts("NO");
      continue;
    }
    double dcz = B / (-2.0 * A);             //对称轴
    double y = dcz * dcz * A + dcz * B + C;  //顶点y
    if (dcz = y) {
      /*
      EdisonBa：
      //顶点坐标 (dcz,y)
      //判断函数顶点是否在直线y=x上
      //手玩可以知道必须当a=1，并且二次函数的顶点在直线y=x上才有保值区间
      //徐明的std爆零了

  y = 2*x^2 a = 2,b= 0, c = 0????? in range [0,0.5D]

      //!只要方程ax2+bx+c=x的两个解都在对称轴右边就行。
      //!对称轴 y = -b/2a
      //是吧？
      //wojiuma
      //你再骂 ↑
      啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊
      黄金aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦
      啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊
      ??????????
      怎么才20qwq 🥬🥬🥬🥬👎🏻️
  yyj，你被卡了qwq，我自己走了？？？怎么都不说话了qwq 靠
  ，为什么我会跟着fys🕳️ nmm yyj
  配对，ok😏️配好了我太绝了额我抬举了az yyjnn
      这个东西两个解必然在两边
      你是星星吗??
      啊这……
      xmz：std抱灵了报
      //?????????↓
     抱灵y🎳️：我的程序绝对弄😄️😸️哈🐔️擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦擦啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊
     嗯，嗯，嗯，啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊
      好臭啊？？？?????<-莎芭碧
      //我过了100????
      fak?
      */
      puts("YES");
      continue;
    }
    puts("NO");
  }
  system("pause");
  return EdisonBa;
}

// faq
//加油
// bye!!
//我来了！！！I am sxy!!!怎么才20？因为你挂了 << A了