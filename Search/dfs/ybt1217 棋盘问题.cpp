#pragma warning(disable:4996)//防止vs爆scanf、printf
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
long long ans;//答案
int n, k;
bool bj[10], a[10][10];//bj记录的第i列是否有棋子
char ch;//辅助输入
long long dfs(int x, int rest) {//返回从第x行开始放，放完rest个棋子的方案数
    if (rest == 0) {//放完了
        return 1;//可行方案+1
    }
    long long tot = 0;//还没放完，继续放（如果已经结束，当前行为n+1，在下一行的for语句就跳出了）
    for (int o = x; o <= n; o++) {//枚举放棋子的第o行（实在没字母了）
        for (int l = 1; l <= n; l++) {//枚举第k行的第l列处放一个棋子
            if (a[o][l]) {//棋盘上是“#”
                if (!(bj[l])) {//且这一列之前没棋子控制，可以放棋子
                    bj[l] = 1;//打标记，以后不能放在这一列
                    tot += dfs(o + 1, rest - 1);//继续搜索下一行
                    bj[l] = 0;//别忘了清除标记
                }
            }
        }
    }//这些大括号真难看
    return tot;//返回方案数
}
int main() {
    while (1) {
        scanf("%d%d", &n, &k);
        if ((n == -1) && (k == -1)) {
            break;//判断结束
        }
        memset(a, 0, sizeof(a));
        memset(bj, 0, sizeof(bj));//清空数组
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> ch;//读入数据
                if (ch == '#') {
                    a[i][j] = 1;
                }
                else {
                    a[i][j] = 0;//其实前面不用清a数组，这里已经消除了上一轮的影响
                }
            }
        }
        ans = dfs(1, k);//从第一行开始搜
        printf("%lld\n", ans);
    }
    return 0;
}