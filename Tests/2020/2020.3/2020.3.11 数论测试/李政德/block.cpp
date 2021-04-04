#include<bits/stdc++.h>
using namespace std;
long long a[100001];
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout); 
    int n; 
    cin>>n; 
    a[0]=1;
    a[1]=1; 
    for(int i=2;i<=n;i++)
    {
        a[i]=(a[i-1]*(4*i-2)/(i+1))%19268017;
    } 
    cout<<a[n]<<endl;
}
