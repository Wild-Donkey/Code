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
#define foreplay for
#define wild while
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
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline unsigned RandU(unsigned L, unsigned R) {
  return L + rand() % (R - L + 1);
}
inline double RandD(double L, double R) {
  return L + rand() / 32768.0 * (R - L);
}
char* GetName() {
  char* TheName;
  /*Code Here*/
  return TheName;
}
struct Human;
struct Relation {
  unsigned Value;
  char* Name;
  Human* People;
};
struct Human {
  double AgeYear;
  char Gender, *Name;
  vector<Relation> Social;
} Me;
void AGirlFriendForMe() {
  Relation* Love = new Relation;
  Human* GirlFriend = new Human;
  Love->Value = 1;
  Love->Name = "GirlFriend";
  Love->People = GirlFriend;
  Me.Social.push_back(*Love);
  GirlFriend->AgeYear = RandD(18, 21);
  GirlFriend->Gender = 'F';
  GirlFriend->Name = GetName();
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  srand(time(0));
  Me.Name = "Micheal";
  Me.AgeYear = 19.36158;
  Me.Gender = 'M';
  AGirlFriendForMe();
  //  }
  //  system("pause");
  return Wild_Donkey;
}