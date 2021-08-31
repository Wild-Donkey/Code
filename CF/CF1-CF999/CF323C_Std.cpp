#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

const int N=1598244;

int n,m,ndn,las;
struct point{
	int x,y;
	bool operator < (const point &b) const {
		return x==b.x?y<b.y:x<b.x;
	}
}p[N];
struct Tree{
	int sum,ls,rs,rt;
}t[N<<4];
inline int gi(){
	char c=getchar();int s=0,f=1;
	while(c>'9'||c<'0'){
		if(c=='-') f=-f;
		c=getchar();
	}
	while(c<='9'&&c>='0') s=(s<<3)+(s<<1)+(c-'0'),c=getchar();
	return s*f;
}
inline void ins(int &now,const int l,const int r,const int pl){
	t[++ndn]=t[now];t[now=ndn].sum++;
	if(l==r) return ;
	int mid=(l+r)>>1;
	if(pl<=mid) ins(t[now].ls,l,mid,pl);
	else ins(t[now].rs,mid+1,r,pl);
}
inline int que(const int now,const int l,const int r,const int ql,const int qr){
	if(ql<=l&&r<=qr) return t[now].sum;
	int mid=(l+r)>>1,sum=0;
	if(ql<=mid) sum+=que(t[now].ls,l,mid,ql,qr);
	if(qr>mid) sum+=que(t[now].rs,mid+1,r,ql,qr);
	return sum;
}
inline int f(const int z){
	return (z-1+las)%n+1;
}
using std::min;
using std::max;
signed main(){
	std::ios::sync_with_stdio(0);
	n=gi();
	int val;
	for(int i=1;i<=n;i++) val=gi(),p[val].x=i;
	for(int i=1;i<=n;i++) val=gi(),p[val].y=i;
	std::sort(p+1,p+n+1);
	for(int i=1;i<=n;i++){
		ins(t[i].rt=t[i-1].rt,1,n,p[i].y);
	}
	int l1,r1,l2,r2,ans,a,b,c,d;
	m=gi();
	
	while(m--){
		a=gi(),b=gi(),c=gi(),d=gi();
		l1=min(f(a),f(b));
		r1=max(f(a),f(b));
		l2=min(f(c),f(d));
		r2=max(f(c),f(d));
		if(n == 1000000)printf("%u %u %u %u\n", a, b, c, d);
		las=que(t[r1].rt,1,n,l2,r2)-que(t[l1-1].rt,1,n,l2,r2);
		printf("%d\n",las);
		las++;
	}
}
