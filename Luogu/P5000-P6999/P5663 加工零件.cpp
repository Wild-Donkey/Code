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
int t, n, q, m, a[100005], ans = 0, A, B;
bool flg;
char ch;
string s;
struct Node;
struct Edge {
	Node *ed;
	Edge *nxt;
}E[1000005], *cnte = E;
struct Node {
	int dst1, dst0;
	Edge *fst;
	int vsd;
	Node () {
		dst1 = 0x3f3f3f3f, dst0 = 0x3f3f3f3f;
		vsd = 0;
		fst = NULL;
	}
}N[100005];
queue<Node*> que;
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
void Bfs () {
	que.push(N + 1);
	N[1].dst0 = 0;
	Node *now;
	Edge *sid;
	while (que.size()) {
		now = que.front();
		//printf("%d\n", now - N); 
		que.pop();
		/*if(now->vsd >= 10){
			continue;
		}*/
		//now->vsd++;
		sid = now->fst;
		while (sid) {
			flg = 0;
			if (sid->ed->dst0 > now->dst1 + 1) {
				sid->ed->dst0 = now->dst1 + 1;
				flg = 1;
			}
			if (sid->ed->dst1 > now->dst0 + 1) {
				sid->ed->dst1 = now->dst0 + 1;
				flg = 1;
			}
			if(flg) {
				que.push(sid->ed);
			}
			sid = sid->nxt;
		}
	}
	return;
}
bool Find (int x, int y) {
	//y -= 1;
	//printf("Find %d %d %d %d\n", x, y, N[x].dst1, N[x].dst0);
	if (y % 2) {
		if (N[x].dst1 <= y) {
			return 1;
		}
		return 0;
	}
	else {
		if (N[x].dst0 <= y) {
			return 1;
		}
		return 0;
	}
}
void Add (int x, int y) {
	cnte->ed = &N[y];
	cnte->nxt = N[x].fst;
	N[x].fst = cnte;
	cnte++;
	return;
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  n = IN();
  m = IN();
  q = IN();
	for (register int i(1); i <= m; ++i) {
    	A = IN();
    	B = IN();
		Add(A, B);
		Add(B, A);
	}
	Bfs();
	for (int i(1); i <= n; ++i) {
		//printf("%d %d\n", N[i].dst0, N[i].dst1); 
	}
    for (register int i(1); i <= q; ++i) {
    	A = IN();
    	B = IN();
    	if (Find (A, B)) {
			printf("Yes\n"); 
		}
		else {
			printf("No\n"); 
		}
    }
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
/*
5 5 5
1 2
2 3
3 4
4 5
1 5
1 1
1 2
1 3
1 4
1 5
*/
