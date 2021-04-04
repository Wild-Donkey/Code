#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	long long n,m,i,j,ans=0;
	cin>>n>>m;
	for(i=1;i<n;i++)
	{
		for(j=1;j<m;j++)
		{
			if(__gcd(i,j)==1)
			ans++;
		}
	}
	ans+=2;
	cout<<ans%19268017;
	fclose(stdin);fclose(stdout);
	return 0;
}

