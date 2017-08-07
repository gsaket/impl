// Inversions, and reverting subarrays
// nice property on inversions while reverting subarrays
// http://codeforces.com/problemset/problem/414/C
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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

int buf[1<<21];
int a[1<<21];
int a_[1<<21];
ll inv[21];
ll rinv[21];
void count_inv(int b, int po){
	if(po==0)return;
	int bb=b+(1<<(po-1));
	int len=1<<(po-1);
	count_inv(b,po-1);
	count_inv(bb,po-1);
	//cout<<b<<" hello "<<po<<endl;
	//cout<<"hello there"<<endl;
	//rep(i,2*len){
		//cout<<a[b+i]<<" ";
	//}cout<<" hello where?"<<endl;
	int i=0;
	int j=0;
	int k=0;
	ll cnt=0;
	while(i<len&&j<len){
		//cout<<(i)<<" "<<a[b+i]<<" "<<b<<" "<<a[bb+j]<<endl;
		if(a[bb+j]<a[b+i]){
			buf[k]=a[bb+j];
			k++;
			j++;
			cnt+=(ll)(len-i);
		}else{
			buf[k]=a[b+i];
			i++;
			k++;
		}
	}
	while(i<len){
		//cout<<i<<" one "<<a[b+i]<<endl;
		buf[k]=a[b+i];
		i++;
		k++;
		//cnt+=(ll)(len);
	}
	while(j<len){
		//cout<<j<<" two "<<a[bb+i]<<endl;
		buf[k]=a[bb+j];
		j++;
		k++;
	}
	inv[po]+=cnt;
	rep(i,2*len){
		a[b+i]=buf[i];
	}
}
void count_rinv(int b, int po){
	if(po==0)return;
	int bb=b+(1<<(po-1));
	int len=1<<(po-1);
	count_rinv(b,po-1);
	count_rinv(bb,po-1);
	int i=0;
	int j=0;
	int k=0;
	ll cnt=0;
	while(i<len&&j<len){
		if(a_[bb+j]<a_[b+i]){
			buf[k]=a_[bb+j];
			k++;
			j++;
			cnt+=(ll)(len-i);
		}else{
			buf[k]=a_[b+i];
			i++;
			k++;
		}
	}
	while(i<len){
		buf[k]=a_[b+i];
		i++;
		k++;
	}
	while(j<len){
		buf[k]=a_[bb+j];
		j++;
		k++;
		//cnt+=(ll)(len);
	}
	rinv[po]+=cnt;
	rep(i,2*len){
		a_[b+i]=buf[i];
	}
}
int rev[21];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	rep(i,1<<n){
		cin>>a[i];
		a_[(1<<n)-i-1]=a[i];
	}
	rep(i,n+1){
		inv[i]=rinv[i]=0;
	}
	count_inv(0,n);
	count_rinv(0,n);
	rep(i,n+1){
		rev[i]=0;
	}
	int m;
	cin>>m;
	int x;
	//rep(i,n+1){
		//cout<<inv[i]<<" ";
	//}cout<<endl;
	//rep(i,n+1){
		//cout<<rinv[i]<<" ";
	//}cout<<endl;
	rep(i,m){
		cin>>x;
		rep(i,x+1){
			rev[i]^=1;
		}
		//rep(i,n+1){
			//cout<<rev[i]<<" "<<inv[i]<<" "<<rinv[i]<<endl;
		//}
		ll ans=0;
		rep(j,n+1){
			if(rev[j]==0){
				ans+=inv[j];
			}else{
				ans+=rinv[j];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

