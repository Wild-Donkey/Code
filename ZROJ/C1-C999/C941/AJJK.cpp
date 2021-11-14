#include<map>
#include<set>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#define il inline
#define mod 998244353
#define inf 0x3fffffff
#define pi pair<int,int>
#define mp(a,b) make_pair(a, b)
#define fi first
#define se second
using namespace std;
typedef long long ll;
int rd(){
	int res = 0, fl = 1;
   char c = getchar();
   while(!isdigit(c)){
       if(c == '-') fl = -1;
       c = getchar();
   }
   while(isdigit(c)){
      res = (res << 3) + (res << 1) + c - '0';
      c = getchar();
   }
   return res * fl;
}

const int maxn = 1000010;
int n, m, fst[maxn], en, dis[maxn], frm[maxn], To[maxn], Wt[maxn], tot, Udis[maxn];
struct Edge{
	int to, nxt, w;
}ed[maxn];
void add(int u, int v, int w){
	ed[++en].to=v;
	ed[en].w=w;
	ed[en].nxt = fst[u];
	fst[u]=en;
}
priority_queue<pi> q;
bool vis[maxn];
void dij(int S, int ds[]){
	for(int i=1;i<=n;++i) ds[i]=0x3fffffff;
//	memset(ds, 0x3f, sizeof(ds));
	memset(vis, 0, sizeof(vis));
	ds[S]=0;
	vis[S]=1; q.push(make_pair(0, S));
	while(q.size()){
		int u=q.top().se; q.pop();
//		printf("u=%d ds[%d]=%d\n", u, u, ds[u]);
		for(int e=fst[u];e;e=ed[e].nxt){
			int v=ed[e].to;
			if(ds[v]>ds[u]+ed[e].w){
				ds[v]=ds[u]+ed[e].w;
				if(!vis[v]){
					vis[v]=1;
					q.push(make_pair(-ds[v], v)); 
				}
			}
		} 
	} 
}
int main(){
  freopen("A.in", "r", stdin);
  freopen("A.ans", "w", stdout);
	n=rd(); m=rd();
	for(int i=1;i<=m;++i){
		frm[++tot]=rd(); To[tot]=rd(); Wt[tot]=rd();
//		frm[tot+1]=To[tot]; To[tot+1]=frm[tot]; Wt[tot+1]=Wt[tot]; tot++;
		add(frm[tot], To[tot], Wt[tot]);
		add(To[tot], frm[tot], Wt[tot]); 
	}
//	printf("Over cin\n");
//	for(int i=1;i<=en;++i) printf("ed[%d].w=%d\n", i, ed[i].w);
	dij(1, dis); 
//	printf("Over dij1\n");
//	for(int i=1;i<=n;++i) printf("%d ", dis[i]); printf("\n");
	dij(n, Udis); 
//	printf("Over dij2\n");
//	for(int i=1;i<=n;++i) printf("%d ", Udis[i]); printf("\n");
	for(int i=1;i<=n;++i){
		printf("%d\n", dis[i]+Udis[i]);
	}
	for(int i=1;i<=m;++i){
		printf("%d\n", min(dis[frm[i]]+Udis[To[i]]+Wt[i], dis[To[i]]+Udis[frm[i]]+Wt[i]));
	}
	return 0;
}


