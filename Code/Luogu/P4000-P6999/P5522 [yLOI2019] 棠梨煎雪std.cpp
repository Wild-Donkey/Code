#include <ctime>
#include <cstdio>
const int maxn = 100010;
int n, m, q;
char s[maxn][35];
struct Tree {
  Tree *ls, *rs;
  int l, r, x, y;
  bool leg;
  Tree() {//构造函数(初始化) 
    ls = rs = NULL;
    l = r = x = y = 0;
    leg = true;
  }
  void pushup() {
    if (!(this->ls->leg && this->rs->leg)) {
      this->leg = false;
    } else {
      if ((this->ls->x & this->rs->x) & (this->ls->y ^ this->rs->y)) {
        this->leg = false;
      } else {
        this->leg = true;
        this->x = this->ls->x | this->rs->x;
        this->y = this->ls->y | this->rs->y;
      }
    }
  }
}*rot;
void build(Tree *const u, const int l, const int r) {
  if ((u->l = l) == (u->r = r)) {
    for (int i = 1; i <= n; ++i) {
      if (s[l][i] != '?') {
        u->x |= 1 << i;
        if (s[l][i] == '1') {
          u->y |= 1 << i;
        }
      }
    }
  } else {
    int mid = (l + r) >> 1;
    build(u->ls = new Tree, l, mid);
    build(u->rs = new Tree, mid + 1, r);
    u->pushup();
  }
}

Tree query(Tree *u, const int l, const int r) {
  if ((u->l > r) || (u->r < l)) return Tree();
  if ((u->l >= l) && (u->r <= r)) return *u;
  Tree _ret;
  auto ll = query(u->ls, l, r), rr = query(u->rs, l, r);
  _ret.ls = &ll; _ret.rs = &rr;
  _ret.pushup();
  return _ret;
}
void Query(const int l, const int r) {
  auto _ret = query(rot, l, r);
  if (!_ret.leg) {
    puts("0");
  } else {
    int ans = 1;
    for (int i = 1; i <= n; ++i) if (!(_ret.x & (1 << i))) {
      ans <<= 1;
    }
    Ans ^= ans;
    printf("%d\n", ans);
  }
}
void update(Tree *u, const int p) {
  if (u->ls) {
    if (u->ls->r >= p) {
      update(u->ls, p);
    } else {
      update(u->rs, p);
    }
    u->pushup();
  } else {
    *u = Tree();
    u->l = u->r = p;
    for (int i = 1; i <= n; ++i) {
      if (s[0][i] != '?') {
        u->x |= 1 << i;
        if (s[0][i] == '1') {
          u->y |= 1 << i;
        }
      }
    }
  }
}
void Update(const int x) {
  update(rot, x);
}
int main() {
  qr(n); qr(m); qr(q);
  for (int i = 1; i <= m; ++i) {
    ReadStr(s[i] + 1);
  }
  build(rot = new Tree, 1, m);
  int opt, l, r;
  while (q--) {
    opt = 0; qr(opt);
    if (opt == 0) {
      l = r = 0; qr(l); qr(r);
      Query(l, r);
    } else {
      l = 0; qr(l);
      ReadStr(s[0] + 1);
      Update(l);
    }
  }
}
