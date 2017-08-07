//nice greedy problem, good observation that if atleast one negative, then ans>=1
//http://codeforces.com/problemset/problem/747/D
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
vector<int > v;
vector<int > v1;
int a[200005];
int main(){
	int n,k;
	cin>>n>>k;
	int neg=0;
	repp(i,1,n+1) {
		cin>>a[i];
		if(a[i]<0)neg++;
	}
	//cout<<neg<<endl;
	//cout<<k<<endl;
	if(neg==0){
		cout<<"0"<<endl;
		return 0;
	}
	if(neg>k) {
		cout<<"-1"<<endl;
		return 0;
	}
	k-=neg;
	//cout<<k<<endl;
	int net=0;
	int l=0;
	int flag=1;
	repp(i,1,n+1) {
		if(a[i] < 0){
			if(flag==1){
				//if(l>0)v1.pb(l);
				flag=0;
				net++;
				l=0;
				continue;
			}
			if(l>0){
				v.pb(l);
				net+=2;
			}
			l=0;
		}else{
			l++;
		}
	}
	sort(v.begin(),v.end());
	rep(i,v.size()) {
		if(k>=v[i]){
			net-=2;
			k-=v[i];
		}else{
			break;
		}
	}
	if(l>0){
		v1.pb(l);
		net++;
	}
	//sort(v1.begin(),v1.endl());
	rep(i,v1.size()) {
		if(k>=v1[i]){
			k-=v1[i];
			net--;
		}else{
			break;
		}
	}

	cout<<net<<endl;
	return 0;
}

