//existence of solution val bounded by min and max
//http://codeforces.com/contest/663/problem/A
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
#define pb puch_back
#define all(s) s.begin(),s.end()
#define present(c,x) ((c).find(x) != (c).end())
const int mod  = 1e9+7;
const int N = 1e6+10;
const ll INF = 1e18;

#define ld long double
//#define double long double
const ld EPS=1e-12;

char c[115];
int abs(int x){
	if(x<0)x=-x;
	return x;
}

int main(){
	int n;
	int pos=0;
	int neg=0;
	cin>>c[0];
	pos++;
	int i=0;
	while(c[i]!='='){
		i++;
		cin>>c[i];
		if(c[i]=='-'){
			neg++;
		}
		if(c[i]=='+'){
			pos++;
		}
	}
	cin>>n;
	//for(int j=0;j<=i;j++){
		//cout<<c[j]<<" ";
	//}cout<<endl;
	int l=i;
	int mi=pos-n*neg;
	int ma=pos*n-neg;
	int s=0;
	if(n<=ma&&mi<=n){
		cout<<"Possible"<<endl;
		if(l==1){
			cout<<n<<" = "<<n<<endl;
			return 0;
		}
		int j;
		for(i=0;i<l-1;i+=2){
			int sign=1;
			if(i>0&&c[i-1]=='-')sign=-1;
			if(sign==1){
				pos--;
			}else{
				neg--;
			}
			for(j=1;j<=n;j++){
				mi=s+j*sign+pos-neg*n;
				ma=s+j*sign+n*pos-neg;
				//cout<<i<<" "<<j<<" "<<mi<<" "<<ma<<endl;
				if(mi <= n && ma >= n){
					break;
				}
			}
			//if(j>n){
				//return 1;
			//}
			s+=j*sign;
			//cout<<s<<" "<<j<<endl;
			if(i>0){
				if(sign==1){
					cout<<" + "<<j;
				}else{
					cout<<" - "<<j;
				}
			}else{
				cout<<j;
			}
		}
		int sign = 1;
		if(c[l-2]=='-')sign=-1;
		int x=abs(s-n);
		if(sign==1){
			cout<<" + ";
		}else{
			cout<<" - ";
		}
		cout<<x<<" = "<<n<<endl;
		//cout<<s<<" "<<l<<endl;
	}else{
		cout<<"Impossible"<<endl;
	}
	return 0;
}

