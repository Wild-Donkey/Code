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
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned BuyToiletPaper() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
vector<unsigned> PaperRoll[1000005];
unsigned Toilet[1000005], PaperShelf[1000005], WhoseShit, Cleaner, Popularity, Cities, MassofShit;
char Rush;
struct Human {
  unsigned Dirty, Shit;
  inline const char operator< (const Human& x) const {return Dirty > x.Dirty;}
}Humanity[1000005];
inline void WipeAss() {
  memset(Toilet, 0, (Popularity + 1) << 2);
  for (unsigned i(1); i <= Popularity; ++i) Humanity[i].Dirty = Humanity[i].Shit = 0;
  for (unsigned i(1); i <= Popularity; ++i) PaperRoll[i].clear();
  Popularity = BuyToiletPaper(), Cleaner = WhoseShit = Rush = 0;
}
signed main() {
//  freopen("discuss2.in", "r", stdin);
//  freopen("discuss.out", "w", stdout);
  Cities = BuyToiletPaper();
  for (unsigned City(1); City <= Cities; ++City){
    WipeAss();
    for (unsigned i(1); i <= Popularity; ++i) {
      MassofShit = BuyToiletPaper(), Humanity[i].Shit = i;
      for (unsigned j(MassofShit); j; --j) PaperShelf[j] = BuyToiletPaper();
      sort(PaperShelf + 1, PaperShelf + MassofShit + 1);
      Humanity[i].Dirty = unique(PaperShelf + 1, PaperShelf + MassofShit + 1) - PaperShelf - 1;
      for (unsigned j(Humanity[i].Dirty); j; --j) PaperRoll[i].push_back(PaperShelf[j]);
    }
    sort(Humanity + 1, Humanity + Popularity + 1);
    for (unsigned i(1); i <= Popularity; ++i) {
      Cleaner = Humanity[i].Shit, WhoseShit = 0x3f3f3f3f;
//      printf("Shiter %u\n", Cleaner);
      for (auto j:PaperRoll[Cleaner]) if(WhoseShit ^ 0x3f3f3f3f) {
        if(Toilet[j] ^ WhoseShit) {
          WhoseShit = max(WhoseShit, Toilet[j]);
          Rush = 1; break;
        }
      } else WhoseShit = Toilet[j];
      if(Rush) break;
      for (auto j:PaperRoll[Cleaner]) Toilet[j] = i;
//      for (unsigned j(1); j <= Popularity; ++j) printf("%u ", Toilet[j]); putchar(0x0A);
    }
    if(Rush) printf("YES\n%u %u\n", Humanity[WhoseShit].Shit, Cleaner);
    else printf("NO\n");
  }
  return Wild_Donkey;
}
/*
1
5
4 1 2 3 5
6 1 2 2 3 4 5
6 1 2 5 5 5 5
0
0
*/

