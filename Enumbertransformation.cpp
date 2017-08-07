// Transforming range into 3 smallr segments, where ans middle segment is repeated multiple times. tags: dp, greedy, number-theory
// http://codeforces.com/problemset/problem/251/C
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


ll gcd(ll x, ll y){
	if(x<y){
		swap(x,y);
	}
	if(y == 0)return x;
	return gcd(y,x%y);
}

ll lcm(ll x, ll y){
	return x*y/gcd(x,y);
}

int dp[500005];
ll k;

ll solve(ll x, ll y){
	//cout<<x<<" "<<y<<endl;
	for(int i=(int)(x);i>=(int)(y);i--){
		dp[i]=x;
	}
	dp[x]=0;
	for(int i=(int)(x);i>(int)(y);i--){
		dp[i-1]=min(dp[i-1],dp[i]+1);
		for(int j=2;j<=(int)(k);j++){
			dp[i-i%j]=min(dp[i-i%j],dp[i]+1);
		}
	}
	return dp[y];
}


int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	ll a,b;
	cin>>a>>b>>k;
	ll m=1;
	repp(i,2,k+1){
		m=lcm(m,(ll)(i));
	}
	ll qu=(a/m)-(b/m);
	if(qu>0){
		cout<<(solve(a%m,0)+solve(m,0)*(qu-1LL)+solve(m,b%m))<<endl;
	}else{
		cout<<(solve(a%m,b%m))<<endl;
	}
	return 0;
}

