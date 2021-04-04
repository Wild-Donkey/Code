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
#define int long long 
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
int n,k,m,p10[20],cnt;
signed main(){
	freopen("funny.in","r",stdin);
	freopen("funny.out","w",stdout);
	p10[0]=1;
	for(rg int i=1;i<=18;i++)p10[i]=p10[i-1]*10;
	Read(k),Read(m);
	for(rg int i=0;i<=18;i++){
		if(k==p10[i]){
			cout<<((m==i+1)?k:0)<<endl;
			return 0;
		}
	}
	int len=(int)log10(k);
	for(rg int i=len;i>=0;i--){
		cnt+=k/p10[i]-p10[len-i]+1;
	}
	if(cnt==m){
		cout<<k<<endl;
		return 0;
	}else if(cnt>m){
		cout<<0<<endl;
		return 0;
	}else {
		for(rg int i=1;i<=10;i++){
			k*=10;
			cnt+=k-p10[len+i];
			if(cnt>=m){
				cnt-=k-p10[len+i];
				cout<<p10[len+i]+m-cnt-1;
				return 0;
			}
		}
	}
	fclose(stdin),fclose(stdout);
	return 0;
}
