#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define Wild_Donkey 0
using namespace std;
template <typename Typ>
class VEC {
  private :
    unsigned Siz, Sizm;
    Typ *St, *Ed;
    void Resiz () {
      Typ *tmp(new Typ[Sizm = (Sizm << 1) + 1]);
      memcpy(tmp, St, sizeof(Typ) * Siz);
      delete[] St;
      St = tmp;
      Ed = St + Siz;
      return;
    }
  public :
    VEC() {//Empty VEC
      Siz = Sizm = 0;
      Ed = St = NULL;
    }
    VEC(const Typ &x) {//One elem VEC
      St = new Typ[3];
      Ed = St;
      Siz = 1;
      Sizm = 3;
      *St = x;
    }
    VEC(const VEC &x) {//VEC to VEC
      this->Siz = x.Siz;
      this->Sizm = x.Sizm;
      this->St = new Typ[x.Sizm];
      this->Ed = St + x.Sizm;
      memcpy(this->St, x.St, sizeof(Typ) * this->Siz);
    }
    unsigned Size() {//size of VEC
      return this->Siz;
    }
    Typ *Frnt() {
      return St;
    }
    Typ *End() {
      return Ed;
    }
    bool Empty() {
      return (bool)Siz;
    }
    void Clr() {
      delete[] St;
      Siz = Sizm = 0;
      Ed = St = NULL;
    }
    Typ *Inst (const Typ &x) {
      if(Siz + 1 >= Sizm) {
        Resiz();
      }
      ++Siz;
      *(Ed++) = x;
      return Ed;
    }
    Typ &operator [] (const unsigned &x) const{
      return this->St[x];
    }
//    VEC &operator = (const &VEC) {
////      this->
//    }
//    Typ *Lwr_Bnd(const Typ &x) {
//
//    }
};
inline unsigned RD() {
  unsigned intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
bool b[10005];
VEC<unsigned> a;
inline void Clr() {
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  printf("1*1= 1\n\n1*2= 2\n2*2= 4\n\n1*3= 3\n2*3= 6\n3*3= 9\n\n1*4= 4\n2*4= 8\n3*4=12\n4*4=16\n\n1*5= 5\n2*5=10\n3*5=15\n4*5=20\n5*5=25\n\n1*6= 6\n2*6=12\n3*6=18\n4*6=24\n5*6=30\n6*6=36\n\n1*7= 7\n2*7=14\n3*7=21\n4*7=28\n5*7=35\n6*7=42\n7*7=49\n\n1*8= 8\n2*8=16\n3*8=24\n4*8=32\n5*8=40\n6*8=48\n7*8=56\n8*8=64\n\n1*9= 9\n2*9=18\n3*9=27\n4*9=36\n5*9=45\n6*9=54\n7*9=63\n8*9=72\n9*9=81\n");
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}

