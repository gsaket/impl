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


ll dist[100005];
int previous[100005];
vector<vector<pair<int,ll> > > adj;
priority_queue <pair<ll,int> > pq;


int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	adj.resize(n+5);
	for(int i=1;i<=m;i++){
		int x,y;
		ll z;
		cin>>x>>y>>z;
		adj[x].push_back(make_pair(y,z));
		adj[y].push_back(make_pair(x,z));
	}
	dist[1]=0;
	previous[1]=-1;
	pq.push(make_pair(dist[1],1));
	for(int i=2;i<=n;i++){
		dist[i]=INF;
		previous[i]=-1;
		pq.push(make_pair(-dist[i],i));
	}
	pair<ll,int> curr;
	while(!pq.empty()){
		curr=pq.top();
		pq.pop();
		int u=curr.Y;
		ll cdist=-curr.X;
		if(dist[u] < cdist){
			// Already visited this node
			continue;
		}
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i].X;
			ll di=adj[u][i].Y;
			if(dist[v] > dist[u]+di){
				previous[v]=u;
				dist[v]=dist[u]+di;
				pq.push(make_pair(-dist[v],v));
			}
		}
	}
	if(dist[n]==INF){
		cout<<"-1"<<endl;
	}else{
		vector<int> vec;
		int curr=n;
		while(previous[curr] != -1){
			vec.push_back(curr);
			curr=previous[curr];
		}
		cout<<"1 ";
		for(int i=(int)(vec.size()-1); i>=0; i--){
			cout<<vec[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

