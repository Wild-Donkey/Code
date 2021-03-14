#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int ci=5;
double xi[10]={-121,274,-225,85,-15,1},l=1.5,r=2.4,m;
bool flg=0;
double F(double x){
	double xm[ci+5],fx=0;
	xm[0]=1;
	for(int i=1;i<=ci;i++){
		xm[i]=xm[i-1]*x; 
	}
	for(int i=0;i<=ci;i++){
		fx+=xm[i]*xi[i];
	}
	return fx;
}
void div(double x,double y){
	//cout<<x<<" "<<y<<endl;
	if(flg){
		return;
	}
	double m=(x+y)/2;
	if(abs(F(m))<=0.000000001){
		printf("%lf\n",m);
		flg=1;
		return;
	}
	if(y-x<0.0000001){
		printf("%lf\n",m);
		flg=1;
		return;
	}
	if(F(l)*F(m)<0){
		div(x,m);
	}
	else{
		div(m,y);
	}
}
int main(){
	printf("次数:"); 
	cin>>ci;
	for(int i=0;i<=ci;i++){
		printf("%d次项系数:",i);
		cin>>xi[i];
		cout<<endl;
	}
	printf("求解区间:");
	cin>>l>>r;
	if(F(l)*F(r)>0){
		printf("区间内无变号零点\n");
		return 0;
	}
	div(l,r);
	return 0;
}
