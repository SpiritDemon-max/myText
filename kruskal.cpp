#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int maxn=1e6+9;
const int N=1<<20;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
const int temp=233;
const double eps=0.000001;
const double PI=acos(-1);
const int dx[] = {0,0,1,1,1,-1,-1,-1};
const int dy[] = {-1,1,1,-1,0,1,-1,0};
inline int read(){
    int num=0, w=0;char ch=0;
    while (!isdigit(ch)) {w|=ch=='-';ch = getchar();}
    while (isdigit(ch)) {num = (num<<3) + (num<<1) + (ch^48);ch = getchar();}return w? -num: num;
}
int n,m;
int fa[maxn];
struct node {
	int from, to;
	double cost;
}E[maxn];
int find(int x) {
	return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);
}
void baba(int x, int y) {
	int fx = find(x), fy = find(y);
	fa[fx] = fy;
}
bool same(int x, int y) {
	return find(x) == find(y);
}
bool cmp(const node &a, const node &b) {
	return a.cost < b.cost;
}
double  kruskal() {
	double   ans = 0;
	sort(E + 1, E + m + 1, cmp);
	for (int i = 1; i <= m; i++)
	{
		if (same(E[i].from, E[i].to)) continue;
		baba(E[i].from, E[i].to);
	}
	return ans;
}
int main() {
	while (~scanf("%d%d",&n,&m) ){
		if (n == 0) break;
		for (int i = 0; i <= n; i++) {
			fa[i] = i;
		}
		for (int i = 1; i <= m; i++) {
			scanf("%lf%lf%lf", &E[i].from,&E[i].to,&E[i].cost);
		}
		double   h=kruskal();
        printf("%.3f\n", h);
	}
	return 0;
}

