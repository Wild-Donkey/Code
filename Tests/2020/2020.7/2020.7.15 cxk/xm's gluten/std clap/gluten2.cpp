#include<cmath>
#include<ctime> 
#include<queue>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1000010;
long long n, m, tim, sumv, sumh, ans, ans0, passgot;
struct build{
	long long h, v, id;
	build(){h = 0; v = 0; id = 0;}
}bd[maxn]; 
bool operator < (build a, build b){
	return a.v > b.v;//小根堆 
}
priority_queue<build> q;

/*
bool cmp(build a, build b){
	return a.v > b.v;
}*/
int main(){
//  double TIme = clock() * -(1.0);
	freopen("gluten5.in","r",stdin);
	freopen("mine.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++){
		scanf("%d%d",&bd[i].h,&bd[i].v);
		if(bd[i].h!=0)
			bd[i].h --;
		bd[i].id = i;
	}
	for(int end = 1; end <= n; end++){
		passgot+=bd[end].v;//路过单独计算贡献 
	    q.push(bd[end]);
	    sumv += bd[end].v * bd[end].h;
	    sumh += bd[end].h;
		tim = m - end + 1;//因为每一栋楼都要经过，所以将（end-1)的时间排除 
		build Now;
		Now.id = 0;
	    while(sumh - q.top().h >= tim && q.size()){
	       Now = q.top();
	       q.pop();
	       sumv -= Now.v * Now.h;
	       sumh -= Now.h; 
	    }
//	    if(Now.id != 0)//保证总层数大于拥有的时间，堆曾经出现过向外弹出的操作 
			ans0 = passgot + sumv - Now.v * (sumh - tim);
//		else ans0 = passgot + sumv;
		ans = max(ans, ans0); 
//		cout << ans0 << endl;
	}
	printf("%lld\n",ans);
//	cout << clock() << endl;
	return 0;
}
/*
3 3
2 1
1 5
3 4

end = 1  tim = 3  sumv = 2  sumh = 1  no pop  ans0 = sumv = 2
*/
