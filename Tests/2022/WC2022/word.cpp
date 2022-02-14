#if !defined(ONLINE_JUDGE)
#include "word.h"
#endif
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
using namespace std;
const unsigned Best[26]{ 7008, 4223, 4223, 7897, 7614, 382, 4223, 4223, 7077, 5406, 6131, 5085, 7612, 147, 7973, 4223, 6104, 147, 5747, 5085, 7077, 6346, 5085, 1560, 3971, 98 };
unsigned char F[8870][8870];
unsigned All[8870], PosL[27];
unsigned Now[8870], NowS(0), Last;
char S[8890][5], G[7];
inline void Prt(char* x) {
  for (unsigned i(0); i < 5; ++i) putchar(x[i]); putchar(' ');
}
inline unsigned Get(char* x, char* y) {
  unsigned Rt(0);
  for (unsigned i(0), j(81); i < 5; ++i, j /= 3) {
    if (x[i] == y[i]) { Rt += (j << 1); continue; }
    char GFlg(0);
    for (unsigned k(0); k < 5; ++k) if ((x[k] ^ y[k]) && (x[i] == y[k])) { GFlg = 1; break; }
    Rt += GFlg * j;
    // printf("%u ", Rt);
  }
  return Rt;
}
inline double Check(unsigned s, unsigned* List, unsigned x) {
  // printf("Check in %u %u ", s, x);
  // for (unsigned i(0); i < 5; ++i) putchar(`[s][i]); putchar(0x0A);
  double Rt(0);
  unsigned Appr[243];
  memset(Appr, 0, sizeof(Appr));
  for (unsigned j(0); j < x; ++j) ++Appr[F[s][List[j]]];
  // for (unsigned i(0); i < 243; ++i) printf("%u %u\n", i, Appr[i]);
  for (unsigned i(0); i < 243; ++i) if (Appr[i]) Rt += Appr[i] * log2((double)x / Appr[i]);
  // printf("Check %u %lf\n", s, Rt / x);
  // system("pause");
  return Rt / x;
}
const char* guess(int num_testcase, int remaining_guesses, char initial_letter, bool* gold, bool* silver) {
  // if (num_testcase != 1)return "dream";
  memset(G, 0, 5);
  initial_letter -= 'a';
  unsigned CntT(0xffffffff), ConDi(0);
  if (remaining_guesses == 5) {
    NowS = PosL[initial_letter + 1] - PosL[initial_letter], memcpy(Now, All + PosL[initial_letter], NowS << 2);
    Last = Best[initial_letter]; for (unsigned i(0); i < 5; ++i) G[i] = S[Last][i];
    return G;
  }
  for (unsigned i(0), j(81); i < 5; ++i, j /= 3) ConDi += gold[i] * (j << 1) + silver[i] * j;
  // printf("Condi %u\n", ConDi);
  for (unsigned i(0); i < NowS; ++i) if (F[Last][Now[i]] == ConDi) Now[++CntT] = Now[i];
  NowS = CntT + 1;
  // if (NowS == 0) { printf("FAQ\n"); return G; }
  double Mx(0);
  // printf("Size %u\n", NowS);
  // for (unsigned i(0); i < NowS; ++i) Prt(S[Now[i]]); putchar(0x0A);
  for (unsigned i(0); i < 8869; ++i) {
    double Cur(Check(i, Now, NowS));
    if (Cur >= Mx) Mx = Cur, Last = i;
  }
  for (unsigned i(0); i < NowS; ++i) {
    double Cur(Check(Now[i], Now, NowS) + 0.0000001);
    if (Cur >= Mx) Mx = Cur, Last = Now[i];
  }
  for (unsigned i(0); i < 5; ++i) G[i] = S[Last][i];
  return G;
}
void init(int num_scramble, const char* scramble) {
  memcpy(S[0], scramble, num_scramble * 5);
  unsigned Con(0xffffffff);
  // for (unsigned i(8813); i < 8869; ++i) printf("%u %u\n", i, Get(S[98], S[i])); // audio dream
  // system("pause");
  for (unsigned i(0); i < num_scramble; ++i) All[i] = i;
  for (unsigned i(0); i < num_scramble; ++i)//, printf("%u To Others\n", i))
    for (unsigned j(0); j < num_scramble; ++j)
      F[i][j] = Get(S[i], S[j]);
  // system("pause");
  // printf("%lf\n", Check(98, All + 8813, 56));
  // system("pause");

  for (unsigned Ini(0), j(0xffffffff); Ini < 26; ++Ini) {
    double Mx(0);
    unsigned Pos(0), Lastj(j);
    PosL[Ini] = j + 1;
    while (S[j + 1][0] == Ini + 'a') ++j;
    // printf("%u (%u, %u]\n", Ini, Lastj, j);
    // for (unsigned i(0); i < num_scramble; ++i) {
    //   double Cur(Check(i, All + Lastj + 1, j - Lastj));
    //   // printf("%u %lf\n", i, Cur);
    //   if (Cur > Mx) Mx = Cur, Pos = i;
    // }
    // printf("%u, ", Pos);
    // printf("%c %u %lf\n", 'a' + Ini, Pos, Mx);

  }
  // putchar(0x0A);
  PosL[26] = 8869;
  // for (unsigned i(0); i < 26; ++i) printf("%c %u\n", i + 'a', PosL[i + 1] - PosL[i]);
  // for (unsigned i(0); i < 26; ++i) printf("%c %u\n", 'a' + i, Nm[i]);
}
//7951