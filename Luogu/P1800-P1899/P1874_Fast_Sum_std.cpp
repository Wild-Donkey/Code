#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
string st;
long long n, i;
long long book[55];
bool f;
void dfs(long long k)  //明明是组合，却被我写成了排列
{
  if (k == i) {  //重点啊重点啊（敲黑板）
    long long ans = 0,
              sum = st[0] -
                    '0';  // sum开始不为0，就使得一开始就有+号的情况能正好避免。
    for (int j = 1; j < st.size(); j++) {
      if (book[j] == 0)
        sum = sum * 10 + st[j] - '0';  //进位就不用我讲了吧
      else
        ans += sum,
            sum =
                st[j] -
                '0';  // ans累计这一段的和，而这时正好所对应的那个数字，sum就不用清零，直接等于那个数字。
    }
    ans += sum;  //最后没有加号，就要把最后一个加数加上。
    if (ans == n) f = true;
    return;
  }
  for (int j = 1; j < st.size(); j++) {
    if (book[j] == 0) {
      book[j] = 1;
      dfs(k + 1);
      book[j] = 0;
    }
  }
}
int main() {
  freopen("P1874.in", "r", stdin);
  freopen("P1874std.out", "w", stdout);
  cin >> st >> n;
  for (i = 0; i < st.size();
       i++)  //要从0开始，可能正好这个字符串就是那个数字本身呢？（这里有10分）
  {
    memset(book, 0, sizeof(book));
    f = false;
    dfs(0);  //从0开始，就可满足字符串就是数字本身的情况。
    if (f == true) {
      cout
          << i
          << endl;  //题目要求最少加号，所以一旦找到一个能使字符串变成n的，就可以输出了。
      return 0;
    }
  }
  cout << -1 << endl;  //别忘了输出-1（这里又有10分）
  return 0;
}