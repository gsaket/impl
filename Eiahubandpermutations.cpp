// Easy question similar to derangement, tags: derangement, math
// http://codeforces.com/problemset/problem/340/E
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

int a[2005];
ll m=0;
ll cnt=0;

ll fac[2005];
ll ifac[2005];

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
	int n;
	n=2005;
	fac[0]=ifac[0]=1LL;
	repp(i,1,n){
		fac[i]=mul(fac[i-1],(ll)i);
	}
	repp(i,1,n){
		ifac[i]=mod_pow(fac[i],mod-2);
	}

	cin>>n;
	repp(i,1,n+1){
		cin>>a[i];
		if(a[i]==-1){
			m++;
		}
	}
	repp(i,1,n+1){
		if(a[i]!=-1 && a[a[i]] == -1){
			cnt++;
		}
	}
	cnt=m-cnt;
	ll ans=0;
	//cout<<"m: "<<m<<endl;
	//cout<<"cnt: "<<cnt<<endl;
	rep(i,cnt+1){
		ll tmp=ncr(cnt,i);
		tmp=mul(tmp,fac[(int)m-i]);
		if(i%2==0){
			ans=add(ans,tmp);
		}else{
			ans=add(ans,mod-tmp);
		}
	}
	cout<<ans<<endl;
	return 0;
}

