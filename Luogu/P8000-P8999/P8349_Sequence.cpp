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
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
unsigned a[300005], Sz[300005], Name[300005], Bucket[300005];
int b[300005];
long long Sum[300005], Ans[1000005];
unsigned A, B, C, D, t;
unsigned Cnt, Mx, Thr, m, n;
vector<pair<unsigned, int> > Vc[300005];
struct Ques {
  unsigned Fs, Sc, Num;
  inline void Init() {
    Num = ++Cnt, Fs = Bucket[RD()], Sc = Bucket[RD()];
    if (Fs < Sc) swap(Fs, Sc);
  }
  inline const char operator< (const Ques& x) const {
    return (Fs ^ x.Fs) ? (Fs < x.Fs) : (Sc < x.Sc);
  }
}Qst[1000005];
inline long long Qry(unsigned x) {
  unsigned Siz(Vc[x].size()), Hei[Siz + 3], List[(Siz << 1) + 3];
  // printf("Qry %u %u\n", x, Siz);
  for (unsigned i(0); i < Siz; ++i) Hei[i + 1] = Siz + Bucket[Vc[x][i].first] - i - 1;
  // for (unsigned i(1); i <= Siz; ++i) printf("%u ", Hei[i]); putchar(0x0A);
  memcpy(List, Hei, (Siz + 1) << 2);
  for (unsigned i(1); i <= Siz; ++i) List[Siz + i] = List[i] + 1;
  sort(List + 1, List + (Siz << 1) + 1);
  // for (unsigned i(1); i <= (Siz << 1); ++i) printf("%u ", List[i]); putchar(0x0A);
  unsigned HCnt(unique(List + 1, List + (Siz << 1) + 1) - List - 1);
  List[HCnt + 1] = 0x3f3f3f3f;
  // for (unsigned i(1); i <= HCnt; ++i) printf("%u ", List[i]); putchar(0x0A);
  long long Shrink[HCnt + 3], Cur(0), Tmp(0xafafafafafafafaf);
  memset(Shrink, 0x3f, (HCnt + 1) << 3);
  unsigned j(0), HC(Siz), Pos(0);
  while (List[j + 1] <= Siz) ++j;
  if (List[j] == Siz) Shrink[j] = 0;
  // printf("Start From %u\n", j);
  for (unsigned i(1); i <= Siz; ++i) {
    while (List[j + 1] <= Hei[i] + 1) {
      unsigned Fw(min(Mx - Pos, List[++j] - HC));
      if (!Fw) continue;
      Cur -= Sum[Pos], Cur += Sum[Pos += Fw];
      // printf("Fw %u Cur %lld\n", Fw, Cur);
      HC = List[j], Tmp = max(Tmp, Cur - Shrink[j]);
      Shrink[j] = min(Shrink[j], Cur);
      // printf("Shrink %u = %lld, Tmp %lld\n", j, Shrink[j], Tmp);
    }
    // printf("j %u\n", j);
    Cur += Vc[x][i - 1].second, --j;
    --HC, Tmp = max(Tmp, Cur - Shrink[j]);
    Shrink[j] = min(Shrink[j], Cur);
    // printf("Shrink %u = %lld, Tmp %lld\n", j, Shrink[j], Tmp);
  }
  while (j < HCnt) {
    unsigned Fw(min(Mx - Pos, List[++j] - HC));
    if (!Fw) continue;
    Cur -= Sum[Pos], Cur += Sum[Pos += Fw];
    HC = List[j], Tmp = max(Tmp, Cur - Shrink[j]);
    Shrink[j] = min(Shrink[j], Cur);
    // printf("Shrink %u = %lld, Tmp %lld\n", j, Shrink[j], Tmp);
  }
  // printf("%lld\n", Tmp);
  return Tmp;
}
//  inline void Clr() {}
signed main() {
  // freopen("P8349_-2.in", "r", stdin);
  // freopen("P8349.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), Thr = (n / (sqrt(m) + 1)) + 1;// Thr = n;
  // printf("Thr %u\n", Thr);
  for (unsigned i(1); i <= n; ++i) ++Sz[a[i] = RD()];
  for (unsigned i(1); i <= n; ++i) b[i] = RDsg();
  for (unsigned i(1); i <= n; ++i) ++Bucket[Sz[i]];
  for (unsigned i(1); i <= n; ++i) Bucket[i] += Bucket[i - 1];
  Thr = Bucket[Thr - 1] + 1;
  for (unsigned i(n); i; --i) Name[Bucket[Sz[i]]--] = i; //Rank
  for (unsigned i(1); i <= n; ++i) Bucket[Name[i]] = i;// Bucket -> Name
  // for (unsigned i(1); i <= n; ++i) printf("%u ", Name[i]); putchar(0x0A);
  // for (unsigned i(1); i <= n; ++i) printf("%u ", Bucket[i]); putchar(0x0A);
  // for (unsigned i(1); i <= n; ++i) printf("%u ", Bucket[a[i]]); putchar(0x0A);
  for (unsigned i(1); i <= n; ++i) Vc[a[i] = Bucket[a[i]]].push_back({ i, b[i] });
  for (unsigned i(1); i <= m; ++i) Qst[i].Init();
  sort(Qst + 1, Qst + m + 1);
  // for (unsigned i(1); i <= m; ++i) printf("%u %u %u\n", Qst[i].Fs, Qst[i].Sc, Qst[i].Num);
  for (unsigned i(Cnt = 1); i <= m; ++i, ++Cnt) {
    // printf("Done\n");
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
  // printf("Little to Little: %u\n", Cnt - 1);
  for (unsigned i(Cnt); i <= m;) {
    unsigned Cur(Qst[i].Fs);
    // printf("Big %u\n", Cur);
    memset(Name, 0, (n + 1) << 2);
    memset(Bucket, 0, (n + 1) << 2);
    memset(Sum, 0, (n + 1) << 3);
    Sum[0] = 0, Mx = Vc[Cur].size();
    for (unsigned j(Vc[Cur].size() - 1); ~j; --j)
      Name[j + 1] = Vc[Cur][j].first, Sum[j + 1] = Vc[Cur][j].second;
    for (auto j : Vc[Cur]) Bucket[j.first] = 1;// Sum[j.first] = j.second;
    for (unsigned j(1); j <= n; ++j) Bucket[j] += Bucket[j - 1];
    for (unsigned j(1); j <= n; ++j) Sum[j] += Sum[j - 1];
    // for (unsigned j(1); j <= n; ++j) printf("%u ", Bucket[j]); putchar(0x0A);
    // for (unsigned j(1); j <= n; ++j) printf("%lld ", Sum[j]); putchar(0x0A);
    for (unsigned j(i); (Qst[j].Fs == Cur); ++j, ++i) {
      if ((Qst[j - 1].Fs == Cur) && (Qst[j].Sc == Qst[j - 1].Sc)) {
        Ans[Qst[j].Num] = Ans[Qst[j - 1].Num];
        continue;
      }
      Ans[Qst[j].Num] = Qry(Qst[j].Sc);
    }
  }
  for (unsigned i(1); i <= m; ++i) printf("%lld\n", Ans[i]);
  //  }
  //  system("pause");
  return Wild_Donkey;
}