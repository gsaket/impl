// woking on smaller data using maps and stuff. tags: dp, counting, ncr, rec-gen
// http://codeforces.com/problemset/problem/145/C
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

int a[100005];
ll cnt[2005];
map <int,int> ma;
vector <ll> vec;
ll fac[100005];
ll inv[100005];
ll invfac[100005];

void gen(ll x){
	x*=10LL;
	if(x+4<=(ll)(1e9)){
		vec.pb(x+4);
		gen(x+4);
	}
	if(x+7<=(ll)(1e9)){
		vec.pb(x+7);
		gen(x+7);
	}
}

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

ll mod_pow(ll x, ll p){
	if(p == 0){
		return 1LL;
	}
	if(p == 1){
		return x;
	}
	ll tmp=mod_pow(x,p/2LL);
	tmp=mul(tmp,tmp);
	if(p%2==1)tmp=mul(tmp,x);
	return tmp;
}

ll ncr(ll x, ll y){
	if(y<0)return 0LL;
	if(y>x)return 0LL;
	ll tmp=fac[x];
	tmp=mul(tmp,invfac[y]);
	tmp=mul(tmp,invfac[x-y]);
	return tmp;
}

ll dp[2005][2005];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	rep(i,n){
		cin>>a[i];
	}
	gen(0LL);
	sort(vec.begin(), vec.end());
	//cout<<(int)(vec.size())<<endl;
	rep(i,vec.size()){
		ma[(int)(vec[i])]=i+1;
		cnt[i+1]=0;
	}
	int un=0;
	rep(i,n){
		if(ma[a[i]] == 0){
			un++;
		}else{
			cnt[ma[a[i]]]++;
		}
	}
	fac[0]=1;
	repp(i,1,n+1){
		fac[i]=mul(fac[i-1],(ll)(i));
	}
	inv[0]=1LL;
	repp(i,1,n+1){
		inv[i]=mod_pow((ll)(i),mod-2);
	}
	invfac[0]=1LL;
	repp(i,1,n+1){
		invfac[i]=mul(inv[i],invfac[i-1]);
	}
	int m=(int)(vec.size());
	repp(i,0,m+1){
		rep(j,m+1){
			dp[i][j]=0;
		}
	}
	dp[0][0]=1LL;
	repp(i,1,m+1){
		rep(j,m+1){
			dp[i][j]=add(dp[i][j],dp[i-1][j]);
			if(j>0)dp[i][j]=add(dp[i][j],mul(dp[i-1][j-1],cnt[i]));
		}
	}
	ll ans=0;
	rep(i,m+1){
		ll tmp=ncr((ll)(un),(ll)(k-i));
		tmp=mul(tmp,dp[m][i]);
		ans=add(ans,tmp);
	}
	cout<<ans<<endl;
	return 0;
}

