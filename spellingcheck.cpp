//Didn't formulate dp properly and missed edge cases
//http://codeforces.com/problemset/problem/39/J
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

int dpl[1000005];
int dpr[1000005];
int net[1000005];

int main(){
	string p,q;
	cin>>p;
	cin>>q;
	fill(dpl,0);
	fill(dpr,0);
	if(p[0] == q[0]) {
		dpl[0]=1;
	}
	repp(i,1,q.size()) {
		if(p[i] == q[i])dpl[i]|=dpl[i-1];
	}
	int n=q.size();
	if(q[n-1] == p[n])dpr[n]=1;
	for(int i=n-1;i>=1;i--) {
		if(q[i-1] == p[i]) {
			dpr[i]|=dpr[i+1];
		}
	}
	//rep(i,n+1){
		//cout<<dpl[i]<<" ";
	//}cout<<endl;
	//rep(i,n+1){
		//cout<<dpr[i]<<" ";
	//}cout<<endl;
	int ans=0;
	for(int i=1;i<=n-1;i++){
		if(dpl[i-1]==1&&dpr[i+1]==1){
			net[i]=1;
			ans++;
		}else{
			net[i]=0;
		}
	}
	if(dpr[1]==1){
		net[0]=1;
		ans++;
	}
	if(dpl[n-1]==1){
		net[n]=1;
		ans++;
	}
	if(ans==0){
		cout<<"0"<<endl;
	}else{
		cout<<ans<<endl;
		rep(i,n+1){
			if(net[i]==1){
				cout<<(i+1)<<" ";
			}
		}cout<<endl;
	}
	return 0;
}

