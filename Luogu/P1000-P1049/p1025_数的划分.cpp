#include <iostream>
using namespace std;
int ans = 0;
void DFS(int Dep, int n, int Last) {
  int Mx(n / Dep);
  if (Dep == 2) {
    ans += Mx - Last + 1;  //[Last, Mx]
    return;
  }
  for (int i(Last); i <= Mx; ++i) DFS(Dep - 1, n - i, i);
  return;
}
int main() {
  int n, m;
  cin >> n >> m;
  DFS(m, n, 1);
  cout << ans;
  return 0;
}
