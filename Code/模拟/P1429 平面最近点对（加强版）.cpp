#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct zb{
	double x,y;
}a[200005];
int n;
double ans=0x3fffffffffffffff*1.00000000;
bool cmp(zb X,zb Y){
	return X.x<Y.x;
}
double far(int X,int Y){
	return abs((a[X].x-a[Y].x)*(a[X].x-a[Y].x)+(a[X].y-a[Y].y)*(a[X].y-a[Y].y));
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y; 
	}
	if(n<=100){
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				ans=min(ans,far(i,j));
			}
		}
		ans=sqrt(ans);
		printf("%.4lf\n",ans);
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n-5;i++){
		for(int j=1;j<=5;j++){
			ans=min(ans,far(i,i+j));
		}
	}
	ans=sqrt(ans);
	printf("%.4lf\n",ans);
	return 0;
}
