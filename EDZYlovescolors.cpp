// My first lazy propagation problem. Here, we push into the whole subtree. tags: segtree, lazy-propagation, godown
// http://codeforces.com/problemset/problem/444/C
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

struct node{
	int color;
	ll lazy;
	ll sum;
};

node tree[400005];

void build_tree(int v, int l, int r){
	tree[v].color=0;
	tree[v].lazy=0;
	tree[v].sum=0;
	if(l == r){
		tree[v].color=l;
		return;
	}
	int mid=(l+r)/2;
	build_tree(2*v, l, mid);
	build_tree(2*v+1, mid+1, r);
}

void push_node(int v, int l,int r){
	if(tree[v].lazy==0){
		return;
	}
	tree[v].sum+=(ll)(r-l+1)*tree[v].lazy;
	if(l!=r){
		tree[2*v].lazy+=tree[v].lazy;
		tree[2*v+1].lazy+=tree[v].lazy;
	}
	tree[v].lazy=0;
}

void godown(int v,int l,int r, int val){
	push_node(v, l, r);
	if(tree[v].color == 0){
		int mid=(l+r)/2;
		godown(2*v,l,mid,val);
		godown(2*v+1,mid+1,r,val);
		tree[v].sum=tree[2*v].sum+tree[2*v+1].sum;
		tree[v].color = val;
	}else{
		tree[v].lazy+=(ll)abs(tree[v].color - val);
		push_node(v, l, r);
		tree[v].color=val;
	}
	//cout<<v<<" "<<l<<" "<<r<<" "<<val<<" "<<tree[v].color<<" "<<tree[v].sum<<endl;
}

void update_tree(int v,int tl, int tr, int ql, int qr, int val){
	if(ql>qr || tl>tr)return;
	if(tree[v].color != 0 && tl != tr){
		tree[2*v].color=tree[2*v+1].color=tree[v].color;
	}
	push_node(v, tl, tr);
	if(tr<ql || tl>qr)return;
	if(ql<=tl && tr<=qr){
		//cout<<v<<" "<<tl<<" "<<tr<<" "<<ql<<" "<<qr<<endl;
		godown(v, tl, tr, val);
		return ;
	}
	int mid=(tl+tr)/2;
	update_tree(2*v, tl, mid, ql, qr, val);
	update_tree(2*v+1, mid+1, tr, ql, qr, val);
	if(tree[2*v].color == tree[2*v+1].color ){
		tree[v].color = tree[2*v].color;
	}else{
		tree[v].color = 0;
	}
	tree[v].sum = tree[2*v].sum+tree[2*v+1].sum;
}

ll query_tree(int v, int tl, int tr, int ql, int qr){
	push_node(v, tl, tr);
	if(ql>qr || tl >tr ){
		return 0;
	}
	if(tr<ql || tl>qr){
		return 0;
	}
	if(ql<=tl && tr<=qr){
		return tree[v].sum;
	}
	int mid=(tl+tr)/2;
	return query_tree(2*v,tl,mid,ql,qr) + query_tree(2*v+1,mid+1,tr,ql,qr);
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	build_tree(1,1,n);
	while(m--){
		int type;
		cin>>type;
		if(type == 1){
			int a,b,c;
			cin>>a>>b>>c;
			update_tree(1,1,n,a,b,c);
		}else{
			int a,b;
			cin>>a>>b;
			ll ans=query_tree(1,1,n,a,b);
			cout<<ans<<endl;
		}
	}
	return 0;
}

