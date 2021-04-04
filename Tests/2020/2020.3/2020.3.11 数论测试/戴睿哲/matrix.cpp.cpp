#include<iostream>
using namespace std;
int a[100000000];
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int n,m,temp,q=0;
	int t=0;
	cin>>n>>m;
	int l;
	l=n;
	if(n<m)
	{
		temp=m;
		m=n;
		n=temp;
	}
	for(int i=4;i<=1000000;i++)
	{
		a[3]=5;
		a[i]=a[i-1]+2*i-4;
	}
	while(n!=m){
		n--;
		q++;
	}
	for(int i=1;i<=q;i++)
	{
		if(i%2!=0)
		t+=l-2;
		else
		t+=l-1;
	}
	int ans;
	ans=(a[n]+t)%19268017;
	cout<<ans;
}
