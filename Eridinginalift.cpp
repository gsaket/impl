// dp with maintaining prefix sum
// http://codeforces.com/problemset/problem/479/E
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

ll mo=1e9+7;

ll dp[5005];
ll pre[5005];
ll tmp[5005];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n,a,b,k;
	cin>>n>>a>>b>>k;
	if(a == b){
		cout<<"0"<<endl;
		return 0;
	}
	dp[a]=1;
	while(k--){
		pre[0]=0;
		repp(i,1,n+1){
			pre[i]=(pre[i-1]+dp[i])%mo;
			tmp[i]=0;
		}
		pre[n+1]=pre[n];
		repp(i,1,n+1){
			if(i == b) continue;
			if( i < b ){
				int mid=(i+b-1)/2;
				tmp[i]=pre[mid];
				tmp[i]-=dp[i];
				tmp[i]%=mo;
				if(tmp[i]<0)tmp[i]+=mo;
			}else{
				int mid=(i+b)/2;
				//cout<<mid<<endl;
				tmp[i]=pre[n];
				tmp[i]-=pre[mid];
				tmp[i]%=mo;
				if(tmp[i] < 0)tmp[i]+=mo;
				tmp[i]-=dp[i];
				tmp[i]%=mo;
				if(tmp[i] < 0)tmp[i]+=mo;
			}
		}
		repp(i,1,n+1){
			dp[i]=tmp[i];
		}
	}
	ll ans=0;
	repp(i,1,n+1){
		ans+=dp[i];
		ans%=mo;
	}
	cout<<ans<<endl;
	return 0;
}

