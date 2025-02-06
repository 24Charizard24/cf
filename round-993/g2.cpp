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
vector<int>adj2[N];
int vis[N];
int d[N];
int in[N],out[N];
int n;
int timer,tg;

int dfs(int v, int p){
    int t=1;

    for(int u:adj2[v]){
        if(u==p || d[u] < d[v])continue;
        t+=dfs(u,v);
    }

    return t;
}

void dfs2(int v, int p){
    in[v]=++timer;

    int u=adj[v];
    int dist=0;
    if(in[u] && !out[u]){
        if(!tg)tg=in[u];
    }
    else if(!in[u]){
        dfs2(u,v);
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
        adj2[i].clear();
    }

    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        adj[i]=a;
        adj2[a].pb(i);
    }

    for(int i=1;i<=n;i++){
        if(!in[i]){
            timer=tg=0;
            dfs2(i,i);
        }
    }

    int mx=0;
    for(int i=1;i<=n;i++){
        if(d[i]==1){
            mx=max(mx,dfs(i,i));
        }
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