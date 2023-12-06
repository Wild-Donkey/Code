#include <stdio.h>
unsigned Op, n, i, j;
unsigned a[10005];
void Swap(unsigned *x, unsigned *y) {  // 传入要交换的元素的地址
  if (x == y) return;  // 如果交换的元素是同一个, 则不操作
  (*x) ^= (*y), (*y) ^= (*x), (*x) ^= (*y);  // 用异或的方法交换
}
void Select() {              // 选择排序
  for (i = 1; i < n; ++i) {  // 选择第 i 小的值
    unsigned Mn = 0xffff, Pos = 0;
    for (j = i; j <= n; ++j)  // 第 i 小的值是数组后 n - i + 1 个元素中的最小值
      if (a[j] < Mn) Mn = a[j], Pos = j;
    Swap(a + i, a + Pos);  // 将第 i 小值放到第 i 个位置
  }
}
void Bubble() {        // 冒泡排序
  for (i = n; i; --i)  // 将前 i 个元素的最大值交换到第 i 位
    for (j = 1; j < i; ++j)
      if (a[j] > a[j + 1])
        Swap(a + j, a + j + 1);  // 前一个元素比后一个大, 冒泡
}
void main() {
  scanf("%u%u", &n, &Op);  // 数组长度 n, 排序方式 Op
  for (i = 1; i <= n; ++i) scanf("%u", a + i);
  if (Op)      // 判断排序方式
    Bubble();  // 冒泡排序
  else
    Select();  // 选择排序
  for (i = 1; i <= n; ++i) printf("%u ", a[i]);
  putchar(0x0A);
}
/*
5 1
7 8 56 4 8
*/