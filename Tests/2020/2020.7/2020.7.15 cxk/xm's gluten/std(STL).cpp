#include<cstdio>
#include<cstdlib>
#include<map>
#include<cmath>
#include<ctime>
#include<queue>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
#define ci cosnt int &
using namespace std;
const int maxn = 1000010;
int n, m, h, v;
ll ans, passgot, sumv, sumh;
struct build{
	int h, v;
	build(){}
	build(int h0, int v0) : h(h0), v(v0){};
};
bool operator < (build a, build b){
	return a.v > b.v;
}
priority_queue <build> q; 
int main(){

	scanf("%d%d",&n,&m);
	m++;
	for(int i = 1; i <= n; i++){
		scanf("%d%d",&h, &v);
		m--;
		passgot += v;
		q.push(build(h-1, v));
		sumh += h-1;
		sumv += 1ll*v*(h-1);		
		while(q.size() && sumh - q.top().h >= m){
			sumh -= q.top().h;
			
			sumv -= q.top().v * q.top().h * 1ll;
			q.pop();
		}
/*		if(sumh >= m){
			ans = max(ans, sumv - (sumh - m) * q.top().v + passgot);
			cout << "*" << sumv << endl;
		}
		else ans = sumv + passgot;
		cout << ans << endl;
*/
		ans = max(ans, sumh >= m ? sumv - (sumh - m) * q.top().v + passgot : sumv + passgot);
		if(m <= 0)	break;
	}
	printf("%lld\n",ans);
	return 0;
}

