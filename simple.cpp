#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+9;
inline int read() {
    char ch = getchar(); int x = 0, f = 1;
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}
	while('0' <= ch && ch <= '9') {x = x * 10 + ch - '0';ch = getchar();} return x * f;
}
int T[maxn],n,x;
int main(){
	std::ios::sync_with_stdio(false);
    cin>>n>>x;
    for(int i=1;i<=n;i++){
    	cin>>T[i];
	}
	int j=0;
	for(int i=1;i<=n;i++){
		if(T[i]==x){
			j=i;
			break;
		}
	}
	printf("%d\n",j);
}
