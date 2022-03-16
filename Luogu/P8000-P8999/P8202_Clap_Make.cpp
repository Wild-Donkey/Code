#include <ctime>
#include <cstdio>
#include <cstdlib>

int main() {
  srand(time(nullptr));
  for (int Test = 0; ; ++Test) {
    auto fin = fopen("data.in", "w");
    int n = 100, m = 1000000; 
    fprintf(fin, "%d %d\n", n, m);
    for (int i = 1; i < n; ++i) {
      fprintf(fin, "%d %d\n", rand() % i + 1, i + 1);
    }
    fflush(fin);
    system("std.exe");
    system("U205888_Fusu_Easy.exe");
    if (system("fc data.out data.ans") == 0) {
      fprintf(stderr, "%d OK!\n", Test);
    } else {
      fprintf(stderr, "WTF!\n");
      return 0;
    }
  }
}
