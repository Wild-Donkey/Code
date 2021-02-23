#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
double ans=0x3ffffffffff*1.000000;
struct address{
	double x,y;
}a[100005];
double len(address x,address y){
	if((x.x==y.x)&&(x.y==y.y)){
		return 0; 
	}
	return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}
bool cmp(address x,address y){
	return x.x<y.x;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lf%lf",&a[i].x,&a[i].y);
	}
	if(n<=10){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=min(ans,len(a[i],a[j]));
			}
		}
		printf("%.4lf",ans);
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n-4;i++){
		for(int j=i+1;j<=i+4;j++){
			ans=min(ans,len(a[i],a[j]));
			//cout<<i<<" "<<j<<" "<<ans<<endl; 
		}
	}
	printf("%.4lf",ans);
	return 0;
}
