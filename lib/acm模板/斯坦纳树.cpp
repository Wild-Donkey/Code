//n���㣬m���ߵ�����ͼ,k������㣬�ʰ����е�����㶼�������ı�Ȩ��С�Ƕ���
//n<=100,m<=n*(n-1)/2,k<=10 
#include<bits/stdc++.h>
using namespace std;
int dp[110][1030];
int n,m,k,h,t;
int fir[110],q[10010],cnt,d[110],g[110];
bool f[110],vst[110];
struct edge{
	int to,nxt,val;
}e[10010];
void insert(int u,int v,int w){
	e[++cnt].to = v;e[cnt].nxt = fir[u];fir[u] = cnt;e[cnt].val = w;
	e[++cnt].to = u;e[cnt].nxt = fir[v];fir[v] = cnt;e[cnt].val = w;
} 
int main(){
	int i,j,l,u,v,w;
	cin>>n>>m>>k;
	for(i = 1;i <= m;++i) {
		cin>>u>>v>>w;
		insert(u,v,w);
	}
	for(i = 1;i <= k;++i){
		cin>>u;
		f[u] = 1;//������ǲ�������� 
		g[u] = i - 1;//������ǵڼ�������0��ʼ������� 
	}
	memset(dp,0x3f,sizeof(dp));
	for(i = 1;i <= n;++i){
		if(f[i]) dp[i][1 << g[i]] = 0;
	}
	for(j = 0;j < (1 << k);++j){
		for(i = 1;i <= n;++i){
			for(l = j - 1 & j;l;l = l - 1 & j){//ö���Ӽ� 
				dp[i][j] = min(dp[i][j],dp[i][l] + dp[l][j]);//��һ��ת�� 
			}
		}
		for(i = 1;i <= n;++i) {
			d[i] = dp[i][j];//spfa�õ�dis���� 
			q[i] = i;//spfa�Ķ��� 
			vst[i] = 1;
		}
		h = 1;
		t = n;
		while(h <= t){
			++h;
			vst[q[h]] = 0;
			for(l = fir[q[h]];l;l = e[l].nxt){
				if(d[e[l].to] > d[q[h]] + e[l].val){
					d[e[l].to] = d[q[h]] + e[l].val;
					if(!vst[e[l].to]){
						vst[e[l].to] = 1;
						q[++t] = e[l].to;
					}
				}
			}
		}
		//�ڶ���ת�ƣ�ͨ����spfaʵ�� 
		for(i = 1;i <= n;++i) dp[i][j] = d[i];
	}
	int ans = 987654321;
	for(i = 1;i <= n;++i) ans = min(ans,dp[i][(1 << k) - 1]);
	cout<<ans;
	return 0;
} 
