// Nice problem based on sorting and pointers, tags: sorting, pointers, BIT
// http://codeforces.com/contest/831/problem/E
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
#define E5 100005

#define ld long double
//#define double long double
const ld EPS=1e-12;

ll a[100005];
ll T[100005];
int n;


void SET(int i, ll va){
	while(i<=n+1){
		T[i]=T[i]+va;
		i += (i&(-i));
	}
}

ll GET(ll i){
	ll s=0;
	while( i>0 ){
		s+=T[i];
		i-=(i&(-i));
	}
	return s;
}
vector<vector<ll > > vec;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	cin>>n;
	vec.resize(100005);
	rep(i,n+1){
		T[i]=0;
	}
	repp(i,1,n+1){
		cin>>a[i];
		SET(i,1);
		vec[a[i]].pb(i);
	}
	ll ans=0;
	int pt=0;
	rep(i,100005){
		if(vec[i].size() == 0){
			continue;
		}
		//cout<<i<<" "<<ans<<endl;
		if(pt < vec[i][0]){
			int si=(int)vec[i].size();
			int x=vec[i][si-1];
			ans+=GET(x);
			ans-=GET(pt);
			pt=x;
			rep(j,vec[i].size()){
				int y=vec[i][j];
				SET(y,-1);
			}
			//cout<<i<<" -1- "<<ans<<endl;
		}else{
			int tmp=0;
			rep(j,vec[i].size()){
				int x=vec[i][j];
				if(x >= pt)break;
				tmp=x;
			}
			ans+=GET(tmp);
			ans+=GET(n);
			ans-=GET(pt);
			pt=tmp;
			rep(j,vec[i].size()){
				int x=vec[i][j];
				SET(x,-1);
			}
			//cout<<i<<" -2- "<<ans<<endl;
		}
		//cout<<"pt: "<<pt<<endl;
	}
	cout<<ans<<endl;
	//cout<<GET(n)<<endl;
	return 0;
}

