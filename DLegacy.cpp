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

vector<vector<pii > > adj;

ll di[1000005];

int n,q,s;

void build(int v, int l, int r){
	//cout<<v<<" "<<l<<" "<<r<<endl;
	if(l == r){
		adj[v+n+1].pb(mp(l,0));
		return ;
	}
	int mid=(l+r)/2;
	build(2*v,l,mid);
	build(2*v+1,mid+1,r);
	adj[v+n+1].pb(mp(2*v+n+1,0));
	adj[v+n+1].pb(mp(2*v+n+2,0));
}

void rbuild(int v, int l, int r){
	if(l == r){
		adj[l].pb(mp(v+n+1,0));
	}
	int mid=(l+r)/2;
	build(2*v,l,mid);
	build(2*v+1,mid+1,r);
	adj[2*v+4*n+1].pb(mp(v+4*n+1,0));
	adj[2*v+4*n+2].pb(mp(v+4*n+1,0));
}

void update(int v, int tl, int tr,int l, int r,int gn,int gw){
	if(tl==l && tr == r){
		adj[gn].pb(mp(v+n+1,gw));
		return ;
	}
	int mid=(l+r)/2;
	if(r<=mid){
		return update(2*v,tl,mid,l,r,gn,gw);
	}
	if(l>mid){
		return update(2*v+1,mid+1,tr,l,r,gn,gw);
	}
	update(2*v,tl,mid,l,r,gn,gw);
	update(2*v+1,mid+1,tr,l,r,gn,gw);
}

void rupdate(int v, int tl, int tr,int l, int r,int gn,int gw){
	if(tl==l && tr == r){
		adj[v+4*n+1].pb(mp(gn,gw));
	}
	int mid=(l+r)/2;
	if(r<=mid){
		return rupdate(2*v,tl,mid,l,r,gn,gw);
	}
	if(l>mid){
		return rupdate(2*v+1,mid+1,tr,l,r,gn,gw);
	}
	rupdate(2*v,tl,mid,l,r,gn,gw);
	rupdate(2*v+1,mid+1,tr,l,r,gn,gw);
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	cin>>n>>q>>s;
	adj.resize(9*n+5);
	build(1,1,n);
	rbuild(1,1,n);
	int t,a,b,c,d;
	repp(i,1,q+1){
		cin>>t;
		if(t == 1){
			cin>>a>>b>>c;
			adj[a].pb(mp(b,c));
		}else if(t ==2){
			cin>>a>>b>>c>>d;
			update(1,1,n,b,c,a,d);
		}else{
			rupdate(1,1,n,b,c,a,d);
		}
	}
	priority_queue<pair<ll,int> > pq;
	rep(i,9*n){
		di[i]=INF;
	}
	di[s]=0;
	pair<ll,int> tmp;
	pq.push(mp(di[s],s));
	while(!pq.empty()){
		tmp=pq.top();
		pq.pop();
		int u=tmp.Y;
		int wi;
		int v;
		rep(i,adj[tmp.Y].size()){
			v=adj[u][i].X;
			wi=adj[u][i].Y;
			if(di[v] > di[u] + wi){
				di[v]=di[u]+wi;
				pq.push(mp(di[v],v));
			}
		}
	}
	repp(i,1,n+1){
		if(di[i]==INF){
			cout<<"-1"<<" ";
		}else{
			cout<<di[i]<<" ";
		}
	}cout<<endl;
	// Dijkstra
	return 0;
}

