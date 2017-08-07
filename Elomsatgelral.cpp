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

vector<vector <int> > adj;
int c[1e5];
int vi[1e5];

map<int,int> ma[1e5];

void dfs(int u,int p){
	int v;
	int idx = -1;
	int maxi=-1;
	rep(i,adj[u].size()){
		v=adj[u][i];
		if(vi[v] == 0){
			vi[v] = 1;
			dfs(v,u);
			if(ma[u].size() > maxi){
				maxi = ma[u].size();
				idx=u;
			}
		}
	}
	map<int,int>::iterator it;
	if(idx != -1){
		rep(i,adj[u].size()){
			v=adj[u][i];
			if(v == idx) continue;
			it=ma[v].begin();
			while(it != ma[v].end()){
				ma[idx][it->X]+=ma[idx][it->Y];
			}
		}
		ma[idx][c[u]]++;
		ma[u]=ma[idx];
	}else{

	}

}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n;
	cin>>n;
	rep(i,n){
		cin>>c[i];
	}
	adj.resize(n+5);
	int x,y;
	rep(i,n-1){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	rep(i,n){
		vi[i]=0;
	}
	vi[1]=1;
	dfs(1,-1);
	return 0;
}

