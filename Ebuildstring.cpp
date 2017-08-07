// My first MCMF question using stjepang snippets. tags: mcmf, stjepang, dfs
// http://codeforces.com/problemset/problem/237/E
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


#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

typedef long long llint;
// Min-cost max-flow (uses DFS)
//
// Given a directed weighted graph, source, and sink, computes the minimum cost
// of the maximum flow from source to sink.
// This version uses DFS to find shortest paths and gives good performance on
// very "shallow" graphs: graphs which have very short paths between source
// and sink (e.g. at most 10 edges).
// In such cases this algorithm can be orders of magnitude faster than the
// Dijkstra version.
//
// To use, call init(n), then add edges using edge(x, y, c, w), and finally
// call run(src, sink).
//
// Functions:
// - init(n) initializes the algorithm with the given number of nodes
// - edge(x, y, c, w) adds an edge x->y with capacity c and weight w
// - run(src, sink) runs the algorithm and returns {total_cost, total_flow}
//
// Time complexity: O(V * E^3)
//
// Constants to configure:
// - MAXV is the maximum number of vertices
// - MAXE is the maximum number of edges (i.e. twice the calls to function edge)
// - oo is the "infinity" value

namespace Mcmf {
  const int MAXV = 1000100;
  const int MAXE = 1000100;
  const llint oo = 1e18;

  int V, E;
  int last[MAXV], curr[MAXV], bio[MAXV]; llint pi[MAXV];
  int next[MAXE], adj[MAXE]; llint cap[MAXE], cost[MAXE];

  void init(int n) {
    V = n;
    E = 0;
    REP(i, V) last[i] = -1;
  }

  void edge(int x, int y, llint c, llint w) {
    //cout<<x<<" "<<y<<" "<<c<<" "<<w<<endl;
    adj[E] = y; cap[E] = c; cost[E] = +w; next[E] = last[x]; last[x] = E++;
    adj[E] = x; cap[E] = 0; cost[E] = -w; next[E] = last[y]; last[y] = E++;
  }

  llint push(int x, int sink, llint flow) {
    if (x == sink) return flow;
    if (bio[x]) return 0;
    bio[x] = true;

    for (int &e = curr[x]; e != -1; e = next[e]) {
      int y = adj[e];

      if (cap[e] && pi[x] == pi[y] + cost[e])
	if (llint f = push(y, sink, min(flow, cap[e])))
	  return cap[e] -= f, cap[e^1] += f, f;
    }
    return 0;
  }

  pair<llint, llint> run(int src, int sink) {
    llint total = 0;
    llint flow = 0;

    REP(i, V) pi[i] = oo;
    pi[sink] = 0;

    for (;;) {
      bool done = true;
      REP(x, V) for (int e = last[x]; e != -1; e = next[e])
	if (cap[e] && pi[x] > pi[adj[e]] + cost[e])
	  pi[x] = pi[adj[e]] + cost[e], done = false;
      if (done) break;
    }

    for (;;) {
      REP(i, V) bio[i] = false;
      REP(i, V) curr[i] = last[i];

      while (llint f = push(src, sink, oo)) {
	total += pi[src] * f;
	flow += f;
	REP(i, V) bio[i] = false;
      }

      llint inc = oo;
      REP(x, V) if (bio[x]) {
	for (int e = last[x]; e != -1; e = next[e]) {
	  int y = adj[e];
	  if (cap[e] && !bio[y]) inc = min(inc, pi[y] + cost[e] - pi[x]);
	}
      }
      if (inc == oo) break;

      REP(i, V) if (bio[i]) pi[i] += inc;
    }
    return {total, flow};
  }
}
using namespace Mcmf;

ll A[105];
string S[105];
ll cnt[105][30];
ll B[30];

int main(){
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);
  string T;
  cin>>T;
  repp(i,1,27){
    B[i]=0;
  }
  rep(i,T.size()){
    B[(int)(T[i]-'a')+1]++;
  }
  int n;
  cin>>n;
  repp(i,1,n+1){
    cin>>S[i]>>A[i];
    repp(j,1,27){
      cnt[i][j]=0;
    }
  }
  repp(i,1,n+1){
    rep(j,S[i].size()){
      cnt[i][(int)(S[i][j]-'a')+1]++;
    }
  }
  // - edge(x, y, c, w) adds an edge x->y with capacity c and weight w
  int sr=0;
  int si = sr+26+n+1;
  init(si+1);
  repp(i,1,27){
    if(B[i] != 0)edge(sr,sr+i,B[i],0);
  }

  repp(i,1,27){
    repp(j,1,n+1){
     if(cnt[j][i]!=0)edge(sr+i,sr+26+j,cnt[j][i],j);
    }
  }
  repp(i,1,n+1){
    if(A[i]!=0)edge(sr+26+i,sr+26+n+1,A[i],0);
  }
  //cout<<sr<<"-"<<si<<endl;
  pair<ll,ll> tp = run(sr,si);
  //cout<<tp.X<<" "<<tp.Y<<endl;
  if(tp.Y == (ll)(T.size())){
    cout<<tp.X<<endl;
  }else{
    cout<<"-1"<<endl;
  }
  return 0;
}

