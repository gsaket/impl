//my first G solved without refering tutorial.
//ans is bounded by min and max possible, and some implementation.
//f[i]->start of level used here is helpful for cleaner implementation.
//http://codeforces.com/problemset/problem/746/G
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
int a[200005];
int f[200005];
vector<vector<int> > adj;
int main(){
	int n,t,k;
	cin>>n>>t>>k;
	adj.resize(n+5);
	int s=0;
	repp(i,1,t+1) {
		cin>>a[i];
		s+=a[i];
	}
	if(s!=n-1){
		cout<<"-1";
		return 0;
	}
	f[0]=1;
	f[1]=2;
	repp(i,2,t+2){
		f[i]=f[i-1]+a[i-1];
	}
	int minl=0;
	a[t+1]=0;
	repp(i,1,t+1){
		minl+=max(0,a[i]-a[i+1]);
	}
	int maxl=n-t;
	if (maxl<k||k<minl) {
		cout<<"-1"<<endl;
		return 0;
	}
	repp(i,f[1],f[2]){
		adj[1].pb(i);
	}
	repp(i,1,t){
		int tp;
		rep(j,a[i]) {
			if(f[i+1]+j>=f[i+2])break;
			tp=j;
			adj[f[i]+j].pb(f[i+1]+j);
		}
		tp++;
		while(tp+f[i+1]<f[i+2]){
			adj[f[i]].pb(f[i+1]+tp);
			tp++;
		}
	}
	k-=minl;
	int flag=0;
	if(k == 0)flag=1;
	for(int i=t-1;i>=1;i--){
		if(flag == 1||k == 0)break;
		for(int j=f[i+1]-1;j>f[i];j--){
			//cout<<i<<" "<<j<<" "<<k<<endl;
			//if(j==5)cout<<"hello "<<adj[5].size()<<endl;
			if(flag == 1 ||k == 0)break;
			if(adj[j].size() == 0)continue;
			for(int k=0;k<adj[j].size();k++){
				int v=adj[j][k];
				adj[f[i]].pb(v);
			}
			adj[j].clear();
			k--;
			if(k==0){
				flag=1;
				break;
			}
		}
	}
	cout<<n<<endl;
	repp(i,1,n+1) {
		rep(j,adj[i].size()){
			cout<<i<<" "<<adj[i][j]<<endl;
		}
	}
	//repp(i,0,t+2){
		//cout<<f[i]<<" ";
	//}cout<<endl;
	return 0;
}

