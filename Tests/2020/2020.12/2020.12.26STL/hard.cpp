#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#define fys 0;
using namespace std;
inline unsigned long long IN() {
  unsigned long long Itmp(0);
  char Ichr(getchar());
  while (Ichr > '9' || Ichr < '0') {
    Ichr = getchar();
  }
  while (Ichr <= '9' && Ichr >= '0') {
    Itmp *= 10;
    Itmp += Ichr - '0';
    Ichr = getchar();
  }
  return Itmp;
}
unsigned int m;
long long ans, Lans(0), Tag(0), DoWt, Lst1, Lst2;
multiset<long long> N;
multiset<long long>::iterator It;
inline int Clr() { return fys; }
int main() {
  // while (1) {
  //   printf("%llu\n", IN());
  // }
  freopen("hard.in", "r", stdin);
  freopen("hard.out", "w", stdout);
  m = int(IN());
  for (register unsigned int i(1); i <= m; ++i) {
    // printf("%u\n", IN());
    Lst2 = Lst1;
    Lst1 = DoWt;
    long long TT(IN());
    DoWt = TT ^ Lans;
    // printf("i = %u, DoWt = %lld, Lans = %lld, TT = %lld\n", i, DoWt, Lans,
    // TT);
    switch (DoWt) {
      case 1: {
        N.insert(IN() - Tag);
        break;
      }
      case 2: {
        long long tmp = IN();
        It = N.find(tmp - Tag);
        if (It != N.end()) {
          N.erase(It);
        }
        break;
      }
      case 3: {
        if (N.empty()) {
          printf("zay\n");
          break;
        }
        Lans = *(--N.end()) + Tag;
        printf("%lld\n", Lans);
      } break;
      case 4: {
        if (N.empty()) {
          printf("zay\n");
          break;
        }
        Lans = *N.begin() + Tag;
        printf("%lld\n", Lans);
        break;
      }
      case 5: {
        It = N.lower_bound(IN() - Tag);
        if (It == N.begin()) {
          printf("cuc\n");
          break;
        }
        if (--It != --N.begin()) {
          Lans = *It + Tag;
          printf("%lld\n", Lans);
          break;
        }
        if (N.empty()) {
          printf("cuc\n");
          break;
        } else {
          Lans = *(--N.end()) + Tag;
          printf("%lld\n", Lans);
          break;
        }
      }
      case 6: {
        It = N.upper_bound(IN() - Tag);
        if (It != N.end()) {
          Lans = *It + Tag;
          printf("%lld\n", Lans);
          break;
        }
        printf("cyc\n");
        break;
      }
      case 7: {
        Tag += IN();
        break;
      }
      default: {
        printf("FYSNBFYSNBFYSNB\n");
        break;
      }
    }
  }
  return fys;
}
/*
5
1 1
1 1
1 2
7 114513
5 114520
*/