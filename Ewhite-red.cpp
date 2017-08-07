//simple observations and very nice graph construction.
//http://codeforces.com/problemset/problem/755/E
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
vector<pii > v;
int main(){
	int n,k,m;
	cin>>n>>k;
	if ( k > 3 || k == 1 ) {
		cout<<"-1"<<endl;
		return 0;;
	}
	if( k == 3 ) {
		if(n<4){
			cout<<"-1"<<endl;
			return 0;
		}
		v.pb(mp(1,2));
		v.pb(mp(2,3));
		v.pb(mp(3,4));
		repp(i,5,n+1) {
			v.pb(mp(i,1));
			v.pb(mp(i,3));
			for (int  j = i-1;j >= 5; j-- ) {
				v.pb(mp(i,j));
			}
		}
		cout<<v.size()<<endl;
		rep(i,v.size()) {
			cout<<v[i].X<<" "<<v[i].Y<<endl;
		}
	}else if( k == 2 ){
		if(n<=4){
			cout<<"-1"<<endl;
			return 0;
		}
		repp(i,1,n) {
			v.pb(mp(i,i+1));
		}
		cout<<v.size()<<endl;
		rep(i,v.size()) {
			cout<<v[i].X<<" "<<v[i].Y<<endl;
		}
	}
	return 0;
}

