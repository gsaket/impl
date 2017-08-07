// Easy implementation, but difficult to prove, tags: greedy, stack, cbs
// http://codeforces.com/problemset/problem/508/E
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

int l[605];
int r[605];
int pos[605];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n;
	cin>>n;
	string s="";
	stack <int> st;
	int flag=0;
	rep(i,n){
		cin>>l[i]>>r[i];
		pos[i]=(int)s.size();
		s+='(';
		st.push(i);
		while(flag==0 && !st.empty() && (int)s.size() - pos[st.top()] >=l[st.top()]){
			if(flag==0&&s.size()-pos[st.top()] > r[st.top()]){
				cout<<"IMPOSSIBLE"<<endl;
				flag=1;
			}
			s+=')';
			st.pop();
		}
	}
	if(flag == 1)return 0;
	if(!st.empty()){
		cout<<"IMPOSSIBLE"<<endl;
	}else{
		cout<<s<<endl;
	}
	return 0;
}

