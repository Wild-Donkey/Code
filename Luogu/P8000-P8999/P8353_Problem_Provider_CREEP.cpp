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
#include <vector>
#define Wild_Donkey 0
#define Lbt(x) ((x)&((~(x))+1))
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
unsigned Type, m, n;
unsigned A, B, C, D, Blc, Ans(0);
const unsigned Twe(1048575), FaPart(134217727), CruPart(2147483648);
inline unsigned Nxt(const unsigned x) { return x * (A * x + B) + C; }
inline unsigned Get(unsigned* Val, unsigned x) {
  unsigned Cur(Val[x / Blc]);
  return 0;
}
inline void Add(unsigned* f, unsigned x, unsigned y) {
  while (x <= n) f[x] += y, x += Lbt(x);
}
inline unsigned Qry(unsigned* f, unsigned x) {
  unsigned y(0);
  while (x) y += f[x], x -= Lbt(x);
  return y;
}
inline void Random() {
  // printf("Done\n");
  unsigned Val[7000005], Fa[7000005];
  for (unsigned i(2); i <= n; ++i) Fa[i] = RD();
  for (unsigned i(1), j(D); i <= n; ++i) Val[i] = j = Nxt(j);
  unsigned Stack[2][3005], * STop[2], Ty, Fs, Sc;
  for (unsigned i(1); i <= m; ++i) {
    Ty = RD(), Fs = (RD() ^ Ans), Sc = (RD() ^ Ans);
    // printf("Do %u %u %u\n", Ty, Fs, Sc);
    STop[0] = Stack[0], STop[1] = Stack[1];
    if (Fs == Sc) *(++STop[0]) = Fs;
    else {
      while (Fs) *(++STop[0]) = Fs, Fs = Fa[Fs];
      while (Sc) *(++STop[1]) = Sc, Sc = Fa[Sc];
      // for (unsigned* j(Stack[0] + 1); j <= STop[0]; ++j) printf("%u ", *j); putchar(0x0A);
      // for (unsigned* j(Stack[1] + 1); j <= STop[1]; ++j) printf("%u ", *j); putchar(0x0A);
      while ((*(STop[0])) == (*(STop[1]))) --STop[0], --STop[1];
      ++STop[0];
    }
    if (Ty) {
      Ans = 0;
      while (STop[0] > Stack[0]) Ans += Val[*(STop[0]--)];
      while (STop[1] > Stack[1]) Ans += Val[*(STop[1]--)];
      printf("%u\n", Ans), Ans &= Twe;
    }
    else {
      Ty = (RD() ^ Ans);
      while (STop[0] > Stack[0]) Val[*(STop[0]--)] += Ty;
      while (STop[1] > Stack[1]) Val[*(STop[1]--)] += Ty;
    }
  }
}
inline void Str() {
  unsigned V1[7000005], V2[7000005], Ty, Fs, Sc;
  memset(V1, 0, (n + 1) << 2);
  memset(V2, 0, (n + 1) << 2);
  for (unsigned i(1); i < n; ++i) RD();
  for (unsigned i(1), j(D), k(0); i <= n; ++i)
    Add(V1, i, (j = Nxt(j)) - k), Add(V2, i, (j - k) * i), k = j;
  for (unsigned i(1); i <= m; ++i) {
    Ty = RD(), Fs = (RD() ^ Ans), Sc = (RD() ^ Ans);
    if (Fs > Sc) swap(Fs, Sc);
    if (Ty) {
      Ans = (Sc + 1) * Qry(V1, Sc);
      Ans -= Qry(V2, Sc);
      if (Fs > 1) {
        Ans -= Fs * Qry(V1, Fs - 1);
        Ans += Qry(V2, Fs - 1);
      }
      printf("%u\n", Ans), Ans &= Twe;
    }
    else {
      Ty = (RD() ^ Ans);
      Add(V1, Fs, Ty);
      Add(V2, Fs, Fs * Ty);
      if (Sc < n) {
        Add(V1, Sc + 1, -Ty);
        Add(V2, Sc + 1, (-Sc - 1) * Ty);
      }
    }
  }
}
inline void Push(unsigned* Fa, unsigned* Val, unsigned x, unsigned& y) {
  // if (y)fprintf(stderr, "Push %u\n", x);
  if (!y) return;
  Val[x] += y, x = (Fa[x] & FaPart);
  if (!x) return;
  while (!(Fa[x] & CruPart)) Val[x] += y, x = (Fa[x] & FaPart);
  y = 0;
}
inline void ReBuild(unsigned* Fa, unsigned* Val, unsigned x, unsigned& y) {
  y = Val[x], x = (Fa[x] & FaPart);
  if (!x) return;
  while (!(Fa[x] & CruPart)) y += Val[x], x = (Fa[x] & FaPart);
}
inline void TreeBlock() {
  srand(89898989);
  unsigned Fa[7000005], Val[7000005], Cru[8005], CFa[8005], CVal[8005], CTag[8005], CLen[8005];
  unsigned CruCnt(0);
  unordered_map<unsigned, unsigned> UM[8005], Num;
  Blc = 4000, Fa[1] = CruPart, Cru[0] = 0;
  for (unsigned i(2); i <= n; ++i) Fa[i] = RD();
  for (unsigned i(1); i <= Blc; ++i) Fa[(rand() * rand()) % n + 1] |= CruPart;
  memset(Val, 0, (n + 1) << 2), memset(CTag, 0, 32020), memset(CLen, 0, 32020);
  for (unsigned i(n); i > 1; --i) {
    if ((!(Fa[i] & CruPart)) && (Val[i] > 1)) Fa[i] |= CruPart;
    if ((Fa[i] & CruPart) || Val[i]) ++Val[Fa[i] & FaPart];
  }
  for (unsigned i(1), j(D); i <= n; ++i) Val[i] = j = Nxt(j);
  for (unsigned i(1); i <= n; ++i) if (Fa[i] & CruPart) Cru[++CruCnt] = i, Num[i] = CruCnt;
  for (unsigned i(2); i <= CruCnt; ++i) {
    unsigned Cur(Fa[Cru[i]] & FaPart), Last(Cur);
    CVal[i] = Val[Cru[i]], CLen[i] = 1;
    while (!(Fa[Cur] & CruPart)) CVal[i] += Val[Last = Cur], ++CLen[i], Cur = (Fa[Cur] & FaPart);
    if (!(Fa[Last] & CruPart)) UM[Num[Cur]][Last] = i;
    CFa[i] = Num[Cur];
  }
  // printf("Done\n");
  for (unsigned i(1); i <= m; ++i) {
    unsigned Ty(RD()), Fs(RD() ^ Ans), Sc(RD() ^ Ans);
    // fprintf(stderr, "%u: Do %u %u %u\n", i, Ty, Fs, Sc);
    unsigned UpF(Fs), DwF(0), HalfDF(0), UpS(Sc), DwS(0), HalfDS(0), Last(0), LCA, LTA, LTB;
    while (!(Fa[UpF] & CruPart)) Last = UpF, UpF = (Fa[UpF] & FaPart);
    if (!Last) HalfDF = DwF = Num[UpF]; else {
      LTA = Cru[HalfDF = UM[Num[UpF]][Last]], DwF = 0;
      if (LTA) while (LTA ^ UpF) {
        if (LTA == Fs) { DwF = HalfDF; break; }
        LTA = (Fa[LTA] & FaPart);
      }
    }
    LTA = UpF = Num[UpF];
    Last = 0;
    while (!(Fa[UpS] & CruPart)) Last = UpS, UpS = (Fa[UpS] & FaPart);
    if (!Last) HalfDS = DwS = Num[UpS]; else {
      LTB = Cru[HalfDS = UM[Num[UpS]][Last]], DwS = 0;
      if (LTB) while (LTB ^ UpS) {
        if (LTB == Sc) { DwS = HalfDS; break; }
        LTB = (Fa[LTB] & FaPart);
      }
    }
    LTB = UpS = Num[UpS];
    while (LTB ^ LTA) {
      if (LTA < LTB) swap(LTA, LTB);
      LTA = CFa[LTA];
    }
    LCA = LTA;
    // if (DwS && (HalfDS ^ DwS)) {
      // fprintf(stderr, "UpF %u, UpS %u, DwF %u, DwS %u, Half %u %u, LCA %u\n", UpF, UpS, DwF, DwS, HalfDF, HalfDS, LCA);
      // for (auto j : UM[UpS]) fprintf(stderr, "(%u, %u)\n", j.first, j.second);
  // }
    if (Ty) {
      Ans = 0;
      Push(Fa, Val, Cru[DwF], CTag[DwF]);
      Push(Fa, Val, Cru[DwS], CTag[DwS]);
      Push(Fa, Val, Cru[UpF], CTag[UpF]);
      Push(Fa, Val, Cru[UpS], CTag[UpS]);
      Push(Fa, Val, Cru[HalfDF], CTag[HalfDF]);
      Push(Fa, Val, Cru[HalfDS], CTag[HalfDS]);
      Push(Fa, Val, Cru[LCA], CTag[LCA]);
      if (UpF == UpS) {
        // fprintf(stderr, "Qry Type 1\n");
        while (Fs ^ Sc) {
          if (Fs < Sc) swap(Fs, Sc);
          Ans += Val[Fs], Fs = (Fa[Fs] & FaPart);
        }
        Ans += Val[Fs], printf("%u\n", Ans), Ans &= Twe;
        continue;
      }
      if (LCA == UpS) swap(UpF, UpS), swap(DwF, DwS), swap(Fs, Sc);
      if (LCA == UpF) {
        // fprintf(stderr, "Qry Type 2\n");
        while (!(Fa[Sc] & CruPart)) Ans += Val[Sc], Sc = (Fa[Sc] & FaPart);
        while (CFa[UpS] != LCA) Ans += CVal[UpS], UpS = CFa[UpS];
        Sc = Cru[UpS], Push(Fa, Val, Sc, CTag[UpS]), CTag[UpS] = 0;
        while (Fs ^ Sc) {
          if (Fs < Sc) swap(Fs, Sc);
          Ans += Val[Fs], Fs = (Fa[Fs] & FaPart);
        }
        Ans += Val[Fs], printf("%u\n", Ans), Ans &= Twe;
        continue;
      }
      // fprintf(stderr, "Qry Type 3\n");
      while (!(Fa[Fs] & CruPart)) Ans += Val[Fs], Fs = (Fa[Fs] & FaPart);
      while (!(Fa[Sc] & CruPart)) Ans += Val[Sc], Sc = (Fa[Sc] & FaPart);
      while (UpF != LCA) Ans += CVal[UpF], UpF = CFa[UpF];
      while (UpS != LCA) Ans += CVal[UpS], UpS = CFa[UpS];
      Ans += Val[Cru[LCA]], printf("%u\n", Ans), Ans &= Twe;
    }
    else {
      Ty = (RD() ^ Ans);
      if (UpF == UpS) {
        // fprintf(stderr, "Chg Type 1\n");
        while (Fs ^ Sc) {
          if (Fs > Sc) Val[Fs] += Ty, Fs = (Fa[Fs] & FaPart);
          else Val[Sc] += Ty, Sc = (Fa[Sc] & FaPart);
        }
        Val[Fs] += Ty; if (Fa[Fs] & CruPart) CVal[UpF] += Ty;
        Push(Fa, Val, Cru[DwF], CTag[DwF]);
        Push(Fa, Val, Cru[DwS], CTag[DwS]);
        Push(Fa, Val, Cru[HalfDF], CTag[HalfDF]);
        Push(Fa, Val, Cru[HalfDS], CTag[HalfDS]);
        ReBuild(Fa, Val, Cru[DwF], CVal[DwF]);
        ReBuild(Fa, Val, Cru[DwS], CVal[DwS]);
        ReBuild(Fa, Val, Cru[HalfDF], CVal[HalfDF]);
        ReBuild(Fa, Val, Cru[HalfDS], CVal[HalfDS]);
        // printf("UpDw %u %u\n", UpF, DwF);
        continue;
      }
      if (LCA == UpS) swap(UpF, UpS), swap(DwF, DwS), swap(Fs, Sc), swap(HalfDF, HalfDS);
      if ((!DwS) && (HalfDS)) {
        LTB = Cru[HalfDS];
        while (Sc ^ LTB) {
          if (Sc > LTB) Val[Sc] += Ty, Sc = (Fa[Sc] & FaPart);
          else LTB = (Fa[LTB] & FaPart);
        }
      }
      while (!(Fa[Sc] & CruPart)) Val[Sc] += Ty, CVal[HalfDS] += Ty, Sc = (Fa[Sc] & FaPart);
      if (LCA == UpF) {
        while (CFa[UpS] != LCA) CVal[UpS] += CLen[UpS] * Ty, CTag[UpS] += Ty, UpS = CFa[UpS];
        Sc = Cru[UpS];
        if ((HalfDF == UpS) || (Fa[Fs] & CruPart)) {
          // fprintf(stderr, "Chg Type 2\n");
          if (!DwF) {
            LTA = Cru[HalfDF];
            while (Fs ^ LTA) {
              if (Fs > LTA) Val[Fs] += Ty, Fs = (Fa[Fs] & FaPart);
              else LTA = (Fa[LTA] & FaPart);
            }
          }
          while (Sc ^ Fs) CVal[UpS] += Ty, Val[Sc] += Ty, Sc = (Fa[Sc] & FaPart);
          CVal[(Fa[Fs] & CruPart) ? UpF : UpS] += Ty, Val[Fs] += Ty;
          continue;
        }
        CVal[UpS] += CLen[UpS] * Ty, CTag[UpS] += Ty, Val[Cru[UpF]] += Ty, CVal[UpF] += Ty;
        if (DwF || (!HalfDF)) {
          // fprintf(stderr, "Chg Type 3\n");
          while (!(Fa[Fs] & CruPart)) Val[Fs] += Ty, CVal[DwF] += Ty, Fs = (Fa[Fs] & FaPart);
          continue;
        }
        // fprintf(stderr, "Chg Type 4\n");
        LTA = Cru[HalfDF];
        while (Fs ^ LTA) {
          if (Fs > LTA) Val[Fs] += Ty, Fs = (Fa[Fs] & FaPart);
          else LTA = (Fa[LTA] & FaPart);
        }
        while (!(Fa[Fs] & CruPart)) Val[Fs] += Ty, CVal[HalfDF] += Ty, Fs = (Fa[Fs] & FaPart);
        continue;
      }
      // fprintf(stderr, "Chg Type 5\n");
      if ((!DwF) && (HalfDF)) {
        LTA = Cru[HalfDF];
        while (Fs ^ LTA) {
          if (Fs > LTA) Val[Fs] += Ty, Fs = (Fa[Fs] & FaPart);
          else LTA = (Fa[LTA] & FaPart);
        }
      }
      while (!(Fa[Fs] & CruPart)) Val[Fs] += Ty, CVal[HalfDF] += Ty, Fs = (Fa[Fs] & FaPart);
      while (UpF != LCA) CVal[UpF] += CLen[UpF] * Ty, CTag[UpF] += Ty, UpF = CFa[UpF];
      while (UpS != LCA) CVal[UpS] += CLen[UpS] * Ty, CTag[UpS] += Ty, UpS = CFa[UpS];
      Val[Cru[LCA]] += Ty, CVal[LCA] += Ty;
    }
  }
}
//  inline void Clr() {}
signed main() {
  freopen("15.in", "r", stdin);
  freopen("15.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  Type = RD(), n = RD(), m = RD(), A = RD(), B = RD(), C = RD(), D = RD();
  // printf("Type %u\n", Type);
  if (Type <= 2) { Random(); return 0; }
  if (Type <= 16) { Str(); return 0; }
  TreeBlock();
  // TreeBlock();
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
g++ P8353_Problem_Provider_CREEP.cpp -o CREEP -O2 -std=c++14 -Wl,--stack=1024000000
*/
/*
17 10 6 935995202 406705156 7034169 418665824
1 1 1 1 1 1 1 7 2
1 7 5
1002663
1 1002671 1002670
424350
1 424351 424340
1 145142 145136
1 854537 854538
1 896515 896525
*/