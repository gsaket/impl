// greedy and brute-type, passed with pruning. tags: greedy, pruning
// http://codeforces.com/problemset/problem/346/C
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

//vector<int>vec;
//map<int,int> ma;
int A[100005];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n;
	//cin>>n;
	scanf("%d",&n);
	rep(i,n){
		//int x;
		//cin>>x;
		scanf("%d",&A[i]);
		//if(ma[x] == 0){
			//ma[x]=1;
			//vec.pb(x);
		//}
	}
	int a,b;
	//cin>>a>>b;
	scanf("%d%d",&a,&b);
	//sort(vec.begin(),vec.end());
	sort(A,A+n);
	n=unique(A,A+n)-A;
	int xy;
	int cnt=0;
	int mx=n-1;
	int mi=a-1;
	while(a!=b&&a>0){
		//cout<<a<<" "<<b<<endl;
		mi=a-1;
		rep(i,mx+1){
			if((a-(a%A[i])) >= b){
				//cout<<(a-(a%A[i]))<<" . "<<b<<endl;
				mi=min(mi,a-(a%A[i]));
			}
			//cout<<mi<<" "<<a<<" "<<(a-(a%A[i]))<<" "<<A[i]<<endl;
		}
		cnt++;
		a=mi;
		while(mx>=0 && a-a%A[mx] < b){
			//vec.pop_back();
			mx--;
		}
	}
	printf("%d\n",cnt);
	return 0;
}

