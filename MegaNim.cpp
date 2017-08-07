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

ll dp[100][1005];


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

ll tp[100];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n;
	ll M;
	cin>>n>>M;
	rep(i,100){
		rep(j,n+5){
			dp[i][j]=0;
		}
	}
	tp[0]=1LL;
	repp(i,1,62){
		tp[i]=mul(2LL,tp[i-1]);
	}
	int cnt=0;
	rep(i,61){
		if((tp[i]&M) == tp[i]){
			cnt=i;
		}
	}
	//cout<<cnt<<endl;
	rep(i,n+1){
		if(i%2==0){
			dp[cnt][i]=1LL;
		}
	}
	for(int i=cnt-1;i>=0;i--){
		ll tmp=(1LL<<i);
		if((tmp&M )== tmp){

		}
	ll ans=0;
	rep(j,n+1){
		ans=add(ans,dp[0][j]);
	}
	rep(i,5){
		rep(j,4){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

