#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define X first
#define Y second
#define rep(i,a) for(int i=0;i<a;i++)
#define repp(i,a,b) for(int i=a;i<b;i++)
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
	int rev;
	int n7;
	int n4;
	int n47;
	int n74;
};
node tree[4e6+5];
string s;
void build(int v, int left, int right){
	if(left == right) {
		tree[v].rev=0;
		if(s[left] == '7') {
			tree[v].n7=1;
			tree[v].n74=type[v].n47=1;
			tree[v].n4=0;
		} else {
			tree[v].n4=1;
			tree[v].n47=tree[v].n74=1;
			tree[v].n7=0;
		}
		return ;
	}
	int mid=(left+right)/2;
	int leftnode=2*v;
	int rightnode=leftnode+1;
	build(leftnode,left,mid);
	build(rightnode,mid+1,right);
	tree[v].rev=0;
	tree[v].n4=tree[leftnode].n4+tree[v].n4;
	tree[v].n7=tree[rightnode].n7+tree[v].n7;
	tree[v].n47=max(tree[leftnode].n4+tree[rightnode].n47,tree[leftnode].n47+tree[v].n7);
	tree[v].n74=max(tree[leftnode].n7+tree[rightnode].n74,tree[leftnode].n74+tree[v].n4);
}
int query(){
	if(tree[1].rev==0) {
		return tree[1].n47;
	}else {
		return tree[1].n74;
	}
}
void update(int v,int left,int right,int l,int r, int up){
	if(left == l && right == r) {
		
	}
}
int main(){
	return 0;
}

