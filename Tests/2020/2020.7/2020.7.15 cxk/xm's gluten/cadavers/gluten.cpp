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
const int maxn = 100010;
int n, m, tim, usedti;
long long ans, ans0;
struct build{
	int h, v, id;
}bd[maxn]; 
bool operator < (build a, build b){
	return a.v < b.v;
}
priority_queue<build> q;
/*
bool cmp(build a, build b){
	return a.v > b.v;
}*/
int main(){
//  double TIme = clock() * -(1.0);
	freopen("gluten7.in","r",stdin);
	freopen("gluten7.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++){
		scanf("%d%d",&bd[i].h,&bd[i].v);
		bd[i].id = i;
		bd[i].h --;
	}
	for(int end = 1; end <= n; end++){
		for(int i = 1; i <= end; i++)	q.push(bd[i]);
		ans0 = 0;
		tim = m - end + 1;
		usedti = 0;
		for(int i = 1; i <= end; i++)		ans0 += bd[i].v;
//		sort(bd + 1, bd + 1 + end, cmp);
		for(int i = 1; i <= end; i++){
			int id = q.top().id;
			q.pop();
			if(usedti + bd[id].h <= tim){
				ans0 += bd[id].h * bd[id].v;
				usedti += bd[id].h; 
			}		
			else{
				ans0 += bd[id].v * (tim - usedti);
				usedti = tim;
			} 
		}
//		cout << end << " " << ans0 << endl;
		ans = max(ans, ans0); 
	}
	printf("%d\n",ans);
	cout << clock() << endl;
	return 0;
}
