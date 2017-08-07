//easy greedy observation and a little implementation problem.
//http://codeforces.com/problemset/problem/746/D
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
vector<char > s;
int main(){
	int n,k,a,b;
	cin>>n>>k>>a>>b;
	int last=0;
	char lc='A';
	rep(i,n){
		//cout<<a<<" "<<b<<" "<<last<<" "<<lc<<endl;
		if(a>b){
			//cout<<"hello "<<a<<" "<<b<<endl;
			if(lc!='G'){
				lc='G';
				s.pb('G');
				a--;
				last=1;
			}else if(last<k){
				s.pb('G');
				a--;
				last++;
				lc='G';
			}else{
				if(b==0){
					//cout<<"first"<<endl;
					//rep(j,s.size()){
						//cout<<s[j];
					//}cout<<endl;
					cout<<"NO"<<endl;
					return 0;;
				}
				last=1;
				lc='B';
				s.pb('B');
				b--;
			}
		}else if(b>a) {
			if(lc!='B'){
				lc='B';
				last=1;
				b--;
				s.pb('B');
			}else if(last < k ){
				last++;
				b--;
				lc='B';
				s.pb('B');
			}else {
				if(a==0){
					//cout<<"second"<<endl;
					//rep(j,s.size()){
						//cout<<s[j];
					//}cout<<endl;
					cout<<"NO"<<endl;
					return 0;
				}
				lc='G';
				s.pb('G');
				a--;
				last=1;
			}
		}else {
			if(lc != 'G' ) {
				lc='G';
				s.pb('G');
				last=1;
				a--;
			}else {
				lc='B';
				s.pb('B');
				last=1;
				b--;
			}
		}
	}
	rep(i,s.size()){
		cout<<s[i];
	}cout<<endl;
	return 0;
}

