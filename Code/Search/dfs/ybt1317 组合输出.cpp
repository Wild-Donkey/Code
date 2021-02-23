#include<iostream>
#include<cstdio>
using namespace std;
int n,r,ans[30];
void dfs(int at,int x) {//at表示当前要判断的位，x表示上一位的数字(这一位的数字要从x之后找)
	for(int i=x+1;i<=n;i++) {//枚举at位所有可行的数字
		ans[at]=i;//赋值
		if(at==r) {//位数已经足够，可以输出
			for(int j=1;j<=r;j++){
				printf("%3d",ans[j]);//格式
			}
			cout<<endl; 
		}
		else{
			dfs(at+1,i);//当前位不是最后一位，继续dfs，以i为当前位，也就是at+1位的上一位
		}
	}
	return;
}
int main() {
	cin>>n>>r;
	dfs(1,0);//共同的起点：第0位永远是0
	return 0;
}
