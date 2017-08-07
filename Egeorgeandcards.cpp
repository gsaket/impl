// Nice problem to practice, tags: set, BIT
// http://codeforces.com/problemset/problem/387/E
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

int n,k;
ll T[1000005];

ll SET(int i, ll va){
	while(i<=n){
		T[i]+=va;
		i += (i&(-i));
	}
}

ll GET(int i){
	ll s=0;
	while(i>0){
		s+=T[i];
		i-= (i&(-i));
	}
	return s;
}

int a[1000006];
int ind[1000006];
int b[1000006];
int fu[1000006];

vector<int> vec;
set<pair<int,int> > se;
vector<int> vec1;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cin>>n>>k;
	ll ans=0;
	scanf("%d%d",&n,&k);
	repp(i,1,n+1){
		SET(i,1LL);
		scanf("%d",&a[i]);
		ind[a[i]]=i;
		fu[i]=1;
	}
	rep(i,k){
		int x;
		scanf("%d",&x);
		fu[ind[x]]=0;
	}
	repp(i,1,n+1){
		if(fu[i]==1){
			vec.pb(a[i]);
		}else{
			vec1.pb(a[i]);
		}
	}
	sort(vec.begin(),vec.end());
	sort(vec1.begin(),vec1.end());
	int pt=0;
	int si=vec1.size();
	se.insert(mp(0,-1));
	se.insert(mp(n+1,-1));
	set<pii> :: iterator it;
	rep(i,vec.size()){
		//cout<<ind[vec[i]]<<" "<<vec[i]<<endl;
		while(pt<si && vec1[pt]< vec[i]){
			se.insert(mp(ind[vec1[pt]],vec1[pt]));
			pt++;
		}
		it=se.lower_bound(mp(ind[vec[i]],vec[i]));
		int up=it->X;
		up--;
		it--;
		int low=it->X;
		low++;
		ans+=GET(up);
		if(low!=0){
			ans-=GET(low-1);
		}
		SET(ind[vec[i]],-1);
		//cout<<ans<<" "<<low<<" "<<up<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

