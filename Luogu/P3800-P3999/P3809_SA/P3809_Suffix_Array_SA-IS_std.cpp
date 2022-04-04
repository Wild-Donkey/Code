#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAXN = 1e6 + 10;
using namespace std;
char s[MAXN];
int N, M, rak[MAXN], sa[MAXN], tax[MAXN], tp[MAXN];
void Qsort() {
    for (int i = 0; i <= M; i++) tax[i] = 0;
    for (int i = 1; i <= N; i++) tax[rak[i]]++;
    for (int i = 1; i <= M; i++) tax[i] += tax[i - 1];
    for (int i = N; i >= 1; i--) sa[ tax[rak[tp[i]]]-- ] = tp[i];
    //�ⲿ���ҵ����µ�ĩβ��ϸ��˵����
}
void SuffixSort() {
    M = 75;
    for (int i = 1; i <= N; i++) rak[i] = s[i] - '0' + 1, tp[i] = i;
    Qsort();
    for (int w = 1, p = 0; p < N; M = p, w <<= 1) {
        //w:��ǰ�����ĳ��ȣ�w = x��ʾ�Ѿ�����˳���Ϊx�ĺ�׺������������Ҫ���³���Ϊ2x�ĺ�׺������
        //p��ʾ��ͬ�ĺ�׺�ĸ���������Ȼԭ�ַ����ĺ�׺���ǲ�ͬ�ģ����p = Nʱ�����˳�ѭ��
        p = 0;//�����p������һ��������000
        for (int i = 1; i <= w; i++) tp[++p] = N - w + i;
        for (int i = 1; i <= N; i++) if (sa[i] > w) tp[++p] = sa[i] - w; //�������Ǻ�׺����ĺ��Ĳ��֣����Ѿ���ͼ˵��
        Qsort();//��ʱ�����Ѿ����³��˵ڶ��ؼ��֣�������һ�ֵ�rak���±��ֵ�sa
        std::swap(tp, rak);//����ԭ��tp�Ѿ�û������
        rak[sa[1]] = p = 1;
        for (int i = 2; i <= N; i++)
            rak[sa[i]] = (tp[sa[i - 1]] == tp[sa[i]] && tp[sa[i - 1] + w] == tp[sa[i] + w]) ? p : ++p;
    }
    for (int i = 1; i <= N; i++)
        printf("%d ", sa[i]);
}
int main() {
   freopen("P3809_-3.in", "r", stdin);
   freopen("std.out", "w", stdout);
    scanf("%s", s + 1);
    N = strlen(s + 1);
    SuffixSort();
    return 0;
}
