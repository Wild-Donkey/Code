#include<bits/stdc++.h>
using namespace std;
string S[8];
int V[8];
unsigned Do(unsigned L, unsigned R) {
  if (L == R) return L;
  unsigned Mid = (L + R) / 2;
  unsigned La, Ra;
  La = Do(L, Mid);
  Ra = Do(Mid + 1, R);
  if (L == 0 && R == 7) {
    if (V[La] > V[Ra]) swap(La, Ra);
    cout << S[Ra] << " beats " << S[La] << endl;
    return 0;
  }
  if (V[La] < V[Ra]) return Ra;
  else return La;
}
signed main() {
  for (unsigned i = 0; i < 8; ++i) {
    cin >> S[i] >> V[i];
  }
  Do(0, 7);
  return 0;
}