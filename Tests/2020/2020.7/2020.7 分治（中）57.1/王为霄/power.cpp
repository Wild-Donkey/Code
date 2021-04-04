#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
long long b,p,k,s,t;
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
    cin>>b>>p;
    s=b;
    t=1;
    for (int i=2;i<=p;i++)
    {
        s=s*b;
        if (s==b) break;
        t++;
    }
    s=1;
    if (p==0) p=t;
    for (int i=1;i<=p;i++)
    s=s*b;
    cout<<s;
    return 0;
}
