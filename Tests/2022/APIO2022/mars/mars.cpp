#include "mars.h"
#include <vector>
#include <string>
#include <cstring>
using namespace std;
inline unsigned Find(unsigned* Fa, unsigned x) {
  unsigned Stack[128], Cnt(0);
  // printf("Find %u = ", x);
  while (Fa[x] ^ x) Stack[++Cnt] = x, x = Fa[x];
  while (Cnt) Fa[Stack[Cnt--]] = x;
  // printf("%u\n", x);
  return x;
}
inline void Merge(unsigned* Fa, unsigned x, unsigned y) {
  // printf("Merge %u %u\n", x, y);
  Fa[Find(Fa, x)] = Find(Fa, y);
}
std::string process(std::vector <std::vector<std::string> > a, int i, int j, int k, int n) {
  string Rt(string(100, '0'));
  k = ((n - k - 1) << 1);
  unsigned N(n << 1);
  if ((i == k) || (j == k)) {
    if (i == j) {
      unsigned Ver[3][50], Hor[3][50], Len(N - k + 1), Ans(0);
      if (k ^ (N - 2)) for (unsigned I(90); I < 100; ++I) Ans = (Ans << 1) + a[2][2][I] - '0';
      // printf("(%u, %u) Ans %u\n", i, j, Ans);
      for (unsigned I(2); I < Len; ++I) {
        Ver[0][I] = a[2][1][((I - 2) << 1) + 1];
        Ver[1][I] = a[2][1][(I - 2) << 1];
        Ver[2][I] = a[2][0][(I - 2) << 1];
      }
      if (k == (N - 2)) Ver[0][2] = a[2][2][0];
      Ver[1][1] = a[1][1][0], Ver[2][1] = a[1][0][0], Ver[2][0] = a[0][0][0];
      for (unsigned I(2); I < Len; ++I) {
        Hor[0][I] = a[1][2][((I - 2) << 1) + 1];
        Hor[1][I] = a[1][2][(I - 2) << 1];
        Hor[2][I] = a[0][2][(I - 2) << 1];
      }
      if (k == (N - 2)) Hor[0][2] = a[2][2][0];
      Hor[1][1] = a[1][1][0], Hor[2][1] = a[0][1][0], Hor[2][0] = a[0][0][0];
      unsigned Cnt[4];
      Cnt[3] = 0;
      for (unsigned I(0); I < 3; ++I) {
        unsigned Last(0);
        for (unsigned J(Len - 1); J > (2 - I); --J)
          if (Ver[I][J] == '1') {
            if (!Last) Last = Ver[I][J] = ++Cnt[3];
            else Ver[I][J] = Last;
          }
          else Ver[I][J] = Last = 0;
        for (unsigned J(2 - I); J < Len; ++J)
          if (Hor[I][J] == '1') {
            if (!Last) Last = Hor[I][J] = ++Cnt[3];
            else Hor[I][J] = Last;
          }
          else Hor[I][J] = Last = 0;
        Cnt[I] = Cnt[3], Ver[I][2 - I] = Hor[I][2 - I];
      }
      // for (unsigned I(0); I < 3; ++I) {
      //   printf("Layer %u:\n", I);
      //   for (unsigned J(0); J < Len; ++J) printf("%u ", Hor[I][J]); putchar(0x0A);
      //   for (unsigned J(0); J < Len; ++J) printf("%u ", Ver[I][J]); putchar(0x0A);
      // }
      unsigned Fa[128], Stack[45], STop(0);
      for (unsigned I(1); I < 128; ++I) Fa[I] = I;
      if (k ^ (N - 2)) for (unsigned I(1); I <= Cnt[0]; ++I) {
        unsigned Cur(((a[2][2][(I - 1) << 1] - '0') << 1) + a[2][2][((I - 1) << 1) + 1] - '0');
        switch (Cur) {
        case 0: { /*printf("( "),*/ Stack[++STop] = I; break;}
        case 1: { /*printf(") "),*/ Merge(Fa, Stack[STop--], I); break;}
              // case 2: { printf("() "); break;}
        case 3: { /*printf(")( "), */Merge(Fa, Stack[STop--], I), Stack[++STop] = I; break; }
        }
      }
      for (unsigned I(0); I < 2; ++I) {
        for (unsigned J(2 - I); J < Len; ++J) {
          // printf("Try %u %u\n", I, J);
          if (Hor[I][J] && Hor[I + 1][J]) Merge(Fa, Hor[I][J], Hor[I + 1][J]);
          if (Ver[I][J] && Ver[I + 1][J]) Merge(Fa, Ver[I][J], Ver[I + 1][J]);
        }
      }
      if (!i) {
        unsigned Lg(0);
        for (unsigned I(1); I <= Cnt[2]; ++I) if (Fa[I] == I) ++Ans;
        while (Ans) Rt[Lg++] = (Ans & 1) + '0', Ans >>= 1;
        return Rt;
      }
      char Ava[128];
      unsigned New[45], NC(0);
      memset(Ava, 0, sizeof(Ava));
      for (unsigned I(Cnt[1] + 1); I <= Cnt[2]; ++I) Ava[Find(Fa, I)] = 1;
      for (unsigned I(1); I <= Cnt[2]; ++I) if ((Fa[I] == I) && (!Ava[I])) ++Ans;
      for (unsigned I(99); I >= 90; --I) Rt[I] = '0' + (Ans & 1), Ans >>= 1;
      memset(Ava, 0, sizeof(Ava));
      for (unsigned I(Cnt[1] + 1); I <= Cnt[2]; ++I) ++Ava[New[++NC] = Fa[I]];
      // printf("New:"); for (unsigned I(1); I <= NC; ++I) printf("%u ", New[I]); putchar(0x0A);
      for (unsigned I(1); I <= NC; ++I) if (Ava[New[I]] == 1) New[I] = 0, Rt[(I - 1) << 1] = '1';
      // printf("New:"); for (unsigned I(1); I <= NC; ++I) printf("%u ", New[I]); putchar(0x0A);
      memset(Ava, 0, sizeof(Ava));
      for (unsigned I(1); I <= NC; ++I) if (New[I] && (!Ava[New[I]]))
        Ava[New[I]] = 1, New[I] = 0;
      // printf("New:"); for (unsigned I(1); I <= NC; ++I) printf("%u ", New[I]); putchar(0x0A);
      memset(Ava, 0, sizeof(Ava));
      for (unsigned I(NC); I; --I) if (New[I] && (!Ava[New[I]]))
        Ava[New[I]] = 1, New[I] = 0, Rt[((I - 1) << 1) + 1] = '1';
      // printf("New:"); for (unsigned I(1); I <= NC; ++I) printf("%u ", New[I]); putchar(0x0A);
      for (unsigned I(NC); I; --I) if (New[I])
        Rt[((I - 1) << 1) + 1] = '1', Rt[(I - 1) << 1] = '1';
      return Rt;
    }
    if (i == k) {
      if ((k + 2) ^ N) for (unsigned I(0); I < 96; ++I) Rt[I + 4] = a[2][0][I];
      Rt[0] = a[0][0][0], Rt[1] = a[0][1][0];
      Rt[2] = a[1][0][0], Rt[3] = a[1][1][0];
      Rt[4] = a[2][0][0], Rt[5] = a[2][1][0];
      return Rt;
    }
    Rt[0] = a[0][0][0], Rt[1] = a[1][0][0];
    Rt[2] = a[0][1][0], Rt[3] = a[1][1][0];
    Rt[4] = a[0][2][0], Rt[5] = a[1][2][0];
    if ((k + 2) ^ N) for (unsigned I(0); I < 96; ++I) Rt[I + 4] = a[0][2][I];
    return Rt;
  }
  return a[0][0];
}
/*
static long long to_longlong(string s) {
  long long Ans(0);
  for (int i(s.size() - 1);~i;--i) Ans = (Ans << 1) + s[i] - '0';
  return Ans;
}
int main() {
  int t, n;
  char s[45][45];
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i(0); i < 2 * n + 1; i++)
      for (int j(0); j < 2 * n + 1; j++)
        scanf(" %c", &s[i][j]);

    vector <vector<string>> h(2 * n + 1, vector<string>(2 * n + 1, string(100, '0')));
    for (int i = 0; i < 2 * n + 1; i++)
      for (int j = 0; j < 2 * n + 1; j++)
        h[i][j][0] = s[i][j];

    vector <vector<string>> subarr(3, vector<string>(3));
    for (int k = 0; k < n; k++)
    {
      int m = 2 * (n - k - 1);
      for (int i = 0; i <= m; i++)
      {
        for (int j = 0; j <= m; j++)
        {
          for (int y = 0; y < 3; y++)
          {
            for (int x = 0; x < 3; x++)
            {
              subarr[y][x] = h[i + y][j + x];
            }
          }
          h[i][j] = process(subarr, i, j, k, n);
        }
      }
    }
    printf("%lld\n", to_longlong(h[0][0]));
  }
}
*/
// g++ -DEVAL -std=gnu++17 -O2 -pipe -static -s -o mars grader.cpp mars.cpp
/*
8
2
1 0 1 0 1
0 1 0 1 0
1 0 1 0 1
0 1 0 1 0
1 0 1 0 1
2
1 0 1 0 1
0 1 0 1 0
1 0 1 0 1
0 1 0 1 1
1 0 1 1 1
2
1 0 1 0 1
0 1 0 1 0
1 0 1 0 1
0 1 1 1 0
1 0 1 0 1
2
1 0 1 0 1
0 1 1 1 0
1 0 1 0 1
1 1 0 1 0
1 0 1 0 1
2
1 0 0 0 1
0 0 0 1 0
0 1 1 0 1
0 0 0 1 0
1 0 1 0 1
2
1 0 1 0 1
0 1 0 1 0
1 0 1 1 1
0 0 1 0 1
1 0 1 1 1
2
1 0 1 0 1
0 1 0 1 1
1 0 1 0 1
0 1 0 1 1
1 1 1 0 1
2
1 0 1 0 1
0 1 1 1 0
1 0 1 0 1
1 1 0 0 1
1 0 1 1 1
*/