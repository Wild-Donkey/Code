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
ll gcd(ll a, ll b){
	return b?gcd(b,a%b):a;
}
const int maxn = 1000010;
int n, s, a[1010], sp[2000010], wa, maxhi, ans, preans;
ll sum[2000010], SP;
int main(){
//	freopen("B.in", "r", stdin);
	freopen("B.in", "r", stdin);
	freopen("B.ans", "w", stdout); 
	n=rd(); s=rd();
//	printf("n=%d s=%d\n", n, s);
	for(int i=1;i<=n;++i){
		a[i]=rd();
		sp[1]++; sp[a[i]+1]--;
//		for(int j=1;j<=a[i];++j) sp[j]++;
		maxhi=max(maxhi, a[i]);
	}
//	cout<<"Over Cin\n";
	a[0]=inf; a[n+1]=inf;
	for(int i=1;i<=n;++i)	if(a[i]>=a[i-1]&&a[i]<=a[i+1]) wa=i;
	SP=sp[0];
//	SP=0;
	for(int i=1;i<=maxhi&&sum[i]<=s;++i){
		SP+=sp[i];
		sum[i]=sum[i-1]+n-SP;
//		printf("i=%d SP=%d sum=%d\n", i, SP, sum[i]);
	}
	if(sum[maxhi]<=s){
		preans=s-sum[maxhi]; preans/=n;
		ll fenzi=s-sum[maxhi]-preans*n, fenmu=n;
		ll g=gcd(fenzi, fenmu); fenzi/=g; fenmu/=g;
		printf("%d+%lld/%lld\n", preans+maxhi, fenzi, fenmu);
		exit(0);
	}
	while(sum[maxhi]<=s){sum[maxhi+1]=sum[maxhi]+n; maxhi++;/*printf("i=%d sum=%lld\n", maxhi, sum[maxhi]);*/}
//	printf("maxhigh=%d wa=%d\n", maxhi, wa);
//	for(int i=1;i<=maxhi;++i) printf("%d ", sp[i]); printf("\n");
//	for(int i=1;i<=maxhi;++i) printf("%lld ", sum[i]); printf("\n");
	int l=0, r=maxhi;
	while(l<r){
		
		int mid=(l+r)>>1;
//		cout<<l<<" "<<mid<<" "<<r<<endl;
		if(sum[mid]<=s && sum[mid+1]>=s){
			ans=mid; break;
		}
		else if(sum[mid]<s) l=mid;
		else if(sum[mid]>s) r=mid;
	}
	if(sum[ans]==s){
//		printf("sum[%d]=%lld\n", ans, sum[ans]);
		printf("%d\n", ans); exit(0);
	}
	if(sum[ans+1]==s){
//		printf("sum[%d]=%lld\n", ans+1, sum[ans+1]);
		printf("%d\n", ans+1); exit(0);
	}
//	printf("sum[%d]=%lld\n", ans, sum[ans]);
//	printf("s=%d-%d=%d\n", s, sum[ans], s-sum[ans]);
	if(ans!=0) printf("%d+", ans);
//	SP=0;
	SP=sp[0];
	for(int i=1;i<=ans+1;++i) SP+=sp[i];
	ll fenzi=s-sum[ans], fenmu=n-SP;
//	printf("rest=%d space=%d\n", fenzi, n-SP);
	ll g=gcd(fenzi, fenmu);
	fenzi/=g; fenmu/=g;
	printf("%lld/%lld\n", fenzi, fenmu);
	return 0;
}
