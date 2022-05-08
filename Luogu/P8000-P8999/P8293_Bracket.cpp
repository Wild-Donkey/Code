#include<algorithm>
#include<bitset> 
#include<cstdio>
#include<cstring>
#include<iostream>
#include<set>
#include<string>
#include<vector>
using namespace std;
const unsigned long long Mod(998244353);
inline void Mn(unsigned &x) {x -= ((x >= Mod) ? Mod : 0);}
inline void Mn(unsigned long long &x) {x -= ((x >= Mod) ? Mod : 0);}
inline unsigned RD() {
  unsigned RTmp(0);
  char ch(getchar()); 
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') RTmp = RTmp * 10 + ch - '0', ch = getchar(); 
  return RTmp;
}
char Br[800005];
vector<unsigned> List[400005];
multiset<unsigned> Cur;
unsigned Stack[400005], Cnt(0), STop(0), Opp[800005], Pos[400005], Val[400005];
unsigned nn, n, m, A, B, Mx;
unsigned long long Ans(0), Sum(0);
char Flg(0);
int main() {
//  freopen("bracket15.in", "r", stdin);
//  freopen("bracket.out", "w", stdout);
  nn = ((n = RD()) << 1), A = RD(), B = RD();
  scanf("%s", Br);
  for (unsigned i(1); i <= n; ++i) Val[i] = RD();
  for (unsigned i(0); i < nn; ++i)
    if(Br[i] ^ ')') List[++STop].push_back(Val[++Cnt]); else --STop;
//  if(!(A | B)) {printf("0\n"); return 0;}
  for (unsigned i(1); i < n; ++i) if(Val[i] ^ Val[i + 1]) {Flg = 1; break;} 
  Cnt = 0;
  if(!Flg) {
    Val[1] *= (A + B);
    for (unsigned i(1); Cnt + List[i].size(); ++i) {
//      printf("Cnt %u %u Size %u\n", Cnt, i, List[i].size());
      Cnt += List[i].size();
      Ans += Cnt - 1, --Cnt;
    }
    printf("%llu\n", Ans * Val[1]);
    return 0;
  }
  if(A == 0 && B == 1) {
    for (unsigned i(1); List[i].size() + Cur.size(); ++i) {
      for (auto j:List[i]) Sum += j, Cur.insert(j);
      Sum -= (A = *(Cur.rbegin())), Cur.erase(--Cur.end());
      Ans += Sum;
    }
    printf("%llu\n", Ans);
    return 0; 
  }
  if(A & B) {
    for (unsigned i(1); List[i].size() + Cur.size(); ++i) {
      for (auto j:List[i]) Sum += j, Cur.insert(j);
      A = *(Cur.begin()); 
//      printf("%u %llu\n", A, Sum);
      Ans += (Sum - A) + (unsigned long long)A * (Cur.size() - 1);
      Sum -= (A = *(Cur.rbegin())), Cur.erase(--Cur.end());
    }
    printf("%llu\n", Ans);
    return 0;
  } 
  unsigned Beg(1), CurC(0);
  unsigned long long SumD(0);
  vector<unsigned> Do;
  for (; CurC += List[Beg].size(); ++Beg, --CurC) {
//    printf("CurC %u\n", CurC);
    if(CurC > 2) break;
    if(CurC == 2) for (auto i:List[Beg]) SumD += i, Do.push_back(i);
  }
//  printf("Beg %u SumD %llu\n", Beg, SumD);
//  for (auto i:Do) printf("%u ", i); putchar(0x0A);
  if(!Do.size()) {
//    printf("Do %u\n", Sum);
    for (unsigned i(1); List[i].size() + Cur.size(); ++i) {
      for (auto j:List[i]) Sum += j, Cur.insert(j);
      if(Cur.size() == 1) continue;
      if(Cur.size() == 2) {Ans += *(Cur.begin()); break;}
      Ans += (A = *(++(Cur.begin()))) + (*(Cur.begin())) * (Cur.size() - 2);
      Sum -= A, Cur.erase(++Cur.begin());
    }
    printf("%llu\n", Ans);
  } else {
    sort(Do.begin(), Do.end());
    if(!(List[Beg].size())) {printf("%llu\n", SumD - Do.back()); return 0;}
    unsigned long long Tmp(SumD - Do[0]);
    Cur.insert(Do[0]);
    for (unsigned i(Beg); List[i].size() + Cur.size(); ++i) {
      for (auto j:List[i]) Sum += j, Cur.insert(j);
      if(Cur.size() == 1) continue;
      if(Cur.size() == 2) {Tmp += *(Cur.begin()); break;}
      Tmp += (A = *(++(Cur.begin()))) + (*(Cur.begin())) * (Cur.size() - 2);
      Sum -= A, Cur.erase(++Cur.begin());
    }
    Cur.clear(), Cur.insert(Do.back()), Ans = SumD - Do.back();
    for (unsigned i(Beg); List[i].size() + Cur.size(); ++i) {
      for (auto j:List[i]) Sum += j, Cur.insert(j);
      if(Cur.size() == 1) continue;
      if(Cur.size() == 2) {Ans += *(Cur.begin()); break;}
      Ans += (A = *(++(Cur.begin()))) + (*(Cur.begin())) * (Cur.size() - 2);
      Sum -= A, Cur.erase(++Cur.begin());
    }
    printf("%llu\n", min(Ans, Tmp));
  }
  return 0;
}
/*
4 1 1
()()()()
1 1 1 1 

2 0 1
()()
1 3

2 1 0
()()
1 3

3 1 0
()()()
1 3 2

4 1 0
()()()()
1 3 2 4
*/
