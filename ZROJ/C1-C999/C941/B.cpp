#include <bits/stdc++.h>
using namespace std;

const int OutputBufferSize = 10000000;
namespace input {
    #define BUF_SIZE 100000 
    #define OUT_SIZE 100000 
    #define ll long long 
    bool IOerror = 0; 
    inline char nc() {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE; 
        if (p1 == pend) { 
            p1 = buf; pend = buf + fread(buf, 1, BUF_SIZE, stdin); 
            if (pend == p1) { IOerror = 1; return -1; } 
        } 
        return *p1++; 
    } 
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    } 
    inline void read(char &ch) { 
        ch = nc();
        while (blank(ch)) ch = nc();
    }
    inline void read(int &x) {
        char ch = nc(); x = 0; 
        for (; blank(ch); ch = nc()); 
        if (IOerror) return; 
        for (; ch >= '0' && ch <= '9'; ch = nc()) x = x * 10 + ch - '0';
    } 
    #undef ll 
    #undef OUT_SIZE 
    #undef BUF_SIZE 
}; 

namespace output {
    char buffer[OutputBufferSize];
    char *s = buffer;
    inline void flush() {
        assert(stdout != NULL);
        fwrite(buffer, 1, s - buffer, stdout);
        s = buffer;
        fflush(stdout);
    }
    inline void print(const char ch) {
        if (s - buffer > OutputBufferSize - 2) flush();
        *s++ = ch;
    }
    inline void print(char* str) {
        while (*str != 0) print(char(*str++));
    }
    inline void print(int x) {
        char buf[25] = {0}, *p = buf;
        if (x == 0) print('0');
        while (x) *(++p) = x % 10, x /= 10;
        while (p != buf) print(char(*(p--) + '0'));
    }
}
const int maxn = 2005;
const int inf = 0x3f3f3f3f;
char s[maxn][maxn];
int n, m, a[maxn][maxn];
unsigned Que[4000005][2], Hd(0), Tl(0);
int main() {
  memset(a, 0x3f, sizeof(a));
  input::read(n), input::read(m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      input::read(s[i][j]);
      if(s[i][j] == '+') {
        a[i][j] = 0;
        Que[++Tl][0] = i, Que[Tl][1] = j;
      }
      if(s[i][j] == '#') {
        a[i][j] = -1;
      }
    }
  }
  for (register unsigned i(0); i <= n + 1; ++i) {
    a[i][0] = a[i][m + 1] = -1; 
  }
  for (register unsigned i(0); i <= m + 1; ++i) {
    a[0][i] = a[n + 1][i] = -1; 
  }
  register unsigned Nowx, Nowy;
  while (Hd < Tl) {
    Nowx = Que[++Hd][0], Nowy = Que[Hd][1];
    register unsigned i(Nowx), j(Nowy);
    while(a[Nowx][Nowy] < a[i + 1][j]) {
      if(a[Nowx][Nowy] + 1 < a[i + 1][j]) {
        a[++i][j] = a[Nowx][Nowy] + 1;
        Que[++Tl][0] = i, Que[Tl][1] = j;
      } else {
        ++i;
      }
    }
    i = Nowx, j = Nowy;
    while(a[Nowx][Nowy] < a[i - 1][j]) {
      if(a[Nowx][Nowy] + 1 < a[i - 1][j]) {
        a[--i][j] = a[Nowx][Nowy] + 1;
        Que[++Tl][0] = i, Que[Tl][1] = j;
      } else{
        --i;
      } 
    }
    i = Nowx, j = Nowy;
    while(a[Nowx][Nowy] < a[i][j + 1]) {
      if(a[Nowx][Nowy] + 1 < a[i][j + 1]) {
        a[i][++j] = a[Nowx][Nowy] + 1;
        Que[++Tl][0] = i, Que[Tl][1] = j;
      } else{
        ++j;
      } 
    }
    i = Nowx, j = Nowy;
    while(a[Nowx][Nowy] < a[i][j - 1]) {
      if(a[Nowx][Nowy] + 1 < a[i][j - 1]) {
        a[i][--j] = a[Nowx][Nowy] + 1;
        Que[++Tl][0] = i, Que[Tl][1] = j;
      } else{
        --j;
      } 
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == -1) {
          output::print('#');
      } else if (a[i][j] == inf) {
          output::print('X');
      } else {
          output::print(a[i][j]);
      }
      output::print(" \n"[j == m]);
    }
  }
  output::flush();
  return 0;
}

