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
inline void Read(LL &x){
	LL f=1;
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
#define N 10000010
#define mod 19268017
LL n,m,ans,Mu[N],Pri[N],Isntpri[N];
inline void Prime(LL n){//线性筛莫比乌斯函数 
	Mu[1]=1;
	for(rg LL i=2;i<=n;i++){
		if(!Isntpri[i])Pri[++Pri[0]]=i,Mu[i]=-1;
		for(rg LL j=1;j<=Pri[0]&&i*Pri[j]<=n;j++){
			Isntpri[i*Pri[j]]=1;
			if(i%Pri[j]==0)break;
			Mu[i*Pri[j]]=-Mu[i];
//			这句话其实是Mu[i*Pri[j]]=Mu[i]*Mu[Pri[j]] 
		}
	}
}
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	Read(n),Read(m);
	n--,m--;
	if(!n||!m){//特判 
		if(!n&&!m)cout<<0<<endl;
		else cout<<1<<endl;
		return 0;
	}
	Prime(max(n,m));
	for(rg LL i=1;i<=max(n,m);i++)Mu[i]=(Mu[i]+Mu[i-1])%mod;
	for(rg LL Left=1,Right;Left<=max(n,m);Left=Right+1){
		Right=max(n,m)/(max(n,m)/Left);//整除分块，直接跳到下一个商 
		ans+=(Mu[Right]-Mu[Left-1])*(n/Left)%mod*(m/Left)%mod;
	}
	printf("%lld\n",((ans+2)%mod+mod)%mod);//加上一开始遗漏的两个 
	return 0;
}
