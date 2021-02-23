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
int n, m, k, ans(0), A, B, C, l(0), r(0), mid, Ma;
bool flg;
char ch;
string s;
struct Node;
struct Edge {
	Node *To;
	Edge *Nxt;
	int Len;
}E[20005], *cnte(E);
struct Node {
	Edge *Fst;
	int Dis;
	bool Vsd;
}N[1005];
inline int In() {
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
void Add (Node *x, Node *y, int z) {
	cnte->To = y;
	cnte->Nxt = x->Fst;
	x->Fst = cnte;
	cnte->Len = z;
	cnte++;
	return;
}
bool Judge (int x) {
	priority_queue <pair <int, int> > q;
	q.push(make_pair(0, 1));
	Edge *sid;
	Node *now, *son;
	while (q.size()) {
		now = N + q.top().second;
		q.pop();
		sid = now->Fst;
		while (sid) {
			son = sid->To;
			if (sid->Len > x) {
				if (son->Dis > now->Dis + 1) {
					son->Dis = now->Dis + 1;
					q.push(make_pair(-son->Dis, son - N));
				}
			}
			else {
				if (son->Dis > now->Dis) {
					son->Dis = now->Dis;
					q.push(make_pair(-son->Dis, son - N));
				}
				}
			sid = sid->Nxt;
	}
	}
	if (N[n].Dis <= k) {
		return 1;
	}
	return 0;
}
int main() {
  // freopen("P1948_7.in","r",stdin);
  // freopen(".out","w",stdout);
  n = In();
  m = In();
  k = In();
  for (register int i(1); i <= m; ++i) {
    A = In();
    B = In();
    C = In();
    Add (N + A, N + B, C);
    Add (N + B, N + A, C);
		r = max(C, r);
  }
	N[1].Dis = 0;
	N[1].Vsd = 1;
	r++;
	Ma = r;
  while (l < r) {
  	for (register int i(2); i <= n; ++i) {
  		N[i].Vsd = 0;
  		N[i].Dis = 0x3fffffff;
		}
		mid = (l + r) >> 1;
		flg = Judge(mid);
		//printf("Judge %d %d\n", mid, (int)flg);
  	if(flg) {
  		r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	if (r == Ma) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n", l);
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

