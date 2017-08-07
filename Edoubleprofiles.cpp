// First non-trivial problem I did on my on. Expected solution was hashing but  I did it by sorting. tags: sorting
// http://codeforces.com/problemset/problem/154/C
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

//vector<pair<pair<int,int>,vector<int> > > adj;
vector<pair<pair<int,vector<int> >,int > > adj;

map<pii ,int> ma;

ll ans[1000006];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n,m;
	//cin>>n>>m;
	scanf("%d%d",&n,&m);
	adj.resize(n);
	rep(i,m){
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x-1].X.Y.pb(y-1);
		adj[y-1].X.Y.pb(x-1);
	}
	rep(i,n){
		adj[i].Y=i;
		adj[i].X.X=(int)(adj[i].X.Y.size());
		sort(adj[i].X.Y.begin(),adj[i].X.Y.end());
	}
	sort(adj.begin(),adj.end());
	ll net=0;
	rep(i,n){
		ans[i]=0;
	}
	repp(i,1,n+1){
		// if i  and i-1 are doubles add ans[i-1]+1
		if((int)adj[i].X.Y.size() != (int)adj[i-1].X.Y.size()){
			continue;
		}
		int l=0;
		int r=0;
		int flag=1;
		while(l<(int)adj[i].X.Y.size() && r<(int)(adj[i-1].X.Y.size())){
			/*
			 *if((adj[i].X.Y)[l] == (adj[i-1].Y) || (adj[i].X.Y)[l] == (adj[i].Y)){
			 *    l++;
			 *    continue;
			 *}
			 *if((adj[i-1].X.Y)[r] == (adj[i].Y) || (adj[i-1].X.Y)[r] == (adj[i-1].Y)){
			 *    r++;
			 *    continue;
			 *}
			 */
			if((adj[i].X.Y)[l] != (adj[i-1].X.Y)[r]){
				flag = 0;
				break;
			}
			l++;r++;
		}
		if(flag==1){
			ma[mp(adj[i].Y,adj[i-1].Y)]=1;
			ma[mp(adj[i-1].Y,adj[i].Y)]=1;
			ans[i]=ans[i-1]+1LL;
		}
	}
	/*
	 *rep(i,n){
	 *    cout<<adj[i].Y<<": ";
	 *    rep(j,adj[i].X.Y.size()){
	 *        cout<<(adj[i].X.Y)[j]<<" ";
	 *    }
	 *    cout<<":: "<<ans[i]<<endl;
	 *}
	 */
	rep(i,n){
		net+=ans[i];
		ans[i]=0;
	}
	rep(i,n){
		adj[i].X.Y.pb(adj[i].Y);
	}
	rep(i,n){
		sort(adj[i].X.Y.begin(),adj[i].X.Y.end());
	}
	sort(adj.begin(),adj.end());

	repp(i,1,n+1){
		// if i  and i-1 are doubles add ans[i-1]+1
		if((int)adj[i].X.Y.size() != (int)adj[i-1].X.Y.size()){
			continue;
		}
		if(ma[mp(adj[i].Y,adj[i-1].Y)] == 1)continue;
		int l=0;
		int r=0;
		int flag=1;
		while(l<(int)adj[i].X.Y.size() && r<(int)(adj[i-1].X.Y.size())){
			if((adj[i].X.Y)[l] != (adj[i-1].X.Y)[r]){
				flag = 0;
				break;
			}
			l++;r++;
		}
		if(flag==1){
			ans[i]=ans[i-1]+1LL;
		}
	}

	/*
	 *rep(i,n){
	 *    cout<<adj[i].Y<<": ";
	 *    rep(j,adj[i].X.Y.size()){
	 *        cout<<(adj[i].X.Y)[j]<<" ";
	 *    }
	 *    cout<<":: "<<ans[i]<<endl;
	 *}
	 */

	rep(i,n){
		net+=ans[i];
		ans[i]=0;
	}
	cout<<net<<endl;
	return 0;
}

