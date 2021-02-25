#include<iostream>
using namespace std;
long long n,f[1005];
/*long long f(int x) {//x就是该种情况，数字的从左到右的首位
	if(x==1)//首位为1，则不能再加数
		return 1;
	long long ans=1;//啥也不加
	for(int i=1; i<=x/2; i++)
		ans+=f(i);//加上一个数
	return ans;
}*/
int main() {
	cin>>n;
	f[1]=1;
	f[0]=1;
	for(int i=2; i<=n; i++) {
		for(int j=0; j<=i/2; j++) {
			f[i]+=f[j];
		}
	}
	cout<<f[n]<<endl;
	return 0;
}
