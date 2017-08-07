// Standard method of using segment tree for dp update. tags: segtree, dp
// http://codeforces.com/problemset/problem/137/E
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
const int inf = 1e9;

#define ld long double
//#define double long double
const ld EPS=1e-12;

int a[200005];
int pre[200005];
int tp[200005];
vector<pair<int,int> > vec;
int posInBase[200005];

int tree[800005];

void build_tree(int v,int l,int r){
	if(l == r){
		tree[v]=vec[l-1].Y;
		return;
	}
	int mid=(l+r)/2;
	build_tree(2*v,l,mid);
	build_tree(2*v+1,mid+1,r);
	tree[v]=min(tree[2*v+1],tree[2*v]);
}

int query_tree(int v,int tl,int tr,int ql,int qr){
	if(tl>tr|| ql>qr)return inf;
	if(ql<=tl && tr<=qr){
		return tree[v];
	}
	int mid=(tl+tr)/2;
	if(qr<=mid){
		return query_tree(2*v,tl,mid,ql,qr);
	}
	if(mid<ql){
		return query_tree(2*v+1,mid+1,tr,ql,qr);
	}
	int tmp1=query_tree(2*v,tl,mid,ql,qr);
	int tmp2=query_tree(2*v+1,mid+1,tr,ql,qr);
	int tmp=min(tmp1,tmp2);
	return tmp;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL)
	string s;
	cin>>s;
	rep(i,s.size()){
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
			a[i+1]=-1;
		}else{
			if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U') a[i+1]=-1;
			else a[i+1]=2;
		}
	}
	int n=(int)(s.size());
		a[0]=0;
	repp(i,1,n+1){
		pre[i]=a[i]+pre[i-1];
	}
	/*
	 *repp(i,1,n+1){
	 *    cout<<a[i]<<" ";
	 *}
	 *cout<<endl;
	 *repp(i,1,n+1){
	 *    cout<<pre[i]<<" ";
	 *}
	 *cout<<endl;
	 *cout<<"/////////"<<endl;
	 */
	repp(i,0,n+1){
		vec.pb(mp(pre[i],i));
	}
	sort(vec.begin(),vec.end());
	rep(i,vec.size()){
		posInBase[vec[i].Y]=i+1;
	}
	int cnt=0;
	int idx=0;
	int len=0;
	build_tree(1,1,n+1);
	repp(i,1,n+1){
		int x=posInBase[i];
		int y=query_tree(1,1,n+1,1,x-1);
		tp[i]=y;
		if(y!=inf){
			if(i>=y){
				int val=pre[i]-pre[y];
				if(val>=0){
					int l=i-y;
					if(l>len){
						len=l;
						cnt=1;
						idx=y;
						//cout<<"YES "<<i<<" "<<len<<endl;
					}else if(l == len){
						cnt++;
					}
				}
			}
		}else{
			if(pre[i]>=0){
				int l=i;
				if(l>len){
					len=l;
					cnt=1;
					idx=0;
					//cout<<"YES "<<i<<" "<<len<<endl;
				}else if(l == len){
					cnt++;
				}
			}
		}
	}
	if(len == 0){
		cout<<"No solution"<<endl;
	}else{
		cout<<len<<" "<<cnt<<endl;
	}
	/*
	 *cout<<"//////"<<endl;
	 *repp(i,1,n+1){
	 *    cout<<i<<" "<<tp[i]<<endl;
	 *}
	 */
	return 0;
}

