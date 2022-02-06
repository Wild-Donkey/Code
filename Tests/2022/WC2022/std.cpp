#include <bits/stdc++.h>
using namespace std ;
#define int long long
#define rep(i, a, b) for (ll i = (a); i <= (b); ++i)
#define per(i, a, b) for (ll i = (a); i >= (b); --i)
#define loop(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define cont(i, x) for (ll i = head[x]; i; i = edge[i].nex)
#define clr(a) memset(a, 0, sizeof(a))
#define ass(a, cnt) memset(a, cnt, sizeof(a))
#define cop(a, b) memcpy(a, b, sizeof(a))
#define lowbit(x) (x & -x)
#define all(x) x.begin(), x.end()
#define SC(t, x) static_cast <t> (x)
#define ub upper_bound
#define lb lower_bound
#define pqueue priority_queue
#define make_pair make_pair
#define push_back push_back
#define pof pop_front
#define pob pop_back
#define fi first
#define se second
#define y1 y1_
#define Pi acos(-1.0)
#define iv inline void
#define enter putchar('\n')
#define siz(x) ((ll)x.size())
#define file(x) freopen(x".in", "r", stdin),freopen(x".out", "w", stdout)
typedef double db ;
typedef long long ll ;
typedef unsigned long long ull ;
typedef pair <ll, ll> pii ;
typedef vector <ll> vi ;
typedef vector <pii> vii ;
typedef queue <ll> qi ;
typedef queue <pii> qii ;
typedef set <ll> si ;
typedef map <ll, ll> mii ;
typedef map <string, ll> msi ;
const ll maxn = 2e6 + 100 ;
const ll inf = 0x3f3f3f3f ;
const ll iinf = 1 << 30 ;
const ll linf = 2e18 ;
const ll mod = 998244353 ;
const double eps = 1e-7 ;
template <class T = ll> T chmin(T &a, T b) { return a = min(a, b);}
template <class T = ll> T chmax(T &a, T b) { return a = max(a, b);}
template <class T = ll> iv red(T &x) { x -= mod, x += x >> 31 & mod;}
template <class T = ll> T read()
{
	T f = 1, a = 0;
	char ch = getchar() ;
	while (!isdigit(ch)) { if (ch == '-') f = -1 ; ch = getchar() ; }
	while (isdigit(ch)) { a =  (a << 3) + (a << 1) + ch - '0' ; ch = getchar() ; }
	return a * f ;
}

ll n, m;

ll a[maxn], b[maxn];

ll Len, Posi[maxn], ans[maxn];

struct foo
{
	ll nex[maxn], pre[maxn], vis[maxn], ans;
	ll stk[maxn], tot, tnex[maxn], tpre[maxn];
	void init(ll l, ll r)
	{
		rep(i, 1, n) nex[i] = pre[i] = vis[i] = 0;
		ans = tot = 0;
		rep(i, l, r) vis[a[i]] = 1;
		ll last = 0;
		rep(i, 1, n)
		{
			if(!vis[i]) continue;
			if(last) nex[last] = i, pre[i] = last, ans += abs(b[last] - b[i]);
			last = i;
		}
	}
	void del(ll k)
	{
		// printf("del : %lld\n", k);
		assert(vis[k]);
		vis[k] = 0;
		stk[++ tot] = k;
		tpre[tot] = pre[k];
		tnex[tot] = nex[k];
		if(pre[k]) ans -= abs(b[pre[k]] - b[k]);
		if(nex[k]) ans -= abs(b[nex[k]] - b[k]);
		if(pre[k] && nex[k]) ans += abs(b[pre[k]] - b[nex[k]]);
		nex[pre[k]] = nex[k], pre[nex[k]] = pre[k];
	}
	void recall()
	{
		ll k = stk[tot];
		// printf("recall : %lld\n", k);
		vis[k] = 1;
		pre[k] = tpre[tot], nex[k] = tnex[tot];
		tot --;
		nex[pre[k]] = pre[nex[k]] = k;
		if(pre[k]) ans += abs(b[pre[k]] - b[k]);
		if(nex[k]) ans += abs(b[nex[k]] - b[k]);
		if(pre[k] && nex[k]) ans -= abs(b[pre[k]] - b[nex[k]]);
	}
	void all_recall()
	{
		while(tot) recall();
	}
	void print()
	{
		printf("now : %lld\n", ans);
		rep(i, 1, n)
		{
			if(!vis[i]) continue;
			printf("%lld : %lld %lld\n", i, pre[i], nex[i]);
		}
	}
}
penis;

vector<pair<pii,ll> > q1[maxn],q2[maxn];

void work1(){
	rep(k,1,Posi[n]){
		ll l=(k-1)*Len+1,r=min(n,k*Len);
		penis.init(l,r);
		for(auto i:q1[k]){
			ll tl=l,tr=r;
			while(tl<i.fi.fi) penis.del(a[tl++]);
			while(tr>i.fi.se) penis.del(a[tr--]);
			ans[i.se]=penis.ans;
			// penis.print();
			penis.all_recall();
		}
	}
}

void work2(){
	rep(k,1,Posi[n]-1){
		ll l=(k-1)*Len+1,r=n;
		penis.init(l,r);
		sort(all(q2[k]),[](pair<pii, ll>a,pair<pii,ll>b){
			return a.fi.se>b.fi.se;
		});
		for(auto i:q2[k]){
			while(r>i.fi.se) penis.del(a[r--]);
			penis.tot=0;
			ll tl=l;
			while(tl<i.fi.fi) penis.del(a[tl++]);
			ans[i.se]=penis.ans;
			penis.all_recall();
		}
	}
}

signed main(){
	read(n);read(m);
	Len=sqrt(n)+1;
	for(int i=1;i<=n;i++) read(a[i]),b[a[i]]=i;
	for(int i=1;i<=n;i++) Posi[i]=(i-1)/Len+1;
	for(int i=1;i<=m;i++){
		ll l,r;read(l);read(r);
		if(Posi[l]==Posi[r]) q1[Posi[l]].push_back(make_pair(make_pair(l,r),i));
		else q2[Posi[l]].push_back(make_pair(make_pair(l,r),i));
	}
	work1();work2();
	for(int i=1;i<=m;i++) printf("%lld\n",ans[i]);
	return 0;
}