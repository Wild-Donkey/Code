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
 private:
  unsigned Siz, Sizm;
  Typ *St, *Ed;
  void Resiz() {
    // printf("Rsz nowsz %u msz %u\n", this->Siz, this->Sizm);
    Typ *tmp(NULL);
    Sizm = (Sizm << 1) + 1;
    while (!tmp) {
      tmp = new Typ[Sizm];
      // printf("Failed?!\n");
    }
    // printf("now %u\n", Sizm);
    if (St) {
      memcpy(tmp, St, sizeof(Typ) * Siz);
      delete[] St;
    }
    St = tmp;
    Ed = St + (Siz - 1);
    return;
  }

 public:
  void Clr() {  // clear
    delete[] St;
    Siz = Sizm = 0;
    Ed = St = NULL;
  }
  void operator=(const VEC &x) {  // vec to vec
    this->Siz = x.Siz;
    this->Sizm = x.Sizm;
    delete[] this->St;
    this->St = new Typ[x.Sizm];
    this->Ed = St + x.Sizm - 1;
    memcpy(this->St, x.St, sizeof(Typ) * this->Siz);
  }
  VEC() {  // Empty VEC
    Siz = Sizm = 0;
    Ed = St = NULL;
  }
  VEC(const Typ &x) {  // One elem VEC
    St = new Typ[3];
    Ed = St;
    Siz = 1;
    Sizm = 3;
    *St = x;
  }
  VEC(const VEC &x) {  // VEC to VEC
    *(this) = x;
  }
  unsigned Size() {  // size of VEC
    return this->Siz;
  }
  Typ *Frnt() {  // front
    return St;
  }
  Typ *End() {  // end
    return Ed;
  }
  bool Empty() {  // empty
    return (bool)Siz;
  }
  Typ *Inst(const Typ &x) {  // Insert
    while (Siz + 1 >= Sizm) {
      // printf("Ist %u x %u\n", Sizm, Siz);
      Resiz();
    }
    ++Siz;
    *(Ed++) = x;
    return Ed;
  }
  Typ &operator[](const unsigned &x) {  // get items
    while (x + 2 >= Sizm) {
      // printf("Sizm %u x %u\n", Sizm, x);
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
 private:
  unsigned Len;
  VEC<unsigned> Num;
  static const unsigned PerLen = 100000000, PerPLen = 8;

 public:
  void operator=(char x[]) {  // string to ulll
    unsigned len(strlen(x)), nowat(0);
    for (register unsigned i(0); i < len; ++i) {
      if (x[i] < '0' || x[i] > '9') {
        continue;
      }
      x[nowat++] = x[i];
    }
    len = nowat;
    // printf("%u In total\n", len);
    unsigned Le((len + PerPLen - 1) / PerPLen), le = (len - 1) % PerPLen + 1;
    Le = max((unsigned)1, Le);
    // printf("Hi\n");
    Num[Le - 1] = 0;
    for (register unsigned i(0); i < le; ++i) {
      // printf("at %u char is %c\n", i, x[i]);
      this->Num[Le - 1] *= 10;
      this->Num[Le - 1] += x[i] - '0';
    }
    // printf("Highest %u %u\n", Le - 1, Num[Le - 1]);
    for (register unsigned i(Le - 2); i < 0x3f3f3f3f; --i) {
      Num[i] = 0;
      for (register unsigned j(le + PerPLen * (Le - 2 - i));
           j < (le + PerPLen * (Le - 1 - i)); ++j) {
        // printf("at %u char is %c\n", j, x[j]);
        this->Num[i] *= 10;
        this->Num[i] += x[j] - '0';
      }
      // printf("The %u th %u\n", i, Num[i]);
    }
    while ((!(this->Num[Le - 1])) && Le > 1) {
      --(Le);
    }
    this->Len = Le;
  }
  void operator=(unsigned long long x) {  // ull to ulll
    Len = 0;
    while (x >= PerLen) {
      ++Len;
      Num.Inst((unsigned)(x % PerLen));
      x /= PerLen;
    }
  }
  void operator=(unsigned x) {  // unsigned to ulll
    Len = 0;
    while (x >= PerLen) {
      ++Len;
      Num.Inst((unsigned)(x % PerLen));
      x /= PerLen;
    }
  }
  void operator=(long long x) {  // ll to ulll
    x &= 0x7FFFFFFFFFFFFFFF;
    Len = 0;
    while (x >= PerLen) {
      ++Len;
      Num.Inst(x % PerLen);
      x /= PerLen;
    }
  }
  void operator=(int x) {  // int to ulll
    x &= 0x7FFFFFFF;
    Len = 0;
    while (x >= PerLen) {
      ++Len;
      Num.Inst(x % PerLen);
      x /= PerLen;
    }
  }
  ulll() {  // new ulll;
    Len = 1;
    Num = 0;
    // printf("Here?!\n");
    return;
  }
  ulll(char x[]) {  // string to ulll
    *(this) = x;
  }
  ulll(unsigned long long x) {  // ull to ulll
    *(this) = x;
  }
  ulll(unsigned x) {  // unsigned to ulll
    *this = x;
  }
  ulll(long long x) {  // ll to ulll
    *this = x;
  }
  ulll(int x) {  // int to ulll
    *this = x;
  }
  ulll(ulll &x) {  // ulll to ulll
    *this = x;
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
  void swap(ulll &x, ulll &y) {  // swap(ulll, ulll)
    ulll tmp = x;
    x = y;
    y = tmp;
    return;
  }
  bool operator==(ulll &x) {  // ulll == ulll
    if (this->Len != x.Len) {
      return false;
    }
    for (register unsigned i(0); i < this->Len; ++i) {
      if (this->Num[i] != x.Num[i]) {  // every (bit?)
        return false;
      }
    }
    return true;
  }
  bool operator<(ulll &x) {  // ulll < ulll
    if (this->Len == x.Len) {
      unsigned i(Len);
      while (i < 0x3f3f3f3f && this->Num[i] == x.Num[i]) {
        --i;
      }
      if (i > 0x3f3f3f3f) {
        return 0;
      }
//      printf("Thisway %u\n", i);
      return this->Num[i] < x.Num[i];
    } else {
//      printf("Length big\n"); 
      return this->Len < x.Len;
    }
  }
  bool operator<(unsigned long long &x) {  // ulll < ull
    ulll tmp(x);
    return *this < tmp;
  }
  bool operator<(const unsigned &x) {  // ulll < unsigned
    ulll tmp(x);
    return *this < x;
  }
  bool operator>(ulll &x) {  // ulll < ulll
    if (*this == x) {
      return false;
    }
    return x < *this;
  }
  ulll operator+(ulll &x) {  // ulll + ulll
    ulll ans(*this);
    unsigned tmp(0), Mlen(min(this->Len, x.Len));
    ans.Len = max(this->Len, x.Len);
    for (register unsigned i(0); i < Mlen; ++i) {  // Plus
      ans.Num[i] = this->Num[i] + x.Num[i] + tmp;
      tmp = ans.Num[i] / PerLen;
      ans.Num[i] %= PerLen;
    }
    for (register unsigned i(Mlen); i < x.Len; ++i) {  // Move
      ans.Num[i] = x.Num[i] + tmp;
      tmp = ans.Num[i] / PerLen;
      ans.Num[i] %= PerLen;
    }
    for (register unsigned i(Mlen); i < this->Len; ++i) {  // Move another
      ans.Num[i] = this->Num[i] + tmp;
      tmp = ans.Num[i] / PerLen;
      ans.Num[i] %= PerLen;
    }
    if (tmp) {  // Add the highest
      ++ans.Len;
      ans.Num.Inst(tmp);
    }
    return ans;
  }
  ulll operator-(ulll &x) {  // ulll - ulll
    if (*this < x) {         // x <= this    ulll ans(*this);
      ulll ans(x); 
      unsigned tmp(0), Mlen(this->Len);
      ans.Len = x.Len;
      for (register unsigned i(0); i < Mlen; ++i) {  // Minus
        ans.Num[i] = PerLen + x.Num[i] - this->Num[i] - tmp;
        if (ans.Num[i] >= PerLen) {
          ans.Num[i] -= PerLen;
          tmp = 0;
        } else {
          tmp = 1;
        }
      }
      for (register unsigned i(Mlen); i < x.Len; ++i) {  // Move another
        ans.Num[i] = PerLen + Num[i] - tmp;
        if (ans.Num[i] >= PerLen) {
          ans.Num[i] -= PerLen;
          tmp = 0;
        } else {
          tmp = 1;
        }
      }
      while (!(ans.Num[ans.Len])) {  // Delete '0'
        --ans.Len;
      }
      return ans;
    }
    ulll ans(*this);
    unsigned tmp(0), Mlen(x.Len);
    ans.Len = this->Len;
    for (register unsigned i(0); i < Mlen; ++i) {  // Minus
      ans.Num[i] = PerLen + this->Num[i] - x.Num[i] - tmp;
      if (ans.Num[i] >= PerLen) {
        ans.Num[i] -= PerLen;
        tmp = 0;
      } else {
        tmp = 1;
      }
    }
    for (register unsigned i(Mlen); i < this->Len; ++i) {  // Move another
      ans.Num[i] = PerLen + this->Num[i] - tmp;
      if (ans.Num[i] >= PerLen) {
        ans.Num[i] -= PerLen;
        tmp = 0;
      } else {
        tmp = 1;
      }
    }
    while (!(ans.Num[ans.Len])) {  // Delete '0'
      --ans.Len;
    }
    return ans;
  }
};
class lll {
 public:
  ulll NUM;
  bool Sig;
  void operator=(ulll &x) {  // ulll to lll
    Sig = 0;
    NUM = x;
  }
  void operator=(unsigned x) {  // unsigned to lll
    Sig = 0;
    NUM = x;
  }
  void operator=(unsigned long long x) {  // ulll to lll
    Sig = 0;
    NUM = x;
  }
  void operator=(int x) {  // int to lll
    Sig = x & 0x80000000;
    x &= 0x7FFFFFFF;
    NUM = x;
  }
  void operator=(long long x) {  // ll to lll
    Sig = x & 0x8000000000000000;
    x &= 0x7FFFFFFFFFFFFFFF;
    NUM = x;
  }
  void operator=(char x[]) {  // sting to lll
    unsigned len(strlen(x));
    Sig = 0;
    for (register unsigned i(0); i < len; ++i) {
      if (x[i] == '-') {
        this->Sig = 1;
        break;
      }
    }
    this->NUM = x;
  }
  lll() {  // Empty lll
    Sig = 0;
  }
  lll(ulll &x) {  // ulll to lll
    *this = x;
  }
  lll(ulll &x, bool &y) {  // ulll with sign to lll
    this->Sig = y;
    this->NUM = x;
  }
  lll(unsigned x) {  // unsigned to lll
    *this = x;
  }
  lll(unsigned long long x) {  // ull to lll
    *this = x;
  }
  lll(int x) {  // int to lll
    *this = x;
  }
  lll(long long x) {  // ll to lll
    *this = x;
  }
  lll(char x[]) {  // string to lll
    *this = x;
  }
  lll(lll &x) {  // lll to lll
    *this = x;
  }
  void Print() {
    if (this->Sig) {
      putchar('-');
    }
    this->NUM.Print();
    return;
  }
  void Print(char x) {
    if (this->Sig) {
      putchar('-');
    }
    this->NUM.Print(x);
    return;
  }
  bool operator==(lll &x) {      // lll with lll
    if (!(x.Sig ^ this->Sig)) {  // + & -
      return false;
    } else {
      return this->NUM == x.NUM;
    }
  }
  bool operator<(lll &x) {       // lll & lll
    if (!(this->Sig ^ x.Sig)) {  //+ & -
      if (x.Sig) {
        return this->NUM < x.NUM;
      }
      return x.NUM < this->NUM;
    }
    if (!(this->Sig)) {  // + & +
      return this->NUM < x.NUM;
    }
    if (this->NUM == x.NUM) {  // - & -
      return false;
    }
    return x.NUM < this->NUM;
  }
  bool operator<(ulll &x) {  // lll with ulll
    if (this->Sig) {         // - & +
      return true;
    } else {
      return this->NUM < x;
    }
  }
  lll operator+(lll &x) {  // lll + lll
//    x.Print(' ');
//    this->Print('\n');
    lll ans(*this);
    if (this->Sig ^ x.Sig) {  //+ & -
      ans.NUM = this->NUM - x.NUM;
//      x.Print(' ');
//      this->Print('\n');
      if (this->Sig) {            //- + +
        if (x.NUM < this->NUM) {  // -
//          x.Print(' ');
//          this->Print('\n');
          ans.Sig = 1;
          return ans;
        }
        ans.Sig = 0;
        return ans;
      }                         // + + -
      if (this->NUM < x.NUM) {  //-
        ans.Sig = 1;
        return ans;
      }
      ans.Sig = 0;
      return ans;
    }
    ans.Sig = this->Sig;  // same sign
    ans.NUM = this->NUM + x.NUM;
    return ans;
  }
  lll operator-(lll &x) {  // lll - lll
    lll ans;
    x.Sig = !(x.Sig);
    ans = *this + x;
    x.Sig = !(x.Sig);
    return ans;
  }
  void operator+=(lll &x) {  // lll += lll
    *this = *this + x;
  }
  void operator-=(lll &x) {  // lll -= lll
    *this = *this - x;
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
lll Cnt(0), A, B, C, D, t;
bool b[10005];
char s[500005];
VEC<unsigned> S;
inline void Clr() {}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
//  while (1) {
    //   if (RDsg() & 0x80000000) {
    //     printf("-\n");
    //   } else {
    //     printf("+\n");
    //   }
    // }
    // printf("here?\n");
    scanf("%s", s);
    A = s;
//     A.Print('\n');
    scanf("%s", s);
    B = s;
//     B.Print('\n');
    C = A + B;
    printf("一个整数");
//    C.Print();
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
-4565465
-5

-4565465 - -5 = -4565460

*/
