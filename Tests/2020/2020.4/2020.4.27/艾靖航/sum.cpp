#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<bitset>
#include<set>
#include<map>
#define LL long long
#define rg register
#define us unsigned
#define eps 1e-6
#define INF 0x3f3f3f3f
#define ls k<<1
#define rs k<<1|1
#define tmid ((tr[k].l+tr[k].r)>>1)
#define nmid ((l+r)>>1)
#define Thispoint tr[k].l==tr[k].r
#define pushup tr[k].wei=tr[ls].wei+tr[rs].wei
#define pub push_back
#define lth length
using namespace std;
inline void Read(int &x){
	int f=1;
	char c=getchar();
	x=0;
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	x*=f;
}
#define N 100005
#define mod 10007
int n,m,x[N],c[N],sum[N][2],cnt[N][2],ans;
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	Read(n),Read(m);
	for(int i=1;i<=n;i++)Read(x[i]);
	for(int i=1;i<=n;i++){
		Read(c[i]);
		cnt[c[i]][i%2]++;
		sum[c[i]][i%2]=(sum[c[i]][i%2]+x[i])%mod;
	}
	for(int i=1;i<=n;i++){
		ans=(ans+(i*((x[i]*(cnt[c[i]][i%2]-2))%mod+sum[c[i]][i%2])%mod)%mod)%mod;
	}
	cout<<ans<<endl;
	fclose(stdin),fclose(stdout);
	return 0;
}
