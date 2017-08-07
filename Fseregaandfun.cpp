// My first sqrt-decompostion problem and nice idea implementing queue as array, tags: sqrt-decomposition
// http://codeforces.com/contest/455/problem/D
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
const int N = 1e5+10;
const ll INF = 1e18;
#define E5 100005

#define ld long double
//#define double long double
const ld EPS=1e-12;

const int SQN=256; // size of block
const int SZ = (N /SQN) + 5; // number of blocks

int n;
int arr[N];
int block[N];
unsigned char freq[SZ][N];
int start[N];
int finish[N]; // finish ~= f
int que[SZ][SQN + 1]; // array to maintain queue
int r[SZ]; // End of queue maintained using array
int f[SZ]; // head of queue - - -
int lastans;

inline void push(int block, int val){
	que[block][r[block]]=val;
	r[block]=(r[block] + 1) & 255;
}

inline int front(int block){
	return que[block][f[block]];
}

inline void pop(int block){
	f[block]=(f[block]+1)&255;
}

void decompose(){
	int cur=0;
	for(int i=1;i<=n;i+=SQN-1){
		int j=min(n,i+SQN-2); // block size is 255, not 256!!
		cur++;
		start[cur]=i;
		finish[cur]=j;
		for(int k = j; k >= i; k--){
			block[k]=cur;
			freq[cur][arr[k]]++;
			push(cur, arr[k]);
		}
	}
}

void query(int ql, int qr, int k){
	lastans=0;
	for(int i = block[ql]; i<=block[qr]; i++){
		if(ql<=start[i] && finish[i]<=qr){
			lastans+=(int)(freq[i][k]);
		}else if(freq[i][k]){
			int idx = finish[i];
			for(int j=f[i]; j!=r[i]; j=(j+1)&255){
				if(ql<=idx && idx<=qr && que[i][j] == k){
					lastans++;
				}
				idx--;
			}
		}
	}
}

void update(int ql, int qr){
	int bl = block[ql];
	int br = block[qr];
	if( bl == br ){
		// kind of brute
		int idx=finish[br];
		for(int i =f[br]; i != r[br]; i = (i+1)&255){
			if((ql+1) <= idx && idx <= qr){
				swap(que[br][i], que[br][(i+1)&255]);
			}
			idx--;
		}
		return;
	}
	int rektval=-1;
	for(int i=finish[br];i>=start[br];i--){
		int val=front(br);
		pop(br);
		if(i == qr){
			rektval=val;
		}else{
			push(br, val);
		}
	}
	freq[br][rektval]--;
	freq[bl][rektval]++;
	for(int i=finish[bl]; i >= start[bl]; i--){
		int val=front(bl);
		pop(bl);
		push(bl,val);
		if( i == ql ){
			push(bl, rektval);
		}
	}
	for(int i=bl; i<br; i++){
		int val=front(i);
		pop(i);
		freq[i][val]--;
		freq[i+1][val]++;
		push(i+1, val);
	}
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	scanf("%d",&n);
	repp(i,1,n+1){
		scanf("%d",&arr[i]);
	}
	decompose();
	int q;
	scanf("%d",&q);
	lastans=0;
	repp(i,1,q+1){
		int x,y,z;
		scanf("%d%d%d",&x, &y, &z);
		y=((y+lastans-1)%n)+1;
		z=((z+lastans-1)%n)+1;
		if(y>z)swap(y,z);
		if(x == 1){
			update(y,z);
		}else{
			int w;
			scanf("%d",&w);
			w=((w+lastans-1)%n)+1;
			query(y,z,w);
			printf("%d\n",lastans);
		}
	}
	return 0;
}

