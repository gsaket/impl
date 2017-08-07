// Best problem on Linearity of Expectation that I ever read. tags: expectation, dfs, trees
// http://codeforces.com/problemset/problem/280/C
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define X first
#define Y second
#define rep(i,a) for(int i=0;i<(int)a;i++)
#define repp(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define fill(a,x) memset(a,x,sizeof(a))
#define foreach( gg, itit) for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define mp make_pair
#define pb push_back
#define all(s) s.begin(),s.end()
#define present(c,x) ((c).find(x) != (c).end())
const int mod  = 1e9+7;
const int N = 1e6+10;
const ll INF = 1e18;

#define ld long double
//#define double long double
const ld EPS=1e-12;

vector<vector<int> > adj;

ld dep[100005];

void dfs(int u){
	int v;
	rep(i,adj[u].size()){
		v=adj[u][i];
		if(dep[v] == -1){
			dep[v]=dep[u]+1.0;
			dfs(v);
		}
	}
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n;
	cin>>n;
	adj.resize(n+5);
	rep(i,n-1){
		int x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	repp(i,1,n+1){
		dep[i]=-1;
	}
	dep[1]=1.0;
	dfs(1);
	ld ans=0;
	repp(i,1,n+1){
		ld tmp=((ld)(1.0))/(dep[i]);
		ans+=tmp;
	}
	cout<<setprecision(20)<<ans<<endl;
	return 0;
}

