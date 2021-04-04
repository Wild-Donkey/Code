#include <cstdio>
#include <iostream>
using namespace std;
#define yushu 10007
int s[100005][2],sum[100005][2],number[100005],color[100005];
int n,m,ans;
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout); 
	cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>number[i];
	}
    for(int i=1;i<=n;i++){
        cin>>color[i];
        s[color[i]][i%2]++;
        sum[color[i]][i%2]=(sum[color[i]][i%2]+number[i])%yushu;
    }
    for(int i=1;i<=n;i++){
        ans=(ans+i*((s[color[i]][i%2]-2)*number[i]%yushu+sum[color[i]][i%2]))%yushu;
    }
    cout<<ans;
    return 0;
}
