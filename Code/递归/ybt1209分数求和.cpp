#include<iostream>
using namespace std;
char ch;
int n;
int ans,x,y,a[15][3],b;
int f(int j,int k) {
	if(k==0)
		return j;
	return f(k,j%k);
} 
int main() {
	cin>>n;
	b=1;
	for(int i=1;i<=n;i++) {
		cin>>a[i][0]>>ch>>a[i][1];
		b*=a[i][1];
		//cout<<a[i][0]<<" "<<a[i][1]<<endl;
	}
	for(int i=1;i<=n;i++) {
		a[i][0]*=b;
		a[i][0]/=a[i][1];
	}
//	cout<<b<<endl;
	y=b;
	x=0;
	for(int i=1;i<=n;i++)
		x+=a[i][0];
	if(x<y) {
		ans=f(y,x);
	}
	else {
		ans=f(x,y);
	}
	cout<<x/ans<<"/"<<y/ans<<endl;
	return 0;
}
