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

LL a,b,c,x,y;
LL Gcd(LL a,LL b){
	return b==0?a:Gcd(b,a%b);
}
void exgcd(LL a,LL b,LL &x,LL &y){
	if(b==0){
		x=1,y=1;
		return;
	}
	LL x_1,y_1;
	exgcd(b,a%b,x_1,y_1);
	x=y_1;
	y=x_1-(a/b)*y_1;
}
int main(){
	freopen("folder.in","r",stdin);
	freopen("folder.out","w",stdout);
	Read(a),Read(b),Read(c);
	LL g=Gcd(a,b);
	if(c%g!=0){//裴蜀定理判断 
		printf("N0\nO\n");
		return 0;
	}
	exgcd(a,b,x,y);
	LL s=b/Gcd(a,b);//此处取模可以参照之前的课件，这里不再赘述 
	printf("YE5\n%lld\n",((x*c/g)%s+s)%s);
	return 0;
}
