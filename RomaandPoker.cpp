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
int n,k;
string s;

string get(char a,char b){
	string t="";
	stack<int> st;
	rep(i,k-1){
		st.push(1);
	}
	rep(i,s.size()){
		if(st.size()>2*k){
			t="";
			return t;
		}
		if(s[i]=='D'){
			t=t+'D';
			continue;
		}
		if(s[i]==b && st.empty()){
			t="";
			return t;
		}
		if(s[i]==b){
			st.pop();
			t=t+s[i];
			continue;
		}
		if(s[i]==a){
			t= t+s[i];
			st.push(1);
		}
		if(s[i]=='?'){
			if(st.empty()){
				st.push(1);
				t=t+a;
			}else{
				//st.pop();
				t=t+'D';
			}
		}
	}
	//if(st.size()!=0){
		//t="";
		//return t;
	//}
	return t;
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	cin>>n>>k;
	cin>>s;
	string net=get('L','W');
	string net_=get('W','L');
	if(net == net_ && net ==""){
		cout<<"NO"<<endl;
	}else{
		if(net != ""){
			cout<<net<<endl;
		}else{
			cout<<net_<<endl;
		}
	}
	return 0;
}

