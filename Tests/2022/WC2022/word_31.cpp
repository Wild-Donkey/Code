#include "word.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <random>
using namespace std;
bitset<1050> S[26][5][26];
char List[26][1050][5], G[5];
unsigned Nm[26], Last(0);
std::mt19937 generator(32098457);
const char* guess(int num_testcase, int remaining_guesses, char initial_letter, bool* gold, bool* silver) {
  memset(G, 0, 5);
  G[0] = initial_letter;
  initial_letter -= 'a';
  unsigned Gd(0), Sv(0), Cho[1050];
  bitset<1050> Me;
  // printf("%c %u\n", initial_letter + 'a', Nm[initial_letter]);
  if (remaining_guesses == 5) {
    Me = S[initial_letter][0][initial_letter];
    Last = (generator() % Nm[initial_letter]);
    for (unsigned i(0); i < 5; ++i) G[i] = List[initial_letter][Last][i];
    return G;
  }
  for (unsigned i(1); i < 5; ++i) if (gold[i]) Me = (Me & S[initial_letter][i][List[initial_letter][Last][i] - 'a']);
  bitset <1050> No(0);
  for (unsigned i(1); i < 5; ++i) if (silver[i]) {
    for (unsigned j(1); j < 5; ++j) if ((!gold[j]) && (j ^ i)) {
      No = (No | S[initial_letter][j][List[initial_letter][Last][i] - 'a']);
    }
    Me = (Me & No);
  }
  // cout << Me << endl;
  for (unsigned i(0); i < Nm[initial_letter]; ++i) if (Me[i]) Cho[++Gd] = i;
  Last = Cho[1 + (generator() % Gd)];
  for (unsigned i(0); i < 5; ++i) G[i] = List[initial_letter][Last][i];
  return G;
}
void init(int num_scramble, const char* scramble) {
  for (unsigned i(1), Cnt(0); i <= num_scramble; ++i, ++Cnt) {
    if (i > 1 && ((*scramble) ^ (*(scramble - 5)))) Cnt = 0;
    char In((*scramble) - 'a');
    ++Nm[In];
    for (unsigned j(0); j < 5; ++j, ++scramble) S[In][j][(*scramble) - 'a'][Cnt] = 1, List[In][Cnt][j] = *scramble;
    // for (unsigned j(0); j < 5; ++j) putchar(List[In][Cnt][j]); printf(" %u\n", Cnt);
  }
  // for (unsigned i(0); i < 26; ++i) printf("%c %u\n", 'a' + i, Nm[i]);
}