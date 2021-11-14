#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5,mod=1e9+7;
int T,n;
char s[N];
int sum[N];
ll ans[N];
vector<int> upd;
ll Mod(ll x){
	if(x>=mod) return x-mod;
	else if(x<0) return x+mod;
	else return x;
}
void solve(int st){
	for(int i=0;i<upd.size();i++){
		ll val1=i+1,val2=upd.size()-i;
		int fro=0;
		if(i==0) fro=st;
		else fro=upd[i-1]+1;
		ll val=val1*val2%mod;
		ans[fro]=Mod(ans[fro]+val);
		ans[upd[i]+1]=Mod(ans[upd[i]+1]-val);
	}
}
int Fro[N<<1],Nxt[N];
bool vis[N];
int main()
{
  freopen("B.in", "r", stdin);
//  freopen("B.ans", "w", stdout);
	scanf("%d",&T);
	while(T--){
		ll anss=0;
		scanf("%s",s+1);
		n=strlen(s+1);
		memset(ans,0,sizeof(ans));
		memset(Fro,-1,sizeof(Fro));
		memset(Nxt,-1,sizeof(Nxt));
		memset(vis,0,sizeof(vis));
		Fro[n]=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='(') sum[i]=sum[i-1]+1;
			else sum[i]=sum[i-1]-1;
			if(Fro[sum[i]+n]!=-1) Nxt[Fro[sum[i]+n]]=i;
			Fro[sum[i]+n]=i;
			if(Fro[sum[i]+n+1]!=-1){
				Nxt[Fro[sum[i]+n+1]]=-1;
				Fro[sum[i]+n+1]=-1;
			}
		}
		
		for(int i=1;i<=n;i++){
			if(vis[i-1]) continue;
			upd.clear();
			int j=i-1;
			while(Nxt[j]!=-1){
				j=Nxt[j];
				vis[j]=1;
				upd.push_back(j);
			}
			solve(i);
		}
		
		for(int i=1;i<=n;i++) ans[i]=Mod(ans[i]+ans[i-1]);
		
		for(int i=1;i<=n;i++) anss+=1ll*i*ans[i]%mod;
		printf("%lld\n",anss);
	}
	return 0;
}

