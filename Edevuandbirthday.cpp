// Good question by Praveen Dhinwa, tags: math, mobius-inversion, divisors, fac, ncr
// http://codeforces.com/problemset/problem/439/E
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

ll fac[100005];
ll ifac[100005];

ll add(ll x, ll y){
	ll tmp=x+y;
	if(tmp<mod){
		tmp+=mod;
	}
	if(tmp>=mod){
		tmp%=mod;
	}
	return tmp;
}

ll mul(ll x, ll y){
	ll tmp=x*y;
	if(tmp<mod){
		tmp+=mod;
	}
	if(tmp>=mod){
		tmp%=mod;
	}
	return tmp;
}

ll mod_pow(ll x, ll p){
	if( p == 0 ){
		return 1;
	}
	if( p == 1 ){
		return x;
	}
	ll tmp=mod_pow(x,p/2);
	tmp=mul(tmp,tmp);
	if(p%2LL == 1){
		tmp=mul(tmp,x);
	}
	return tmp;
}

ll nu[100015];
int pr[100015];
vector<vector<int> > di;

void compute_nu(int n){
	nu[1]=1;
	repp(i,2,n){
		pr[i]=1;
		nu[i]=1;
	}
	repp(i,2,n){
		if(pr[i]==1){
			nu[i]=-1;
			for(int j=2;i*j<n;j++){
				pr[i*j]=0;
				if(j%i == 0){
					nu[i*j]=0;
				}else{
					nu[i*j]*=-1;
				}
			}
		}
	}
}

void compute_div(int n){
	repp(i,1,n){
		for(int j=1;i*j<n;j++){
			di[i*j].pb(i);
		}
	}
}

ll ncr(ll x, ll y){
	if(x<y)return 0;
	ll tmp=fac[x];
	tmp=mul(tmp,ifac[y]);
	tmp=mul(tmp,ifac[x-y]);
	return tmp;
}



int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int q,n,f;
	n=100005;
	compute_nu(n);
	di.resize(n+5);
	compute_div(n);
	cin>>q;
	fac[0]=ifac[0]=1LL;
	repp(i,1,n){
		fac[i]=mul(fac[i-1],(ll)i);
	}
	repp(i,1,n){
		ifac[i]=mod_pow(fac[i],mod-2);
	}
	while(q--){
		cin>>n>>f;
		ll ans=0;
		rep(i,di[n].size()){
			int x=di[n][i];
			ll tmp=ncr(x-1,f-1);
			//cout<<x<<" "<<tmp<<endl;
			tmp=mul(tmp,nu[n/x]);
			ans=add(ans,tmp);
		}
		cout<<ans<<endl;
	}
	return 0;
}

