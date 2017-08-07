// Nice game theory question with good state transitions. tags: game-theory
// http://codeforces.com/problemset/problem/87/C
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

int dp[100005];
int pre[100005];
int net[100005];
int ans[100005];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n;
	cin>>n;
	rep(i,n+1){
		dp[i]=0;
		pre[i]=0;
		net[i]=0;
		ans[i]=-1;
	}
	repp(i,2,n+1){
		for(int j=2;(2*i)>j*(j-1);j++){
			int k=2*i-j*(j-1);
			if(k%(2*j) == 0){
				int d=k/(2*j);
				int val=pre[j+d-1]^pre[d-1];
				net[val]=i;
				if(val == 0 && ans[i]==-1){
					ans[i]=j;
				}
			}
		}
		int mex=0;
		while(net[mex] == i)mex++;
		dp[i]=mex;
		pre[i]=dp[i]^pre[i-1];
	}
	cout<<ans[n]<<endl;
	return 0;
}

