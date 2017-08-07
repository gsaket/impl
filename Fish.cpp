// My first bitmask-dp which I solved without referring tutorial, tags: bitmask-dp, bfs
// http://codeforces.com/problemset/problem/16/E
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

ld a[20][20];
ld dp[300005];
int se[300005];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	ld n;
	cin>>n;
	rep(i,n){
		rep(j,n){
			cin>>a[i][j];
		}
	}
	int tmp=0;
	rep(i,n){
		tmp=(tmp<<1)+1;
	}
	//cout<<tmp<<endl;
	rep(i,tmp+1){
		dp[i]=0;
		se[i]=0;
	}
	dp[tmp]=1;
	int p=tmp;
	int q=0;
	queue<int> qu;
	qu.push(tmp);
	se[tmp]=1;
	while(!qu.empty()){
		p=qu.front();
		//cout<<p<<endl;
		qu.pop();
		q=0;
		rep(i,n){
			q=(1<<i);
			if((p&q) == q){
				//cout<<(p&q)<<" "<<p<<" "<<q<<endl;
				int r=0;
				ld net=0;
				ld num=0;
				rep(j,n){
					r=(1<<j);
					if(i==j){
						r=(r<<1);
						num++;
						continue;
					}
					if((p&r) == r){
						num++;
						//if(p == 5){
							//cout<<net<<" a  ad "<<a[j][i]<<endl;
						//}
						net+=(dp[p]*a[j][i]);
					}
				}
				//if(p==5)cout<<num<<endl;
				if(num>=2){
					net*=(2)/(num*(num-1));
				}
				if(se[p^q] == 0){
					se[p^q]=1;
					qu.push(p^q);
				}
				dp[p^q]+=net;
				//if(p==5&& (p^q)==1){
					//cout<<dp[5]<<endl;
					//cout<<(p^q)<<" "<<net<<endl;
				//}
				//if((p^q) == 1){
					//cout<<p<<" "<<q<<" "<<(p^q)<<" "<<net<<endl;
				//}
			}
		}
	}
	int P=0;
	rep(i,n){
		P=(1<<i);
		cout<<setprecision(16)<<dp[P]<<" ";
	}cout<<endl;
	//rep(i,32){
		//cout<<i<<" "<<dp[i]<<endl;
	//}
	return 0;
}

