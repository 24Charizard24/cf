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

const int N = 100010;
const int NULO = INT_MAX;

int seg[4*N];
int v[N];
int merge(int a, int b){
    return min(a,b);
}

void build(int i, int l, int r){
    if(l==r){
        seg[i]=v[l];
        return;
    }
    int m=(l+r)/2;
    int e=2*i,d=e+1;
    build(e,l,m);
    build(d,m+1,r);
    seg[i]=merge(seg[e],seg[d]);
}

void update(int i, int l, int r, int idx, int val){
    if(l==r){
        seg[i]=val;
        return;
    }

    int m=(l+r)/2;
    int e=2*i,d=e+1;
    if(idx<=m)update(e,l,m,idx,val);
    else update(d,m+1,r,idx,val);
    seg[i]=merge(seg[e],seg[d]);
}

int query(int i, int l, int r, int ql, int qr){
    if(qr < l || r < ql) return NULO;
    if(ql <= l && r <= qr) return seg[i];

    int m=(l+r)/2;
    int e=2*i,d=e+1;
    return merge(query(e,l,m,ql,qr),query(d,m+1,r,ql,qr));
}

void solve(){
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    build(1,1,n);

    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        b++;
        if(a==1){  
            update(1,1,n,b,c);
        }   
        else{
            cout<<query(1,1,n,b,c)<<"\n";
        }
    }

}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}