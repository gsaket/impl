// TLE cout(even with sync) 1e6!! tags: cbs, greedy, stack
// http://codeforces.com/problemset/problem/286/C
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
int p[1000006];
int q[1000006];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n,x;
	//cin>>n;
	scanf("%d",&n);
	rep(i,n){
		q[i]=0;
	}
	rep(i,n){
		//cin>>p[i];
		scanf("%d",&p[i]);
	}
	int t;
	//cin>>t;
	scanf("%d",&t);
	rep(i,t){
		//cin>>x;
		scanf("%d",&x);
		x--;
		q[x]=1;
	}
	stack <pii > st;
	pii tp;
	for(int i=n-1;i>=0;i--){
		if(st.empty()){
			q[i]=1;
			st.push(mp(p[i],i));
			continue;
		}
		tp=st.top();
		if(tp.X == p[i]){
			if(q[i]==1){
				st.push(mp(p[i],i));
			}else{
				st.pop();
			}
		}else{
			q[i]=1;
			st.push(mp(p[i],i));
		}
	}
	//cout<<st.size()<<endl;
	if(!st.empty()){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	rep(i,n){
		if(q[i]==0){
			//cout<<p[i]<<" ";
			printf("%d ",p[i]);
		}else{
			//cout<<-p[i]<<" ";
			printf("-%d ",p[i]);
		}
	}
	printf("\n");
	//cout<<endl;
	return 0;
}

