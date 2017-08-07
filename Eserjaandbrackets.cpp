// Segment tree, nice combine step.
// http://codeforces.com/problemset/problem/380/C
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

struct node {
	int a;
	int b;
	int c;
};
string s;

node tree[4000005];

void build (int v, int l,int r) {
	if ( l == r ) {
		if(s[l-1]=='(') {
			tree[v].a=0;
			tree[v].b=1;
			tree[v].c=0;
		}else{
			tree[v].a=0;
			tree[v].b=0;
			tree[v].c=1;
		}
		return;
	}
	int mid=(l+r)/2;
	build(2*v, l, mid);
	build(2*v+1, mid+1, r);
	int tmp=min(tree[2*v].b,tree[2*v+1].c);
	tree[v].a=tree[2*v].a+tree[2*v+1].a+2*tmp;
	tree[v].b=tree[2*v].b+tree[2*v+1].b-tmp;
	tree[v].c=tree[2*v].c+tree[2*v+1].c-tmp;
}

pair<int, pii> query(int v,int l,int r,int l_,int r_) {
	if(l==l_&&r==r_) {
		pair<int, pii> tp;
		tp.X=tree[v].a;
		tp.Y.X=tree[v].b;
		tp.Y.Y=tree[v].c;
		return tp;
	}
	int mid=(l+r)/2;
	if(r_<=mid){
		return query(2*v,l,mid,l_,r_);
	}
	if(l_>mid){
		return query(2*v+1,mid+1,r,l_,r_);
	}
	pair<int, pii > tp1=query(2*v,l,mid,l_,mid);
	pair<int, pii > tp2=query(2*v+1,mid+1,r,mid+1,r_);
	pair<int, pii > tp;
	int tmp=min(tp1.Y.X,tp2.Y.Y);
	tp.X=tp1.X+tp2.X+2*tmp;
	tp.Y.X=tp1.Y.X+tp2.Y.X-tmp;
	tp.Y.Y=tp1.Y.Y+tp2.Y.Y-tmp;
	return tp;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	cin>>s;
	int q;
	cin>>q;
	int l_,r_;
	build(1,1,s.size());
	while(q--) {
		cin>>l_>>r_;
		pair<int, pii> t=query(1,1,s.size(),l_,r_);
		cout<<t.X<<endl;
	}
	return 0;
}

