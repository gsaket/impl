#include <bits/stdc++.h>

using namespace std;
#define MAXN 100005
#define LOGN 20
#define vi vector<int>
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)

vector<pii > edges;
vector<vi> adj;
vi temp;
int n,m;
int dist[MAXN];
int par[MAXN][LOGN];
int add[MAXN];
int ans[MAXN];
void dfs(int v,int father)
{
	if(father!=-1)
		par[v][0]=father;
	for(int i=1;i<LOGN;i++)
		if(par[v][i-1]+1)
		par[v][i]=par[par[v][i-1]][i-1];
	for(int i=0;i<adj[v].size();i++)
	{
		int u=adj[v][i];
		if(u==father)
			continue;
		dist[u]=dist[v]+1;
		dfs(u,v);
	}

}
int lca(int u,int v)
{
	//dist[u]<=dist[v];

	if(dist[u]>dist[v])
		swap(u,v);
	for(int i=LOGN-1;i>=0;i--)
	{
		if(par[v][i]+1)
		{
			if(dist[par[v][i]]>=dist[u])
				v=par[v][i];
		}
	}
	if(v==u)
		return v;
	//dist[v]==dist[u]
	for(int i=LOGN-1;i>=0;i--)
	{
		if(par[v][i]!=par[u][i])
			v=par[v][i],u=par[u][i];
	}
	return par[v][0];
}

void dfs2(int u,int father)
{
	ans[u]=add[u];
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(v==father)continue;
		dfs2(v,u);
		ans[u]+=ans[v];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(par,-1,sizeof(par));
	memset(dist,0,sizeof(dist));
	memset(add,0,sizeof(add));
	cin>>n;
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n+5;i++)
		adj.push_back(temp);

	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges.push_back(mp(u,v));
	}

	dist[1]=0;
	dfs(1,-1);

	int q;
	cin>>q;
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		//cout<<lca(u,v)<<endl;;
		int l=lca(u,v);

		add[u]+=1;
		add[v]+=1;
		add[l]-=2;


	}

	dfs2(1,-1);

	for(int i=0;i<n-1;i++)
	{
		int u=edges[i].first,v=edges[i].second;
		if(dist[u]<dist[v])
			swap(u,v);
		cout<<ans[u]<<" ";
	}
	cout<<endl;

	return 0;
}
