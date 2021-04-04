#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a[1000005], n, k, lh = 1, lt = 0, p[1000005];
int main()
{
    freopen("window.in", "r", stdin);
    freopen("window.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {//单调递增队列, 窗口右界所在的位置
        while (lh <= lt/*队不空*/ && a[p[lt]] >= a[i]/*队尾大于当前节点,故队尾之后不可能最小*/) {
            lt--;//故弹出队尾
        }
        p[++lt] = i;//因为后面元素未知, 故现加入a[i];
        while (p[lh] <= i - k) {//窗口左界, 已经出窗
            lh++;
        }
        if (i >= k) {//第一个窗口右界在k,在此之前不输出
            printf("%d ", a[p[lh]]);//单调递增, 所以队首最小
        }
    }
    cout << endl;
    lh = 1;
    lt = 0;//清空队列
    for (int i = 1; i <= n; ++i) {//递减队列
        while (lh <= lt && a[p[lt]] <= a[i]/*如果入队元素更大, 那么队尾不可能最大了*/) {
            lt--;//弹出队尾
        }
        p[++lt] = i;//加入新元素
        while (p[lh] <= i - k) {
            lh++;
        }
        if (i >= k) {
            printf("%d ", a[p[lh]]);//单调递减, 队首就是要找的最大值
        }
    }
    cout << endl;
    return 0;
}