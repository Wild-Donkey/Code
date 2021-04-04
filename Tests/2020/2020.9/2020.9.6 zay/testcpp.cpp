#include <set>
#include <ctime>
#include <cstdio>
#include <cstdlib> 
#ifdef ONLINE_JUDGE
#define freopen(a, b, c)
#endif

typedef long long int ll;

namespace IPT {
  const int L = 1000000;
  char buf[L], *front=buf, *end=buf;
  char GetChar() {
    if (front == end) {
      end = buf + fread(front = buf, 1, L, stdin);
      if (front == end) return -1;
    }
    return *(front++);
  }
}

template <typename T>
inline void qr(T &x) {
  char ch = IPT::GetChar(), lst = ' ';
  while ((ch > '9') || (ch < '0')) lst = ch, ch=IPT::GetChar();
  while ((ch >= '0') && (ch <= '9')) x = (x << 1) + (x << 3) + (ch ^ 48), ch = IPT::GetChar();
  if (lst == '-') x = -x;
}

namespace OPT {
  char buf[120];
}

template <typename T>
inline void qw(T x, const char aft, const bool pt) {
  if (x < 0) {x = -x, putchar('-');}
  int top=0;
  do {OPT::buf[++top] = static_cast<char>(x % 10 + '0');} while (x /= 10);
  while (top) putchar(OPT::buf[top--]);
  if (pt) putchar(aft);
}

std::set<ll>s;

int main() {
  freopen("testdata.in", "r", stdin);
  ll tmp = 0;
  for (int i = 0; i < 1000000; ++i) {
    tmp = 0; qr(tmp);
    s.insert(tmp);
  }
  fprintf(stderr, "%ld\n", clock());
  system("pause");
  return 0;
}
