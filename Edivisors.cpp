// Very cool implementation made easy using dfs-trick. tags: implementation, dfs, divisors
// http://codeforces.com/problemset/problem/448/E
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

ll x,k;
vector<ll> vec;
vector<ll> vec1;

ll tmp=100000;

void dfs(int a,int b){
	//cout<<a<<" "<<b<<endl;
	if(tmp<=0){
		return;
	}
	if(a == 0 || b == k){
		tmp--;
		printf("%I64d ",vec[a]);
		return;
	}
	for(int i=0;i<=a;i++){
		if(vec[a]%vec[i] == 0){
			dfs(i,b+1);
		}
	}
}


int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	scanf("%I64d%I64d",&x,&k);
	for(ll i=1LL;i*i<=x;i++){
		if(x%i==0){
			vec.pb(i);
			if(i*i!=x)vec1.pb(x/i);
		}
	}
	for(int i=vec1.size()-1;i>=0;i--){
		vec.pb(vec1[i]);
	}
	int l=(int)(vec.size());
	dfs(l-1,0);
	printf("\n");
	return 0;
}

