// dp, maintaing max and second max
// http://codeforces.com/contest/264/problem/C
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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

ll v[100005];
int c[100005];
ll dp[100005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	cin>>n>>q;
	repp(i,1,n+1){
		cin>>v[i];
	}
	repp(i,1,n+1) {
		cin>>c[i];
	}
	ll a,b;
	if(n == 1){
		while(q--){
			cin>>a>>b;
			cout<<(max(b*v[1],0LL))<<endl;
		}
		return 0;
	}
	ll m1,m1i,m2,m2i;
	m1=0;
	m2=-1e18;
	while(q--){
		cin>>a>>b;
		m1=0;
		m2=-1e18;
		repp(i,1,n+1){
			dp[i]=-1e18;
		}
		repp(i,1,n+1){
			ll dif;
			ll same=dp[c[i]]+a*v[i];
			if(m1 == dp[c[i]]){
				dif=m2+b*v[i];
			}else{
				dif=m1+b*v[i];
			}
			same=max(same,dif);
			if(same<=dp[c[i]]){
				continue;
			}
			if(dp[c[i]] == m1){
				m1=same;
				dp[c[i]]=same;
				continue;
			}
			dp[c[i]]=same;
			if(m1<=same){
				m2=m1;
				m1=same;
			}else if(m2<same){
				m2=same;
			}
			//cout<<m1<<" "<<m2<<endl;
		}
		//repp(i,1,n){
			//cout<<dp[i]<<" ";
		//}cout<<endl;
	cout<<m1<<endl;
	}

	return 0;
}

