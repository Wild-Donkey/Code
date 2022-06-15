#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define Wild_Donkey 0
using namespace std;
namespace io {
  const int __SIZE = (1 << 21) + 1;
  char ibuf[__SIZE], * iS, * iT, obuf[__SIZE], * oS = obuf, * oT = oS + __SIZE - 1, __c, qu[55]; int __f, qr, _eof;
#define Gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
  inline void flush() { fwrite(obuf, 1, oS - obuf, stdout), oS = obuf; }
  inline void gc(char& x) { x = Gc(); }
  inline void pc(char x) { *oS++ = x; if (oS == oT) flush(); }
  inline void pstr(const char* s) { int __len = strlen(s); for (__f = 0; __f < __len; ++__f) pc(s[__f]); }
  inline void gstr(char* s) {
    for (__c = Gc(); __c < 32 || __c > 126 || __c == ' ';)  __c = Gc();
    for (; __c > 31 && __c < 127 && __c != ' '; ++s, __c = Gc()) *s = __c; *s = 0;
  }
  template <class I> inline bool gi(I& x) {
    _eof = 0;
    for (__f = 1, __c = Gc(); (__c < '0' || __c > '9') && !_eof; __c = Gc()) { if (__c == '-') __f = -1; _eof |= __c == EOF; }
    for (x = 0; __c <= '9' && __c >= '0' && !_eof; __c = Gc()) x = x * 10 + (__c & 15), _eof |= __c == EOF; x *= __f; return !_eof;
  }
  template <class I> inline void print(I x) {
    if (!x) pc('0'); if (x < 0) pc('-'), x = -x;
    while (x) qu[++qr] = x % 10 + '0', x /= 10; while (qr) pc(qu[qr--]);
  }
  struct Flusher_ { ~Flusher_() { flush(); } }io_flusher_;
} using io::pc; using io::gc; using io::pstr; using io::gstr; using io::gi; using io::print;
unsigned a[300005], Sz[300005], Name[300005], Bucket[300005];
int b[300005];
long long Sum[300005], Ans[1000005];
unsigned A, B, C, D, t;
unsigned Cnt, Mx, Thr, m, n;
vector<pair<unsigned, int> > Vc[300005];
struct Ques {
  unsigned Fs, Sc, Num;
  inline void Init() {
    Num = ++Cnt, gi(A), Fs = Bucket[A], gi(A), Sc = Bucket[A];
    if (Fs < Sc) swap(Fs, Sc);
  }
  inline const char operator< (const Ques& x) const { return (Fs ^ x.Fs) ? (Fs < x.Fs) : (Sc < x.Sc); }
}Qst[1000005];
inline long long Qry(unsigned x) {
  unsigned Siz(Vc[x].size()), Hei[Siz + 3], List[(Siz << 1) + 3];
  for (unsigned i(0); i < Siz; ++i) Hei[i + 1] = Siz + Bucket[Vc[x][i].first] - i - 1;
  memcpy(List, Hei, (Siz + 1) << 2);
  for (unsigned i(1); i <= Siz; ++i) List[Siz + i] = List[i] + 1;
  sort(List + 1, List + (Siz << 1) + 1);
  unsigned HCnt(unique(List + 1, List + (Siz << 1) + 1) - List - 1);
  List[HCnt + 1] = 0x3f3f3f3f;
  long long Shrink[HCnt + 3], Cur(0), Tmp(0xafafafafafafafaf);
  memset(Shrink, 0x3f, (HCnt + 1) << 3);
  unsigned j(0), HC(Siz), Pos(0);
  while (List[j + 1] <= Siz) ++j;
  if (List[j] == Siz) Shrink[j] = 0;
  for (unsigned i(1); i <= Siz; ++i) {
    while (List[j + 1] <= Hei[i] + 1) {
      unsigned Fw(min(Mx - Pos, List[++j] - HC));
      if (!Fw) continue;
      Cur -= Sum[Pos], Cur += Sum[Pos += Fw];
      HC = List[j], Tmp = max(Tmp, Cur - Shrink[j]);
      Shrink[j] = min(Shrink[j], Cur);
    }
    Cur += Vc[x][i - 1].second, --j;
    --HC, Tmp = max(Tmp, Cur - Shrink[j]);
    Shrink[j] = min(Shrink[j], Cur);
  }
  while (j < HCnt) {
    unsigned Fw(min(Mx - Pos, List[++j] - HC));
    if (!Fw) continue;
    Cur -= Sum[Pos], Cur += Sum[Pos += Fw];
    HC = List[j], Tmp = max(Tmp, Cur - Shrink[j]);
    Shrink[j] = min(Shrink[j], Cur);
  }
  return Tmp;
}
signed main() {
  // freopen("P8349_-2.in", "r", stdin);
  // freopen("P8349.out", "w", stdout);
  gi(n), gi(m), Thr = (n / (sqrt(m) + 1)) + 1;
  for (unsigned i(1); i <= n; ++i) gi(a[i]), ++Sz[a[i]];
  for (unsigned i(1); i <= n; ++i) gi(b[i]);
  for (unsigned i(1); i <= n; ++i) ++Bucket[Sz[i]];
  for (unsigned i(1); i <= n; ++i) Bucket[i] += Bucket[i - 1];
  Thr = Bucket[Thr - 1] + 1;
  for (unsigned i(n); i; --i) Name[Bucket[Sz[i]]--] = i; //Rank
  for (unsigned i(1); i <= n; ++i) Bucket[Name[i]] = i;// Bucket -> Name
  for (unsigned i(1); i <= n; ++i) Vc[a[i] = Bucket[a[i]]].push_back({ i, b[i] });
  for (unsigned i(1); i <= m; ++i) Qst[i].Init();
  sort(Qst + 1, Qst + m + 1);
  for (unsigned i(Cnt = 1); i <= m; ++i, ++Cnt) {
    unsigned Cur(Qst[i].Fs);
    if (Cur >= Thr) break;
    unsigned With(Qst[i].Sc), Mxk(Vc[With].size()), Top(Thr + 2), Hei(Top), Bot(Top), k(0);
    long long CSum(0), Tmp(0xafafafafafafafaf);
    Sum[Top] = 0;
    for (auto j : Vc[Cur]) {
      while (k < Mxk && Vc[With][k].first < j.first) {
        CSum += Vc[With][k++].second, --Hei;
        if (Hei < Bot) Sum[Bot = Hei] = 0x3f3f3f3f3f3f3f3f;
        Tmp = max(Tmp, CSum - Sum[Hei]);
        Sum[Hei] = min(CSum, Sum[Hei]);
      }
      CSum += j.second, ++Hei;
      if (Hei > Top) Sum[Top = Hei] = 0x3f3f3f3f3f3f3f3f;
      Tmp = max(Tmp, CSum - Sum[Hei]);
      Sum[Hei] = min(CSum, Sum[Hei]);
    }
    while (k < Mxk) {
      CSum += Vc[With][k++].second, --Hei;
      if (Hei < Bot) Sum[Bot = Hei] = 0x3f3f3f3f3f3f3f3f;
      Tmp = max(Tmp, CSum - Sum[Hei]);
      Sum[Hei] = min(CSum, Sum[Hei]);
    }
    Ans[Qst[i].Num] = Tmp;
  }
  for (unsigned i(Cnt); i <= m;) {
    unsigned Cur(Qst[i].Fs);
    memset(Bucket, 0, (n + 1) << 2);
    Sum[0] = 0, Mx = Vc[Cur].size();
    for (unsigned j(Mx); j; --j) Sum[j] = Vc[Cur][j - 1].second;
    for (auto j : Vc[Cur]) Bucket[j.first] = 1;// Sum[j.first] = j.second;
    for (unsigned j(1); j <= n; ++j) Bucket[j] += Bucket[j - 1];
    for (unsigned j(1); j <= Mx; ++j) Sum[j] += Sum[j - 1];
    while (Qst[i].Fs == Cur) {
      if ((Qst[i - 1].Fs == Cur) && (Qst[i].Sc == Qst[i - 1].Sc)) {
        Ans[Qst[i].Num] = Ans[Qst[i - 1].Num], ++i;
        continue;
      }
      Ans[Qst[i].Num] = Qry(Qst[i].Sc), ++i;
    }
  }
  for (unsigned i(1); i <= m; ++i) print(Ans[i]), pc(0x0A);
  return Wild_Donkey;
}