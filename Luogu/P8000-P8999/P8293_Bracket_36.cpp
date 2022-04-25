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
unsigned Stack[400005], STop(0), Opp[800005], Pos[400005], Val[400005], Lay[400005];
unsigned nn, n, m, Cnt(0), A, B, Mx;
unsigned long long Ans(0);
char Flg(0);
int main() {
//  freopen("bracket3.in", "r", stdin);
//  freopen("bracket.out", "w", stdout);
  nn = ((n = RD()) << 1), A = RD(), B = RD();
  scanf("%s", Br);
  for (unsigned i(0); i < nn; ++i) 
    if(Br[i] ^ ')') Pos[++Cnt] = Stack[++STop] = i, Lay[Cnt] = STop;// printf("Caonidie %u %u\n", Cnt, STop);
    else Opp[Stack[STop]] = i, Opp[i] = Stack[STop--];// printf("Caonima\n");
//  for (unsigned i(1); i <= n; ++i) printf("%u %u ", Lay[i], ); putchar(0x0A);
//  printf("Val\n"); 
//  printf("%u\n", RD());
  for (unsigned i(1); i <= n; ++i) Val[i] = RD();
  for (unsigned i(1); i < n; ++i) if(Val[i] ^ Val[i + 1]) {Flg = 1; break;} 
  if(!Flg) {
    unsigned La[400005];
    memset(La, 0, sizeof(La));
    Val[1] *= A + B;
//    Val[1] = 20000000;
    for (unsigned i(1); i <= n; ++i) ++La[Lay[i]];
//    La[1] = 400000;
    for (unsigned i(1); La[i]; ++i) {
      Ans += (unsigned long long)Val[1] * (La[i] - 1);
      La[i + 1] += La[i] - 1;
    }
    printf("%llu\n", Ans);
    return 0;
  }
  if(!(A | B)) {printf("0\n"); return 0;}
  if(A == 0 && B == 1) {
    vector<unsigned> List[400005];
    multiset<unsigned> Cur;
    unsigned long long Sum(0);
    for (unsigned i(1); i <= n; ++i) List[Lay[i]].push_back(Val[i]);
    for (unsigned i(1); List[i].size() + Cur.size(); ++i) {
      for (auto j:List[i]) Sum += j, Cur.insert(j);
      Sum -= (A = *(Cur.rbegin())), Cur.erase(--Cur.end());
      Ans += Sum;
    }
    printf("%llu\n", Ans);
    return 0; 
  }
  if(A & B) {
    vector<unsigned> List[400005];
    multiset<unsigned> Cur;
    unsigned long long Sum(0);
    for (unsigned i(1); i <= n; ++i) List[Lay[i]].push_back(Val[i]);
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
  Br[0x3f3f3f3f] = 0;
  vector<unsigned> List[400005];
  multiset<unsigned> Cur;
  unsigned long long Sum(0);
  for (unsigned i(1); i <= n; ++i) List[Lay[i]].push_back(Val[i]);
  for (unsigned i(1); (List[i].size() + Cur.size()) > 1; ++i) {
    for (auto j:List[i]) Sum += j, Cur.insert(j);
//      printf("%u %llu\n", A, Sum);
    Sum -= (A = *(Cur.rbegin())), Cur.erase(A);
    Ans += A + (unsigned long long)(*(Cur.begin())) * (Cur.size() - 2);
  }
  printf("%llu\n", Ans);
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
*/
