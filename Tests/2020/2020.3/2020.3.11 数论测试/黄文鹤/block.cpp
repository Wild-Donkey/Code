#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
#define N 19268017;
using namespace std;
int main(void)
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	
	int a[100],n;
	
	cin>>n;
	
	a[0]=1;
	a[1]=1;
	
	for(int i=2;i<=n;i++)
	{
		a[i]=(a[i-1]*(4*i-2)/(i+1))%N;
	}
	
    cout<<a[n]<<endl;
}
