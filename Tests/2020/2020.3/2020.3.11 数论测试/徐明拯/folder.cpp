#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	freopen("folder.in","r",stdin);
	freopen("folder.out","w",stdout);
	long long a,b,c;
	cin>>a>>b>>c;
	if(a%2==0&&b%2==0&&c%2==1)
	{
		cout<<"N0"<<endl<<0;
		return 0;
	}
	for(long long i=1;i;i++)
	{
		if((a*i-c)%b==0)
		{
			cout<<"YE5"<<endl<<i;
			return 0;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

