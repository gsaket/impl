//my first Div-2 F
//simple question for a F, but nice observations made
//sometimes simple is all you need.
//http://codeforces.com/contest/758/problem/F
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

ll gcd(ll x, ll y ) {
	if(y==0) {
		return x;
	}
	return gcd(y,x%y);
}
ll pow_(ll x, ll p) {
	if(p==0){
		return 1LL;
	}
	if(p==1){
		return x;
	}
	ll tp=pow_(x,p/2LL);
	tp*=tp;
	if(p%2==1){
		tp*=x;
	}
	return tp;
}

ll n,l,r;
int main(){
	cin>>n>>l>>r;
	if(n==1){
		cout<<(r-l+1)<<endl;
		return 0;
	}
	if(n == 2){
		ll net=(r-l+1)*(r-l);
		cout<<net<<endl;
		return 0;
	}
	ll net=0;
	for(int i=1;(int)pow_(i,n-1)<=r;i++){
		for(int j=i+1;(int)pow_(j,n-1)<=r;j++){
			if(j>3200)break;
			if(gcd(j,i) == 1 ){
				ld tp=(ld)(pow_(i,n-1));
				ld tp1=(ll)(pow_(j,n-1));
				ll tmp=(ll)(floor(r/tp1)-ceil(l/tp)+1);
				if(tmp>0){
					net+=tmp;
				}
			}
		}
	}
	net*=2;
	cout<<net<<endl;
	return 0;
}

