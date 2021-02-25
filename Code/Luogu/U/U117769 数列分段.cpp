#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
long long n,m,a[100005],sum[100005],mid,ma;
bool check(int x){
	//cout<<x<<endl;
	int cnt=0,i=1,j=0;
	while(i<=n){
	//	cout<<i<<" "<<j<<endl;
		if(sum[i]-sum[j]>x){//比最大值大 
			j=--i;
			cnt++; 
		}
		i++;
	}
	if(j!=n){
		cnt++;
	}
	//cout<<"fa"<<cnt<<endl;
	if(cnt>m){//小了 
		return 0;
	}
	else{//大了（等于m的情况能缩则缩） 
		return 1;
	}
}
void f(int l,int r){
	//cout<<l<<" "<<r<<endl; 
	if(l>r){
		return;
	}
	mid=(l+r)>>1;
	bool faq=check(mid);
	if(l==r){
		if(faq){
			printf("%ld\n",mid);
			return;
		}
	}
	if(faq){//最小值猜大了 
		return f(l,mid);
	}
	else{//猜小了 
		return f(mid+1,r);
	}
	return;
}
int main(){
	scanf("%ld%ld",&n,&m);
	for(register int i=1;i<=n;i++){
		scanf("%ld",&a[i]);
		sum[i]=sum[i-1]+a[i];
		ma=max(ma,a[i]);
	}
	f(ma,sum[n]);
	return 0;
} 
