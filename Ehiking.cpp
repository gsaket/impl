// Frustating base case issue!! Nice question converting math to graph and binary search, tags: math, binary-search
// http://codeforces.com/problemset/problem/489/E
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
const ld EPS=1e-6;

int x[1005];
ld p[1005];
ld d[1005];
int pre[1005];

ld mo(ld c){
	if(c<0){
		c=-c;
	}
	return c;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n,L;
	cin>>n>>L;
	repp(i,1,n+1){
		cin>>x[i]>>p[i];
	}
	x[0]=0;
	ld l=0;
	ld r=1e3;
	int cnt=0;
	while(cnt<70){
		cnt++;
		ld mid=(l+r)/(ld)(2.0);
		rep(i,n+1){
			d[i]=1e18;
			pre[i]=0;
		}
		d[0]=0;
		repp(i,1,n+1){
			rep(j,i){
				if(d[i]>d[j]+sqrtl(mo(x[i]-x[j]-L))-mid*(p[i])){
					d[i]=d[j]+sqrtl(mo(x[i]-x[j]-L))-mid*(p[i]);
					pre[i]=j;
				}
			}
		}
		//cout<<l<<" "<<r<<" "<<d[n]<<endl;
		if(d[n]<=0){
			r=mid;
		}else{
			l=mid;
		}
	}
	vector<int> vec;
	int x=n;
	while(x!=0){
		vec.pb(x);
		x=pre[x];
	}
	int si=vec.size();
	for(int i=si-1;i>=0;i--){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
	return 0;
}

