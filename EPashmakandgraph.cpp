// Very good dp problem, my first question from a2oj
// 3*10^5 push_back of make_pair can get TLE!!
// http://codeforces.com/problemset/problem/459/E
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

vector< vector<pii > > w;
int dp[300005];
int tmp[300005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	w.resize(100005);
	int u,v,l;
	rep(i,100005) {
		tmp[i]=0;
	}
	rep(i,n+1){
		dp[i]=0;
	}
	rep(i,m) {
		cin>>u>>v>>l;
		w[l].pb(mp(u,v));
	}
	rep(i,100005){
		rep(j,w[i].size()) {
			v = w[i][j].Y;
			tmp[v]=0;
		}
		rep(j,w[i].size()) {
			v = w[i][j].Y;
			u = w[i][j].X;
			tmp[v]=max(tmp[v],dp[u]+1);
		}
		rep(j,w[i].size()) {
			v = w[i][j].Y;
			dp[v]=max(dp[v],tmp[v]);
		}
	}
	int net=0;
	rep(i,n+1){
		net=max(dp[i],net);
	}
	cout<<net<<endl;
	return 0;
}

