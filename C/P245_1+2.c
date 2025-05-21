#include <stdio.h>
struct Emp {
  unsigned Num, Age, Salary;
  char *Name, *Job;
};
void In(struct Emp *x) {
  char Tmp[2][105];
  unsigned Len[2];
  scanf("%u%s%u%s%u", &(x->Num), Tmp[0], &(x->Age), Tmp[1], &(x->Salary));
  // printf("Done\n");
  x->Name = malloc(Len[0] = strlen(Tmp[0]) + 1);
  x->Job = malloc(Len[1] = strlen(Tmp[1]) + 1);
  memcpy(x->Name, Tmp[0], Len[0]);
  memcpy(x->Job, Tmp[1], Len[1]);
}
void Prt(struct Emp *x) {
  printf("No.%u %s %s %u Years' Experience %u$ Per Year\n", x->Num, x->Name,
         x->Job, x->Age, x->Salary);
}
void main() {
  struct Emp a[1005];
  unsigned n, i;
  unsigned long Tot = 0;
  scanf("%u", &n);
  for (i = 1; i <= n; ++i) {
    In(a + i);
    Prt(a + i);
    Tot += a[i].Salary;
  }
  printf("Total %lu$ Per Year, %f$ on average\n", Tot, Tot / (n * 1.0));
}
/*
3
114 Mike 6 Killer 65535
514 MyCall 4 Driver 32768
1919 MightCould 3 Gunner 810
*/