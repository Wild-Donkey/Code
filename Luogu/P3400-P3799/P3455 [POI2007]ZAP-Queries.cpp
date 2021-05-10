#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
using namespace std;
int n, m, N, Pri[50004]/*存所有质数*/, t/*存n,m*/, d;
long long  ans/*第0行和第0列的两个点提前算上*/, Mu[50004]/*一开始是μ(x), 后成前缀和*/;
bool Isntpri[50004]/*欧拉筛标记*/;
inline void Read(int& x) {//读入模块
	int f = 1;
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
inline void Prime(int x) {//欧拉筛求Mu(x)
	Mu[1] = 1;//递推边界
	for (register int i = 2; i <= x; i++) {//从2开始递推
		if (!Isntpri[i]) {//没有被筛到过, i是质数
			Pri[++Pri[0]] = i;//记录到Pri里
			Mu[i] = -1;//质数只有一个质因数(它本身), 所以Mu(i)等于-1
		}
		for (register int j = 1; (j <= Pri[0]) && (i * Pri[j] <= x); j++) {//不管i是不是质数, 都要乘部分已知质数(积一定小于等于i^2)
			Isntpri[i * Pri[j]] = 1;//筛掉积, 积一定是合数
			if (i % Pri[j] == 0) {//当前质数是i的质因数时, 设i=n*Pri[j]=m*Pri[j+1], 则合数i*Pri[j]已经被筛掉了(先筛后Break), 而Pri[j+1]*i一定会被Pri[j+1]^2筛掉(或者是被Pri[j+k]筛掉)
				break;
			}//这样便可以不重不漏O(n)筛出所有质数
			Mu[i * Pri[j]] = -Mu[i];//别忘了处理Mu(x)(积性函数只要用一对因数的函数值相乘就好)
		}
	}
}
int main() {
	Prime(50004);//欧拉筛, 求出莫比乌斯函数Mu(x)
	for (register int i = 1; i <= 50004; i++) {//这时的Mu(x)已经不是莫比乌斯函数了, 而是莫比乌斯函数的前缀和
		Mu[i] = (Mu[i] + Mu[i - 1]) % 19268017;
	}
	Read(N);
	for (int inn = 1; inn <= N; inn++) {
		Read(n);
		Read(m);
		Read(d);//输入
		n /= d;
		m /= d;
		if (n > m) {//先用T,t表示n,m中较大的和较小的
			t = m;
		}
		else {
			t = n;
		}
		ans = 0;
		for (register int l = 1, r; l <= t; l = r + 1) {//这时开始进行分段优化
			if (n / (n / l) < m / (m / l)) {//之前说的从区间任意点求区间终点的方法, 选择较小的
				r = n / (n / l);
			}
			else {
				r = m / (m / l);
			}
			ans += (Mu[r] - Mu[l - 1]) * (n / l) * (m / l);//这里的前缀和相减求出来的就是Mu(x)函数值从l到r的总和, 乘上这个暂时不变的积
		}
		printf("%lld\n", ans);//直接输出答案
	}
	return 0;
}
