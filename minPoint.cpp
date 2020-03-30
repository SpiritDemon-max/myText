#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int maxn=1e5+9;
const int inf=0x3f3f3f3f;
int n;
struct node{
	double x,y;
}a[maxn];
bool cmpx(const node &s1,const node &s2){
	return s1.x<s2.x;
}
double getdis(node p,node q){
	return sqrt((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y));
}
double minPoint(int l,int r){
	if(r-l==1) return getdis(a[l],a[r]);
	if(r-l==2) return min(getdis(a[l],a[l+1]),getdis(a[l+1],a[r]));
	int mid=(l+r)/2;
	double dis=min(minPoint(l,mid),minPoint(mid+1,r));
	while(dis<a[r].x-a[mid].x&&r>=l) r--;
	while(dis<a[mid].x-a[l].x&&l<=r) l++;
	for(int i=l;i<=r;i++){
		for(int j=i+1;j<=r;j++){
			if(a[j].y-a[j].y>=dis) break;
			else dis=min(dis,getdis(a[i],a[j]));
		}
	}
	return dis;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmpx);
	double ans=minPoint(1,n);
	printf("%f\n",ans);
	return 0;
}
