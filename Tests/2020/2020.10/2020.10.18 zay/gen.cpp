#include <cstdio>
#include <cstring>
#include <string>

const char s[] = "ACDABBCBCDBCBBC";
const char ans16[] = "-Wall";
const char ans17[] = "-Wconversion";
const char ans18[] = "_Wextra";
const char ans19[] = "33554432";
const char ans20[] = "-Wl,--stack=1024000000";
std::string makename(int x);

int main() {
  if (strlen(s) != 15) {
    printf("ѡ�����������ȷ");
    return 0;
  }
  for (int T = 1; T <= 20; ++T) {
    std::string name = makename(T);
    freopen(name.c_str(), "w", stdout);
    if (T <= 15)
      printf("%c\n", s[T - 1]);
    else if (T == 16)
      printf("%s\n", ans16);
    else if (T == 17)
      printf("%s\n", ans17);
    else if (T == 18)
      printf("%s\n", ans18);
    else if (T == 19)
      printf("%s\n", ans19);
    else if (T == 20)
      printf("%s\n", ans20);
    fflush(stdout);
  }
  return 0;
}

std::string makename(int x) {
  std::string ret = "";
  if (x >= 10) {
    ret += char(x / 10 + '0');
    x %= 10;
  }
  ret += char(x % 10 + '0');
  return ret + ".out";
}
