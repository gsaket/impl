// dp, same sum strings are interconvertible type query
// http://codeforces.com/problemset/problem/156/C
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

ll dp[105][2510];
ll mo=(ll)(1e9+7);
int a[105];

ll add(ll x,ll y){
	ll tmp=x+y;
	if(tmp>=mo)tmp%=mo;
	return tmp;
}

ll mul(ll x,ll y){
	ll tmp=x*y;
	if(tmp>=mo)tmp%=mo;
	return tmp;
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int t;
	cin>>t;
	rep(i,2510){
		if(i<26){
			dp[0][i]=1;
		}else{
			dp[0][i]=0;
		}
	}
	repp(i,1,101){
		rep(j,2510){
			dp[i][j]=0;
			rep(k,26){
				if(j-k>=0)dp[i][j]=add(dp[i][j],dp[i-1][j-k]);
			}
		}
	}
	string s;
	while(t--){
		cin>>s;
		int x;
		int net=0;
		rep(i,s.size()){
			x=(int)(s[i]-'a');
			net+=x;
		}
		cout<<add(dp[(int)(s.size()-1)][net],mo-1)<<endl;
	}
	return 0;
}

