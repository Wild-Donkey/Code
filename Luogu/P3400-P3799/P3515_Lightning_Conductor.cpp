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
      if(St) {
        memcpy(tmp, St, sizeof(Typ) * Siz);
        delete[] St;
      }
      St = tmp;
      Ed = St + Siz;
      return; 
    }
  public :
    void Clr() {//clear
      delete[] St;
      Siz = Sizm = 0;
      Ed = St = NULL;
    }
    VEC &operator = (const VEC &x) {//vec to vec
      this->Siz = x.Siz;
      this->Sizm = x.Sizm;
      delete[] this->St;
      this->St = new Typ[x.Sizm];
      this->Ed = St + x.Sizm;
      memcpy(this->St, x.St, sizeof(Typ) * this->Siz);
    }
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
      *(this) = x;
    }
    unsigned Size() {//size of VEC
      return this->Siz;
    }
    Typ *Frnt() {//front
      return St; 
    }
    Typ *End() {//end
      return Ed;
    }
    bool Empty() {//empty
      return (bool)Siz;
    }
    Typ *Inst (const Typ &x) {//Insert
      if(Siz + 1 >= Sizm) {
        Resiz();
      }
      ++Siz;
      *(Ed++) = x;
      return Ed;
    }
    Typ &operator [] (const unsigned &x) {//get items
      while (x + 2 >= Sizm) {
        this->Resiz();
      }
      this->Siz = max(this->Siz, x + 1);
      return this->St[x];
    }
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
  n = RD();
  for (register unsigned i(1); i <= a[0]; ++i) {
    a[i] = RD();
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}

