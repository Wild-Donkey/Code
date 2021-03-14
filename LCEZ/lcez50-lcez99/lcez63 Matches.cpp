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
    const VEC &operator = (const VEC &x) const{
//      this->
    }
//    Typ *Lwr_Bnd(const Typ &x) {
//      
//    } 
};
class ulll {
  private :
    unsigned Len;
    VEC<unsigned> Num;
    static const unsigned PerLen = 100000000, PerPLen = 8;
  public :
    ulll () {//new ulll;
      Len = 1;
      Num.Inst(0);
    }
    ulll (ulll &x) {
      this->Len = x.Len;
      this->Num = x.Num;
    }
    ulll (unsigned long long x) {//ull to ulll
      Len = 0;
      while (x >= PerLen) {
        ++Len;
        Num.Inst((unsigned)(x % PerLen));
        x /= PerLen;
      }
    }
    ulll (unsigned x) {//unsigned to ulll
      Len = 0;
      while (x >= PerLen) {
        ++Len;
        Num.Inst(x % PerLen);
        x /= PerLen;
      }
    }
    ulll (int x) {
      Len = 0;
      while (x >= PerLen) {
        ++Len;
        Num.Inst(x % PerLen);
        x /= PerLen;
      }
    }
    ulll (char x[]) {
      this->Len = 1;
      unsigned len(strlen(x)), Le((len + PerPLen - 1) / PerPLen), le = len - Le * PerPLen;
      this->Len = Le;
      for (register unsigned i(0); i < le; --i) {
        this->Num[this->Len - 1] *= 10;
        this->Num[this->Len - 1] += x[i] - '0';
      }
      for (register unsigned i(Le - 2); i < 0x3f3f3f3f; --i) {
        for (register unsigned j(le + PerPLen * (Le - 2 - i)); j < (le + PerPLen * (Le - 1 - i)); ++j) {
          this->Num[i] *= 10;
          this->Num[i] += x[j] - '0';
        }
      }
      while((!(this->Num[this->Len - 1])) && this->Len > 1) {
        --(this->Len);
      }
    }
    const bool operator< (const ulll &x) const{//ulll with ulll
      if(this->Len == x.Len) {
        unsigned i(Len);
        while(i < 0x3f3f3f3f && this->Num[i] == x.Num[i]) {
          --i;
        }
        if(i > 0x3f3f3f3f){
          return 0;
        }
        return this->Num[i] < x.Num[i];
      }
      else {
        return this->Len < x.Len;
      }
    }
    bool operator< (const unsigned long long &x) {//ulll with ull
      ulll tmp(x);
      return *this < x;
    }
    bool operator< (const unsigned &x) {//ulll with unsigned
      ulll tmp(x);
      return *this < x;
    }
//    bool operator> () {
//      return 
//    }
    ulll operator+ (const ulll &x) {
      ulll ans(*this);
      unsigned tmp, Mlen(min(this->Len, x.Len));
      ans.Len = max(this->Len, x.Len);
      for (register unsigned i(0); i < Mlen; ++i) {
        ans.Num[i] = this->Num[i] + x.Num[i] + tmp;
        tmp = ans.Num[i] / PerLen;
      }
      if (this->Len < x.Len) {
        for (register unsigned i(Mlen); i < x.Len; ++i) {
          ans.Num[i] = x.Num[i] + tmp;
          tmp = ans.Num[i] / PerLen;
        }
      }
      else {
        for (register unsigned i(Mlen); i < this->Len; ++i) {
          ans.Num[i] = this->Num[i] + tmp;
          tmp = ans.Num[i] / PerLen;
        }
      }
      if(tmp) {
        ans.Num[++(ans.Len)] = tmp;
      }
      return ans;
    }
    ulll operator- (const ulll &x) {
      
    }
};
class lll {
  private :
    ulll NUM;
    bool Sig;
  public :
    const bool operator <(const lll &x) const{
      if(!(this->Sig ^ x.Sig)) {
        if(!(this->Sig)) {
          return this->NUM < x.NUM;
        }
        else {
          return x.NUM < this->NUM;
        }
      }
      else {
        
      }
    }
    bool operator <(const ulll &x) {//lll with ulll
      if (this->Sig) {
        return true;
      }
      else {
        return this->NUM < x;
      }
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
ulll a[10005], m, n, Cnt(0), A, B, C, D, t;
bool b[10005];
char s[1005];
VEC<unsigned> S; 
inline void Clr() {
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  printf("You can do it:\n0 6 9 14 41 77 111\n");
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
