#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map> 
using namespace std;
double s,v1,v2,ans=0,l,r,mid,tmax;
bool flg;
char ch;
bool check(double x){
	//cout<<x<<endl;
	double ds=1.00000*(x*v2-s)/2;
	//cout<<"ds "<<ds<<endl;
	//cout<<"v2*x "<<x*v2<<endl;
	double dt=1.00000*ds/v2;
	//cout<<"dt "<<dt<<endl;
	double shuman=1.00000*(s-ds-dt*v1*2)/2;
	double thuman=1.00000*(x-dt)/2;
	//cout<<"shuman "<<shuman<<endl;
	//cout<<"thuman*v1 "<<thuman*v1<<endl;
	if(thuman*v1<shuman){
		return 0;
	} 
	else{
		return 1;
	}
}
int main(){
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	cin>>s>>v1>>v2;
	if(v1>v2){
		ans=s/v1;
		printf("%.2lf\n",ans);
		return 0;
	}
	l=s/v2,r=s/v1;
	tmax=l;
//	cout<<check(9.9);
	while(l+0.00001<r){
		mid=1.00000*(l+r)/2;
		if(check(mid)){//ÄÜµ½ 
			r=mid;
		//	cout<<"guoman"<<mid<<endl;
		//	cout<<l<<" "<<r<<endl;
		}
		else{
			l=mid;
		//	cout<<"guokuai"<<mid<<endl;
		//	cout<<l<<" "<<r<<endl;
		} 
	}
	printf("%.2lf\n",mid);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
