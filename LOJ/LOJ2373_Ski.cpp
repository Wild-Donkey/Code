#include<bits/stdc++.h>
#define N 1000010
#define INF 0x3f3f3f
using namespace std;
inline void read(int &x){
	x=0;int f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='0')
		f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	x*=f;
}
inline void write(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)
	write(x/10);
	putchar(x%10+'0');
}
long long ans(0);
int tot, fa[100005], Stack[100005], STop(0);
int h[100005], head[100005], sum(0);
bitset<100005> vis;
struct edge{
	int from, to, next, val;
	inline const char operator< (const edge& x) const{return (h[to] ^ h[x.to]) ? (h[to] > h[x.to]) : (val < x.val);}
}e[N << 1], e1[N << 1];
inline void add(int u,int v,int w){
	e[++tot].to=v;
	e[tot].from=u;
	e[tot].next=head[u];
	head[u]=tot;
	e[tot].val=w;
}

inline int find(int x){
  while (x ^ fa[x]) Stack[++STop] = x, x = fa[x];
  while (STop) fa[Stack[STop--]] = x;
  return x;
}

inline void dfs(int u){
  ++sum;
	for(int i=head[u];i;i=e[i].next){
		if(h[u] >= h[e[i].to]) e1[++tot] = e[i];
		int v(e[i].to);
		if(!vis[v]) vis[v]=1, dfs(v);
	}
}

inline void kruskal(){
	sort(e1+1,e1+tot+1);
	for(int i=1;i<=tot;i++){
		int x=find(e1[i].from),y=find(e1[i].to);
//		printf("Link %u %u %u\n", x, y, e1[i].val);
    if(x!=y){
			fa[y]=x;
			ans+=e1[i].val;
		}
	}
	return ;
}

signed main(){
	int n,m;
	read(n);read(m);
	for(int i=1;i<=n;i++)fa[i]=i,read(h[i]);
	for(int i=1;i<=m;i++){
		int u,v,w;
		read(u);read(v);read(w);
		if(h[u]>=h[v])add(u,v,w);
		if(h[u]<=h[v])add(v,u,w);
	}
	vis[1]=1, tot = 0, dfs(1);
//	if(h[1] == 180285) printf("tot %u\n", tot);
	kruskal();
	write(sum);putchar(' ');
	write(ans);putchar('\n');
	return 0;
}
