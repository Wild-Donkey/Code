#include <bits/stdc++.h>
#define ll(x) ((x)<<1)
#define rr(x) ((x)<<1|1)
using namespace std;

const int T=31,N=100010;
int n,t,m;
int laz[T][N<<2],sum[T][N<<2];

void pushup(int i,int x)
{
	sum[i][x]=sum[i][ll(x)]+sum[i][rr(x)];
}

void build(int i,int x,int l,int r)
{
	if (l==r) {
		sum[i][x]=1;
		return;
	}
	int mid=l+r>>1;
	build(i,ll(x),l,mid);
	build(i,rr(x),mid+1,r);
	pushup(i,x);
}

void pushdown(int i,int x)
{
	if (laz[i][x]==-1) {
		sum[i][ll(x)]=sum[i][rr(x)]=0;
		laz[i][ll(x)]=laz[i][rr(x)]=-1;
	}
	else {
		sum[i][ll(x)]=sum[i][rr(x)]=laz[i][x];
		laz[i][ll(x)]=laz[i][rr(x)]=laz[i][x];
	}
	laz[i][x]=0;
}

void change(int i,int x,int l,int r,int ls,int rs,int v)
{
	if (l>rs||r<ls) return;
	if (l>=ls&&r<=rs) {
		sum[i][x]=v;
		if (!v) laz[i][x]=-1;
		else laz[i][x]=v;
		return;
	}
	if (laz[i][x]) pushdown(i,x);
	int mid=l+r>>1;
	if (ls<=mid) change(i,ll(x),l,mid,ls,rs,v);
	if (rs>mid) change(i,rr(x),mid+1,r,ls,rs,v);
	pushup(i,x);
}

int ask(int i,int x,int l,int r,int ls,int rs)
{
	if (l>rs||r<ls) return 0;
	if (l>=ls&&r<=rs) return sum[i][x];
	if (laz[i][x]) pushdown(i,x);
	int mid=l+r>>1;
	return ask(i,ll(x),l,mid,ls,rs)+ask(i,rr(x),mid+1,r,ls,rs);
}

int main()
{
	cin>>n>>t>>m;
	build(1,1,1,n);
	char s[3];int l,r,v;
	for (int i=1;i<=m;++i) {
		scanf("%s%d%d",s,&l,&r);
		if (l>r) swap(l,r);
		if (s[0]=='C') {
			scanf("%d",&v);
			for (int k=1;k<=t;++k)
				if (k!=v)
					change(k,1,1,n,l,r,0);
				else change(k,1,1,n,l,r,1);
		}
		else {
			int ans=0;
			for (int k=1;k<=t;++k)
				if (ask(k,1,1,n,l,r))
					++ans;
			printf("%d\n",ans);
		}
	}
	return 0;
}
