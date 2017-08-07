// Too many precision errors!!, tags: precision, expo, optimisation
// http://codeforces.com/contest/837/problem/F
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
const ll INF = 1e18+5;
#define E5 100005

#define ld long double
//#define double long double
const ld EPS=1e-12;

int flag=0;
ll a[200005];
ll ans=(ll)(1e18+2);
ll mid=0;
int pt=1;
ll n,K;
ll mat[20][20];
ll si;
ll tmat[20][20];
ll mat_[20][20];
ll tmat_[20][20];

void print(){
	cout<<"///////////////////////"<<endl;
	cout<<"mat: "<<mid<<endl;
	rep(i,si){
		rep(j,si){
			cout<<mat[i][j]<<" ";
		}cout<<endl;
	}
	cout<<"///////////////////////"<<endl;
}



void ex(ll po){
	if( po == 1 ){
		return;
	}
	ll hl=(po/2LL);
	ex(hl);
	rep(i,si){
		rep(j,si){
			tmat[i][j]=0;
		}
	}
	rep(i,si){
		rep(j,si){
			rep(k,si){
				//if(INF/mat[k][j] <= mat[i][k])flag=1;
				if(tmat[i][j] < K)tmat[i][j]+=mat[i][k]*mat[k][j];
				if(mat[i][k]*mat[k][j]>=K)tmat[i][j]=K;
				if(tmat[i][j]>K)tmat[i][j]=K;
			}
		}
	}
	if(po%2 ==1){
		rep(i,si){
			rep(j,si){
				tmat_[i][j]=0;
			}
		}
		rep(i,si){
			rep(j,si){
				rep(k,si){
					//if(i == 0 && j == 5){
						//cout<<tmat_[i][j]<<"+="<<tmat[i][k]<<" "<<mat_[k][j]<<endl;
					//}
					//if(INF/mat_[k][j] <= tmat[i][k])flag=1;
					if(tmat_[i][j] < K)tmat_[i][j]+=tmat[i][k]*mat_[k][j];
					if(tmat[i][k]*mat_[k][j]>=K)tmat_[i][j]=K;
					if(tmat_[i][j]>K)tmat_[i][j]=K;
					//if(i == 0 && j == 5){
						//cout<<tmat_[i][j]<<" "<<tmat[i][k]<<" "<<mat_[k][j]<<endl;
					//}
				}
			}
		}
		//print();
		rep(i,si){
			rep(j,si){
				mat[i][j]=min(K,tmat_[i][j]);
			}
		}
		//cout<<"power: "<<po<<endl;
		//print();
		return;
	}
	rep(i,si){
		rep(j,si){
			mat[i][j]=min(K,tmat[i][j]);
		}
	}
	//cout<<"power: "<<po<<endl;
	//print();
}
void solve(){
	si=n-pt+1;
	rep(i,si){
		rep(j,si){
			if(i<=j){
				mat_[i][j]=mat[i][j]=1LL;
			}else{
				mat_[i][j]=mat[i][j]=0;
			}
		}
	}
	flag=0;
	ex(mid);
	if(flag == 1){
		ans=min(ans,mid);
		return;
	}
	//print();
	ll tmp=0;
	rep(j,si){
		if(mat[j][si-1]>=K){
			ans=min(ans,mid);
			flag=1;
			return;
		}
		if(mat[j][si-1]*a[j+pt]>=K){
			ans=min(ans,mid);
			flag=1;
			return;
		}
		if(tmp>=K-(mat[j][si-1]*a[j+pt])){
			ans=min(ans,mid);
			flag=1;
			return;
		}
		//ll tep=a[j+pt]*mat[j][si-1];
		if(a[j+pt] != 0 && (INF/a[j+pt] ) <= mat[j][si-1]){
			ans=min(ans,mid);
			flag=1;
			return;
		}
		tmp+=(mat[j][si-1]*a[j+pt]);
		if(tmp>=K){
			ans=min(ans,mid);
			flag=1;
			return;
		}
	}
	//cout<<"tmp: "<<tmp<<endl;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	cin>>n>>K;
	repp(i,1,n+1){
		cin>>a[i];
		if(a[i]>=K)flag=1;
	}
	if(flag == 1){
		cout<<"0"<<endl;
		return 0;
	}
	while(a[pt] == 0 && pt<=n){
		pt++;
	}
	if( n-pt+1>=10 ){
		ll tans=0;
		ll fl=0;
		while(fl ==0){
			tans++;
			repp(i,pt+1,n+1){
				if(a[i]>=a[i-1] && K<=a[i-1]*2LL){
					fl=1;
					break;
				}
				if(a[i]+a[i-1]>=K){
					fl=1;
					break;
				}
				a[i]+=a[i-1];
			}
		}
		cout<<tans<<endl;
		return 0;
	}
	if(n-pt+1 == 2){
		ll l=1;
		ll r=1e18+5;
		K-=a[pt+1];
		ll an=r;
		while(l<=r){
			//cout<<l<<" "<<r<<endl;
			if(l == r){
				if(K<=l*a[pt] || l*a[pt]<0){
					an=min(an,l);
				}
				break;
			}
			ll mid=(l+r)/2LL;
			if(K<=mid*a[pt] || mid*a[pt]<0){
				an=min(an,mid);
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		cout<<an<<endl;
		return 0;
	}
	ll l=1;
	ll r=1e18+1;
	while(l<=r){
		//cout<<l<<" "<<r<<endl;
		if( l == r ){
			mid=l;
			flag=0;
			solve();
			break;
		}
		flag=0;
		mid=(l+r)/2LL;
		solve();
		if(flag == 1){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	cout<<ans<<endl;
	/*
	 *si=n-pt+1;
	 *rep(i,si){
	 *    rep(j,si){
	 *        if(i<=j){
	 *            mat[i][j]=mat_[i][j]=1;
	 *        }else{
	 *            mat[i][j]=mat_[i][j]=0;
	 *        }
	 *    }
	 *}
	 */
	//ex(909498);
	//ex(454749);
	//ex(454748);
	//ex(227374);
	//ex(113687);
	/*
	 *ex(28421);
	 *ex(7105);
	 *print();
	 *ll temp=0;
	 *rep(j,si){
	 *    temp+=mat[j][si-1]*a[j+1];
	 *    cout<<temp<<" "<<mat[j][si-1]<<" "<<a[j+1]<<" "<<mat[j][si-1]*a[j+1]<<endl;
	 *}
	 *cout<<temp<<endl;
	 *if(temp>=K)cout<<"YES"<<endl;
	 *else cout<<"NO"<<endl;
	 */
	return 0;
}

