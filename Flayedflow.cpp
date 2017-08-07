// Barely related to flow, bfs, constructive
// http://codeforces.com/problemset/problem/269/C
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
vector<vector<pair<pii,pii> > > adj;
int d[200005];
int flow[200005];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	memset(d,-1,sizeof(d));
	memset(flow,0,sizeof(flow));
	int n,m;
	cin>>n>>m;
	adj.resize(n+5);
	rep(i,m){
		int p,q,r;
		cin>>p>>q>>r;
		adj[p].pb(mp(mp(q,r),mp(i,0)));
		adj[q].pb(mp(mp(p,r),mp(i,1)));
		flow[p]+=r;
		flow[q]+=r;
	}
	repp(i,1,n+1){
		flow[i]/=2;
		//cout<<flow[i]<<endl;
	}
	queue<int> Q;
	Q.push(1);
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		//cout<<"qz "<<u<<endl;
		rep(i,adj[u].size()){
			int p,q,r,s;
			p=adj[u][i].X.X;
			q=adj[u][i].X.Y;
			r=adj[u][i].Y.X;
			s=adj[u][i].Y.Y;
			if(d[r] == -1){
				d[r]=s;
				flow[p]-=q;
				if(flow[p]==0 && p!=n){
					Q.push(p);
				}
			}
		}
	}
	rep(i,m){
		cout<<d[i]<<endl;
	}
	return 0;
}

