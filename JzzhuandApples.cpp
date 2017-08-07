// Maximum pairs with gcd > 1; tags: gcd sieve
// http://codeforces.com/problemset/problem/449/C
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

int mk[200005];
int net[200005];
vector<vector<int> > vec;
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n;
	cin>>n;
	vec.resize(n+5);
	rep(i,n+1){
		mk[i]=1;
		net[i]=1;
	}
	repp(i,2,n+1){
		if(mk[i]==1){
			for(int j=2;j*i<=n;j++){
				mk[i*j]=0;
			}
		}
	}
	int ans=0;
	repp(i,3,n+1){
		if(mk[i]==1){
			int tmp=0;
			for(int j=1;j*i<=n;j++){
				if(net[i*j]==0)continue;
				if(j!=2){
					//cout<<i<<" "<<i*j<<endl;
					vec[i].pb(i*j);
				}
				tmp++;
				net[i*j]=0;
			}
			if(tmp%2==1){
				net[2*i]=1;
				tmp--;
			}else{
				vec[i].pb(i*2);
			}
			ans+=tmp/2;
		}
	}
	int tmp=0;
	repp(i,2,n+1){
		if(i%2==0&&net[i]==1){
			tmp++;
			vec[2].pb(i);
		}
	}
	ans+=tmp/2;
	cout<<ans<<endl;
	rep(i,n+1){
		if((int)(vec[i].size())<2)continue;
		rep(j,vec[i].size()-1){
			cout<<vec[i][j]<<" "<<vec[i][j+1]<<endl;
			j++;
		}
	}
	return 0;
}

