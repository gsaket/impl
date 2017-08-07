// 3e5 input and output ->TLE for cin/cout!!
// dsu, diameter of tree, tree construction
// http://codeforces.com/problemset/problem/455/C
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
int p[300005];
int dia[300005];
int d[300005];
int vi[300005];
int di;
int idx;

void dfs(int u) {
	int v;
	rep(i,adj[u].size()) {
		v=adj[u][i];
		if(p[v] == -1) {
			p[v] = u;
			d[v]=d[u]+1;
			dfs(v);
			if(d[v]>di){
				di=d[v];
				idx=v;
			}
		}
	}
}
void dfs1(int u) {
	int v;
	//cout<<u<<" qaz "<<d[u]<<endl;
	rep(i,adj[u].size()) {
		v=adj[u][i];
		if(vi[v] == 0) {
			vi[v]=1;
			d[v]=d[u]+1;
			dfs1(v);
			if(d[v]>di){
				di=d[v];
				//idx=v;
			}
		}
	}
}

int find(int u){
	if(p[u] == -2) {
		return u;
	}else {
		p[u]=find(p[u]);
		return p[u];
	}
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n,m,q;
	//cin>>n>>m>>q;
	scanf("%d%d%d",&n,&m,&q);
	adj.resize(n+5);
	//fill(p,-1);
	//fill(dia,0);
	//fill(vi,0);
	int p_,q_;
	rep(i,m){
		//cin>>p_>>q_;
		scanf("%d%d",&p_,&q_);
		adj[p_].pb(q_);
		adj[q_].pb(p_);
	}
	repp(i,0,n+1) {
		vi[i]=0;
		dia[i]=0;
		p[i]=-1;
	}
	repp(i,1,n+1) {
		//cout<<i<<" "<<p[i]<<endl;;
		if(p[i]==-1){
			p[i]=-2;//parent
			d[i]=0;
			di=0;
			idx=i;
			dfs(i);
			//cout<<i<<" hello "<<idx<<endl;
			di=0;
			vi[idx]=1;
			d[idx]=0;
			dfs1(idx);
			//cout<<i<<" adf "<<idx<<" "<<di<<endl;
			dia[i]=di;
		}
	}
	int c,x,y;
	while(q--){
		//cin>>c>>x;
		scanf("%d%d",&c,&x);
		if(c==1){
			int pa=find(x);
			//cout<<dia[pa]<<endl;
			printf("%d\n",dia[pa]);
		}else{
			//cin>>y;
			scanf("%d",&y);
			int u=find(x);
			int v=find(y);
			//cout<<"q2 "<<u<<" "<<v<<endl;
			if(u!=v){
				int tmp=dia[u];
				tmp=max(dia[v],tmp);
				int t1=dia[u]/2;
				if(dia[u]%2==1)t1++;
				t1+=dia[v]/2;
				if(dia[v]%2==1)t1++;
				t1++;
				tmp = max(tmp,t1);
				p[v]=u;
				dia[u]=tmp;
			}
		}
	}
	return 0;
}

