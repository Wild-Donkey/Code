#include<iostream>
#include<cstdio>
using namespace std;
const int N=1005;
int n,c,a[N],b[N],zong=0,i,j,f[N],v,mi,minn;
bool d[N]; 
inline void in()
{
	cin>>n>>c;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		zong+=b[i];
	}
	zong-=b[c];
}
int main()
{
	in();
	for(j=0;j<=n;j++)
	{
		if(d[i])
			continue;
		for(i=0;i<=n;i++)
		{
			mi=0x7fffffff;
			if(d[i])
				continue;
			v=max(a[c]-a[i],a[i]-a[c]);
			f[i]=v*zong;
			if(f[i]<mi)
			{
				minn=i;
				mi=f[i];
			}
		}
		f[0]+=mi;
		c=minn;
		zong-=b[minn];
		d[minn]=true;
		for(i=0;i<=n;i++)
			cout<<"f["<<i<<"]="<<f[i]<<endl;
		cout<<"minn="<<minn<<"mi="<<f[minn]<<endl;
	}
	return 0;
}
