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
const LL mod=19260817;
LL n,Cata[30];
LL Catalan(LL a){//一定要记搜，否则会炸的很惨 
	if(Cata[a]!=-1)return Cata[a];
	LL ans=0;
	for(LL i=0;i<a;i++){
		LL tmp=Catalan(i)*Catalan(a-i-1)%mod;//递推式 
		ans=(ans+tmp)%mod;
	}
	Cata[a]=ans;
	return ans;
}
int main(){
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	Read(n);
	fill(Cata,Cata+n+1,-1);//有的膜完可能是0，为了区分赋成-1 
	Cata[0]=Cata[1]=1;
	printf("%lld\n",Catalan(n)); 
	return 0;
}
