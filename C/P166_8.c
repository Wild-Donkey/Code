#include <stdio.h>
unsigned Scr[4][5];
void Ave() {
  printf("%f\n", (Scr[0][0] + Scr[1][0] + Scr[2][0] + Scr[3][0]) / 4.0);
}
float AveP(unsigned x) {
  return (Scr[x][0] + Scr[x][1] + Scr[x][2] + Scr[x][3] + Scr[x][4]) / 5.0;
}
unsigned Min(unsigned x, unsigned y) { return (x < y) ? x : y; }
unsigned MinP(unsigned x) {
  return Min(Min(Min(Scr[x][0], Scr[x][1]), Min(Scr[x][2], Scr[x][3])),
             Scr[x][4]);
}
void Prt(unsigned x) {
  printf("Num %u, %u %u %u %u %u, Ave %f\n", x, Scr[x][0], Scr[x][1], Scr[x][2],
         Scr[x][3], Scr[x][4], AveP(x));
}
void Fail() {
  int i = 0;
  while (i < 4) {
    int NFail = (Scr[i][0] < 60) + (Scr[i][1] < 60) + (Scr[i][2] < 60) +
                (Scr[i][3] < 60) + (Scr[i][4] < 60);
    if (NFail > 2) printf("Fail "), Prt(i);
    ++i;
  }
}
void Good() {
  int i = 0;
  while (i < 4) {
    if ((AveP(i) > 90) || (MinP(i) > 85)) printf("Good "), Prt(i);
    ++i;
  }
}
void main() {
  scanf("%u%u%u%u%u", Scr[0], Scr[0] + 1, Scr[0] + 2, Scr[0] + 3, Scr[0] + 4);
  scanf("%u%u%u%u%u", Scr[1], Scr[1] + 1, Scr[1] + 2, Scr[1] + 3, Scr[1] + 4);
  scanf("%u%u%u%u%u", Scr[2], Scr[2] + 1, Scr[2] + 2, Scr[2] + 3, Scr[2] + 4);
  scanf("%u%u%u%u%u", Scr[3], Scr[3] + 1, Scr[3] + 2, Scr[3] + 3, Scr[3] + 4);
  Ave();
  Fail();
  Good();
}
/*
gcc P166_8.c -o P166_8.exe && P166_8.exe
61 68 79 92 52
76 56 59 47 85
99 75 87 97 94
86 87 92 86 89
*/