// trie of suffix xor and best match with prefix xor
// Irritating problem of ll and int
// http://codeforces.com/problemset/problem/282/E
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
const ll int N = 1e6+10;
const ll INF = 1e18;

#define ld long double
//#define double long double
const ld EPS=1e-12;

struct node{
	node *child[2];
	node(){
		child[0]=NULL;
		child[1]=NULL;
	}
};

ll a[100005];
ll pr[100005];
ll tp;

vector<int> bi(ll x){
	vector<int> temp;
	ll tmp=tp;
	//cout<<tmp<<endl;
	while(tmp>0){
		ll qa=(x&tmp);
		//if(x == 5){
			//cout<<qa;
		//}
		if(qa>0LL){
			temp.pb(1);
		}else{
			temp.pb(0);
		}
		tmp=(tmp>>1LL);
	}
	//if(x==5)cout<<endl;
	//cout<<temp.size()<<endl;
	return temp;
}

node *root;

vector<int> b;

void add(ll x){
	node* tr=root;
	b=bi(x);
	//cout<<b.size()<<" hello"<<endl;
	rep(i,43){
		//cout<<b[i];
		if(b[i] == 0){
			if(tr->child[0] == NULL){
				tr->child[0]= new node;
				(tr->child[0])->child[0]=(tr->child[0])->child[1]=NULL;
			}
			tr = tr->child[0];
		}else{
			if(tr->child[1] == NULL){
				tr->child[1] = new node;
				(tr->child[1])->child[0]=(tr->child[1])->child[1]=NULL;
			}
			tr = tr->child[1];
		}
	}
	//cout<<endl;
}

ll get(ll x){
	b=bi(x);
	ll val=0;
	node *tr=root;
	ll an=0;
	ll tmp=tp;
	rep(i,43){
		if(b[i] == 0){
			if(tr == NULL)break;
			if(tr->child[1] != NULL){
				tr=tr->child[1];
				an+=tmp;
			}else{
				if(i!=40 && tr->child[0] == NULL){
					cout<<"WTF"<<endl;
					return an;
				}
				tr=tr->child[0];
			}
		}else{
			if(tr->child[0] != NULL){
				tr=tr->child[0];
				an+=tmp;
			}else{
				if(i != 40 && tr->child[1] == NULL){
					cout<<"WTF1"<<endl;
					return (ll)(i);
				}
				tr=tr->child[1];
			}
		}
		tmp=(tmp>>1LL);
	}
	return an;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n;
	cin>>n;
	ll ans=0;
	rep(i,n){
		cin>>a[i];
	}
	tp=(1LL<<42LL);
	//vector<int> it=bi(1000);
	pr[0]=a[0];
	repp(i,1,n){
		pr[i]=(pr[i-1]^a[i]);
	}
	root=new node;
	root->child[0]=root->child[1]=NULL;
	add(a[n-1]);
	for(int i=n-2;i>=0;i--){
		ans=max(ans,get(pr[i]));
		//cout<<i<<" "<<pr[i]<<" "<<get(pr[i])<<endl;
		if(i>0)add(pr[n-1]^pr[i-1]);
		//cout<<(pr[n-1]^pr[i-1])<<endl;
	}
	rep(i,n){
		ans=max(ans,pr[i]);
		ans=max(ans,(pr[n-1]^pr[i]));
	}
	cout<<ans<<endl;
	return 0;
}

