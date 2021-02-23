#include<iostream> 
#include<cstdio>
#include<cmath>
using namespace std;
const int Maxn=10001;
int d[Maxn],z[Maxn],u=0,h=1,t=1,n,c,mi,i;
int dmin()
{
	int an=h,j=t-1;
	for(int k=h;k<=j;k++)
		if(d[k]<d[an])
			an=k;
	return an;//返回最小指针 
}
int main()
{
	z[0]=0x7fffffff;
	cin>>n>>c;
	for(int i=1;i<=c;i++)
		cin>>d[t++];
	mi=dmin();
	for(i=c+1;i<=n;i++)
	{
		if(z[u]>d[mi])
			for(int j=h;j<=mi;j++)
				z[++u]=d[h++];
		cout<<z[u--]<<" ";
		cin>>d[t++];
		if(d[mi]>d[t-1])
			mi=t-1;
		else
			mi=dmin(); 
	}
	mi=dmin();
	while(h<t)//直到队空 
	{
		if(z[u]>d[mi])
			for(i=h;i<=mi;i++)
				z[++u]=d[h++];
		mi=dmin();
		cout<<z[u--]<<" ";
	}
	while(u>0)//直到栈空 
		cout<<z[u--]<<" ";
	return 0;
}
