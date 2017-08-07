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

vector<pair<ll,int> > a,b;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n;
	cin>>n;
	rep(i,n){
		ll x;
		cin>>x;
		a.pb(mp(x,i));
	}
	rep(i,n){
		ll x;
		cin>>x;
		b.pb(mp(x,i));
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	ll ans=INF;
	if(a[0].Y == b[0].Y){
		ans=min(a[0].X+b[1].X, a[1].X+b[0].X);
	}else{
		ans=a[0].X+b[0].X;
	}
	cout<<ans<<endl;
	return 0;
}

