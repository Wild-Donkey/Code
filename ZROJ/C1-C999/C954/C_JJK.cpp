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
#define fi first
#define se second
#define il inline
#define ui unsigned
#define Mod 998244353
#define inf 0x3fffffff
#define ri register int
#define pi pair<int,int>
#define mp(a,b) make_pair(a, b)
using namespace std;
typedef long long ll;
double pw10[55];
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
const int maxn = 100010;
int n, m, fst[maxn], en, ind[maxn], otd[maxn], S = 0;
queue<int> q;
struct InEdge{
	int u, v;
	const inline bool operator < (const InEdge X) const{
		return (X.u ^ this->u) ? (this->u < X.u) : (this->v < X.v);
	}
}IE[maxn << 2]; 
struct Edge{
	int to, nxt;
}ed[maxn << 2];
void add(int u, int v){
	ed[++en].to=v;
	ed[en].nxt=fst[u];
	fst[u]=en;
	ind[v]++; otd[u]++;
}
int stk[maxn], top;
bool InStk[maxn];
set<int> ZeroInd;
unsigned long long dfs(int u, int rk){
	if(rk == 3){
		return 1;
	}
	stk[++top]=u;
	InStk[u] = 1;
	unsigned long long res=0; int v;
	for(ri e=fst[u];e;e=ed[e].nxt){
		v=ed[e].to;
		ind[v]--;
		if(ind[v]==0){
			ZeroInd.insert(v); 
		} 
	}
	set<int>::iterator it = ZeroInd.begin();
	it=ZeroInd.begin();
	for(; it != ZeroInd.end(); ++it){
		v=*it;
		if(!InStk[v])
			res += dfs(v, rk + 1);
	}
	top--;
	InStk[u] = 0;
	for(ri e=fst[u];e;e=ed[e].nxt){
		ind[ed[e].to]++;
		if(ind[ed[e].to] == 1) ZeroInd.erase(ed[e].to); 
	}
	return res;
}
int main(){
	freopen("C.in", "r", stdin);
	freopen("C.ans", "w", stdout);
	int u, v;
	n=rd(); m=rd();
	if(m==0){
		printf("%lld\n", 1ll * n * (n - 1) * (n - 2)); return 0;
	}
	for(ri i=1;i<=m;++i){
		IE[i].u=rd(); IE[i].v=rd();
	}
	sort(IE + 1, IE + 1 + m);
	for(ri i=1;i<=m;++i){
		if((IE[i].u ^ IE[i-1].u) || (IE[i].v ^ IE[i-1].v)){
			add(IE[i].u, IE[i].v);
		}
	}
	for(ri i=1;i<=n;++i){
		if(ind[i] == 0){
			add(S, i);
		}
	}
	ZeroInd.insert(0); 
	printf("%llu\n", dfs(0, 0));
	return 0;
}

