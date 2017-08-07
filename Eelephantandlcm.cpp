// prefix sum type of optimization. tags: prefix-sum, dp, number-theory, divisors, counting
// http://codeforces.com/contest/258/problem/C
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

vector<ll> a;
vector <ll> vec;
vector<ll>vec1;
ll pr[100006];
ll dp[100005];

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
	if(x<0)return 0LL;
	if(p == 0){
		return 1LL;
	}
	if(p == 1LL){
		return x;
	}
	ll tmp=mod_pow(x,p/2);
	tmp=mul(tmp,tmp);
	tmp=(p%2==1)?mul(tmp,x):tmp;
	return tmp;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n;
	//cin>>n;
	scanf("%d",&n);
	ll mx=0;
	rep(i,10){
		pr[i]=0LL;
	}
	rep(i,n){
		ll x;
		//cin>>x;
		scanf("%I64d",&x);
		a.pb(x);
		pr[(int)(x)]++;
		mx=max(mx,x);
	}
	repp(i,1,100005){
		pr[i]+=pr[i-1];
	}
	//sort(a.begin(),a.end());
	//cout<<"a:"<<endl;
	//rep(i,n){
		//cout<<a[i]<<" ";
	//}cout<<endl;
	ll ans=0;
	repp(k,1,mx+1){
		//cout<<k<<":"<<endl;
		vec.resize(0);
		vec1.resize(0);
		repp(j,1,k+1){
			if(j*j>k)break;
			if(k%j == 0){
				vec.pb(j);
				if(j*j!=k)vec1.pb(k/j);
			}
		}
		for(int i=(int)(vec1.size())-1;i>=0;i--){
			vec.pb(vec1[i]);
		}
		//sort(vec.begin(),vec.end());
		int pt=0;
		rep(i,vec.size()){
			dp[i]=0;
			if(i+1 == (int)(vec.size())){
				dp[i]=pr[100002]-pr[(int)(vec[i])-1];
			}else{
				dp[i]=pr[(int)(vec[i+1])-1]-pr[(int)(vec[i])-1];
			}
		}
		rep(i,vec.size()){
			//cout<<i+1<<":"<<dp[i]<<":"<<vec[i]<<" ";
		}
		//cout<<endl;
		ll tmp=1LL;
		ll y = (ll)(vec.size());
		rep(i,(int)(vec.size())-1){
			tmp=mul(tmp,mod_pow((ll)(i+1),(ll)(dp[i])));
		}
		ll tmp1=mod_pow(y,(ll)(dp[y-1]));
		ll tmp2=mod_pow(y-1,(ll)(dp[y-1]));
		//cout<<tmp1<<" "<<tmp2<<" ...."<<endl;
		tmp1=add(tmp1,mod-tmp2);
		tmp=mul(tmp,tmp1);
		//cout<<tmp<<"//"<<endl;
		ans=add(ans,tmp);
	}
	cout<<ans<<endl;
	return 0;
}

