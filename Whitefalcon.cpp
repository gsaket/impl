// My first HLD implementation ever, had some fun getting here. tags: hld, lca, segtree
// https://www.hackerrank.com/challenges/heavy-light-white-falcon
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

int subsize[50005];
vector<vector<int> > adj;
int vi[50005];
int val[50005];
int pa[50005][20];
int dep[50005];

void dfs(int u){
	int v;
	subsize[u]=1;
	rep(i,adj[u].size()){
		v=adj[u][i];
		if(vi[v]== 0){
			vi[v]=1;
			pa[v][0]=u;
			dep[v]=dep[u]+1;
			dfs(v);
			subsize[u]+=subsize[v];
		}
	}
}

int lca(int u,int v){
	if(dep[u]>dep[v]){
		swap(u,v);
	}
	for(int i=19;i>=0;i--){
		if(pa[v][i]!=-1){
			if(dep[pa[v][i]]>=dep[u]){
				v=pa[v][i];
			}
		}
	}
	if(u == v){
		return v;
	}
	for(int i=19;i>=0;i--){
		if(pa[u][i]!=-1&&pa[v][i]!=-1&&pa[v][i]!=pa[u][i]){
			v=pa[v][i];
			u=pa[u][i];
		}
	}
	return pa[v][0];
}

int posInBase[50005];
int chainInd[50005];
int chainHead[50005];
int chainNo;
int ptr;
int n,q;
int tree[200005];

void hld(int u){
	int sc,v;
	if(chainHead[chainNo]==-1){
		chainHead[chainNo]=u;
	}
	posInBase[u]=ptr;
	ptr++;
	sc=-1;
	chainInd[u]=chainNo;
	rep(i,adj[u].size()){
		v=adj[u][i];
		if(vi[v] == 1){
			if(sc==-1){
				sc=v;
			}else{
				sc=(subsize[v]>subsize[sc])?v:sc;
			}
		}
	}
	if(sc!=-1){
		vi[sc]=2;
		hld(sc);
	}
	rep(i,adj[u].size()){
		v=adj[u][i];
		if(vi[v] == 1 && v!=sc){
			chainNo++;
			vi[v]=2;
			hld(v);
		}
	}
}

void buid_tree(int v,int l,int r){
	if(l == r){
		tree[v]=val[l];
		return;
	}
	int mid=(l+r)/2;
	buid_tree(2*v, l, mid);
	buid_tree(2*v+1,mid+1,r);
	tree[v]=max(tree[2*v],tree[2*v+1]);
}

bool flag=false;
int query_tree(int v,int tl, int tr, int ql, int qr){
	if(flag)cout<<tl<<" "<<tr<<" "<<ql<<" "<<qr<<endl;
	if(flag){
		if(tl == 406 && tr == 407){
			cout<<tree[v]<<" "<<v<<endl;
			cout<<tree[2*v]<<" "<<tree[2*v+1]<<endl;
		}
	}
	if(tl>tr || ql >qr ){
		return 0;
	}
	if(ql<=tl && tr <= qr){
		return tree[v];
	}
	int mid=(tl+tr)/2;
	if(qr<=mid){
		return query_tree(2*v, tl, mid, ql,qr);
	}
	if(ql>mid){
		return query_tree(2*v+1, mid+1, tr, ql, qr);
	}
	int tmp1=query_tree(2*v, tl, mid, ql,qr);
	int tmp2=query_tree(2*v+1, mid+1, tr, ql, qr);
	int tmp=max(tmp1, tmp2);
	return tmp;
}

void update_tree(int v,int l, int r, int pos){
	if(l == r && l == pos){
		//if(pos == 406){
			//cout<<v<<"/////////////"<<endl;
		//}
		tree[v]=val[pos];
		return;
	}
	int mid=(l+r)/2;
	if(pos<=mid){
		update_tree(2*v, l, mid, pos);
	}else{
		update_tree(2*v+1, mid+1, r, pos);
	}
	tree[v]=max(tree[2*v],tree[2*v+1]);
}

int query_up(int u, int v){
	//bool flag=false;
	//if(u == 911 && v==64){
		//flag=true;
	//}
	//if(u == v){
		//return val[posInBase[u]];
	//}
	int uchain, vchain = chainInd[v];
	uchain=chainInd[u];
	int ans=-1;
	while(1){
		uchain=chainInd[u];
		if(uchain == vchain){
			//if(flag == true){
				//cout<<v<<" "<<u<<endl;
			//}
			int tmp=query_tree(1, 1, n,posInBase[v],posInBase[u]);
			ans=max(ans,tmp);
			break;
		}
		//if(flag){
			//cout<<chainHead[uchain]<<" "<<u<<endl;
		//}
		int tmp=query_tree(1, 1, n,posInBase[chainHead[uchain]],posInBase[u]);
		ans=max(ans,tmp);
		u=chainHead[uchain];
		u=pa[u][0];
	}
	return ans;
}

bool reach(int u, int v){
	if(u == v){
		return true;
	}
	while(1){
		if(u==v){
			return true;
		}
		if(u == 1){
			return false;
		}
		int uchain=chainInd[u];
		int vchain=chainInd[v];
		if(uchain == vchain){
			u=v;
		}else{
			u=chainHead[uchain];
			u=pa[u][0];
		}
	}
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	chainNo=0;
	ptr=1;
	cin>>n>>q;
	adj.resize(n+5);
	rep(i,n-1){
		int x,y;
		cin>>x>>y;
		x++;
		y++;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	rep(i,n+1){
		chainHead[i]=chainInd[i]=posInBase[i]=-1;
	}
	rep(i,4*n+4){
		tree[i]=0;
	}
	rep(i,n+1){
		val[i]=0;
	}
	rep(i,n+1){
		vi[i]=0;
		dep[i]=-1;
	}
	rep(i,n+1){
		rep(j,20){
			pa[i][j]=-1;
		}
	}
	vi[1]=1;
	dep[1]=0;
	dfs(1);
	vi[1]=2;
	hld(1);
	repp(j,1,20){
		repp(i,1,n+1){
			pa[i][j]=(pa[i][j-1]!=-1) ? pa[pa[i][j-1]][j-1]:-1;
		}
	}
	buid_tree(1,1,n);
	//cout<<endl;
	/*
	 *cout<<dep[911]<<" "<<dep[686]<<endl;
	 *cout<<"911:"<<chainInd[911]<<":"<<val[911]<<" "<<endl;
	 *int ti=911;
	 *while(ti!=1){
	 *    cout<<pa[ti][0]<<":"<<chainInd[pa[ti][0]]<<":"<<val[pa[ti][0]]<<" ";
	 *    ti=pa[ti][0];
	 *}cout<<endl;
	 *cout<<"686:"<<chainInd[686]<<":"<<val[686]<<" "<<endl;
	 *ti=686;
	 *while(ti!=1){
	 *    cout<<pa[ti][0]<<":"<<chainInd[pa[ti][0]]<<":"<<val[pa[ti][0]]<<" ";
	 *    ti=pa[ti][0];
	 *}cout<<endl;
	 *cout<<lca(911,686)<<endl;
	 */
	rep(i,q){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==1){
			b++;
			val[posInBase[b]]=c;
			update_tree(1,1,n,posInBase[b]);
		}else{
			b++;
			c++;
			int lc=lca(b,c);
			int tmp1=query_up(b,lc);
			int tmp2=query_up(c,lc);
			int tmp=max(tmp1,tmp2);
			cout<<tmp<<endl;
		}
		//flag=true;
		//cout<<query_tree(1,1,n,406,408)<<endl;
		//flag=false;
	}
	return 0;
}

