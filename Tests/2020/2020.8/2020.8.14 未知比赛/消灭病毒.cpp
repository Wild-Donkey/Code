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
int t, n, m, s, Do, A, B, ans(0), Fak(0);
bool flg;
priority_queue <pair<int, int> > q;
struct Node;
struct Edge {
	Edge *Nxt;
	Node *To;
}E[1000005], *cnte = E;
struct Node {
	Edge *Fst;
	bool Vsd;
	int Val;
}N[1000005];
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
void Add (Node *x, Node *y) {
	cnte->To = y;
	cnte->Nxt = x->Fst;
	x->Fst = cnte;
	++cnte;
	return;
}
void DFS (int now) {
	//printf("here %d\n", now);
	Edge *sid(N[now].Fst);
	Node *son;
	while (sid) {
		son = sid->To;
		sid = sid->Nxt;
		if (son->Vsd) {
			continue;
		}
		son->Vsd = 1;
		int backup(son->Val);
		if (son->Val == N[now].Val) {
			flg = 1;
			++Fak;
			return;
		}
		if (!son->Val) {
			son->Val = (N[now].Val % 2) + 1;
		}
		DFS (son - N);
		if(flg) {
			son->Val = backup;
			return;
		}
	}
	return;
}
void DFSForce (int now) {
	//printf("here %d\n", now);
	Edge *sid(N[now].Fst);
	Node *son;
	while (sid) {
		son = sid->To;
		sid = sid->Nxt;
		if (son->Vsd) {
			continue;
		}
		son->Vsd = 1;
		if (!son->Val) {
			son->Val = (N[now].Val % 2) + 1;
			DFSForce (son - N);
		}
	}
	return;
} 
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  n = In();
  m = In();
  for (register int i(1); i <= m; ++i) {
    Do = In();
		A = In();
		B = In();
		if (Do <= 2) {
			if (Do == 1) {//1
				if (N[A].Val) {
					if (N[A].Val == N[B].Val) {
						Fak++;
						continue;
					}
					if(!N[B].Val) {
						N[B].Val = (N[A].Val % 2) + 1;
						DFS(B);	
						if(flg) {
							N[B].Val = 0;
							flg = 0;
						}
					}
					continue;
				}
				if (N[B].Val) {
					N[A].Val = (N[B].Val % 2) + 1;
					DFS(A);
					if(flg) {
						N[A].Val = 0;
						flg = 0;
					}
					continue; 
				} 
				Add (N + A, N + B);
				Add (N + B, N + A);
			}
			else {//2
				if (!N[A].Val) {
					N[A].Val = B;
					DFS(A);
					if(flg) {
						N[A].Val = 0;
						flg = 0;
					}
					continue;
				}
				if (N[A].Val == (B % 2) + 1) {
					Fak++;
					continue;
				}
			}
		}
		else {
			if (Do == 3) {//3
				if (N[A].Val == B) {
					Fak++;
					continue;
				}
				if (!N[A].Val) {
					N[A].Val = (B % 2) + 1;
					DFS(A);
					if(flg) {
						N[A].Val = 0;
						flg = 0;
					}
					continue;
				}
			}
			else {//4
				N[A].Val = B;
				DFSForce(A);
				N[A].Fst = NULL;
			}
		}
  }
  cout<<Fak<<endl;
  for (register int i(1); i < n; ++i) {
  	if (N[i].Val) {
			printf("%d ", N[i].Val);
		}
		else {
			N[i].Val = 1;
			DFS(i);
		}
	}
	printf("%d", N[n].Val?N[n].Val:1);
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
/*
5 5
*/
