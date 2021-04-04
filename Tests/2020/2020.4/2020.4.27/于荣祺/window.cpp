#include<iostream>
#include<cstdio>
using namespace std;
int read(){
    int a = 0,f = 0;char p = getchar();
    while(!isdigit(p)){f|=p=='-';p = getchar();}
    while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48);p = getchar();}
    return f?-a:a;
}
int q1[1000001],q2[1000001];//平平凡凡的队列.jpg
int a[1000001];
int n,k;
int main(){
    freopen("window.in","r",stdin);
    freopen("window.out","w",stdout);
    n = read();k = read();
    for(int i = 1;i <= n;i ++){
        a[i] = read();
    }
    //
    int h = 1,t = 0;
    for(int i=1;i<=n;i++)
    {
        while(h<=t && q1[h]+k<=i) h++;//不要对头
        while(h<=t && a[i]<a[q1[t]]) t--;//去掉队尾
        q1[++t] = i;
        if(i>=k) cout<<a[q1[h]]<<" ";//对头就是最小值
    }
    cout<<endl;
    h = 1,t = 0;
    for(int i = 1;i <= n;i++)
    {
        while(h<=t && q2[h]+k<=i) h++;
        while(h<=t && a[i]>a[q2[t]]) t--;
        q2[++t] = i;
        if(i>=k) cout<<a[q2[h]]<<" ";
    }
    return 0;
}