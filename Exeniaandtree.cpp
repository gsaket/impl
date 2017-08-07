// My first centroid decomposition tree problem, tags: centroid-decomposition, dfs, coloring
// http://codeforces.com/contest/342/problem/E
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
//const int N = 1e6+10;
const ll INF = 1e18;
const int inf=2e9;
#define E5 100005

#define ld long double
//#define double long double
const ld EPS=1e-12;

vector< set<int> > adj;

const int N=(int)(1e5+5);
const int logN=21;

int dist[N];
int pa[N][logN];
int pcd[N];
int si[N];
int ans[N];

void dfs0(int u,int p){
	int v;
	set<int> :: iterator it;
	for(it=adj[u].begin(); it!=adj[u].end(); it++){
		v=(*it);
		if(v != p){
			dist[v]=dist[u]+1;
			dfs0(v,u);
			pa[v][0]=u;
		}
	}
}

int nn;
void dfs1(int u, int p){
	int v;
	nn++;
	si[u]=1;
	set<int>::iterator it;
	for(it=adj[u].begin(); it!=adj[u].end(); it++){
		v=(*it);
		if(v != p){
			dfs1(v,u);
			si[u]+=si[v];
		}
	}
}

int dfs2(int u, int p){
	int v;
	set<int>::iterator it;
	for(it=adj[u].begin(); it!=adj[u].end(); it++){
		v=(*it);
		if(v != p && si[v]>nn/2){
			return dfs2(v,u);
		}
	}
	return u;
}

void decompose(int root, int p){
	nn = 0;
	dfs1(root, root);
	int centroid = dfs2(root, root);
	if( p == -1 ){
		p = centroid;
	}
	pcd[centroid]=p;
	set<int>::iterator it;
	int v;
	for(it =adj[centroid].begin(); it != adj[centroid].end(); it++){
		v=(*it);
		adj[v].erase(centroid);
		decompose(v,centroid);
	}
	adj[centroid].clear();
}

int lca(int u, int v){
	if(dist[v]>dist[u])swap(u,v);
	int gap=dist[u]-dist[v];
	for(int i=logN-1;i>=0;i--){
		if(gap&(1<<i)){
			u=pa[u][i];
		}
	}
	if( u == v ) return u;
	for(int i=logN-1;i>=0;i--){
		if(pa[u][i] != pa[v][i]){
			u=pa[u][i];
			v=pa[v][i];
		}
	}
	return pa[u][0];
}

int di(int u, int v){
	return dist[u] + dist[v] - 2*dist[lca(u,v)];
}

void update(int u){
	int x=u;
	while(1){
		ans[x]=min(ans[x],di(x,u));
		if(x == pcd[x])break;
		x=pcd[x];
	}
}

int query(int u){
	int x=u;
	int tmp=inf;
	while(1){
		tmp=min(tmp,ans[x]+di(x,u));
		if( x==pcd[x] )break;
		x=pcd[x];
	}
	return tmp;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	adj.resize(N);
	rep(i,n-1){
		int x,y;
		cin>>x>>y;
		adj[x].insert(y);
		adj[y].insert(x);
	}
	rep(i,n+1){
		rep(j,logN){
			pa[i][j]=-1;
		}
		dist[i]=-1;
	}
	dist[1]=0;
	pa[1][0]=1;
	dfs0(1,1);
	repp(i,1,logN){
		repp(j,1,n+1){
			pa[j][i]=pa[pa[j][i-1]][i-1];
		}
	}
	rep(i,n+1){
		ans[i]=inf;
	}
	decompose(1,-1);
	update(1);
	rep(i,m){
		int x,y;
		cin>>x>>y;
		if( x==1 ){
			update(y);
		}else{
			cout<<query(y)<<endl;
		}
	}
	return 0;
}

