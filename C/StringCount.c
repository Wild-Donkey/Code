#include <stdio.h>
void count(char *str, int *alph, int *num, int *space, int *oth) {
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
      (*alph)++;
    else if (str[i] >= '0' && str[i] <= '9')
      (*num)++;
    else if (str[i] == 32)
      (*space)++;
    else
      (*oth)++;
    printf("%d: %d %d %d %d\n", i, *alph, *num, *space, *oth);
  }
}
int main() {
  int alph, num, space, oth;
  char str[100];
  fgets(str, 100, stdin);
  count(str, &alph, &num, &space, &oth);
  printf("字母=%d,数字=%d,空格=%d,其他=%d\n", alph, num, space, oth);
}
// ABCabc   123!@#