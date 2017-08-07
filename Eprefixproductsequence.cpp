// Constructive prefix product. tags: number-theory.
// http://codeforces.com/problemset/problem/488/E
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
//const ll mod  = 1e9+7;
const int N = 1e6+10;
const ll INF = 1e18;

#define ld long double
//#define double long double
const ld EPS=1e-12;

ll inv[100005];
int pr[100005];
ll mod;

ll mod_pow(ll x, ll p){
	if(p == 0){
		return 1LL;
	}
	if( p == 1 ){
		return x;
	}
	ll tmp=mod_pow(x,p/2LL);
	tmp=tmp*tmp;
	tmp%=mod;
	if(p%2 == 1){
		tmp*=x;
		tmp%=mod;
	}
	return tmp;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n;
	cin>>n;
	repp(i,2,n+1){
		pr[i]=1;
	}
	repp(i,2,n+1){
		if(pr[i] == 1){
			for(int j=2;i*j<=n;j++){
				pr[i*j]=0;
			}
		}
	}
	if(n == 1){
		cout<<"YES"<<endl;
		cout<<"1"<<endl;
		return 0;
	}
	if(n == 4){
		cout<<"YES"<<endl;
		cout<<"1"<<endl;
		cout<<"3"<<endl;
		cout<<"2"<<endl;
		cout<<"4"<<endl;
		return 0;
	}
	if(pr[n] == 0){
		cout<<"NO"<<endl;
		return 0;
	}
	mod=n;
	repp(i,1,n+1){
		inv[i]=mod_pow((ll)(i),mod-2);
	}
	cout<<"YES"<<endl;
	cout<<"1"<<endl;
	repp(i,2,n){
		ll x=(ll)(i);
		x*=inv[x-1];
		x%=mod;
		cout<<x<<endl;
	}
	cout<<n<<endl;
	return 0;
}

