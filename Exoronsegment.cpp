// Lazy Propagation, array -> arrays of bits.
// My first question I solved using lazy propagation, though I used others code(see bookmark)
// http://codeforces.com/contest/242/problem/E
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
int a[100005];
ll tp[21];


int lazy[400005][21];
int tree[400005][21];

// build (1,1,n)
void build(int v, int left, int right) {
	//cout<<v<<" "<<left<<" "<<right<<endl;;
	if(left == right) {
		rep(i,21){
			if(a[left]&tp[i]){
				//cout<<left<<" "<<i<<endl;
				tree[v][i]=1;
			}else{
				tree[v][i]=0;
			}
			lazy[v][i]=0;
		}
		return ;
	}
	int mid=(left+right)/2;
	build(2*v, left, mid);
	build(2*v+1, mid+1, right);
	rep(i,21) {
		tree[v][i]=tree[2*v][i]+tree[2*v+1][i];
		lazy[v][i]=0;
	}
}

void update_tree(int v, int left,int right, int l , int r,int idx) {
	if(lazy[v][idx] != 0){ //This node is not updated previously.
		tree[v][idx]=(right-left+1)-tree[v][idx]; //update it.

		if(left != right) {
			lazy[2*v][idx] ^= lazy[v][idx];
			lazy[2*v+1][idx] ^= lazy[v][idx];
		}
		lazy[v][idx]=0;
	}
	int qaz;
	if(left > r || left > right || right < l )return;

	if(left >= l && right <= r ) {
		tree[v][idx]=(right-left+1)-tree[v][idx];
		if(left != right ) {
			lazy[2*v][idx] ^= 1;
			lazy[2*v+1][idx] ^= 1;
		}
		return;
	}
	int mid=(left+right)/2;
	update_tree(2*v,left,mid,l,r,idx);
	update_tree(2*v+1,mid+1,right,l,r,idx);
	tree[v][idx] = tree[2*v][idx]+tree[2*v+1][idx];
}

int query_tree(int v,int left,int right,int l,int r,int idx) {
	if(left > right || left > r || right < l ) return 0;

	if(lazy[v][idx] != 0) {
		tree[v][idx] = (right-left+1)-tree[v][idx];
		if( left != right ) {
			lazy[2*v][idx] ^= lazy[v][idx];
			lazy[2*v+1][idx] ^= lazy[v][idx];
		}
		lazy[v][idx] = 0;
	}
	if( left >= l && right <= r) {
		return tree[v][idx];
	}
	int mid=(left+right)/2;
	int tmp1=query_tree(2*v,left,mid,l,r,idx);
	int tmp2=query_tree(2*v+1,mid+1,right,l,r,idx);
	int res=tmp1+tmp2;
	return res;
}



int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n,m;
	scanf("%d",&n);
	repp(i,1,n+1) {
		cin>>a[i];
	}
	repp(i,1,4e5){
		rep(j,21){
			lazy[i][j]=0;
		}
	}
	ll tmp=1;
	rep(i,21){
		tp[i]=tmp;
		tmp*=2;
	}
	build(1,1,n);
	cin>>m;
	int c,l,r,x;
	while(m--){
		cin>>c>>l>>r;
		if(c==1){
			ll net=0;
			rep(i,21){
				net+=tp[i]*(ll)(query_tree(1,1,n,l,r,i));
			}
			cout<<net<<endl;
		}else{
			cin>>x;
			rep(i,21){
				if(x&tp[i]){
					update_tree(1,1,n,l,r,i);
				}
			}
		}
	}
	return 0;
}

