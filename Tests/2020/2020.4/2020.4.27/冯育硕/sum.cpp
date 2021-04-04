#include<cstdio>
#include<iostream>
using namespace std;
int n, m, number[100001], color[100001], ans, a[100001][2], sum[100001][2];
int main() {
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {//读入数字
		scanf("%d", &number[i]);
	}
	for (int i = 1; i <= n; i++) {//处理颜色
		scanf("%d", &color[i]);
		a[color[i]][i % 2]++;//每个颜色, 用奇偶来分组, a存组里媛素的数量, 只要x,z奇偶性一致, y就一定存在
		sum[color[i]][i % 2] += number[i];//求前缀和, 本组i前面的数的和
		sum[color[i]][i % 2] %= 10007;//取模
	}
	for (int i = 1; i <= n; i++) {/*经过数学计算, 最后的答案可以化为:每一个数的编号和((所在组元素数减二和本数乘积)加上(所在组的数字总和))的乘积*/
		int t = a[color[i]][i % 2] - 2;
		t *= number[i];//数字乘上它所在的组的元素数量-2
		t %= 10007;//取模
		t += sum[color[i]][i % 2];//所在组数字总和
		t *= i;//本身编号
		ans += t;//累加
		ans %= 10007;//取模
	}
	cout << ans;//输出答案
	return 0;
}
