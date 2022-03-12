#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lf;

// #define int ll
#define rep(i, f, t) for (int i = (f), ed##i = (t); i <= ed##i; ++i)
#define re(i, t) rep (i, 1, t)
#define per(i, t, f) for (int i = (t), ed##i = (f); i >= ed##i; --i)
#define ste(i, f, t, s) for (int i = (f), ed##i = (t); i <= ed##i; i += s)
#define each(i, x) for (auto &&i : (x))
#define nxt(i, f, g) for (int i = g.h[f]; i; i = g.e[i].n)
#define dbg(x) (cerr << "\033[34m" << #x " = " << (x) << "\033[0m\n")
#define umod(x) ((x) >= mo && ((x) -= mo))
#define dmod(x) ((x) < 0 && ((x) += mo))
#define y1 y1__
#define fio(x) (freopen(x ".in", "r", stdin), freopen(x ".out", "w", stdout))

template <class T, class E>
__attribute__((always_inline)) inline void up(T& x, E&& y) {
  if (x < y) x = y;
}
template <class T, class E>
__attribute__((always_inline)) inline void down(T& x, E&& y) {
  if (y < x) x = y;
}

const int N((1 << 18) + 9);
// const int inf = 2147483647;
typedef tree<unsigned long long, __gnu_pbds::null_type, less<>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> Rbt;
Rbt tr[N >> 1];
unsigned l, r, Qk, Qx, Tmp(0), n, m;
unsigned long long Val, a[100005];
struct Seg {
  inline void Build(const int u, const int L, const int R) {
    // printf("Build %u %u %u\n", u, L, R);
    if (L == R) return;
    rep(i, L, R) tr[u].insert(a[i]);
    int mid((L + R) >> 1);
    Build(u << 1, L, mid), Build(u << 1 | 1, mid + 1, R);
  }
  inline void Rnk(const int u, const int L, const int R) {
    // printf("Rnk %u [%u, %u]\n", u, L, R);
    if (L == R) { Tmp += (a[L] < Val); return; }
    if (l <= L && R <= r) { Tmp += tr[u].order_of_key(Val); return; }
    int mid((L + R) >> 1);
    if (l <= mid) Rnk(u << 1, L, mid);
    if (r > mid) Rnk(u << 1 | 1, mid + 1, R);
  }
  inline void Add(const int u, const int L, const int R) {
    if (L == R) { a[l] = Val; return; }
    tr[u].erase(a[l]), tr[u].insert(Val);
    int mid((L + R) >> 1);
    if (l <= mid) Add(u << 1, L, mid);
    else Add(u << 1 | 1, mid + 1, R);
  }
} seg;
char op[10];
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  re(i, n) cin >> a[i], a[i] *= 100001, a[i] += i;
  seg.Build(1, 1, n);
  while (m--) {
    cin >> op >> l >> r;
    if (op[0] == 'Q') {
      cin >> Qk;
      int L(0), R(1e9);
      while (L ^ R) {
        Qx = ((L + R + 1) >> 1), Val = (unsigned long long)Qx * 100001, Tmp = 0, seg.Rnk(1, 1, n);
        if (Tmp < Qk) L = Qx; else R = Qx - 1;
      }
      cout << L << '\n';
    }
    else Val = (unsigned long long)r * 100001 + l, seg.Add(1, 1, n);
  }
  return 0;
}