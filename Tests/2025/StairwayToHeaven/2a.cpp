#include<bits/stdc++.h>
using namespace std;
unsigned RD() {
  unsigned RTm = 0;
  char Rchr = getchar();
  while (Rchr < '0' || Rchr > '9') Rchr = getchar();
  while (Rchr >= '0' && Rchr <= '9') RTm = (RTm * 10) + Rchr - '0', Rchr = getchar();
  return RTm;
}
int RDsg() {
  int RTm = 0;
  char Rchr = getchar(), Flg = 0;
  while ((Rchr < '0' || Rchr > '9') && Rchr != '-') Rchr = getchar();
  if (Rchr == '-') Flg = 1, Rchr = getchar();
  while (Rchr >= '0' && Rchr <= '9') RTm = (RTm * 10) + Rchr - '0', Rchr = getchar();
  return Flg ? -RTm : RTm;
}
signed main() {
  string S;
  cin >> S;
  stack<char> Stk;
  vector<char> Out;
  for (auto i : S) {
    if (i == ')') {
      while (Stk.size()) {
        if (Stk.top() == '(') {
          Stk.pop();
          break;
        }
        Out.push_back(Stk.top()), Stk.pop();
      }
      if (Out.size()) {
        for (unsigned j = Out.size() - 1; ~j; --j) putchar(Out[j]);
        putchar(0x0A);
        Out.clear();
      }
    } else Stk.push(i);
  }
  while (Stk.size()) {
    Out.push_back(Stk.top()), Stk.pop();
  }
  if (Out.size()) {
    for (unsigned j = Out.size() - 1; ~j; --j) putchar(Out[j]);
    putchar(0x0A);
    Out.clear();
  }
  return 0;
}