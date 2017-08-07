// Took me 4 days, but amazing question. sum of fibonacci into produt of two fibonacci numbers. tags: fibonacci, BIT
// http://codeforces.com/problemset/problem/446/C
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
const ll mod  = 1e9+9;
const int N = 1e6+10;
const ll INF = 1e18;

#define ld long double
//#define double long double
const ld EPS=1e-12;

ll add(ll x,ll y){
	ll z=x+y;
	z%=mod;
	return z;
}


ll mul(ll x,ll y){
	ll z=x*y;
	z%=mod;
	return z;
}

int fib[300025];
ll T[300025][3];
int n,m;

ll SET(ll i, ll va, int idx){
	while(i<=n+1){
		T[i][idx]=add(T[i][idx],va);
		i+=(i&(-i));
	}
}

ll GET(ll i, int idx){
	ll s=0;
	while(i>0){
		s=add(s,T[i][idx]);
		i-=(i&(-i));
	}
	return s;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	scanf("%d%d",&n,&m);
	fib[1]=1;
	fib[2]=1;
	repp(i,3,n+6){
		fib[i]=add(fib[i-1],fib[i-2]);
	}
	repp(i,1,n+6){
		rep(j,3){
			T[i][j]=0;
		}
	}
	repp(i,1,n+1){
		ll x;
		cin>>x;
		SET(i,x,0);
	}
	while(m--){
		ll x,l,r;
		cin>>x>>l>>r;
		if(x==1){
			// For complete ranges
			//cout<<l<<" "<<(mod-1)<<": 0"<<endl;
			SET(l,mod-1LL,0);
			//cout<<r+1<<" "<<fib[r-l+3]<<": 0"<<endl;
			SET(r+1,fib[r-l+3],0);
			// For partial ranges
			if(l%2==0){
				// fib[r+3]*..
				//cout<<l<<" "<<fib[l+1]<<": 1"<<endl;
				SET(l,fib[l+1],1);
				//cout<<r+1<<" "<<mod-fib[l+1]<<": 1"<<endl;
				SET(r+1,mod-fib[l+1],1);
				 //fib[r+4]*..
				//cout<<l<<" "<<mod-fib[l]<<": 2"<<endl;
				SET(l,mod-fib[l],2);
				//cout<<r+1<<" "<<fib[l]<<": 2"<<endl;
				SET(r+1,fib[l],2);
			}else{
				// fib[r+3]*..
				//cout<<l<<" "<<mod-fib[l+1]<<": 1"<<endl;
				SET(l,mod-fib[l+1],1);
				//cout<<r+1<<" "<<fib[l+1]<<": 1"<<endl;
				SET(r+1,fib[l+1],1);
				// fib[r+4]*..
				//cout<<l<<" "<<fib[l]<<": 2"<<endl;
				SET(l,fib[l],2);
				//cout<<r+1<<" "<<mod-fib[l]<<": 2"<<endl;
				SET(r+1,mod-fib[l],2);
			}
		}else{
			l--;
			//r++;
			ll tmp1=GET(r,1);
			tmp1=mul(fib[r+3],tmp1);
			ll tmp2=GET(r,2);
			tmp2=mul(fib[r+4],tmp2);
			//cout<<tmp1<<" "<<tmp2<<endl;
			tmp1=add(tmp1,tmp2);
			ll tmp=GET(r,0);
			//cout<<tmp<<endl;
			tmp=add(tmp,tmp1);
			ll tp1=GET(l,1);
			tp1=mul(fib[l+3],tp1);
			ll tp2=GET(l,2);
			tp2=mul(fib[l+4],tp2);
			//cout<<tp1<<" "<<tp2<<endl;
			tp1=add(tp1,tp2);
			ll tp=GET(l,0);
			//cout<<tp<<endl;
			tp=add(tp,tp1);
			tmp=add(tmp,mod-tp);
			tmp=add(tmp,0);
			cout<<tmp<<endl;
		}
	}
	return 0;
}

