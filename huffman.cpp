#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
#include<queue>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
const int maxn=1e6+9;
const int mod=998244353;
const double eps=0.00000;
const int inf=0x3f3f3f3f;
const double Pi=acos(-1.0);
const int N=1<<20;
inline int read() {
    char ch = getchar(); int x = 0, f = 1;
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}
	while('0' <= ch && ch <= '9') {x = x * 10 + ch - '0';ch = getchar();} return x * f;
}
int main() {
    int n;
    while(~scanf("%d", &n)) {
        priority_queue<ll, vector<ll>, greater<ll> >q;
        ll res = 0;
        for (int i = 1; i <= n; ++i) {
            ll x;
            scanf("%lld", &x);
            q.push(x);
        }
        while (1) {
            ll a = q.top();
            q.pop();
            if (q.empty())break;
            ll b = q.top();
            q.pop();
            res += a + b;
            q.push(a + b);
        }
        printf("%lld\n", res);
    }
}
 

