#include <cstdio>
using namespace std;
int n, m, DoWhat;
long long a[300005];
long long IN() {
  char ich = getchar();
  long long intmp = 0, insign = 1;
  while (((ich < '0') || (ich > '9')) && ((ich != '-'))) ich = getchar();
  if (ich == '-') insign = -1, ich = getchar();
  while ((ich <= '9') && (ich >= '0'))
    intmp *= 10, intmp += ich - '0', ich = getchar();
  return intmp * insign;
}
struct Node {
  int L, R;
  long long tagg, val;
  Node *ls, *rs;
} N[300005], *cntnd = N + 0;
void PsDo(Node *now) {
  if (now->tagg == 0) return;
  now->val += (now->tagg) * (now->R - now->L + 1);
  if ((now->ls != NULL) && (now->rs != NULL))
    now->ls->tagg += now->tagg, now->rs->tagg += now->tagg;
  now->tagg = 0;
  return;
}
void UD(Node *now) {
  if ((now->ls != NULL) && (now->rs != NULL)) {
    PsDo(now->ls);
    PsDo(now->rs);
    now->val = now->ls->val + now->rs->val;
  }
  return;
}
Node *Build(Node *now, int l, int r) {
  now->L = l;
  now->R = r;
  if (l == r) {
    now->ls = NULL;
    now->rs = NULL;
    now->val = a[l];
    return now;
  }
  int m = (l + r) >> 1;
  now->ls = Build(++cntnd, l, m);
  now->rs = Build(++cntnd, m + 1, r);
  UD(now);
  return now;
}
long long Find(int fl, int fr, Node *now) {
  UD(now);
  PsDo(now);
  if ((fl <= now->L) && (fr >= now->R)) return now->val;
  if ((fl > now->R) || (fr < now->L)) return 0;
  return Find(fl, fr, now->ls) + Find(fl, fr, now->rs);
}
void Change(int cl, int cr, int cx, Node *now) {
  if ((cl <= now->L) && (cr >= now->R)) {
    now->tagg += cx;
    return;
  }
  if ((cl > now->R) || (cr < now->L)) return;
  Change(cl, cr, cx, now->ls);
  Change(cl, cr, cx, now->rs);
  UD(now);
  return;
}
int main() {
  n = IN(), m = IN();
  for (int i = 1; i <= n; i++) a[i] = IN();
  Build(N + 0, 1, n);
  for (int i = 1; i <= m; i++) {
    DoWhat = IN();
    int tmpp = IN(), tmpmp = IN();
    if (DoWhat == 1)
      Change(tmpp, tmpmp, IN(), N + 0);
    else
      printf("%lld\n", Find(tmpp, tmpmp, N + 0));
  }
  return 0;
}