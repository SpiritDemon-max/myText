#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+9;
const double inf = 0x3f3f3f3f;
double minn = inf;              //��СԲ���г���
int n;
double x[maxn], r[maxn];             //�ֱ�Ϊÿ��Բ�ĺ����꣬ÿ��Բ�뾶
double arr[maxn];                //��СԲ���еİ뾶˳��

double Getc(int t) {         //�����t��Բ��Բ������
    double temp = 0;
    for (int j = 1; j < t; ++j) {
        double val = x[j] + 2.0 * sqrt(r[t] * r[j]);  //�ж�����֮ǰ������Բ���е����
        temp=max(temp,val);
    }
    return temp;
}
void compute() {
    double L = inf, R = 0;   //L����߽磬R���б߽�
    for (int i = 1; i <= n; ++i) {
        if (x[i] - r[i] < L)
            L = x[i] - r[i];
        if (x[i] + r[i] > R)
            R = x[i] + r[i];
    }
    if (R - L < minn) {
        minn = R - L;
        for (int i = 1; i <= n; ++i)
            arr[i] = r[i];
    }
}
void dfs(int t) {
    if (t == n + 1) {
        compute();
    }
    else {
        for (int j = t; j <= n; ++j) {
            swap(r[t], r[j]);
            double val = Getc(t);
            if (val + r[t] + r[1] < minn) {
                x[t] = val;
                dfs(t + 1);
            }
            swap(r[t], r[j]);     //��ԭ
        }
    }
}
int main() {
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i)scanf("%lf", &r[i]);
    dfs(1);
    printf("��СԲ���г���Ϊ��%.4f\n", minn);
    printf("��СԲ���е�˳���Ӧ�İ뾶�ֱ�Ϊ��\n");
    for (int i = 1; i <= n; ++i) {
        printf("%.4f%c", arr[i],i==n?'\n':' ');
    }
    return 0;
}
