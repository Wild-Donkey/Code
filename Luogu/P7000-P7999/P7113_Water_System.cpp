#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<algorithm>
#include<queue>
using namespace std;
inline unsigned RD() {
  unsigned TmpRD(0);
  char TmpRC(getchar());
  while ((TmpRC < '0') || (TmpRC > '9')) TmpRC = getchar();
  while ((TmpRC >= '0') && (TmpRC <= '9'))
    TmpRD = (TmpRD << 3) + (TmpRD << 1) + TmpRC - '0', TmpRC = getchar();
  return TmpRD;
}
const unsigned long long Base(100000000);
struct BI {
  unsigned Val[5], Len;
  inline BI(const unsigned long long& x) {
    Val[0] = x % Base, Val[1] = x / Base;
    Len = Val[1] ? 2 : 1;
  }
  inline void operator = (const unsigned long long& x) {(*this) = BI(x);}
  inline void operator = (const BI& x) {
    memcpy(Val, x.Val, 20), Len = x.Len;
  }
  inline const char operator > (const unsigned long long& x) const {
    return ((Val[1] * Base) + Val[0]) > x;
  }
  inline const char operator < (const BI& x) const {
    if(Len ^ (x.Len)) return Len < x.Len;
    for (unsigned i(Len - 1); ~i; --i) if(Val[i] ^ (x.Val[i])) return Val[i] < (x.Val[i]);
    return 0;
  }
  inline BI operator + (const BI& x) {
    BI TmpP(*this);
    TmpP.Len = max(Len, x.Len), TmpP.Val[TmpP.Len] = 0;
    for (unsigned i(0); i < TmpP.Len; ++i) {
      TmpP.Val[i] += x.Val[i];
      if(TmpP.Val[i] >= Base) TmpP.Val[i] -= Base, ++(TmpP.Val[i + 1]);
    }
    if(TmpP.Val[TmpP.Len]) ++TmpP.Len;
    return TmpP;
  }
  inline BI operator / (const unsigned& x) {
    BI TmpP(*this);
    unsigned long long TmpD(0), Lef(0);
    for (unsigned i(TmpP.Len - 1); ~i; --i) {
      Lef = Lef * Base + TmpP.Val[i], TmpP.Val[i] = Lef / x, Lef = TmpD % x;
    }
    if((TmpP.Len > 1) && (!(TmpP.Val[TmpP.Len - 1]))) --TmpP.Len;
  }
  
  inline BI operator / (BI x) {
    BI TmpP(*this), Bin(1);
    unsigned CTm(0);
    while (!((*this) < x)) x = x + x, ++CTm;
    x = x / 2, --CTm;
    for (unsigned i(CTm); i; --i) {
      if(!((*this) < x)) {
        
      }
      x = x / 2;
    }
  }
  inline BI operator % (BI x) {
    while (!((*this) < x)) {
      x = x + x;
    }
    x = x / 2;
  }
  inline BI Gcd(BI x) {
    BI TmpG(*this), Me(*this);
    while (x > 0) TmpG = Me, Me = x, x = TmpG % x;
    return x;
  }
};
struct Div {
  BI Up, Down;
  inline Div operator+ (Div x) {
//    printf("Pls %Lf %Lf\n", Up / Down, x.Up / x.Down);
    Div TmpP(*this);
    BI G(Down.Gcd(x.Down));
    x.Down = x.Down / G, Down = Down / G;
    TmpP.Up = (x.Up * Down) + (Up * x.Down);
    Down *= G;
    TmpP.Down = x.Down * Down;
    G = Gcd(TmpP.Up, TmpP.Down);
    TmpP.Up /= G, TmpP.Down /= G;
//    printf("Plused %Lf %Lf\n", TmpP.Up, TmpP.Down);
    return TmpP;
  }
  inline Div Di(unsigned x) {
//    printf("Divi %Lf %Lf / %u\n", Up, Down, x);
    Div TmpP(*this);
    long double G(Gcd(Down, (long double)x));
    TmpP.Down /= G, TmpP.Up /= G, TmpP.Down *= x;
//    printf("Got %Lf %Lf\n", TmpP.Up, TmpP.Down);
    return TmpP;
  }
  inline void Set(unsigned x) {
    Down = 1, Up = x;
  }
  inline void Prt() {
//    printf("%llu %llu\n", (unsigned long long)Up, (unsigned long long)Down);
    char Len(0), TpP;
    while (Ten[Len] <= Up + Epsi) ++Len;
    --Len;
    for (unsigned i(Len); ~i; --i)
      putchar('0' + (TpP = char((Up / Ten[i]) + 0.1))), Up -= TpP * Ten[i];
    putchar(' '), Len = 0;
    while (Ten[Len] <= Down + Epsi) ++Len;
    --Len;
    for (unsigned i(Len); ~i; --i)
      putchar('0' + (TpP = char((Down / Ten[i]) + 0.1))), Down -= TpP * Ten[i];
    putchar(0x0A);
  }
};
struct Node {
  vector<Node*> E;
  Div Val;
  unsigned Idg, Odg;
}N[100005], * Q[100005], * End[100005];
unsigned n, m;
unsigned Hd(0), Tl(0), CntEn(0);
unsigned A, B, C, D;
signed main() {
  freopen("water3.in", "r", stdin);
  freopen("water.out", "w", stdout);
  n = RD(), m = RD();
  for (unsigned i(20); i <= 50; ++i) Ten[i] = Ten[19] * Ten[i - 19];
//  for (unsigned i(1); i <= 50; ++i) printf("%u %Lf\n", i, Ten[i]);
  for (unsigned i(1); i <= n; ++i) {
    N[i].Odg = RD(), N[i].Val.Set(0);
    if(!(N[i].Odg)) End[++CntEn] = N + i;
    for (unsigned j(1); j <= N[i].Odg; ++j) {
      B = RD();
      N[i].E.push_back(N + B);
      ++(N[B].Idg);
    }
  }
  for (unsigned i(1); i <= n; ++i) if(!(N[i].Idg)) Q[++Tl] = N + i, N[i].Val.Set(1);
  while (Hd < Tl) {
    Node* Cur(Q[++Hd]);
//    printf("Cur %u\n", Cur - N);
    for (auto i:Cur->E) if(!(--(i->Idg))) Q[++Tl] = i;
  }
  for (unsigned i(1); i <= n; ++i) {
    if(!(Q[i]->Odg)) continue;
//    printf("Do %u %Lf %Lf\n", Q[i] - N, Q[i]->Val.Up, Q[i]->Val.Down);
    Div No(Q[i]->Val.Di(Q[i]->Odg));
    for (auto j:Q[i]->E) j->Val = j->Val + No;
  }
  for (unsigned i(1); i <= CntEn; ++i) End[i]->Val.Prt();
  return 0;
}
