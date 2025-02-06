#include <bits/stdc++.h>
using namespace std;

#define humberto long long
#define dbg(x) cout << #x << " = " << x << '\n';
#define all(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define pii pair<int,int> 
#define int long long

const int N = 2e5+50;
int adj[N];
int vis[N];
int d[N];
int in[N],out[N];
int n;
int timer,tg;


void dfs(int v, int p){
    // cout<<"\n";
    // dbg(p);
    // dbg(v);
    // dbg(adj[v]);
    // cout.flush();
    // usleep((int)1e5);

    in[v]=++timer;

    int u=adj[v];
    int dist=0;
    if(in[u] && !out[u]){
        if(!tg)tg=in[u];
        // cout<<"CICLO COMECOU EM " << u << " COM TEMPO " << in[u]<<"\n";
        // cout<<"ALI\n";
    }
    else if(!in[u]){
        // cout<<"AQ\n";
        dfs(u,v);
        dist=d[u]+1;
    }
    else if(d[u]!=-1){
        dist=d[u]+1;
    }

    out[v]=++timer;
    if(in[v]>=tg&&tg)dist=0;

    d[v]=dist;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        vis[i]=0;
        d[i]=-1;
        in[i]=out[i]=0;
    }

    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        adj[i]=a;
    }

    for(int i=1;i<=n;i++){
        if(!in[i]){
            timer=tg=0;
            dfs(i,i);
            // dbg(i);
            // dbg(tg);
            // cout<<"\n";
        }
    }

    int mx=0;
    for(int i=1;i<=n;i++){
        // dbg(i);
        // dbg(d[i]);
        // cout<<"\n";
        mx=max(mx,d[i]);
    }

    cout<<mx+2<<"\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}