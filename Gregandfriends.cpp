// My first problem after a long time, dp, nice state transition using bfs!!
// http://codeforces.com/problemset/problem/295/C
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
ll mo=(ll)(1e9+7);
ll dp[55][55][2];
ll add(ll p,ll q){
	ll temp=p+q;
	temp%=mo;
	return temp;
}

ll mul(ll p,ll q){
	ll temp=p*q;
	temp%=mo;
	return temp;
}
ll ways[55][55][2];
ll ncr[55][55];
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	rep(i,55){
		rep(j,55){
			ncr[i][j]=0LL;
		}
	}
	ncr[0][0]=1LL;
	ncr[1][0]=1LL;
	ncr[1][1]=1LL;
	repp(i,2,55){
		ncr[i][0]=1LL;
		repp(j,1,i+1){
			ncr[i][j]=add(ncr[i-1][j],ncr[i-1][j-1]);
		}
	}
	int n,K;
	cin>>n>>K;
	int a=0,b=0;
	rep(i,n){
		int x;
		cin>>x;
		if(x==50){
			a++;
		}else{
			b++;
		}
	}
	//cout<<a<<" "<<b<<endl;
	rep(i,55){
		rep(j,55){
			rep(k,2){
				dp[i][j][k]=INF;
			}
		}
	}
	int x,y,z;
	queue<pair<pair<int, int> , int> > qu;
	pair<pair<int,int> , int> tmp;
	qu.push(mp(mp(a,b),0));
	ways[a][b][0]=1LL;
	while(!qu.empty()){
		tmp=qu.front();
		qu.pop();
		x=tmp.X.X;
		y=tmp.X.Y;
		z=tmp.Y;
		//cout<<x<<" "<<y<<" "<<z<<endl;
		dp[a][b][0]=0LL;
		if(z==0||z==1){
			for(int i=0;i<=x;i++){
				for(int j=0;j<=y;j++){
					if(i+j==0){
						continue;
					}
					int tp=(i)*50+(j)*100;
					//cout<<i<<" ds"<<j<<endl;
					//cout<<tp<<endl;
					if(tp>K)break;
					if(dp[a-x+i][b-y+j][z^1] > 1LL+dp[x][y][z]){
						dp[a-x+i][b-y+j][z^1]=1LL+dp[x][y][z];
						ways[a-x+i][b-y+j][z^1]=mul(ways[x][y][z],mul(ncr[x][i],ncr[y][j]));
						qu.push(mp(mp(a-x+i,b-y+j),z^1));
					}else if(dp[a-x+i][b-y+j][z^1] == 1LL+dp[x][y][z]){
						ways[a-x+i][b-y+j][z^1]=add(ways[a-x+i][b-y+j][z^1],mul(ways[x][y][z],mul(ncr[x][i],ncr[y][j])));
					}
				}
			}
		}
	}
	if(dp[a][b][1] == INF){
		cout<<"-1"<<endl;
		cout<<"0"<<endl;
	}else{
		cout<<dp[a][b][1]<<endl;
		cout<<ways[a][b][1]<<endl;
	}
	return 0;
}

