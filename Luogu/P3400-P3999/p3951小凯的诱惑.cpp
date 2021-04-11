#include <iostream>
using namespace std;
long long a, b, ans;
int main() {
  cin >> a >> b;
  ans = a * b - a - b;
  cout << ans << endl;
  return 0;
}