//usage of stack, maintain dynammic left and right bracket present :)
//http://codeforces.com/problemset/problem/670/E
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

stack <int > st;
int pos[500005];
int lef[500005];
int rit[500005];
int cut[500005];
int main(){
	int n,m,p;
	fill(pos,-1);
	fill(lef,-1);
	fill(rit,-1);
	fill(cut,0);
	string s,q;
	int x;
	cin>>n>>m>>p;
	cin>>s;
	rep(i,n) {
		if(s[i]=='(') {
			st.push(i);
		} else {
			x=st.top();
			st.pop();
			pos[x]=i;
			pos[i]=x;
		}
	}
	p--;
	cin>>q;
	rep(i,n){
		if(i>0) {
			lef[i] = i-1;
		}
		if(i < n-1) {
			rit[i] = i+1;
		}
	}
	int le,ri;
	rep(i,q.size()) {
		//cout<<"intitlal "<<p<<endl;
		if(q[i] == 'L') {
			p=lef[p];
		}
		if(q[i] == 'R') {
			p=rit[p];
		}
		if(q[i] == 'D') {
			le=p;
			ri=pos[p];
			if(le>ri) swap(le,ri);
			cut[le]=1;
			cut[ri]=1;
			le=lef[le];
			ri=rit[ri];
			//cout<<le<<" "<<ri<<endl;
			if(le < 0 && le != -1) {
				if(ri < n) {
					lef[ri]=-1;
				}
			} else {
				if(ri < n && ri != -1 ) {
					lef[ri]=le;
					rit[le]=ri;
				} else {
					rit[le]=-1;
				}
			}
			if(ri < n && cut[ri] == 0 && ri != -1) {
				p=ri;
			} else {
				p=le;
			}
			//cout<<"cut "<<(le+1)<<endl;
		}
		//cout<<"final "<<p<<endl;
	}
	//rep(i,n){
		//cout<<cut[i]<<endl;
	//}
	rep(i,n) {
		if(cut[i] == 1) {
			i=pos[i];
		} else {
			cout<<s[i];
		}
	}cout<<endl;
	return 0;
}

