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
int cnt=0;

vector<vector<pii> > adj;
int of[100005];
int p[100005][20];
int d[100005];
int net[100005];
void dfs(int u){
	int v;
	rep(i,adj[u].size()){
		v=adj[u][i].X;
		if(d[v]==-1){
			d[v]=d[u]+1;
			p[v][0]=u;
			dfs(v);
		}
	}
}
int n;
int lca(int u,int v){
	int c=0;
	if(d[u]<d[v]){
		swap(u,v);
	}
	if(d[u]<d[v]){
		return 0;
	}
	int diff;
	//while(d[u] != d[v]){
		//c++;
		//if(n > 500&&c>100){
			//return 1;
		//}
		//diff=d[u]-d[v];
		//int te=1;
		//int idx=0;
		//while(!(te<=diff&&2*te>diff)){
			//te*=2;
			//idx++;
		//}
		//u=p[u][idx];
	//}
	diff =d[u]-d[v];
	int tp[20];
	tp[0]=1;
	repp(i,1,20){
		tp[i]=2*tp[i-1];
	}
	if(diff != 0){
		for(int i=19;i>=0;i--){
			if(tp[i]<=diff){
				diff-=tp[i];
				u=p[u][i];
			}
		}
	}
	if(u == v){
		return u;
	}
	while(p[u][0] != p[v][0]){
		for(int i=19;i>=0;i--){
			if(p[u][i] != p[v][i]){
				u=p[u][i];
				v=p[v][i];
			}
		}
	}
	return p[u][0];
}
int dfs1(int u,int qa){
	int v;
	int edge;
	int tmp=0;
	tmp+=of[u];
	rep(i,adj[u].size()){
		v=adj[u][i].X;
		edge=adj[u][i].Y;
		if(v == qa)continue;
		int val=dfs1(v,u);
		net[edge]=val;
		tmp+=val;
	}
	return tmp;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int l,p_,q;
	cin>>n;
	adj.resize(n+5);
	repp(i,1,n){
		cin>>p_>>q;
		adj[p_].pb(mp(q,i));
		adj[q].pb(mp(p_,i));
	}
	rep(i,n+1){
		d[i]=-1;
		of[i]=0;
		net[i]=0;
	}
	rep(i,n+1){
		rep(j,20){
			p[i][j]=1;
		}
	}
	d[1]=0;
	dfs(1);
	rep(i,n+1){
		repp(j,1,20){
			p[i][j]=p[p[i][j-1]][j-1];
		}
	}
	int k;
	cin>>k;
	rep(i,k){
		cin>>p_>>q;
		l=1;
		if(p_ == q)continue;
		l=lca(p_,q);
		if(p_ == l){
			of[p_]--;
			of[q]++;
		}else if(q == l){
			of[q]--;
			of[p_]++;
		}else{
			of[p_]++;
			of[q]++;
			of[l]-=2;
		}
	}
	int aqwer=dfs1(1,0);
	repp(i,1,n){
		cout<<net[i]<<" ";
	}cout<<endl;
	return 0;
}

