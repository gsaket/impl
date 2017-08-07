// First quest in many days that I did on my own, related to Z-Algorithm, tags: string, z-function
// http://codeforces.com/problemset/problem/149/E
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

int z[100005];
int z_[100005];
int zr_[100005];
int zr[100005];
int pref[100005];
int suff[100005];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	string s;
	cin>>s;
	int n=(int)s.size();
	int q;
	cin>>q;
	int ans=0;
	int cnt=0;
	while(q--){
		cnt++;
		rep(i,n){
			z[i]=0;
			zr[i]=0;
		}
		int l=-1;
		int r=-1;
		string t;
		cin>>t;
		int m=(int)t.size();
		rep(i,m){
			z_[i]=0;
			zr_[i]=0;
		}
		if(m == 1)continue;
		if(m>n)continue;
		repp(i,1,m){
			if(i>r){
				l=r=i;
				while(r<m&&t[r-l] == t[r]){
					r++;
				}
				z_[i]=r-l;
				r--;
			}else{
				int k=i-l;
				if(z_[k] < r-i+1){
					z_[i]=z_[k];
				}else{
					l=i;
					while(r<m&&t[r-l] == t[r]){
						r++;
					}
					z_[i]=r-l;
					r--;
				}
			}
		}
		l=r=-1;
		rep(i,n){
			if(i>r){
				l=r=i;
				while(r<n && r-l<m && t[r-l] == s[r]){
					r++;
				}
				z[i]=r-l;
				r--;
			}else{
				int k=i-l;
				if(z_[k] < r-i+1){
					z[i]=z_[k];
				}else{
					l=i;
					while(r<n &&r-l<m && t[r-l]==s[r]){
						r++;
					}
					z[i]=r-l;
					r--;
				}
			}
		}
		l=r=m+5;
		for(int i=m-2;i>=0;i--){
			if(i<l){
				l=r=i;
				while(l>=0&&t[m-1-(r-l)] == t[l]){
					l--;
				}
				zr_[i]=r-l;
				l++;
			}else{
				int k=r-i;
				if(zr_[m-1-(r-i)] > i-l+1){
					zr_[i]=zr_[m-1-(r-i)];
				}else{
					r=i;
					while(l>=0&&t[m-1-(r-l)] == t[l]){
						l--;
					}
					zr_[i]=r-l;
					l++;
				}
			}
		}
		l=r=n+5;
		for(int i=n-1;i>=0;i--){
			if(i<l){
				l=r=i;
				while(l>=0 && m-1>=(r-l) && t[m-1-(r-l)] == s[l] ){
					l--;
				}
				zr[i]=r-l;
				l++;
			}else{
				int k=r-i;
				if(zr_[m-1-(k)] < i-l+1){
					zr_[i]=zr_[m-1-k];
				}else{
					r=i;
					while(l>=0 && m-1>=(r-l) && t[m-1-(r-l)] == s[l]){
						l--;
					}
					zr[i]=r-l;
					l++;
				}
			}
		}
		rep(i,m+1){
			pref[i]=n+5;
			suff[i]=-1;
		}
		int mx=-1;
		rep(i,n){
			//if(cnt==4){
				//cout<<i<<" "<<mx<<endl;
			//}
			if(z[i]>mx){
				repp(j,mx+1,z[i]+1){
					pref[j]=i;
					//if(cnt==4)cout<<j<<"->"<<i<<endl;
				}
				mx=z[i];
			}
			//if(cnt==4)cout<<i<<" "<<mx<<endl;
		}
		mx=-1;
		for(int i=n-1;i>=0;i--){
			if(zr[i]>mx){
				repp(j,mx+1,zr[i]+1){
					suff[j]=i;
				}
				mx=zr[i];
			}
		}
		rep(i,m+1){
			if(suff[m-i]-pref[i]>=m-1){
				ans++;
				//cout<<"YES: "<<cnt<<endl;
				//cout<<pref[i]<<" "<<suff[m-i]<<endl;
				break;
			}
		}
		/*
		 *cout<<cnt<<": "<<endl;
		 *rep(i,n){
		 *    //cout<<z[i]<<" ";
		 *    rep(j,z[i]){
		 *        if(s[i+j]!=t[j]){
		 *            cout<<i<<" "<<j<<", z-"<<z[i]<<endl;
		 *            break;
		 *        }
		 *    }
		 *}
		 *rep(i,n){
		 *    cout<<zr[i]<<" ";
		 *    int ab=0;
		 *    rep(j,zr[i]){
		 *        if(s[i-j] != t[m-1-j]){
		 *            cout<<i<<" "<<j<<", zr-"<<zr[i]<<endl;
		 *        }
		 *    }
		 *}
		 *cout<<endl;
		 *cout<<endl;
		 *rep(i,m){
		 *    cout<<zr_[i]<<" ";
		 *}
		 *cout<<endl;
		 */
	}
	cout<<ans<<endl;
	return 0;
}

