// nice implementatioon problem using set. tags: counting, set, lower_bound
// http://codeforces.com/contest/400/problem/E
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

set<pll> se[20];

int a[100005][20];

ll ans;
ll tp[20];

ll cp(ll x){
	ll tmp=(x+2)*(x+1);
	tmp/=2LL;
	return tmp;
}
int fla=0;

void upd(int po,int j, int x){
	if(se[j].empty()){
		se[j].insert(mp(po,po));
		ans+=tp[j];
		return;
	}
	set<pll> :: iterator it;
	if(x==0){
		it=se[j].lower_bound(mp(po,po));
		if(fla){
			//if(it!=se[j].end()){
				//cout<<j<<":: "<<it->X<<" "<<it->Y<<endl;
			//}
		}
		if(it == se[j].end() || it->X > po){
			it--;
		}
		ll l=it->X;
		ll r=it->Y;
		ll r1=po-1;
		ll l1=po+1;
		ans-=tp[j]*cp(it->Y- it->X);
		se[j].erase(it);
		if(l<=r1){
			se[j].insert(mp(l,r1));
			ans+=tp[j]*cp(r1-l);
		}
		if(l1<=r){
			se[j].insert(mp(l1,r));
			ans+=tp[j]*cp(r-l1);
		}
	}else{
		it=se[j].lower_bound(mp(po,po));
		//if(po == 4 && j ==2){
			//cout<<it->X<<"--"<<it->Y<<endl;
		//}
		if(it == se[j].end()){
			it--;
			if(it->Y+1 == po){
				ll l=it->X;
				ll r=it->Y;
				ans-=tp[j]*cp(r-l);
				se[j].erase(it);
				r++;
				ans+=tp[j]*cp(r-l);
				se[j].insert(mp(l,r));
			}else{
				ans+=tp[j];
				se[j].insert(mp(po,po));
			}
		}else{
			ll l=it->X;
			ll r=it->Y;
			if(po+1 == l){
				int flag=1;
				if(it!=se[j].begin()){
					it--;
					if(it->Y+1 == po){
						flag=0;
						ll l1=it->X;
						ll r1=it->Y;
						ans-=tp[j]*cp(r1-l1);
						se[j].erase(it);
						ans-=tp[j]*cp(r-l);
						se[j].erase(mp(l,r));
						ans+=tp[j]*cp(r-l1);
						se[j].insert(mp(l1,r));
					}else{
						it++;
					}
				}
				if(flag == 1){
					se[j].erase(it);
					ans-=tp[j]*cp(r-l);
					l--;
					se[j].insert(mp(l,r));
					ans+=tp[j]*cp(r-l);
				}
			}else{
				if(it!=se[j].begin())it--;
				if(it->Y+1 == po){
					ll l=it->X;
					ll r=it->Y;
					ans-=tp[j]*cp(r-l);
					se[j].erase(it);
					r++;
					ans+=tp[j]*cp(r-l);
					se[j].insert(mp(l,r));
				}else{
					ans+=tp[j];
					se[j].insert(mp(po,po));
				}
			}
		}
	}
}


int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n,m;
	ans=0;
	cin>>n>>m;
	repp(i,1,n+1){
		int x;
		cin>>x;
		rep(j,20){
			a[i][j]=(x%2);
			x/=2;
		}
	}
	tp[0]=1LL;
	repp(i,1,20){
		tp[i]=tp[i-1]*2LL;
	}
	rep(j,20){
		ll l=0;
		ll r=0;
		repp(i,1,n+1){
			if(a[i][j]==1){
				if(l == 0){
					l=i;
					r=i;
				}else{
					r++;
				}
			}else{
				if(l!=0){
					se[j].insert(mp(l,r));
				}
				l=r=0;
			}
		}
		if(l!=0){
			se[j].insert(mp(l,r));
		}
	}
	set<pll> :: iterator it;
	rep(j,20){
		it=se[j].begin();
		while(it!=se[j].end()){
			//if(j<=4){
				//cout<<it->X<<":"<<it->Y<<" ";
			//}
			ans+=tp[j]*cp(it->Y - it->X);
			it++;
		}
		//if(j<=4)cout<<endl;
	}
	int cnt=1;
	while(m--){
		int x,po;
		cin>>po>>x;
		//if(po==8 && x ==2){
			/*
			 *rep(j,5){
			 *    it=se[j].begin();
			 *    while(it!=se[j].end()){
			 *        cout<<it->X<<":"<<it->Y<<" ";
			 *        it++;
			 *    }
			 *    cout<<endl;
			 *}
			 */
		//}
		rep(j,20){
			int bi=x%2;
			x/=2;
			if(bi!=a[po][j]){
				if(po == 6)fla=1;
				a[po][j]^=1;
				upd(po,j,bi);
			}
		}
		//cout<<cnt<<"//";
		//cnt++;
		cout<<ans<<endl;
	}
	return 0;
}

