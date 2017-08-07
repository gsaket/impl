// bit, Tin-Tout
// My first problem I solved using bit, and alldo Tin-Tout.
// http://codeforces.com/problemset/problem/383/C
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int vi[200005];
int d[200005];
int start[200005];
int stop[200005];
int st_[200005];
int en_[200005];
int ti=0;

//vector<int> vec;
int vec=0;

void dfs(int u) {
	//cout<<u<<" "<<d[u]<<endl;
	int v;
	rep(i,adj[u].size()) {
		v=adj[u][i];
		if(vi[v] == 0) {
			ti++;
			d[v]=(d[u]+1)%2;
			st_[v]=vec;
			vec++;
			//vec.pb(v);
			vi[v]=1;
			dfs(v);
			en_[v]=vec;
		}
	}
}
int n,m;
int a[200005];
int T[200005][2];

int SET(int i,int va, int x){
	//cout<<i<<" "<<va<<" "<<x<<endl;
	while(i<=n+1) {
		//cout<<i<<endl;
		T[i][x]=T[i][x]+va;
		i += (i & (-i));
	}
}

int GET(int i, int x) {
	int s=0;
	while( i > 0 ) {
		s += T[i][x];
		i -= ( i & (-i) );
	}
	return s;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	adj.resize(n+5);
	int p=0;
	int q=0;
	repp(i,1,n+5){
		vi[i]=0;
		d[i]=0;
	}
	repp(i,1,n+1) {
		cin>>a[i];
	}
	repp(i,1,n+1) {
		T[i][0]=T[i][1]=0;
	}
	int u,v;
	rep(i,n-1){
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	st_[1]=0;
	vi[1]=1;
	ti=0;
	d[1]=0;
	vec=0;
	//vec.pb(1);
	vec++;
	dfs(1);
	en_[1]=vec;
	int c,x,val;
	rep(i,m){
		cin>>c>>x;
		if(c==1) {
			cin>>val;
			SET(st_[x]+1, val, d[x]);
			SET(en_[x]+1, -val, d[x]);
			SET(st_[x]+1,-val,(d[x]+1)%2);
			SET(en_[x]+1,val,(d[x]+1)%2);
			//repp(i,1,n+1){
				//cout<<T[i][1]<<" ";
			//}cout<<endl;
		}else {
			int tmp=GET(st_[x]+1,d[x]);
			tmp+=a[x];
			cout<<tmp<<endl;
		}
	}
	//repp(i,1,n+1) {
		//cout<<i<<" "<<st_[i]<<" "<<en_[i]<<endl;
	//}
	return 0;
}

