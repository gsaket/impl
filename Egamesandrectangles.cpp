// Nice combinatorics question
// http://codeforces.com/problemset/problem/128/C
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

ll ncr[1005][1005];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	rep(i,1005){
		rep(j,1005){
			ncr[i][j]=0;
		}
	}
	ll mo=1e9+7;
	ncr[0][0]=1;
	repp(i,1,1005){
		ncr[i][0]=1;
		repp(j,1,i+1){
			ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%(mo);
		}
	}
	int n,m,k;
	ll ans;
	cin>>n>>m>>k;
	if(2*k>min(n-1,m-1)){
		cout<<"0"<<endl;
		return 0;
	}else{
		ans=ncr[n-1][2*k];
		ans=(ans*ncr[m-1][2*k])%mo;
	}
	cout<<ans<<endl;
	return 0;
}

