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

vector<string> st;
int k;
bool solve(int x){
	//cout<<x<<endl;
	int n=st.size();
	int tep=0;
	int net=0;
	int i=0;
	while(i<n){
		//if(x==9)cout<<i<<" ";
		tep=0;
		while(i<n && tep <= x){
			if(tep+st[i].size()<=x){
				tep+=st[i].size();
				i++;
			}else{
				break;
			}
		}
		//if(x==9)cout<<i<<endl;
		net++;
	}
	if(net<=k)return true;
	else return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s,tp;
	getline(cin, s);
	k=0;
	rep(i,s.size()){
		k*=10;
		k+=(int)(s[i]-'0');
	}
	//cout<<k<<endl;
	getline(cin, s);
	//cout<<s<<endl;
	tp="";
	for(int i=0;i<(int)(s.size());i++){
		//cout<<i<<endl;
		tp+=s[i];
		if(s[i] == '-'|| s[i]==' '){
			st.pb(tp);
			tp="";
		}
		if(i == s.size()-1){
			st.pb(tp);
			tp="";
		}
	}
	//}
	//while(cin>>tp){
	//cout<<"hello"<<endl;
	//cin>>s;
	//cout<<tp<<endl;
	//}
	int ans=(int)(1e9);
	int l=1;
	int r=(int)(1e6+5);
	rep(i,st.size()){
		l=max(l,(int)(st[i].size()));
	}
	//cout<<l<<endl;
	while(l<=r){
		//cout<<l<<" "<<r<<endl;
		if(l == r){
			int mid=l;
			if(solve(mid)){
				ans = min(ans,mid);
			}
			break;
		}
		int mid=(l+r)/2;
		if(solve(mid)){
			ans=min(ans,mid);
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	if(ans==(int)(1e9)){
		cout<<"IMPOSSIBLE"<<endl;
	}else{
		cout<<ans<<endl;
	}
	return 0;
}

