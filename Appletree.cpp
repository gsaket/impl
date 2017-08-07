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
int di[100005];

int mx=0;

void dfs(int u){
	int v;
	rep(i,adj[u].size()){
		v=adj[u][i];
		if(di[v]==-1){
			di[v]=di[u]+1;
			mx=max(mx,di[v]);
			dfs(v);
		}
	}
}

int a[100005];
map<int,ll> ma[2];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n;
	ll cnt;
	cnt=0;
	cin>>n;
	adj.resize(n+5);
	repp(i,1,n+1){
		cin>>a[i];
	}
	//repp(i,1,n+1){
		//cout<<a[i]<<" ";
	//}
	//cout<<endl;
	repp(i,2,n+1){
		int x;
		cin>>x;
		adj[i].pb(x);
		adj[x].pb(i);
	}
	rep(i,n+1){
		di[i]=-1;
	}
	di[1]=0;
	dfs(1);
	mx%=2;
	int mi=mx^1;
	int tans=0;
	ll cnt1=0;
	repp(i,1,n+1){
		if(di[i]%2 == mx){
			tans^=a[i];
			ma[mx][a[i]]++;
			cnt1++;
		}else{
			cnt++;
			//cout<<a[i]<<"//"<<endl;
			ma[mi][a[i]]++;
		}
	}
	//cout<<tans<<endl;
	ll ans=0;
	repp(i,1,n+1){
		if(di[i]%2==mx){
			if(tans == 0){
				ans+=cnt1-1;
			}
			int tmp=tans^a[i];
			//cout<<tmp<<" "<<ma[mi][tmp]<<endl;
			ans+=ma[mi][tmp];
		}else{
			if(tans == 0){
				ans+=cnt-1;
			}
			int tmp=tans^a[i];
			ans+=ma[mx][tmp];
		}
	}
	ans/=2LL;
	cout<<ans<<endl;
	return 0;
}

