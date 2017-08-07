// sorting, queen placing implementation.
// very simple problem.(Maybe it shouldn't be E)
// http://codeforces.com/contest/131/problem/E
#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
vector<vector<pair<int,int> > > vec;
pair<int,int> pos[100005];
int net[100005];
int main(){
	int n,m;
	cin>>n>>m;
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		pos[i].X=x;
		pos[i].Y=y;
	}
	for(int i=1;i<=n;i++){
		net[i]=0;
	}
	vec.resize(0);
	vec.resize(n+5);
	for(int i=1;i<=m;i++){
		vec[pos[i].X].push_back(make_pair(pos[i].Y,i));
	}
	for(int i=1;i<=n;i++){
		sort(vec[i].begin(),vec[i].end());
		if(vec[i].size()>=2){
			int si=vec[i].size();
			net[vec[i][0].Y]++;
			net[vec[i][si-1].Y]++;
			for(int j=1;j<si-1;j++){
				net[vec[i][j].Y]+=2;
			}
		}
	}

	vec.resize(0);
	vec.resize(n+5);
	for(int i=1;i<=m;i++){
		vec[pos[i].Y].push_back(make_pair(pos[i].X,i));
	}
	for(int i=1;i<=n;i++){
		//cout<<i<<" "<<vec[i].size()<<endl;
		sort(vec[i].begin(),vec[i].end());
		if(vec[i].size()>=2){
			int si=vec[i].size();
			net[vec[i][0].Y]++;
			net[vec[i][si-1].Y]++;
			for(int j=1;j<si-1;j++){
				net[vec[i][j].Y]+=2;
			}
		}
	}

	vec.resize(0);
	vec.resize(2*n+5);
	for(int i=1;i<=m;i++){
		vec[pos[i].Y-pos[i].X+n].push_back(make_pair(pos[i].Y,i));
	}
	for(int i=0;i<=2*n+1;i++){
		sort(vec[i].begin(),vec[i].end());
		//cout<<i<<" "<<vec[i].size()<<endl;
		if(vec[i].size()>=2){
			int si=vec[i].size();
			net[vec[i][0].Y]++;
			net[vec[i][si-1].Y]++;
			for(int j=1;j<si-1;j++){
				net[vec[i][j].Y]+=2;
			}
		}
	}

	vec.resize(0);
	vec.resize(2*n+5);
	for(int i=1;i<=m;i++){
		vec[pos[i].X+pos[i].Y].push_back(make_pair(pos[i].Y,i));
	}
	for(int i=0;i<=2*n+1;i++){
		sort(vec[i].begin(),vec[i].end());
		if(vec[i].size()>=2){
			int si=vec[i].size();
			net[vec[i][0].Y]++;
			net[vec[i][si-1].Y]++;
			for(int j=1;j<si-1;j++){
				net[vec[i][j].Y]+=2;
			}
		}
	}
	int adfd;
	int t[9];
	for(int i=0;i<=8;i++) {
		t[i]=0;
	}
	for(int i=1;i<=m;i++){
		t[net[i]]++;
	}
	for(int i=0;i<=8;i++) {
		cout<<t[i]<<" ";
	}cout<<endl;
	return 0;

}
