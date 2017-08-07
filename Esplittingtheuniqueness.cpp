// Good but guessable problem. tags: greedy
// http://codeforces.com/problemset/problem/297/C
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


vector<pii > vec;
int a[100005];
int b[100005];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n;
	cin>>n;
	rep(i,n){
		int x;
		cin>>x;
		vec.pb(mp(x,i));
	}
	sort(vec.begin(),vec.end());
	rep(i,(n+2)/3){
		int idx=vec[i].Y;
		a[idx]=i;
		b[idx]=(vec[i].X)-i;
	}
	repp(i,((n+2)/3),n-((n+2)/3)){
		int idx=vec[i].Y;
		b[idx]=i;
		a[idx]=(vec[i].X)-i;
	}
	repp(i,n-((n+2)/3),n){
		int idx=vec[i].Y;
		b[idx]=n-i-1;
		a[idx]=(vec[i].X)-b[idx];
	}
	cout<<"YES"<<endl;
	rep(i,n){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	rep(i,n){
		cout<<b[i]<<" ";
	}
	cout<<endl;
	return 0;
}

