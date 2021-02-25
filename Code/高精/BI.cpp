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
        printf("Sizm %u x %u\n", Sizm, x);
        this->Resiz();
      }
      this->Siz = max(this->Siz, x + 1);
      return this->St[x];
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
    ulll &operator= (char x[]){// string to ulll
      string tmp;
      this->Num.Clr();
      unsigned tmpcnt(0), len(strlen(x));
      for (register unsigned i(0); i < len; ++i) {
        if (x[i] < '0' || x[i] > '9') {
          --i;
          --len;
          continue;
        }
        tmp[tmpcnt] = x[i];
        ++tmpcnt;
      }
      len = tmpcnt;
      unsigned Le((len + PerPLen - 1) / PerPLen), le = len % PerPLen;
      Le = max((unsigned)1, Le);
      printf("Hi\n");
      Num[Le - 1] = 0;
      for (register unsigned i(0); i < le; ++i) {
        printf("at %u\n", i); 
        this->Num[Le - 1] *= 10;
        this->Num[Le - 1] += x[i] - '0';
      }
      printf("again\n");
      for (register unsigned i(Le - 2); i < 0x3f3f3f3f; --i) {
        Num[i] = 0;
        for (register unsigned j(le + PerPLen * (Le - 2 - i)); j < (le + PerPLen * (Le - 1 - i)); ++j) {
          this->Num[i] *= 10;
          this->Num[i] += tmp[j] - '0';
        }
      }
      while((!(this->Num[Le - 1])) && Le > 1) {
        --(Le);
      }
      this->Len = Le;
    }
    ulll &operator= (unsigned long long x) {//ull to ulll
      Len = 0;
      while (x >= PerLen) {
        ++Len;
        Num.Inst((unsigned)(x % PerLen));
        x /= PerLen;
      }
    }
    ulll &operator= (const ulll &x) {
      this->Len = x.Len;
      this->Num = x.Num;
    }
    ulll () {//new ulll;
      Len = 1;
      Num.Inst(0);
    }
    ulll (ulll &x) {
      this->Len = x.Len;
      this->Num = x.Num;
    }
    ulll (unsigned long long x) {//ull to ulll
      *(this) = x;
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
      *(this) = x;
    }
    void Print() {
      char Fmt[105];
      sprintf(Fmt, "%%0%uu", PerPLen);
      printf("%u", Num[Len - 1]);
      for (register unsigned i(Len - 2); i < 0x3f3f3f3f; --i) {
        printf(Fmt, Num[i]);
      }
    }
    void Print(char x) {
      Print();
      putchar(x); 
      return;
    }
    bool operator< (ulll &x) {//ulll with ulll
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
    bool operator< (unsigned long long &x) {//ulll with ull
      ulll tmp(x);
      return *this < tmp;
    }
    bool operator< (const &x) {//ulll with unsigned
      ulll tmp(x);
      return *this < x;
    }
//    bool operator> () {
//      return 
//    }
    ulll operator+ (ulll &x) {
      ulll ans(*this);
      unsigned tmp(0), Mlen(min(this->Len, x.Len));
      ans.Len = max(this->Len, x.Len);
      for (register unsigned i(0); i < Mlen; ++i) {//Plus
        ans.Num[i] = this->Num[i] + x.Num[i] + tmp;
        tmp = ans.Num[i] / PerLen;
        ans.Num[i] %= PerLen;
      }
      printf("?\n");
      for (register unsigned i(Mlen); i < x.Len; ++i) {//Move
        ans.Num[i] = x.Num[i] + tmp;
        tmp = ans.Num[i] / PerLen;
        ans.Num[i] %= PerLen;
        printf("%u %u %u\n", i, ans.Num[i], tmp);
      }
      printf("!\n");
      for (register unsigned i(Mlen); i < this->Len; ++i) {//Move another
        ans.Num[i] = this->Num[i] + tmp;
        tmp = ans.Num[i] / PerLen;
        ans.Num[i] %= PerLen;
      }
      printf("FA\n");
      if(tmp) {//Add the highest
        printf("yes\n");
        ++ans.Len;
        ans.Num.Inst(tmp);
//        ans.Num[++(ans.Len)] = tmp;
      }
      return ans;
    }
//    ulll operator- (const ulll &x) {
//      
//    }
};
class lll {
  private :
    ulll NUM;
    bool Sig;
  public :
    bool operator <(lll &x) {
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
    bool operator <(ulll &x) {//lll with ulll
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
//  while(1) {
    cin.getline(s, 505);
    A = s;
    A.Print('\n');
    cin.getline(s, 505);
    B = s;
    B.Print('\n');
    C = A + B;
    C.Print('\n');
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
2389562348956348975
93846237894623642378423
93848627456972598727398
93870133518113205868138

*/
