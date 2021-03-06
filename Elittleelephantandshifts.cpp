// One of the most frustrating question
// http://codeforces.com/problemset/problem/220/C
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<algorithm>
#define N 120000
using namespace std;
multiset<int> s;
int n,a[N],x,ans,i,b[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&x),a[x]=i;
	for(i=1;i<=n;++i){
		scanf("%d",&b[i]);
		s.insert(i-a[b[i]]);
	}
	for(i=0;i<n;++i){
		set <int> ::iterator it=s.lower_bound(i);
		ans=1<<20;
		if(it!=s.end())ans=min(ans,(*it)-i);
		if(it!=s.begin())ans=min(ans,i-(*(--it)));
		s.erase(s.find(i+1-a[b[i+1]]));
		s.insert(i+1-a[b[i+1]]+n);
		printf("%d\n",ans);
	}
}
