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

vector<pair<int,int> > ad1,ad2;

int get(int v){
	if(p[])
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	ad1.resize(n+5);
	ad2.resize(n+5);
	rep(i,1,m){
		int x,y;
		char c;
		cin>>x>>y>>c;
		if(c =='S'){
			ad1[x].pb(mp(y,c));
			ad1[y].pb(mp(x,c));
		}else{
			ad2[x].pb(mp(y,c));
			ad2[y].pb(mp(x,c));
		}
	}
	int hf=(n-1)/2;
	if(n%2==0){
		cout<<"-1"<<endl;
		return 0;
	}
	
	return 0;
}

