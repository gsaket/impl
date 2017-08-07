// Direct use of map and set
// http://codeforces.com/problemset/problem/69/E
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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

map<int,int> mp_;
set<int> se;
int a[100005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	rep(i,n){
		cin>>a[i];
	}
	rep(i,k){
		mp_[a[i]]++;
	}
	rep(i,k){
		if(mp_[a[i]] == 1){
			se.insert(-a[i]);
		}
	}
	a[n]=0;
	set<int>::iterator it;
	rep(i,n-k+1){
		if(se.size()==0){
			cout<<"Nothing"<<endl;
		}else{
			//it=se.begin();
			//while(it != se.end()){
				//cout<<(-(*it))<<" ";
				//it++;
			//}cout<<endl;
			it=se.begin();
			cout<<(-(*it))<<endl;
		}
		if(mp_[a[i]]==1){
			se.erase(-a[i]);
		}
		if(mp_[a[i]]==2){
			se.insert(-a[i]);
		}
		mp_[a[i]]--;
		if(mp_[a[i+k]] == 0){
			se.insert(-a[i+k]);
		}
		if(mp_[a[i+k]] == 1){
			se.erase(-a[i+k]);
		}
		mp_[a[i+k]]++;
	}
	return 0;
}

