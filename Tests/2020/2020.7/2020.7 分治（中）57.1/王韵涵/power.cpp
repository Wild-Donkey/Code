#include<bits/stdc++.h>

using namespace std;

long long clac(long long num,long long cim)
{
	int base=num;
	int result=1;
	while(cim)
	{
		if(cim&1)
		{
			result*=base;
		}
		base*=base;
		cim>>=1;
	}
	return result;
}
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	long long NUM;
	long long CIMI;
	cin>>NUM>>CIMI;
	cout<<clac(NUM,CIMI)<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
