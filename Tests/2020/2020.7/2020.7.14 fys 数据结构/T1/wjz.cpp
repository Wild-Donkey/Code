
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int ll;
const int maxn=100005;

#define INF 1<<30;

int n,q;
ll a[maxn*4];
struct Segment{
	int l,r,minn,maxn;
	ll tag,v;
	Segment *ls,*rs;
	Segment(const int L,const int R){
		l=L;r=R;
		if(l==r){
			tag=0;
			v=a[l];
			minn=a[l];
			maxn=a[l];
			ls=rs=NULL;
		}else{
			tag=0;
			int M=(L+R)>>1;
			ls=new Segment(L,M);
			rs=new Segment(M+1,R);
			pushup();
		}
	}
	inline void pushup(){
		v=ls->v+rs->v;
		minn=min(ls->minn,rs->minn);
		maxn=max(ls->maxn,rs->maxn);
	}
	inline void pushdown(){
		if(tag==0)return;
		ls->maketag(tag);
		rs->maketag(tag);
		tag=0;
	}
	inline void maketag(ll w){
		v+=(r-l+1)*w;
		tag+=w;
	}
	inline int getmin(const int L,const int R){
		if(inrange(L,R))return minn;
		else if(outrange(L,R)){
			return INF;
		}
		return min(ls->getmin(L,R),rs->getmin(L,R));
	} 
	inline int getmax(const int L,const int R){
		if(inrange(L,R))return maxn;
		else if(outrange(L,R)){
			return -INF;
		}
		return max(ls->getmax(L,R),rs->getmax(L,R));
	}
	inline void upd(const int L,const int R,ll w){
		if(inrange(L,R))maketag(w);
		else if(!outrange(L,R)){
			pushdown();
			ls->upd(L,R,w);
			rs->upd(L,R,w);
			pushup();
		}
	}
	inline ll qry(const int L,const int R){
		if(inrange(L,R))return v;
		if(outrange(L,R))return 0;
		pushdown();
		return ls->qry(L,R)+rs->qry(L,R);
	}
	inline bool inrange(const int L,const int R){
		return (L<=l)&&(r<=R);
	}
	inline bool outrange(const int L,const int R){
		return (l>R)||(r<L);
	}
};
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	Segment *rot=new Segment(1,n);
	scanf("%d",&q);
	for(ll x,y;q;q--){
		scanf("%lld%lld",&x,&y);
		printf("%.4lf\n",(double)(rot->qry(x,y)-rot->getmin(x,y)-rot->getmax(x,y))/(y-x-1));
	}
	return 0;
}
