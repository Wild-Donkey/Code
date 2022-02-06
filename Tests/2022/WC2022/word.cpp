#include "word.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <cstdlib>
using namespace std;
bitset<5000> S[5][26];
char List[26][5000][5], G[5];
unsigned Nm[26], Last(0);
const char* guess(int num_testcase, int remaining_guesses, char initial_letter, bool* gold, bool* silver) {
  memset(G, 0, 5);
  G[0] = initial_letter;
  initial_letter -= 'a';
  unsigned Gd(0), Sv(0), Cho[5005];
  bitset<5000> Me(S[0][initial_letter]);
  // printf("%c %u\n", initial_letter + 'a', Nm[initial_letter]);
  if (remaining_guesses == 5) {
    Last = (rand() % Nm[initial_letter]);
    for (unsigned i(0); i < 5; ++i) G[i] = List[initial_letter][Last][i];
    return G;
  }
  for (unsigned i(1); i < 5; ++i) if (gold[i]) Me = Me & S[i][List[initial_letter][Last][i] - 'a'];
  bitset <5000> No(0);
  for (unsigned i(1); i < 5; ++i) if (silver[i]) {
    for (unsigned j(1); j < 5; ++j) if ((!gold[j]) && (j ^ i)) {
      No = No | S[j][List[initial_letter][Last][i] - 'a'];
    }
  }
  Me = Me | No;
  for (unsigned i(0); i < Nm[initial_letter]; ++i) if (Me[i]) Cho[++Gd] = i;
  Last = Cho[1 + (rand() % Gd)];
  for (unsigned i(0); i < 5; ++i) G[i] = List[initial_letter][Last][i];
  return G;
}
void init(int num_scramble, const char* scramble) {
  srand(32098457);
  for (unsigned i(1), Cnt(0); i <= num_scramble; ++i, ++Cnt) {
    if (i > 1 && ((*scramble) ^ (*(scramble - 5)))) Cnt = 0;
    char In((*scramble) - 'a');
    ++Nm[In];
    for (unsigned j(0); j < 5; ++j, ++scramble) S[j][(*scramble) - 'a'][Cnt] = 1, List[In][Cnt][j] = *scramble;
    // for (unsigned j(0); j < 5; ++j) putchar(List[In][Cnt][j]); printf(" %u\n", Cnt);
  }
}