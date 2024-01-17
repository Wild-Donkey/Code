#include <stdio.h>
struct Stu {
  unsigned Num, Scr;
  char Gen, *Name;
};
void In(struct Stu *x) {
  char Tmp[105];
  unsigned Len;
  scanf("%u%s%c%c%u", &(x->Num), Tmp, &(x->Gen), &(x->Gen), &(x->Scr));
  // printf("Done %u %u %u\n", x->Num, x->Scr, x->Gen);
  x->Name = malloc(Len = strlen(Tmp) + 1);
  memcpy(x->Name, Tmp, Len);
}
void Prt(struct Stu *x) {
  printf("No.%u %s %c %uPts\n", x->Num, x->Name, x->Gen, x->Scr);
}
void main() {
  struct Stu a[1005];
  unsigned n, i, Hi = 0;
  scanf("%u", &n);
  for (i = 1; i <= n; ++i) {
    In(a + i);
    if (a[i].Gen == 'f' && Hi < a[i].Scr) Hi = a[i].Scr;
  }
  for (i = 1; i <= n; ++i)
    if (a[i].Gen == 'f' && a[i].Scr == Hi) Prt(a + i);
}
/*
5
114 Mike m 514
514 MyCall f 810
1919 MightCould f 114
810 MathCoach m 1919
1989 MaimiCore f 810
*/