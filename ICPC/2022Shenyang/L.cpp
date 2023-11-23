#include <bits/stdc++.h>
using namespace std;
struct Pr {
  double Als, Bob;
  void Ini() { Als = Bob = 0; }
  void Devi(unsigned x) { Als /= x, Bob /= x; }
  void operator+=(Pr x) { Als += x.Als, Bob += x.Bob; }
  void operator+=(Pr &x) { Als += x.Als, Bob += x.Bob; }
} Ans;
unsigned n[2], Ali[2];
int At[2][10], Hp[2][10], Num[2][10];
inline void Prt() {
  cout << "Ali " << Ali[0] << ' ' << Ali[1] << '\n';
  for (unsigned i(1); i <= n[0]; ++i) cout << Hp[0][i] << ' ';
  cout << '\n';
  for (unsigned i(1); i <= n[1]; ++i) cout << Hp[1][i] << ' ';
  cout << '\n';
}
inline Pr DFS(char Cur) {
  // Prt();
  char Opo(Cur ^ 1), Flg(0);
  unsigned Mat(0x3f3f3f3f), Pos;
  Pr Rt;
  Rt.Ini();
  for (unsigned i(n[Cur]); i; --i)
    if (Hp[Cur][i] > 0 && Num[Cur][i] <= Mat) Mat = Num[Cur][i], Pos = i;
  for (unsigned i(1); i <= n[Opo]; ++i)
    if (Hp[Opo][i] > 0) {
      Flg = 0;
      Num[Cur][Pos]++;
      Hp[Opo][i] -= At[Cur][Pos];
      Hp[Cur][Pos] -= At[Opo][i];
      if (Hp[Opo][i] <= 0) --Ali[Opo], Flg ^= 1;
      if (Hp[Cur][Pos] <= 0) --Ali[Cur], Flg ^= 2;
      if (Ali[Opo] && Ali[Cur])
        Rt += DFS(Cur ^ 1);
      else {
        if (Ali[0]) Rt.Als += 1;
        if (Ali[1]) Rt.Bob += 1;
      }
      if (Flg & 1) ++Ali[Opo];
      if (Flg & 2) ++Ali[Cur];
      Hp[Opo][i] += At[Cur][Pos];
      Hp[Cur][Pos] += At[Opo][i];
      Num[Cur][Pos]--;
    }
  Rt.Devi(Ali[Opo]);
  // cout << Rt.Als << ' ' << Rt.Bob << '\n';
  return Rt;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n[0] >> n[1];
  for (unsigned i(1); i <= n[0]; ++i) cin >> At[0][i], Hp[0][i] = At[0][i];
  for (unsigned i(1); i <= n[1]; ++i) cin >> At[1][i], Hp[1][i] = At[1][i];
  Ali[0] = n[0], Ali[1] = n[1];
  if (n[0] > n[1]) Ans = DFS(0);
  if (n[0] < n[1]) Ans = DFS(1);
  if (n[0] == n[1]) Ans = DFS(0), Ans += DFS(1), Ans.Devi(2);
  cout << fixed << setprecision(10) << Ans.Als << '\n'
       << Ans.Bob << '\n'
       << 1 - Ans.Als - Ans.Bob << '\n';
  return 0;
}