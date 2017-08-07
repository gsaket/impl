// BIT, coordinate compression, number of inversions extension
// http://codeforces.com/problemset/problem/61/E
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
map<int,int> ma;
map<int,int> ma1;
vector<int> vec;
ll a[1000005];
ll T[1000005];
ll n;

ll SET(ll i,ll va){
	//cout<<i<<" "<<va<<endl;
	while(i<=n+1) {
		//cout<<i<<endl;
		T[i]=T[i]+va;
		i += (i & (-i));
	}
}

ll GET(ll i) {
	ll s=0;
	while( i > 0 ) {
		s += T[i];
		i -= ( i & (-i) );
	}
	return s;
}


int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	cin>>n;
	repp(i,0,n){
		cin>>a[i];
		vec.pb(a[i]);
	}
	sort(vec.begin(),vec.end());
	int t=1;
	rep(i,n){
		//cout<<vec[i]<<" "<<i<<" "<<(n-i)<<endl;
		ma[vec[i]]=(n-i);
	}
	repp(i,0,n){
		a[i]=ma[a[i]];
		//cout<<i<<" "<<a[i]<<endl;
	}
	repp(i,1,n+1){
		T[i]=0;
	}
	ll ans=0;
	repp(i,0,n){
		ll tmp;
		tmp=GET(a[i]-1);
		ll tmp1=(n-a[i])-(i-tmp);
		ans+=tmp*tmp1;
		//cout<<i<<" "<<tmp<<" "<<tmp1<<endl;
		SET(a[i],1LL);
	}
	cout<<ans<<endl;
	return 0;
}

