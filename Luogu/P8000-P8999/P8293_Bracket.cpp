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
unsigned Stack[400005], STop(0), Opp[800005], Pos[400005], Val[400005];
unsigned nn, n, m, Cnt(0), A, B, Mx;
unsigned long long Ans(0), Sum(0);
char Flg(0);
inline unsigned long long DFS(unsigned Dep) {
  for (auto i:List[Dep]) Cur.insert(i);
//  printf("Size %u %u\n", Cur.size(), List[Dep].size());
  for (auto i:Cur) printf("%u ", i); putchar(0x0A); 
  if(!Cur.size()) return 0;
  if(Cur.size() == 1){
    unsigned Er(*(Cur.begin()));
    Cur.erase(Cur.begin());
    unsigned long long TmpA(DFS(Dep + 1));
    Cur.insert(Er); 
    for (auto i:List[Dep]) {
      multiset<unsigned>::iterator It(Cur.find(i));
      Cur.erase(It);
    }
    printf("Size %u f %u %llu\n", Cur.size(), Dep, TmpA);
    return TmpA;
  }
  unsigned Sz(Cur.size()), Mn(*(Cur.begin())), Mx(*(Cur.rbegin()));
  Cur.erase(Cur.begin());
  unsigned long long TmpA(Mn + DFS(Dep + 1));
  Cur.insert(Mn), Cur.erase(--(Cur.end()));
  unsigned long long DFSD(DFS(Dep + 1));
  printf("DFSD %llu %llu -> %llu %llu\n", DFSD, TmpA - Mn, DFSD + Mx, TmpA);
  TmpA = min(Mx + DFSD, TmpA), Cur.insert(Mx);
//  TmpA = min(Mx + DFS(Dep + 1), TmpA), Cur.insert(Mx);
  for (auto i:List[Dep]) {
    multiset<unsigned>::iterator It(Cur.find(i));
    Cur.erase(It);
  }
  printf("Size %u f %u %llu\n", Cur.size(), Dep, TmpA + (unsigned long long)Mn * (Sz - 2));
  return (unsigned long long)Mn * (Sz - 2) + TmpA;
}
int main() {
//  freopen("bracket3.in", "r", stdin);
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
//  Br[0x3f3f3f3f] = 1;
  printf("%llu\n", DFS(1));
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
