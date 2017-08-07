//#include <cstdio>
#include<bits/stdc++.h>

using  namespace std;
#ifndef ONLINE_JUDGE
const int maxn=300;
#else
const int maxn=300000;
#endif
const long long mod=1e9+9;

struct fenv {
    long long tree[maxn+10];
    void add(int i, long long d) {
        for (;i<maxn+10;i|=(i+1)) tree[i]=(tree[i]+d)%mod;
    }
    long long get(int i) {
        long long ans=0;
        for (;i>=0; i=(i&(i+1))-1) ans+=tree[i];
        return ans%mod;
    }
};

fenv t1, t2, t3;
long long fb[maxn+10];
int n, m, a;
int t, l, r;

inline long long getfb(int i) {
    if (i>0) return fb[i];
    else if (i%2) return fb[-i];
    else return mod-fb[-i];
}

int main() {
//#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
//#endif
    fb[1]=fb[2]=1;
    for (int i=3; i<maxn+10; i++) fb[i]=(fb[i-1]+fb[i-2])%mod;
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++) scanf("%d", &a), t3.add(i, a);
    for (int i=0; i<m; i++) {
        scanf("%d%d%d", &t, &l, &r);
        if (t==1) {
            //cout<<l<<" "<<getfb(2-l)<<" : 1"<<endl;
            t1.add(l, getfb(2-l));
            //cout<<l<<" "<<getfb(3-l)<<" : 2"<<endl;
            t2.add(l, getfb(3-l));
            //cout<<l<<" "<<"-1"<<" : 3"<<endl;
            t3.add(l, -1);
            //cout<<r+1<<" "<<-getfb(2-l)<<" : 1"<<endl;
            t1.add(r+1, -getfb(2-l));
            //cout<<r+1<<" "<<-getfb(3-l)<<" : 2"<<endl;
            t2.add(r+1, -getfb(3-l));
            //cout<<r+1<<" "<<fb[r-l+3]<<" : 3"<<endl;
            t3.add(r+1, fb[r-l+3]);
        } else {
            cout<<t1.get(r)<<" "<<getfb(r)<<endl;
            cout<<t2.get(r)<<" "<<getfb(r+1)<<endl;
            cout<<t3.get(r)<<endl;

            cout<<t1.get(l-1)<<" "<<getfb(l-1)<<endl;
            cout<<t2.get(l-1)<<" "<<getfb(l)<<endl;
            cout<<t3.get(l-1)<<endl;
            cout<<"//////"<<endl;
            printf("%d\n", (int)(((t3.get(r)+t1.get(r)*getfb(r)+t2.get(r)*getfb(r+1)-t3.get(l-1)-t1.get(l-1)*getfb(l-1)-t2.get(l-1)*getfb(l))%mod+mod)%mod));
            //printf("%d\n", (int)(((t1.get(r)*getfb(r))%mod+mod)%mod));
            //printf("%d\n", (int)(((t2.get(r)*getfb(r+1))%mod+mod)%mod));
            //printf("%d\n", (int)(((t3.get(r))%mod+mod)%mod));
            //printf("%d\n", (int)(((t3.get(r)+t1.get(r)*getfb(r)+t2.get(r)*getfb(r+1))%mod+mod)%mod));
        }
    }
    return 0;
}
