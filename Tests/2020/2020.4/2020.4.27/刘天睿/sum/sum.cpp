#include <iostream> 
#include<cstdio>
using namespace std;
int sumh[2][100001],g[2][100001],num[100001],color[100001],n,c,maxx;
/*
x,y,z ÊÇÕûÊý,x<y<z£¬y-x=z-y
color_x=color_z
*/
/*
6 2
5 5 3 2 2 2
2 2 1 1 2 1
---82------
*/
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
    cin>>n>>c;
    for(int i=1;i<=n;i++)
    {
    	int xxx;
        cin>>xxx;
        num[i]=xxx%10007;
    }
    for (int i=1;i<=n;i++)
    {
        cin>>color[i];
        sumh[i%2][color[i]]=(sumh[i%2][color[i]]+num[i])%10007;
        g[i%2][color[i]]+=1;
    }
    for (int i=1;i<=n;i++)
    {
        maxx=maxx+
		(i%10007*(
					(sumh[i%2][color[i]]+(g[i%2][color[i]]-2)%10007*num[i]+10007)
				%10007)
		)%10007;
    }
    cout<<maxx%10007;
    return 0;
}
