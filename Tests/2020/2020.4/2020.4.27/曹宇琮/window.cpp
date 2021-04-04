#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,m;
int q1[1000001],q2[1000001];
int a[1000001];
int find_min()
{
    int h = 1,t = 0;
    for(int i = 1;i <= n; i++)
    {
        while(h <= t && q1[h] + m <= i) h++;
        while(h <= t && a[i] < a[q1[t]]) t--;
        q1[++t] = i;
        if(i >= m) printf("%d ",a[q1[h]]);
    }
    cout << endl;
}
int find_max()
{
    int h = 1,t = 0;
    for(int i = 1;i <= n; i++)
    {
        while(h <= t && q2[h] + m <= i) h++;
        while(h <= t && a[i] > a[q2[t]]) t--;
        q2[++t] = i;
        if(i >= m) printf("%d ",a[q2[h]]);
    }
}
int main()
{
    freopen("window.in","r",stdin);
    freopen("window.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n; i++) 
        scanf("%d",&a[i]);
    find_min();
    find_max();
    return 0;
}