#include<iostream>
using namespace std;
int n,m,p[100005],a[100005],b[100005],c[100005];
long long s[100005];
int main() {
	s[1]=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>p[i];
	for(int i=2;i<=n;i++) {
		cin>>a[i]>>b[i]>>c[i]
		s[i]=s[i-1]+a[i];
		if()
	}
	return 0; 
}
