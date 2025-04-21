#include<bits/stdc++.h>
using namespace std;
unsigned RD() {
  unsigned RTm = 0;
  char Rchr = getchar();
  while (Rchr < '0' || Rchr > '9') Rchr = getchar();
  while (Rchr >= '0' && Rchr <= '9') RTm = (RTm * 10) + Rchr - '0', Rchr = getchar();
  return RTm;
}
signed main() {
  string S;
  int Val[30], Cnt[30], Ans = 0;
  cin >> S;
  memset(Cnt, 0, sizeof(Cnt));
  for (unsigned i = 0; i < 26; ++i) cin >> Val[i];
  for (auto i : S) {
    ++Cnt[i - 'a'];
  }
  for (unsigned i = 0; i < 26; ++i) {
    Ans += Cnt[i] * Val[i];
    cout << Cnt[i];
    if (i < 25) cout << ' ';
  }
  cout << '\n' << Ans << '\n';
  return 0;
}