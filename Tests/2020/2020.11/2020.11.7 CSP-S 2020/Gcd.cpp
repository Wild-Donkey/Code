#include <iostream>
using namespace std;
int Gcd(int x, int y) {
  if(y == 0) {
    return x;
  }
  return Gcd(y, x % y);
}
int a, b;
int main() {
  while (1) {
    cin >> a >> b;
    cout <<a<<" "<<b<< "\n";
    if(a < b) {
      swap(a, b);
    }
    cout << Gcd(a, b) << "\n";
  }
  return 0;
}
