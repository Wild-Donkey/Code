#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lf;

// #define int ll
#define rep(i, f, t) for (int i = (f), ed##i = (t); i <= ed##i; ++i)
#define re(i, t) rep (i, 1, t)
#define per(i, t, f) for (int i = (t), ed##i = (f); i >= ed##i; --i)
#define ste(i, f, t, s) for (int i = (f), ed##i = (t); i <= ed##i; i += s)
#define each(i, x) for (auto&& i : (x))
#define nxt(i, f, g) for (int i = g.h[f]; i; i = g.e[i].n)
#define dbg(x) (cerr << "\033[34m" << #x " = " << (x) << "\033[0m\n")
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
// clang-format on

const int N = 50009 + 9;
const int mo = 1e9 + 7;

int n, m, K, QCnt(0);
struct Mat {
  int a[5][5];
  int* operator[](int x) { return a[x]; }
  const int* operator[](int x) const { return a[x]; }
  Mat() { memset(a, 0, sizeof a); }
  inline Mat operator*(const Mat& T) const {
    Mat res;
    int r;
    for (int i = 0; i < K; ++i)
      for (int k = 0; k < K; ++k) {
        r = a[i][k];
        for (int j = 0; j < K; ++j) res.a[i][j] += 1ll * T.a[k][j] * r % mo, umod(res.a[i][j]);
      }
    return res;
  }
} a[N];

ll Pow(ll a, ll b, const ll& m) {
  ll res = 1;
  a %= m;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m, b >>= 1;
  }
  return res;
}

Mat Inv(Mat M) {
  static int f[6][12];
  memset(f, 0, sizeof f);
  re(i, K) {
    re(j, K)
      f[i][j] = M[i - 1][j - 1];
    f[i][K + i] = 1;
  }
  int n = K, m = K << 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j++)
      if (f[j][i]) {
        for (int k = 1; k <= m; k++) swap(f[i][k], f[j][k]);
        break;
      }
    int r = Pow(f[i][i], mo - 2, mo);
    for (int j = i; j <= m; ++j) f[i][j] = 1ll * f[i][j] * r % mo;
    for (int j = 1; j <= n; ++j)
      if (j != i) {
        r = f[j][i];
        for (int k = i; k <= m; ++k) f[j][k] += 1ll * -r * f[i][k] % mo + mo, umod(f[j][k]);
      }
  }
  Mat res;
  re(i, n) {
    for (int j = n + 1; j <= m; ++j) res[i - 1][j - n - 1] = f[i][j];
  }
  return res;
}

Mat Rot(Mat x) {
  rep(i, 0, K - 1)
    rep(j, 0, i - 1)
    swap(x[i][j], x[j][i]);
  return x;
}

signed main() {
  in(n)(m)(K);
  re(i, n) {
    rep(j, 0, K - 1)
      rep(k, 0, K - 1)
      in(a[i][j][k]);
  }
  while (m--) {
    int op = in(), l = in(), r = in();
    if (op == 1) {
      ++QCnt;
      auto res = a[l];
      rep(i, l + 1, r)
        res = res * a[i];
      int ans = 0;
      rep(i, 0, K - 1)
        rep(j, 0, K - 1)
        ans += res[i][j], umod(ans);
      out(ans)('\n');
    }
    else if (op == 2) {
      l = 4122, r = 9719;
      auto res = a[l];
      rep(i, l + 1, r)
        res = res * a[i];
      int ans = 0;
      rep(i, 0, K - 1)
        rep(j, 0, K - 1)
        ans += res[i][j], umod(ans);
      out(ans)('\n');
      rep(i, l, r)
        a[i] = Inv(a[i]);
      // Inv(l, r);
    }
    else if (op == 3) {
      rep(i, l, r)
        a[i] = Rot(a[i]);
      // Rot(l, r);
    }
    else {
      Mat x;
      rep(j, 0, K - 1)
        rep(k, 0, K - 1)
        in(x[j][k]);
      rep(i, l, r)
        a[i] = x;
    }
    if (QCnt >= 2) break;
  }
  // system("pause");
  return 0;
}
/*
67161600
262768610
*/