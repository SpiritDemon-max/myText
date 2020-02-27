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
int n,m,ans;
int mp[100][100],dis[maxn];
bool vis[maxn];
void init(){
	ans=0;
	memset(mp,inf,sizeof mp);
	memset(dis,0,sizeof dis);
	memset(vis,false,sizeof false);
	for(int i=1;i<=n;i++) mp[i][i]=0;
}
void Prim(){
	vis[1]=true;
	for(int i=1;i<=n;i++) dis[i]=mp[1][i];
	for(int i=1;i<n;i++){
		int maxdis=inf,pos=0;
		for(int j=2;j<=n;j++){
			if(!vis[j]&&dis[j]<maxdis){
				maxdis=dis[j];
				pos=j;
			}
		}
		vis[pos]=true;
		ans+=dis[pos];
		for(int j=2;j<=n;j++){
			if(!vis[j]&&j!=pos)
				dis[j]=min(dis[j],mp[pos][j]);
		}
	} 
}
int main(){
	n=read(),m=read();
	init();
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read(),v=read(),w=read();
		mp[u][v]=mp[v][u]=w;
	}
	Prim();
	printf("%d\n",ans);
  	return 0;
}
