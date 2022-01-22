#include<bits/stdc++.h>
#define ll long long
using namespace std;
unsigned T, n, List[20];
inline void Random() {
	n=List[18];
	for(unsigned i(n); i; --i) putchar((rand() & 2) ? ')' : '(');
}
inline void Russia (unsigned Len) {
  if(!Len) return;
  putchar('(');
  Russia((Len - 2) >> 1);
  Russia((Len - 2) >> 1);
  putchar(')');
}
inline void Thick () {
	n=List[18];
	for(unsigned i(n >> 1); i; --i) putchar('(');
	for(unsigned i(n >> 1); i; --i) putchar(')');
}
inline void Pairs() {
	n=List[18];
	for(unsigned i(n >> 1); i; --i) putchar('('), putchar(')');
}
inline void ComplexRandom () {
	n=List[18];
	for(unsigned i(n >> 1); i; --i) putchar((rand() & 3) ? '(' : ')');
	for(unsigned i(n >> 1); i; --i) putchar((rand() & 3) ? ')' : '(');
}
inline void Left () {
  n = (List[18] - 2) / 4;
  for (unsigned i(n); i; --i) putchar('('), putchar('('), putchar(')');
  putchar('('), putchar(')');
  for (unsigned i(n); i; --i) putchar(')');
}
int main() {
	freopen("B.in", "w", stdout);
	srand(time(0));
	for (unsigned i(1); i <= 18; ++i) List[i] = (List[i - 1] << 1) + 2;
	T = 6;
	printf("%d\n",T);
	Left(), putchar(0x0A);
	Random(), putchar(0x0A);
  Russia(List[18]), putchar(0x0A);
  Thick(), putchar(0x0A);
  Pairs(), putchar(0x0A);
  ComplexRandom(), putchar(0x0A);
	return 0;
}

