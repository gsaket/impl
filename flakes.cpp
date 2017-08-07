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
#define pb puch_back
#define all(s) s.begin(),s.end()
#define present(c,x) ((c).find(x) != (c).end())
const int mod  = 1e9+7;
const int N = 1e6+10;
const ll INF = 1e18;

#define ld long double
//#define double long double
const ld EPS=1e-12;

int n,m;
string s[5];
string le="left";
string ri ="right";
int main(){
	cin>>n>>m;
	int l,r;
	l=1;r=n;
	int si=0;
	rep(i,m){
		rep(j,5)
			cin>>s[j];
		if(s[2]==le){
			si=0;
		}else{
			si=1;
		}
		int x=stoi(s[4]);
		if(si==1){
			l=max(l,x+1);
		}else{
			r=min(r,x-1);
		}
	}
	if(l>n || r<1){
		cout<<"-1"<<endl;
	}else{
		int net=r-l+1;
		if(net>=1){
			cout<<net<<endl;
		}else{
			cout<<"-1"<<endl;
		}
	}
	return 0;
}

