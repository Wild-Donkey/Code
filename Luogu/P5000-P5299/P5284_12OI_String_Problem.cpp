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
unsigned n, t, A, B;
struct Suffix_Array {
  unsigned SA[200005], RK[400005], ST[18][200005], BucSize;
  inline void Prt() {
    printf("RK:"); for (unsigned i(1); i <= n; ++i) printf("%u ", RK[i]); putchar(0x0A);
    printf("SA:"); for (unsigned i(1); i <= n; ++i) printf("%u ", SA[i]); putchar(0x0A);
    printf("Ht:"); for (unsigned i(1); i <= n; ++i) printf("%u ", ST[0][i]); putchar(0x0A);
  }
  inline void Init(char* x) {
    memset(RK, 0, (n + 1) << 3);
    unsigned Tmp[(n + 1) << 1], Bucket[max((unsigned)27, n + 1)], Cnt(0), Cons(1);
    BucSize = 26;
    memset(Bucket, 0, (BucSize + 1) << 2);
    for (unsigned i(1); i <= n; ++i) ++Bucket[RK[i] = x[i] - 'a' + 1];
    for (unsigned i(1); i <= BucSize; ++i) Bucket[i] += Bucket[i - 1];
    for (unsigned i(1); i <= n; ++i) SA[Bucket[RK[i]]--] = i;
//    Prt();
    while (Cnt < n) {
      memset(Bucket, 0, (BucSize + 1) << 2);
      for (unsigned i(1); i <= n; ++i) ++Bucket[RK[i]];
      for (unsigned i(1); i <= BucSize; ++i) Bucket[i] += Bucket[i - 1];
      unsigned Top(0);
      for (unsigned i(n); i; --i) if(SA[i] > Cons) Tmp[++Top] = SA[i] - Cons;
      for (unsigned i(++Top); i <= n; ++i) Tmp[i] = i;
//      for (unsigned i(1); i <= n; ++i) printf("%u ", Tmp[i]); putchar(0x0A);
      for (unsigned i(1); i <= n; ++i) SA[Bucket[RK[Tmp[i]]]--] = Tmp[i];
      memcpy(Tmp, RK, (n + 1) << 3);
      RK[SA[1]] = 1, Cnt = 1;
      for (unsigned i(2); i <= n; ++i)
        if((Tmp[SA[i]] ^ Tmp[SA[i - 1]]) || (Tmp[SA[i] + Cons] ^ Tmp[SA[i - 1] + Cons])) 
          RK[SA[i]] = ++Cnt;
        else RK[SA[i]] = Cnt;
      Cons <<= 1, BucSize = Cnt;
//      Prt();
    }
    memset(ST[0], 0, (n + 1) << 2);
    for (unsigned i(1); i < n; ++i) if(RK[i] > 1) {
      unsigned& H(ST[0][RK[i]]);
      while (x[i + H] == x[SA[RK[i] - 1] + H]) ++H;
      if(H) ST[0][RK[i + 1]] = H - 1;
    }
    ST[0][1] = 0;
    for (unsigned i(1), j(1); (j << 1) <= n; ++i, j <<= 1)
      for (unsigned k(n - j); k; --k)
        ST[i][k] = min(ST[i - 1][k], ST[i - 1][k + j]);
  }
  inline void Find(unsigned Pos, unsigned Len) {
    A = B = Pos;
//    while (ST[0][B + 1] >= Len) ++B;
//    while (ST[0][A] >= Len) --A; 
    B = Pos + 1;
    for (unsigned i(17); ~i; --i)
      if((B + (1 << i) - 1 <= n) && (ST[i][B] >= Len)) 
        B += (1 << i);// printf("%u %u %u\n", i, B, ST[i][B]);
    --B;
    A = Pos;
    for (unsigned i(17); ~i; --i) 
      if((A > (1 << i)) && (ST[i][A - (1 << i)] >= Len)) A -= (1 << i);
    --A;
    if(ST[0][Pos] < Len) A = Pos;
  }
}Su_Ar;
char a[200005];
struct Node {
  vector<Node*> E;
  unsigned long long Val;
  unsigned Idg;
  inline void LinkTo(Node* x);
}N[5000005], *NB, *CntN(N);
struct String {
  Node* Nd;
  unsigned Len, L;
  inline const char operator< (const String& x) const { 
    return (Len ^ x.Len) ? (Len > x.Len) : (Su_Ar.RK[L] < Su_Ar.RK[x.L]);
  }
  inline void Input() { L = RD(), Len = RD() - L + 1;}
}TpA[200005], TpB[200005];
inline void Node::LinkTo(Node* x) { 
//  printf("%u %u\n", this - N, x - N);
  E.push_back(x), ++(x->Idg);
}
Node* From;
struct Seg {
  Node *Emp;
  Seg *LS, *RS;
  inline void Insert(unsigned L, unsigned R, Seg *x, String **List, unsigned Len);
  inline void Link(unsigned L, unsigned R) {
    if(A <= L && R <= B) {From->LinkTo(Emp); return;}
    unsigned Mid((L + R) >> 1);
    if(A <= Mid && LS) LS->Link(L, Mid);
    if(B > Mid && RS) RS->Link(Mid + 1, R);
  }
}S[5000005], *Ver[200005], *CntS(S);
inline void Seg::Insert(unsigned L, unsigned R, Seg *x, String **List, unsigned Len) {
  Emp = ++CntN;
  if(L == R) {
    for (unsigned i(1); i <= Len; ++i) Emp->LinkTo(List[i]->Nd);
    if(x) Emp->LinkTo(x->Emp);
    return;
  }
//  printf("Insert %u To [%u, %u]\n", Len, L, R);
//  for (unsigned i(1); i <= Len; ++i)
//    printf("Nd %u Frm %u Len %u Rk %u\n", List[i]->Nd - N, List[i]->L, List[i]->Len, Su_Ar.RK[List[i]->L]);
  unsigned Mid((L + R) >> 1), LenR(0);
  while (Len && Su_Ar.RK[List[Len]->L] > Mid) ++LenR, --Len;
  if(Len) (LS = ++CntS)->Insert(L, Mid, x ? x->LS : NULL, List, Len);
  else LS = x ? x->LS : NULL;
  if(LenR) (RS = ++CntS)->Insert(Mid + 1, R, x ? x->RS : NULL, List + Len, LenR);
  else RS = x ? x->RS : NULL;
  if(LS) Emp->LinkTo(LS->Emp);
  if(RS) Emp->LinkTo(RS->Emp);
}
unsigned long long Ans(0);
unsigned m, ma, mb;
inline void Clr() {
  memset(N, 0, (m + 1) * sizeof(Node));
  memset(S, 0, (CntS - S + 1) * sizeof(Seg));
  memset(Ver, 0, (n + 2) << 3);
  CntN = N, CntS = S, Ans = 0;
  memset(a, 0, n + 1);
  scanf("%s", a + 1); 
  n = strlen(a + 1);
  Su_Ar.Init(a);
//  Su_Ar.Prt();
}
signed main() {
//  freopen("P5284_9.in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    CntN = N + (ma = RD());
    for (unsigned i(1); i <= ma; ++i)
      TpA[i].Input(), (TpA[i].Nd = N + i)->Val = TpA[i].Len;
//    printf("Idg9 %u\n", N[9].Idg);
    sort(TpA + 1, TpA + ma + 1);
//    for (unsigned i(1); i <= ma; ++i) printf("%u ", TpA[i].Nd - N); putchar(0x0A);
    String* Ins[ma + 1];
    for (unsigned i(1), j(n + 1); i <= ma; ) {
      unsigned CntI(0), Cur(TpA[i].Len);
      while (TpA[i].Len == Cur) Ins[++CntI] = TpA + (i++);
      (Ver[Cur] = ++CntS)->Insert(1, n, Ver[j], Ins, CntI);
//      printf("Insert Len %u Ver %u, CntI %u\n", Cur, Ver[Cur]->Emp - N, CntI);
      j = Cur;
    }
//    printf("Done\n");
    for (unsigned i(n); i; --i) if(!Ver[i]) Ver[i] = Ver[i + 1];
//    printf("Start Link B To A\n");
    printf("Done\n");
    NB = CntN, mb = RD();
    for (unsigned i(1); i <= mb; ++i) {
      TpB[i].Input(), From = NB + i;
      Su_Ar.Find(Su_Ar.RK[TpB[i].L], TpB[i].Len);
//      printf("RK Range [%u, %u]\n", A, B);
      if(Ver[TpB[i].Len]) Ver[TpB[i].Len]->Link(1, n);
    }
//    printf("Start Link A To B\n");
    m = RD();
    for (unsigned i(1); i <= m; ++i) 
      A = RD(), B = RD(), N[A].LinkTo(NB + B);
    m = CntN - N + mb;
//    printf("m %u\n", m);
    Node* Que[m + 1], **Hd(Que), **Tl(Que);
    for (Node* i(N + m); i > N; --i) if(!(i->Idg)) *(++Tl) = i;
//    printf("Idg9 %u\n", N[9].Idg);
    while (Hd < Tl) {
      Node* Cur(*(++Hd));
//      printf("Extend %u\n", Cur - N);
      for (auto i:Cur->E) if(!(--(i->Idg))) *(++Tl) = i;
    }
    printf("Len %u Node %u Seg %u\n", n, CntN - N, CntS - S);
    if(Tl - Que != m) {printf("-1\n"); continue;}
    for (Node**i(Tl); i > Que; --i) {
      Node* Cur(*i);
      unsigned long long Mx(0);
      for (auto j:Cur->E) Mx = max(Mx, j->Val);
      Cur->Val += Mx, Ans = max(Ans, Cur->Val);
//      printf("%u Val %u From %u\n", Cur - N, Cur->Val, Tw - N);
    }
    printf("%llu\n", Ans);
  }
  return Wild_Donkey;
}

