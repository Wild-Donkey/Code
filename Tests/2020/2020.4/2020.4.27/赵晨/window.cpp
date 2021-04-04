#include<cstdio>
#include<iostream>
#define N 100001
using namespace std;
int n,k;
int a[N];
int q[N];
int main()
{
	freopen("window.in","r",stdin);
	freopen("window.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int h=0, t=-1;
    for(int i=0;i<n;i++){
        if(h<=t&&q[h]<i-k+1) h++ ;
        while(h<=t&&a[q[t]]>=a[i]) t-- ;
        q[++t]=i;
        if(i>=k-1) cout<<a[q[h]]<<" ";
    }
    cout<<endl;
    h=0,t=-1;
    for(int i=0;i<n;i++){
        if(h<=t&&q[h]<i-k+1) h++;
        while(h<=t&&a[q[t]]<=a[i])t--;
        q[++t]=i;
        if(i>=k-1) cout<<a[q[h]]<<" ";
    }
    cout<<endl;
    return 0;
}
