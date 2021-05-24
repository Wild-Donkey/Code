#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
#define ll int
#define ld long double
#define isdigit(x) ((x)>='0'&&(x)<='9')
using namespace std;

inline ll read()
{
	ll x=0;
	char ch=getchar();
	while(!isdigit(ch))
	{
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	}
	return x;
}

const ll maxn=2e5+10;
const ll maxv=1e6+10;
ll n,m,ask,block,tot,pos,cntt,cntq,tim=0,siz,l=1,r=0;
ll v[maxn],w[maxn],c[maxn],vis[maxn],dep[maxn],head[maxn],belong[maxn],first[maxn],last[maxn];
ll ouler[maxn],fa[maxn][24];
ll cnt[maxn];
long long now,ans[maxn];
struct node
{
	ll v,nxt;
} s[maxn];
struct update
{
	ll pos,val;
} upd[maxn];
struct query
{
	ll l,r,id,tim,lcaa;
} q[maxn];

int cmp(query a, query b) {
    return (belong[a.l] ^ belong[b.l]) ? belong[a.l] < belong[b.l] : ((belong[a.r] ^ belong[b.r]) ? belong[a.r] < belong[b.r] : a.tim < b.tim );
}

inline void add_edge(ll u,ll v)
{
	s[++tot]=(node){v,head[u]};
	head[u]=tot;
	s[++tot]=(node){u,head[v]};
	head[v]=tot;
}

void dfs(ll x)
{
	ouler[++pos]=x;
	first[x]=pos;
	
	for(int i=head[x];i;i=s[i].nxt)
	{
		ll v=s[i].v;
		
		if(dep[v]) continue;
		
		dep[v]=dep[x]+1;
		fa[v][0]=x;
		for(int i=1;(1<<i)<=dep[v];++i) fa[v][i]=fa[fa[v][i-1]][i-1];
		
		dfs(v);
	}
	
	ouler[++pos]=x;
	last[x]=pos;
}

inline ll LCA(ll x,ll y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i+1;--i)
	{
		if(dep[fa[x][i]]>=dep[y])
		{
			x=fa[x][i];
		}
	}
	if(x==y) return x;
	for(int i=20;i+1;--i)
	{
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i],y=fa[y][i];
		}
	}
	return fa[x][0];
}

inline void add(ll x)
{
	now+=1ll*v[c[x]]*w[++cnt[c[x]]];
}

inline void del(ll x)
{
	now-=1ll*v[c[x]]*w[cnt[c[x]]--];
}

inline void work(ll pos)
{
	vis[pos] ? del(pos) : add(pos),	vis[pos]^=1;
}

inline void change(ll t)
{
	if(vis[upd[t].pos])
	{
		work(upd[t].pos), swap(upd[t].val,c[upd[t].pos]), work(upd[t].pos);
	}
	else swap(upd[t].val,c[upd[t].pos]);
}

int main(void)
{
  freopen("P4074_4.in", "r", stdin);
	
	n=read(), m=read(), ask=read();
	
	for(register int i=1;i<=m;i++) v[i]=read();
	for(register int i=1;i<=n;i++) w[i]=read();
	for(register int i=1;i<n;i++)
	{
		ll u=read(),v=read();
		add_edge(u,v);
	}
	for(register int i=1;i<=n;i++) c[i]=read();
	
	dep[1]=1;
	dfs(1);
	

	
	for(register int i=1;i<=ask;i++)
	{
		ll op=read(),u=read(),v=read();
		
		if(!op)
		{
			upd[++cntt].pos=u;
			upd[cntt].val=v;
		}
		if(op)
		{
			++cntq;
			ll lcaa=LCA(u,v);
			q[cntq].id=cntq, q[cntq].tim=cntt;
			if(first[u]>first[v]) swap(u,v);
			if(lcaa==u) q[cntq].l=first[u], q[cntq].r=first[v];
			else q[cntq].l=last[u], q[cntq].r=first[v], q[cntq].lcaa=lcaa;
		}
	}
	block = (pow(((unsigned long long)n * n * (cntt + 1) / (cntq + 1)), 1.0/3.0) * 3.5) + 1;
	printf("%u %u %u blocklen %u\n", n, cntt, cntq, block);
//	block = pow(pos,2.0/3.0);
//	printf("blocklen %u\n", block);
	siz=ceil((double)(pos/block));
  freopen("my.out", "w", stdout);
	for(register int i=1;i<=siz; ++i)
	{
		register ll B=i*block;
		for(int j((i-1)*block+1);j<=B;++j)
		{
			belong[j]=i;
		}
	}
	sort(q+1,q+cntq+1,cmp);
	
	for(register int i=1;i<=cntq;i++)
	{
		ll ql=q[i].l,qr=q[i].r,qlca=q[i].lcaa,qt=q[i].tim;
		
		while(l<ql) work(ouler[l++]);
		while(l>ql) work(ouler[--l]);
		while(r<qr) work(ouler[++r]);
		while(r>qr) work(ouler[r--]);
		while(tim<qt) change(++tim);
		while(tim>qt) change(tim--);
		
		if(qlca) work(qlca);
		
		ans[q[i].id]=now;
	
//		printf("%lld\n",now);
		
		if(qlca) work(qlca);
	}
	
	for(int i=1;i<=cntq;i++)
	{
		printf("%lld\n",ans[i]);
	}
	
	return 0;
}
