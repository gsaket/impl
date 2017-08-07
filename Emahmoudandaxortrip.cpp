// Important: While using & operator enclose between bracket and type cast.
// http://codeforces.com/problemset/problem/766/E
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

int a[100005][21];
ll tp[21];
vector<vector<int> > adj;
int vi[100005];
ll dp[100005][21][2];
ll net[21];

void dfs(int u) {
	int v;
	rep(i,21){
		if(a[u][i]==1){
			dp[u][i][1]++;
		}else{
			dp[u][i][0]++;
		}
	}
	rep(i,adj[u].size()){
		v=adj[u][i];
		if(vi[v]==0){
			vi[v]=1;
			dfs(v);
			rep(j,21){
				if(a[v][j]==1){
					dp[u][j][1]+=dp[v][j][0];
					dp[u][j][0]+=dp[v][j][1];
				}else{
					dp[u][j][1]+=dp[v][j][1];
					dp[u][j][0]+=dp[v][j][0];
				}
			}
		}
	}
}

void dfs1(int u){
	int v;
	ll temp[21];
	rep(i,21){
		temp[i]=0;
	}
	rep(j,adj[u].size()){
		v=adj[u][j];
		if(vi[v]==1){
			vi[v]=2;
			dfs1(v);
			rep(i,21){
				if(a[u][i]==0){
					temp[i]+=2*(dp[v][i][1])*dp[v][i][0];
				}else{
					temp[i]+=dp[v][i][1]*dp[v][i][1];
					temp[i]+=dp[v][i][0]*dp[v][i][0];
				}
			}
		}
	}
	rep(i,21){
		if(a[u][i]==0){
			net[i]+=2*dp[u][i][0]*dp[u][i][1];
			net[i]-=temp[i];
		}else{
			net[i]+=dp[u][i][0]*dp[u][i][0];
			net[i]+=dp[u][i][1]*dp[u][i][1];
			net[i]-=temp[i];
		}
	}
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n;
	cin>>n;
	rep(i,21){
		net[i]=0;
	}
	adj.resize(n+5);
	int tmp=1;
	rep(i,21){
		tp[i]=tmp;
		tmp*=2;
	}
	int x;
	repp(i,1,n+1){
		cin>>x;
		rep(j,21){
			//cout<<x<<" "<<j<<" "<<(x&tp[j])<<endl;
			if( (int)(x&tp[j]) > 0){
				//cout<<"YES "<<i<<" "<<j<<endl;
				a[i][j]=1;
			}else{
				a[i][j]=0;
			}
		}
	}
	int u_,v_;
	rep(i,n-1){
		cin>>u_>>v_;
		adj[u_].pb(v_);
		adj[v_].pb(u_);
	}
	repp(i,1,n+1){
		vi[i]=0;
	}
	rep(i,n+1){
		rep(j,21){
			rep(k,2){
				dp[i][j][k]=0;
			}
		}
	}
	vi[1]=1;
	dfs(1);
	repp(i,1,n+1){
		rep(j,21){
			cout<<dp[i][j][0]<<" ";
		}cout<<endl;
	}
	cout<<"/////////////////"<<endl;
	repp(i,1,n+1){
		rep(j,21){
			cout<<dp[i][j][1]<<" ";
		}cout<<endl;
	}
	vi[1]=2;
	dfs1(1);
	//rep(i,21){
		//net[i]/=2;
	//}
	//repp(i,1,n+1) {
		//rep(j,21){
			//if(a[i][j]==1){
				//net[j]++;
			//}
		//}
	//}
	ll ans=0;
	//repp(i,1,n+1){
		//rep(j,21){
			//cout<<a[i][j]<<" ";
		//}cout<<endl;
	//}
	cout<<"NET[i]"<<endl;
	rep(i,21){
		cout<<net[i]<<" ";
		ans+=tp[i]*net[i];
	}
	cout<<ans<<endl;
	return 0;
}

