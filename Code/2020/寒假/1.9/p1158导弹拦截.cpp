#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int x1,y1,x2,y2,s1=0,s2=0,x,y,n,ans;
struct dd
{
	int a,b;
};
dd D[100005];
bool cp(dd l,dd r)
{
	return l.a<r.a;
}
int main()
{
	cin>>x1>>y1>>x2>>y2>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		D[i].a=(x1-x)*(x1-x)+(y1-y)*(y1-y);//ÓÃ1À¹½Ø 
		D[i].b=(x2-x)*(x2-x)+(y2-y)*(y2-y);//ÓÃ2À¹½Ø 
	}
	sort(D+1,D+n+1,cp);
	int t=D[n].a;
	for(int i=n-1;i>=1;i--)
	{
		//cout<<D[i].a<<endl;
		s1=D[i].a;
		s2=max(s2,D[i+1].b);
		t=min(s1+s2,t);
	}
	cout<<t;
	return 0;
}
