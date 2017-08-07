// In case of long long see that everything is long long
// Problem I faced here is I multiplied with int and it got type casted
// http://codeforces.com/problemset/problem/83/B
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

ll a[100005];
int present[100005];
vector<pair<ll, int> > v;
int main(){
	ll n,k;
	cin>>n>>k;
	rep(i,n) {
		present[i]=1;
	}
	//rep(i,n){
		//cout<<present[i]<<" ";
	//}cout<<endl;
	ll sum = 0;
	rep(i,n) {
		cin>>a[i];
		sum+=a[i];
		v.pb(mp(a[i],i));
	}
	if( sum == k ) {
		cout<<endl;
		return 0;
	}
	if(sum < k) {
		cout<<"-1"<<endl;
		return 0;
	}
	sort(all(v));
	ll cur=0;
	ll lef=n;
	ll val,pos;
	ll preval=0;
	while(lef>0){
		//cout<<lef<<" "<<k<<endl;
		val=v[cur].X;
		pos=v[cur].Y;
		if((val-preval)*lef<=k){
			k-=(val-preval)*lef;
			preval=val;
			lef--;
			cur++;
			//cout<<"absent "<<pos<<endl;
			present[pos]=0;
		}else{
			break;
		}
	}
	if(lef==0 && k==0){
		cout<<endl;
		return 0;
	}
	if(lef==0){
		cout<<"-1"<<endl;
		return 0;
	}
	ll tmp=(k/lef);
	k-=tmp*lef;
	preval+=tmp;
	//cout<<preval<<" "<<k<<endl;
	rep(i,n){
		//preval last
		a[i]-=preval;
		if(a[i]<=0){
			present[i]=0;
		}
	}
	//rep(i,n)cout<<"aa "<<i<<" "<<present[i]<<endl;
	rep(i,n){
		if(k <= 0)break;
		if(present[i]==1){
			if(k<=0)break;
			a[i]--;
			k--;
			present[i]=2;
			//cout<<i<<endl;
			if(a[i]<=0)present[i]=0;
			if(k<=0)break;
		}
	}
	//rep(i,n){
		//cout<<present[i]<<" ";
	//}cout<<endl;
	rep(i,n) {
		if(present[i] == 1) cout<<(i+1)<<" ";
	}
	rep(i,n) {
		if(present[i] == 2) cout<<(i+1)<<" ";
	}cout<<endl;

	return 0;
}

