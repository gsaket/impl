// Greedy Game Play problem. tags: game-theory, greedy
// http://codeforces.com/problemset/problem/135/C
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

int ans[4];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	string s;
	int one,zr,qu;
	one=zr=qu=0;
	cin>>s;
	rep(i,4){
		ans[i]=0;
	}
	string net[4]={"00","01","10","11"};
	rep(i,s.size()){
		if(s[i] == '1'){
			one++;
		}else if(s[i] == '0'){
			zr++;
		}else{
			qu++;
		}
	}
	if(zr+qu>one){
		ans[0]=1;
	}
	if(qu+one>zr+1){
		ans[3]=1;
	}
	int n=(int)(s.size());
	int x=(one+zr+qu)%2;
	x+=zr+qu-one;
	x/=2;
	if(x>=0&&x<=qu){
		if(s[n-1] == '0'){
			ans[2]=1;
		}else if(s[n-1] == '1'){
			ans[1]=1;
		}
	}
	if(s[n-1] == '?'){
		// 0
		zr++;
		qu--;
		x=(one+zr+qu)%2;
		x+=zr+qu-one;
		x/=2;
		if(x>=0&&x<=qu){
			ans[2]=1;
		}
		zr--;
		one++;
		x=(one+zr+qu)%2;
		x+=zr+qu-one;
		x/=2;
		if(x>=0&&x<=qu){
			ans[1]=1;
		}
	}
	rep(i,4){
		if(ans[i]==1){
			cout<<net[i]<<endl;
		}
	}
	return 0;
}

