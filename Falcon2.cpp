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
const ll mod  = 1e9+7;
const int N = 1e6+10;
const ll INF = 1e18;

#define ld long double
//#define double long double
const ld EPS=1e-12;
int subsize[50005];
vector<vector<int> > adj;
int vi[50005];
int pa[50005][20];
int n,q;
int dep[50005];

struct node{
	ll sum;
	int lazy;
	ll st;
	ll di;
	ll size;
};

void dfs(int u){
	int v;
	subsize[u]=1;
	rep(i,adj[u].size()){
		v=adj[u][i];
		if(vi[v]==0){
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
	//cout<<u<<" "<<v<<endl;
	//cout<<dep[u]<<" "<<dep[v]<<endl;
	for(int i=19;i>=0;i--){
		if(pa[v][i]!=-1){
			if(dep[pa[v][i]]>=dep[u]){
				v=pa[v][i];
			}
		}
	}
	if(u == v){
		return u;
	}
	for(int i=19;i>=0;i--){
		if(pa[u][i]!=-1&&pa[v][i]!=-1&&pa[v][i]!=pa[u][i]){
			u=pa[u][i];
			v=pa[v][i];
		}
	}
	return pa[u][0];
}

int posInBase[50005];
int chainInd[50005];
int chainHead[50005];
int chainNo;
int ptr;
node tree[200005];
ll tw;

void hld(int u){
	int sc,v;
	if(chainHead[chainNo]==-1){
		chainHead[chainNo]=u;
	}
	chainInd[u]=chainNo;
	posInBase[u]=ptr;
	ptr++;
	sc=-1;
	rep(i,adj[u].size()){
		v=adj[u][i];
		if(vi[v]==1){
			sc=(sc==-1)?v:((subsize[v]>subsize[sc])?v:sc);
		}
	}
	if(sc!=-1){
		vi[sc]=2;
		hld(sc);
	}
	rep(i,adj[u].size()){
		v=adj[u][i];
		if(vi[v]==1&&v!=sc){
			vi[v]=2;
			chainNo++;
			hld(v);
		}
	}
}

ll add(ll x, ll y){
	ll tmp=x+y;
	tmp%=mod;
	return tmp;
}

ll mul(ll x, ll y){
	ll tmp=x*y;
	tmp%=mod;
	return tmp;
}

ll mod_pow(ll x, ll p){
	if(p == 0){
		return 1LL;
	}
	if(p == 1){
		return x;
	}
	ll tmp=mod_pow(x,p/2);
	tmp=mul(tmp,tmp);
	if(p%2==1){
		tmp=mul(x,tmp);
	}
	return tmp;
}

void build_tree(int v,int l,int r){
	tree[v].sum=0;
	tree[v].lazy=0;
	tree[v].st=0;
	tree[v].di=0;
	if(l == r){
		tree[v].size=1LL;
		return;
	}
	int mid=(l+r)/2;
	build_tree(2*v,l,mid);
	build_tree(2*v+1,mid+1,r);
	tree[v].size=tree[2*v].size+tree[2*v+1].size;
	//cout<<l<<" "<<r<<"/ /  / "<<tree[v].size<<endl;
}

bool debug=false;

void push_node(int v,int tl, int tr){
	if(tree[v].lazy == 1){
		tree[v].lazy=0;
		if(tl == tr){
			tree[v].sum=add(tree[v].sum,tree[v].st);
		}else{
			ll sta=tree[v].st;
			ll dif=tree[v].di;
			ll tmp=mul(2LL, sta);
			ll siz=tree[v].size;
			//if(debug)cout<<tl<<" "<<tr<<"//// "<<tree[v].size<<endl;
			if(siz>0){
				ll tmp1=mul(siz-1LL,dif);
				tmp=add(tmp,tmp1);
			}
			tmp=mul(siz,tmp);
			tmp=mul(tw,tmp);
			tree[2*v].lazy=tree[2*v+1].lazy=1;
			tree[v].sum=add(tree[v].sum,tmp);
			tree[2*v].st=add(tree[2*v].st,sta);
			siz=tree[2*v].size;
			tmp=mul(siz,dif);
			tmp=add(tmp,sta);
			tree[2*v+1].st=add(tree[2*v+1].st,tmp);
			tree[2*v].di=add(tree[2*v].di,dif);
			tree[2*v+1].di=add(tree[2*v+1].di,dif);
		}
		tree[v].st=0;
		tree[v].di=0;
	}
}


ll query_tree(int v, int tl, int tr, int ql, int qr){
	/*
	 *if(debug){
	 *    cout<<"query: "<<endl;
	 *    cout<<tl<<" "<<tr<<" "<<ql<<" "<<qr<<": "<<tree[v].sum<<endl;
	 *}
	 */
	push_node(v, tl,tr);
	/*
	 *if(debug){
	 *    cout<<"query1: "<<endl;
	 *    cout<<tl<<" "<<tr<<" "<<ql<<" "<<qr<<": "<<tree[v].sum<<endl;
	 *}
	 */

	if(ql>tr || qr<tl)return 0;
	if(ql<=tl && tr<=qr){
		return tree[v].sum;
	}
	int mid=(tl+tr)/2;
	if(qr<=mid){
		return query_tree(2*v,tl,mid,ql,qr);
	}
	if(ql>mid){
		return query_tree(2*v+1,mid+1,tr,ql,qr);
	}
	ll tmp1=query_tree(2*v,tl,mid,ql,qr);
	ll tmp2=query_tree(2*v+1,mid+1,tr,ql,qr);
	ll tmp=add(tmp1,tmp2);
	tree[v].sum=tmp;
	return tmp;
}

void update_tree(int v,int tl, int tr,int ql,int qr, ll sta, ll dif){
	if(ql>qr||tl>tr)return;
	push_node(v,tl,tr);
	if(ql>tr||qr<tl)return;
	if(ql <= tl && tr <= qr){
		//if(debug){
			//cout<<"hello"<<endl;
		//}
		tree[v].lazy=1;
		ll tmp=mul((ll)(ql-tl),dif);
		tmp=add(sta,tmp);
		tree[v].st=tmp;
		tree[v].di=dif;
		push_node(v,tl,tr);
		/*
		 *if(debug){
		 *    cout<<tl<<" "<<tr<<" "<<ql<<" "<<qr<<" "<<tmp<<" "<<dif<<endl;
		 *    cout<<tree[v].sum<<endl;
		 *}
		 *if(debug){
		 *    cout<<"hello end"<<endl;
		 *}
		 */
		return;
	}
	int mid=(tl+tr)/2;
	update_tree(2*v,tl,mid,ql,qr,sta,dif);
	update_tree(2*v+1,mid+1,tr,ql,qr,sta,dif);
	tree[v].sum=add(tree[2*v].sum,tree[2*v+1].sum);
	/*
	 *if(debug){
	 *    cout<<tl<<" "<<tr<<" "<<ql<<" "<<qr<<endl;
	 *    cout<<tree[v].sum<<endl;
	 *}
	 */
}

ll query_up(int u, int v){
	int uchain=chainInd[u];
	int vchain=chainInd[v];
	ll ans=0;
	while(1){
		uchain=chainInd[u];
		if(uchain == vchain){
			ll tmp=query_tree(1,1,n,posInBase[v],posInBase[u]);
			ans=add(ans,tmp);
			break;
		}
		ll tmp=query_tree(1,1,n,posInBase[chainHead[uchain]],posInBase[u]);
		ans=add(ans,tmp);
		u=chainHead[uchain];
		u=pa[u][0];
	}
	return ans;
}

void update_up(int u, int v, ll sta,ll dif){
	int uchain=chainInd[u];
	int vchain=chainInd[v];
	cout<<"update_up: "<<u<<" "<<v<<" "<<sta<<" "<<dif<<endl;
	cout<<dep[u]<<" "<<dep[v]<<endl;
	while(1){
		//cout<<u<<" "<<v<<endl;
		uchain=chainInd[u];
		if(uchain == vchain){
			ll tmp=mul((ll)(dep[u]-dep[v]),dif);
			tmp=add(tmp,sta);
			ll dif1=add(mod-dif,0LL);
			cout<<"YES"<<endl;
			cout<<posInBase[v]<<" "<<posInBase[u]<<" "<<tmp<<" "<<dif1<<endl;
			//if(posInBase[v]==8&&posInBase[u]==14)debug=true;
			update_tree(1,1,n,posInBase[v],posInBase[u],tmp,dif1);
			break;
		}
		ll tmp=mul((ll)(dep[u]-dep[chainHead[uchain]]),dif);
		tmp=add(tmp,sta);
		ll dif1=add(mod-dif,0LL);
		cout<<posInBase[chainHead[uchain]]<<" "<<posInBase[u]<<" "<<tmp<<" "<<dif1<<endl;
		update_tree(1,1,n,posInBase[chainHead[uchain]],posInBase[u],tmp,dif1);
		u=chainHead[uchain];
		u=pa[u][0];
	}
}


int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	chainNo=0;
	ptr=1;
	cin>>n>>q;
	adj.resize(0);
	adj.resize(n+5);
	tw=mod_pow(2LL,mod-2);
	rep(i,n-1){
		int a,b;
		cin>>a>>b;
		a++;
		b++;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	rep(i,n+1){
		dep[i]=-1;
		vi[i]=0;
	}
	rep(j,20){
		rep(i,n+1){
			pa[i][j]=-1;
		}
	}
	rep(i,n+1){
		chainHead[i]=posInBase[i]=chainHead[i]=-1;
	}
	vi[1]=1;
	dep[1]=0;
	dfs(1);
	vi[1]=2;
	hld(1);
	repp(j,1,20){
		repp(i,1,n+1){
			pa[i][j]=(pa[i][j-1] != -1)?pa[pa[i][j-1]][j-1]:-1;
		}
	}
	build_tree(1,1,n);
	while(q--){
		int x;
		cin>>x;
		if(x ==2){
			int a,b;
			cin>>a>>b;
			a++;b++;
			int lc=lca(a,b);
			//cout<<lc<<endl;
			ll tmp1=query_up(a,lc);
			ll tmp2=query_up(b,lc);
			ll tmp3=query_up(lc,lc);
			//cout<<a<<" "<<lc<<": "<<tmp1<<endl;
			//cout<<b<<" "<<lc<<": "<<tmp2<<endl;
			//cout<<lc<<" "<<lc<<": "<<tmp3<<endl;
			//cout<<tmp1<<" "<<tmp2<<" "<<tmp3<<endl;
			ll ans=add(tmp1,tmp2);
			ans=add(ans,mod-tmp3);
			cout<<ans<<endl;
		}else{
			int u,v;
			cin>>u>>v;
			u++;v++;
			ll x;
			cin>>x;
			x%=mod;
			if(u == v){
				update_up(u,u,x,x);
				continue;
			}
			int lc=lca(u,v);
			cout<<"lca: "<<lc<<endl;
			//cout<<u<<" "<<lc<<" "<<x<<" "<<x<<endl;
			//cout<<"hel"<<endl;
			update_up(u,lc,x,x);
			//cout<<"//////lo"<<endl;
			ll len=(ll)(dep[u]-dep[lc]);
			len=add(len,(ll)(dep[v]-dep[lc]));
			len=add(len,1LL);
			ll tx=mul(len,x);
			//cout<<v<<" "<<lc<<" "<<tx<<" "<<((mod-x)%mod)<<endl;
			//cout<<"hel"<<endl;
			update_up(v,lc,tx,(mod-x)%mod);
			//cout<<"//lo"<<endl;
			len=(ll)(dep[u]-dep[lc]+1);
			tx=mul(len,x);
			//cout<<lc<<" "<<lc<<" "<<(mod-tx)%mod<<" "<<x<<endl;
			//cout<<"hel"<<endl;
			update_up(lc,lc,(mod-tx)%mod,x);
			//cout<<"/lo"<<endl;
		}
	}
	//cout<<"//////////////////////"<<endl;
	//update_up(1,1,mod-1,0);
	/*
	 *debug=true;
	 *update_tree(1,1,n,1,3,1,1);
	 *cout<<posInBase[1]<<": "<<endl;
	 *cout<<"val 1: "<<query_tree(1,1,n,posInBase[1],posInBase[1])<<endl;
	 *cout<<posInBase[2]<<": "<<endl;
	 *cout<<"val 2: "<<query_tree(1,1,n,posInBase[2],posInBase[2])<<endl;
	 *cout<<posInBase[3]<<": "<<endl;
	 *cout<<"val 3: "<<query_tree(1,1,n,posInBase[3],posInBase[3])<<endl;
	 */
	return 0;
}

