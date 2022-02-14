#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lf;

#define rep(i, f, t) for (int i = (f), ed##i = (t); i <= ed##i; ++i)
#define re(i, t) rep (i, 1, t)
#define per(i, t, f) for (int i = (t), ed##i = (f); i >= ed##i; --i)
#define ste(i, f, t, s) for (int i = (f), ed##i = (t); i <= ed##i; i += s)
#define each(i, x) for (auto& i : (x))
#define nxt(i, f, g) for (int i = g.h[f]; i; i = g.e[i].n)
#define dbg(x) (cerr << "(dbg) " << #x " = " << (x) << '\n')
#define umod(x) ((x) >= mo && ((x) -= mo))
#define dmod(x) ((x) < 0 && ((x) += mo))
#define up(x, y) (((x) < (y)) && ((x) = (y)))
#define down(x, y) (((x) > (y)) && ((x) = (y)))
#define y1 y1__
#define fio(x) (freopen(x ".in", "r", stdin), freopen(x ".out", "w", stdout))

// clang-format off
namespace FastIO {
  const int SZ = (1 << 21) + 1;
  struct I {
    char ibuf[SZ], * iS, * iT, c;int f, _eof;FILE* fi;
    I(FILE* f) :fi(f) {}
    inline char Gc() { return iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SZ, fi), (iS == iT ? EOF : *iS++)) : *iS++; }
    inline ll operator()() { ll x;operator()(x);return x; }
    inline I& operator()(char& x) { x = Gc();return*this; }
    inline I& operator()(char* s) { for (c = Gc();c < 32 || c>126 || c == ' ';)c = Gc();for (;c > 31 && c < 127 && c != ' ' && c != '\n' && c != '\r';++s, c = Gc())*s = c;*s = 0;return*this; }
    template<class T>inline I& operator()(T& x) { _eof = 0;for (f = 1, c = Gc();(c < '0' || c>'9') && !_eof;c = Gc()) { if (c == '-')f = -1;_eof |= c == EOF; }for (x = 0;c <= '9' && c >= '0' && !_eof;c = Gc())x = x * 10 + (c & 15), _eof |= c == EOF;x *= f;return*this; }
    template<class T>I& operator()(T* x, const int& n, const int& st = 1) { rep(i, st, n) { operator()(x[i]); }return*this; }
  } in(stdin);
  struct O {
    char obuf[SZ], * oS = obuf, * oT = oS + SZ - 1, qu[55];int f, qr;FILE* fi;
    O(FILE* f) :fi(f) {}
    ~O() { Flush(); }
    inline void Flush() { fwrite(obuf, 1, oS - obuf, fi), oS = obuf; }
    inline O& operator()(char x) { *oS++ = x;if (oS == oT)Flush();return*this; }
    inline O& operator()(char* s) { int len = strlen(s);for (f = 0;f < len;++f)operator()(s[f]);return*this; }
    inline O& operator()(const char* s) { return operator()((char*)s); }
    template<class T>inline O& operator()(T x) { if (!x)operator()('0');if (x < 0)operator()('-'), x = -x;while (x)qu[++qr] = x % 10 + '0', x /= 10;while (qr)operator()(qu[qr--]);return*this; }
    template<class T>O& operator()(T* x, const int& n, const char& ed = ' ', const int& st = 1) { rep(i, st, n)operator()(x[i])(ed);return*this; }
  } out(stdout);
}
using FastIO::in;using FastIO::out;
template<class T>T Abs(const T& a) { return a > 0 ? a : -a; }
ll Pow(ll a, ll b, const ll& m) { ll res = 1;a %= m;while (b > 0) { if (b & 1)res = res * a % m;a = a * a % m, b >>= 1; }return res; }
ll Gcd(ll a, ll b) { ll t;while (b != 0)t = a % b, a = b, b = t;return a; }
ll C(ll n, ll m) { if (m > n)return 0;ll a = 1;re(i, m)a *= (n - i + 1), a /= i;return a; }
ll C(ll n, ll m, ll p) { if (m > n)return 0;ll x = 1;re(i, m) { ll a = (n + i - m) % p, b = i % p;x = x * (a * Pow(b, p - 2, p) % p) % p; }return x; }
// clang-format on

const int N = 3e5 + 9;
const int B = 880;

int a[N], b[N], n, m, q, T, pos[N], sz, pre[N], suf[N], f[N], lastans, preans[B][B], bl[N],
pref[B][N];

signed main() {
  freopen("P8120.in", "r", stdin);
  freopen("P8120.ans", "w", stdout);
  in(m)(n)(q)(T)(b, m)(a, n);
  sz = 0.63 * sqrt(n);
  rep(i, 1, n)
    bl[i] = (i - 1) / sz + 1;
  re(i, m)
    pos[b[i]] = i;
  re(i, n)
    a[i] = pos[a[i]];
  re(i, n)
    pre[i] = f[a[i] - 1], f[a[i]] = i;
  memset(f, 0, sizeof f);
  per(i, n, 1)
    suf[i] = f[a[i] + 1], f[a[i]] = i;
  memset(f, 0, sizeof f);
  ste(l, 1, n, sz) {
    int ans = 0;
    rep(r, l, n) {
      f[r] = f[pre[r]] + 1;
      up(ans, f[r]);
      if (bl[r] != bl[r + 1]) preans[bl[l]][bl[r]] = ans;
    }
    rep(j, l, n) { pref[bl[l]][j] = f[j]; }
    memset(f, 0, sizeof f);
  }
  ste(r, sz, n, sz) {
    per(l, r, 1) { f[l] = f[suf[l]] + 1; }
    re(j, r) { pref[bl[r] + 1][j] = f[j]; }
    memset(f, 0, sizeof f);
  }
  // return 0;
  int lastans = 0;
  while (q--) {
    // int l = in() ^ lastans, r = in() ^ lastans;
    int l = in(), r = in();
    if (T) l ^= lastans, r ^= lastans;
    int lb = bl[l] + 1, rb = bl[r] - 1;
    if (lb > rb) {
      int ans = 0;
      rep(i, l, r)
        up(f[a[i]], f[a[i] - 1] + 1), up(ans, f[a[i]]);
      // out(ans)('\n');
      out(lastans = ans)('\n');
      rep(i, l, r)
        f[a[i]] = 0;
      continue;
    }
    int ans = preans[lb][rb];
    rep(i, rb * sz + 1, r) {
      up(f[a[i] - pref[lb][i] + 1], pref[lb][i]);
      up(ans, f[a[i] - pref[lb][i] + 1]);
    }
    per(i, (lb - 1) * sz, l) {
      up(f[a[i]], pref[rb + 1][i]);
      up(f[a[i]], f[a[i] + 1] + 1);
      up(ans, f[a[i]]);
    }
    // out(ans)('\n');
    out(lastans = ans)('\n');
    rep(i, rb * sz + 1, r)
      f[a[i] - pref[lb][i] + 1] = 0;
    per(i, (lb - 1) * sz, l)
      f[a[i]] = 0;
  }
  return 0;
}