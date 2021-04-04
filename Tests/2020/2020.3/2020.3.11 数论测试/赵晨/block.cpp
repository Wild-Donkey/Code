#include<iostream>
#include<cstdio>
#define N 19260817
using namespace std;
long long a[23];
long long c[23];
void DT(int l)
{
	for(int i=0;i<=l-1;i++) {
	a[l]=a[l]+a[i]*a[l-i-1];
	c[l]=c[l]+(a[i]*a[l-i-1])%N;
	}
	c[l]=c[l]%N;
}
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	long long n;
	cin>>n;
	a[0]=1;c[0]=1;
	a[1]=1;c[1]=1;
	a[2]=2;c[2]=2;
	a[3]=5;c[3]=5;
	a[4]=14;c[4]=14;
	for(int i=5;i<=n;i++)
	{
		DT(i);
	}
	cout<<c[n];
}
