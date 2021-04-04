#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
inline int RD() {
  int intmp(0), insign(1);
  char rdch(getchar());
  while ((rdch != '-') && (rdch < '0' || rdch > '9')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    insign = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp *= 10;
    intmp += rdch - '0';
    rdch = getchar();
  }
  return intmp * insign;
}
struct Edge;
struct Node {
  bool vsd, avl;
  // int O, dep, rol;
  int Lw, Dfsr;
  Edge *fst;
} N[100005];
struct Edge {
  Node *to;
  Edge *nxt;
} E[100005], *cnte(E);
int /* Om(0),*/ C_(0), rcnt(0);
bool flg(0);
void Lk(const int &A, const int &B) {
  (++cnte)->to = N + B;
  cnte->nxt = N[A].fst;
  N[A].fst = cnte;
  ++N[A].O;
  // Om = max(N[A].O, Om);
  return;
}
void Tarjan() { return; }
void DFS(Node *now) {
  if (C_ == -1) {
    return;
  }
  if (now->vsd) {    //环根
    if (now->rol) {  //相交
      C_ = -1;
      return;
    }
    now->rol = ++rcnt;  //独立环接驳
    flg = 1;
    return;
  }
  now->vsd = 1;
  Edge *Sid(now->fst);
  while (Sid) {
    /*if(Sid->to->avl) {
            Sid = Sid->nxt;
            continue;
    }*/
    DFS(Sid->to);
    if (flg) {          //向上寻找独立环
      if (!now->rol) {  //中间节
        now->rol = rcnt;
        return;
      }
      if (now->rol < rcnt) {  //相交
        C_ = -1;
        return;
      }
      ++C_;  //独立环根
      flg = 0;
    }
    Sid = Sid->nxt;
  }
  return;
}
int m, n, A, B, ans(0);
bool _0(1);
long long feb[1005];
queue<Node> q;
int main() {
  n = RD();
  m = RD();
  for (register int i(1); i <= m; ++i) {
    A = RD();
    B = RD();
    Lk(A, B);
  }
  for (register int i(1); i <= n; ++i) {
    if (N[i].O > 1) {
      _0 = 0;
    }
  }
  if (_0) {
    printf("0\n");
    return 0;
  }
  for (register int i(1); i <= n; ++i) {
    if (N[i].avl) {
      continue;
    }
    DFS(&N[i]);
    if (C_ == -1) {
      printf("-1%d\n", i);
      return 0;
    }
    if (C_ >= 2) {
      printf("2\n");
      return 0;
    }
    ans = max(ans, C_);
    C_ = 0;
    rcnt = 0;
    for (register int i(1); i <= n; ++i) {
      N[i].vsd = 0;
      N[i].rol = 0;
    }
  }
  printf("%d\n", ans);
  /*q.push(N[1]);
  N[1].dep = 0;
  int Dep(0);
  /*feb[3] = 1;
  feb[4] = 1;
  for (register int i(5); i <= 159; ++i) {
          feb[i] = feb[i - 3] + feb[i - 2];
          printf("feb %d = %lld,  i^5 = %lld, bi = %lf\n", i, feb[i], (long
  long)i*i*i * i * i*i*i, (double)feb[i]/ i/ i/ i/i/i/i/i/i/i/i);
  }*/
  /*	while (q.front().dep <= 100 && q.size()) {
                  if(Dep < q.front().dep) {
                          printf("dep %d ans %d dep^3 %d\n", Dep, ans, Dep* Dep
     * Dep);
                          ++Dep;
                  }
                  ans += max(0, q.front().O - 1);
                  Edge *Sd(q.front().fst);
                  while (Sd) {
                          Sd->to->dep = q.front().dep + 1;
                          q.push(*Sd->to);
                          Sd = Sd->nxt;
                  }
                  q.pop();
          }*/
  /*for (register int i(1); i <= n; ++i) {

  }*/
  /*while (1) {
    printf("%d\n", RD());
  }*/
  return 0;
}
/*
5 5
1 2
2 3
3 4
4 5
5 1

0

3 4
1 2
2 3
3 1
1 3

-1


3 3
1 2
2 1
1 3

1


4 5
1 2
2 1
2 3
3 4
4 3

2
*/
