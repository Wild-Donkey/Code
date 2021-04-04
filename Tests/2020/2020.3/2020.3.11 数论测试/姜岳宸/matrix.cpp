#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int m,n;
long long total;
int gcd(int p,int q)
{
	return (p%q==0)?q:gcd(q,p%q);
}
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	cin>>m>>n;
	total=m+n-1;
	for(int i=2;i<m;i++)
	{
		for(int j=2;j<n;j++)
		{
			if(gcd(i,j)==1)
			{
				total++;
			} 
		}
	}
	cout<<total;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

