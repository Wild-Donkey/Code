#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
int t, n, m, ans = 0, A, B, s, dis[100005];
bool vst[100005] = {0};
inline int IN() {
  char ich = getchar();
  int intmp = 0, insign = 1;
  while (((ich < '0') || (ich > '9')) && ((ich != '-'))) {
    ich = getchar();
  }
  if (ich == '-') {
    insign = -1;
    ich = getchar();
  }
  while ((ich <= '9') && (ich >= '0')) {
    intmp *= 10;
    intmp += ich - '0';
    ich = getchar();
  }
  return intmp * insign;
}
struct Edge;
priority_queue <pair <int, int> > q;
struct Edge {
	int val;
	Edge *nxt;
	int to;
}E[500005], *cnte = E, *fir[100005] = {NULL};
inline void Cnct (int x, int y, int z) {
	cnte->to = y;
	cnte->val = -z;
	cnte->nxt = fir[x];
	fir[x] = cnte;
	cnte++;
}
inline void Dijkstra (int x) {
	dis[x] = 0;
	q.push(make_pair(dis[x],x));
	//Node now = q.top();
	int di, now; 
	while (!q.empty()) {
		now = q.top().second;
		di = q.top().first;
		q.pop();
		if(vst[now]) {
			continue;
		}
		vst[now] = 1;
		//printf("%d now\n", now); 
		/*if(now->vist) {
			q;
		}*/
		int xx;
		for(register Edge *i = fir[now]; i; i = i->nxt) {
			xx = i->to;
			//printf("%d son\n", xx); 
			if(dis[xx] < di + i->val) {
				dis[xx] = di + i->val;
				q.push(make_pair(dis[xx], xx)); 
			}
		}
	}
	return;
}
int main() {
  //freopen("P3371_2.in", "r", stdin);
  //freopen("A1.out", "w", stdout);
    n = IN();
    m = IN();
    s = IN();
    memset(E, 0, sizeof(E));
    for (register int i = 1; i <= m; i++) {
    	A = IN();
    	B = IN();
    	Cnct(A, B, IN());
    	//printf("faq\n"); 
    }
    for (register int i = 1; i <= n; i++) {
    	dis[i] = -0x7fffffff;
    }
    Dijkstra(s);
    for(register int i = 1; i <= n; i++) {
		printf("%d ", -dis[i]);
	}
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

