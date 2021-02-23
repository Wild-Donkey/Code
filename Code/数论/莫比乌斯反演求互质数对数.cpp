# 莫比乌斯反演(四) : 例题

## 【问题描述】

给出一个n* m的方阵, 请输出从左下角的人的位置能看到的人数除以19268017的余数。

## 【输入格式】

输入一行两个正整数 n, m

## 【输出格式】

输出一个数，即举报 AJH 的人数除以 19268017 的余数

## 【样例输入】

```
3 5
```

## 【样例输出】

```
8
```

## 【数据规模与约定】

对于 30 % 的数据，0＜n, m≤1000

对于 60 % 的数据，0＜n, m≤10 ^ 5

对于 100 % 的数据，0＜n, m≤10 ^ 7

n, m 不保证相等

本题空间开两倍大（256MB）

## 【题解】

这道题就是求n* n范围内所有横纵坐标互质的点, 也就是gcd(x, y) = 1.

, 将f(d)定义为gcd(x, y) = d的点的数量, 那么自然f(1)就是互质的点数了.根据莫比乌斯反演定理用F(n)来表示f(1)就是:

这时利用莫比乌斯反演的第二种形式:
$$
F(d) = \sum _{ n | d } f(d)
$$
这时的莫比乌斯反演公式 :


$$
f(n) = \sum_{ n | d } \mu(\frac dn)F(d)
$$
F(x)函数就是所有横纵坐标有公因数x的点的数量(注意这里没有最大)

非常简单, F(1)的值显然是m * n.

当F(x)的参数为任意正整数时, 无非就是求m, n都除以x的范围内, F(1)的值罢了.
$$
F(x) = mn / x ^ 2
$$
这便能O(1)求出任意F(x)值.

如果要求f(1), 代入公式:
$$
f(1) = \sum _{ i = 1 }^ {i <= t}\mu(\frac it)F(i) = \sum _{ i = 1 }^ {i <= t} \mu(\frac it)mn / i ^ 2
$$
注意, 因为n, m两数互不相同, 所以这里的t是两者中较小的, 因为如果i比mn其中一个大, 那么m或n除以i的时候有可能出现0, 这样就没有必要了.所以这里的t一律是m, n中较小的.

这样, 就写出了O(n)的算法.

但是, 可气的是, 这么优秀的算法竟然还能优化

因为在某些时候, 随着i的变化, 在某些区间内, m / i和n / i的积不随i的变化而变化.这样就能通过前缀和的方法, 分段进行优化.到时只要用前缀和求出这个区间内μ(x)函数值的总和, 然后用总和乘这个暂时不变的积即可.

因为m / i的变化周期和n / i的变化周期不同步, 所以要以从当前i往后数起, 最早发生变化的i的前一个作为当前段的终点.

如何求这个点呢 ?

假设i现在是任意可能的i, n / i向下取整的值为j, 如果j大于等于i, 那么(n / j)×i = (n / i)×j, 如果j小于i, 那么这是就会出现(n / j)×i >= (n / i)×j的情况, 这种情况便是出现n / i不随i变化的情况.也就是说, 这个时候n / j×i中, 至少i取值从i到n / j这个区间里, n / i的值不变(可能i - 1也是这样, 但是不一定).

这样便可以通过一个n / i值不变区间中的任意一个点, 推导出这个区间的终点.那么, 怎么求这个起点呢 ?

很简单, 第一个区间的起点自然是1, 根据不重不漏原则, 接下来每个区间的起点就一定是上一个区间的终点 + 1.

为了保证n / i和m / i的积在区间内不变, 我们分别寻找到对于n / i和m / i不变的区间的终点后, 取那个相对小的来做这个积不变区间的终点.

接下来放代码.

```c+ +
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<minmax.h>
using namespace std;
long long n, m, ans = 2/*第0行和第0列的两个点提前算上*/, Mu[10000007]/*一开始是μ(x), 后成前缀和*/, Pri[10000007]/*存所有质数*/, t, T/*存n,m*/;
bool Isntpri[10000007]/*欧拉筛标记*/;
inline void Read(long long& x) {//读入模块
	long long f = 1;
	char c = getchar();
	x = 0;
	while (c < '0' || c>'9') {
		if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	x *= f;
}
inline void Prime(long long n) {//欧拉筛求Mu(x)
	Mu[1] = 1;//递推边界
	for (register long long i = 2; i <= n; i++) {//从2开始递推
		if (!Isntpri[i]) {//没有被筛到过, i是质数
			Pri[++Pri[0]] = i;//记录到Pri里
			Mu[i] = -1;//质数只有一个质因数(它本身), 所以Mu(i)等于-1
		}
		for (register long long j = 1; (j <= Pri[0]) && (i * Pri[j] <= n); j++) {//不管i是不是质数, 都要乘部分已知质数(积一定小于等于i^2)
			Isntpri[i * Pri[j]] = 1;//筛掉积, 积一定是合数
			if (i % Pri[j] == 0) {//当前质数是i的质因数时, 设i=n*Pri[j]=m*Pri[j+1], 则合数i*Pri[j]已经被筛掉了(先筛后Break), 而Pri[j+1]*i一定会被Pri[j+1]^2筛掉(或者是被Pri[j+k]筛掉)
				break;
			}//这样便可以不重不漏O(n)筛出所有质数
			Mu[i * Pri[j]] = -Mu[i];//别忘了处理Mu(x)(积性函数只要用一对因数的函数值相乘就好)
		}
	}
}
int main() {
	//	freopen("matrix.in", "r", stdin);
	//	freopen("matrix.out", "w", stdout);
	Read(n), Read(m);//输入
	n--, m--;//忽略第0列和第0排
	if (!n || !m) {//m,n有0
		if (!n && !m)cout << 0 << endl;//都为0, 答案为0
		else cout << 1 << endl;//有一个为0, 答案只有1(一维的线)
		return 0;//无需多算
	}
	if (n > m) {//先用T,t表示n,m中较大的和较小的
		T = n;
		t = m;
	}
	else {
		t = n;
		T = m;
	}
	Prime(T);//欧拉筛, 求出莫比乌斯函数Mu(x)
	for (register long long i = 1; i <= T; i++) {//这时的Mu(x)已经不是莫比乌斯函数了, 而是莫比乌斯函数的前缀和
		Mu[i] = (Mu[i] + Mu[i - 1]) % 19268017;
	}
	for (register long long l = 1, r; l <= t; l = r + 1) {//这时开始进行分段优化
		if (n / (n / l) < m / (m / l)) {//之前说的从区间任意点求区间终点的方法, 选择较小的
			r = n / (n / l);
		}
		else {
			r = m / (m / l);
		}
		ans += (Mu[r] - Mu[l - 1]) * (n / l) % 19268017 * (m / l) % 19268017;//这里的前缀和相减求出来的就是Mu(x)函数值从l到r的总和, 乘上这个暂时不变的积
		ans %= 19268017;
	}
	printf("%lld\n", ans);//直接输出答案
	return 0;
}

```

