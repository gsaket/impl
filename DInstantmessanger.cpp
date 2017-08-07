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

int x[50000];
unordered_set<int> S[50000];
unordered_set<int> H[50000];
int O[50000];

int sq;

void add_edge(int u, int v){
	S[u].insert(v);
	int w;
	if(S[u]== sq){
		// becomes heavy
		unordered_set<int> :: iterator it;
		for(it=S[u].begin();it!=S[u].end();it++){
			w=(*it);
			O[w]-=x[w];
			
		}
	}
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	repp(i,1,n+1){
		x[i]=0;
		as[i]=0;
	}
	sq=sqrt(m);
	int o;
	scanf("%d",&o);
	int a,b;
	rep(i,o){
		cin>>a;
		x[a]=1;
	}
	rep(i,m){
		cin>>a>>b;
		S[a].insert(b);
		//add_edge(a,b);
		//add_edge(b,a);
	}
	while(q--){
		
	}
	return 0;
}

