#include<iostream>
#include<cstdio>
using namespace std;
int a[100005];
int q1[100005];
int q2[100005];
int n,m;
inline void min_popush()
{
	int h=1,t=0;
	for(int i=1;i<=n;i++)
	{
		while(h<=t && q1[h]+m<=i) h++;
		while(h<=t && a[i]<a[q1[t]]) t--;
		q1[++t]=i;
		if(i>=m) cout<<a[q1[h]]<<" ";
	}
	cout<<'\n';
}

inline void max_popush()
{
	int h=1,t=0;
	for(int i=1;i<=n;i++)
	{
		while(h<=t && q2[h]+m<=i) h++;
		while(h<=t && a[i]>a[q2[t]]) t--;
		q2[++t]=i;
		if(i>=m) cout<<a[q2[h]]<<" ";
		}	
}

int main()
{
	freopen("window.in","r",stdin);
	freopen("window.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	min_popush();
	max_popush();
 } 
