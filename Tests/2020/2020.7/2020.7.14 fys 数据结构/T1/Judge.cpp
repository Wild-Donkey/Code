#include <windows.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
double tim;
int t;
int main() {
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    system("Rand.exe >t1_9.in");
    tim = clock();
    system("T1std.exe <t1_9.in >t1_9.out");
    tim = clock() - tim;
    printf("Time: %lfms\n", tim);
    tim = clock();
    system("wjz.exe <t1_9.in >wjz.out");
    tim = clock() - tim;
    printf("Time: %lfms\n", tim);
    if(system("fc t1_9.out wjz.out")){
    	break;
	}
	else{
		printf("Test %d Accepted100!\n", i);
	}
  }
  system("pause");
  return 0;
}
