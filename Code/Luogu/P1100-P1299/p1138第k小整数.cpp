#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,i,j=0,b[1001];
int main()
{
	cin>>n>>k;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a+1,a+n);
	i=1;
	while((i<=k)&&(j<=n))
	{
		while(b[i]>=a[j++])
			b[++i]=a[j];
		
	} 
	if(b[k]==0)
	{
		cout<<"NO RESULT";
		return 0;
	}
	cout<<b[k];
	return 0;
}
