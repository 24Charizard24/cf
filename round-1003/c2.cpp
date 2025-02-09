#include <bits/stdc++.h>
using namespace std;

#define int long long
#define dbg(x) cout << #x << " = " << x << '\n';
#define all(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define mkp make_pair
#define vi vector<int>
#define pii pair<int,int>

const int N = 2e5+50;
const int INF = INT_MAX;
int n,m;
int a[N];
int b[N];

void solve(){
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<m;i++){
        cin>>b[i];
    }   
    sort(b,b+m);
    
    a[n-1]=max(a[n-1],b[m-1]-a[n-1]);

    for(int i=n-2;i>=0;i--){
        int sum=a[i]+a[i+1];
        int idx=lower_bound(b,b+m,sum)-b;
        if(idx==m)idx--;
        if(b[idx]>sum)idx--;
        int nw=a[i];
        if(idx>=0)nw=b[idx]-a[i];
        
        // dbg(i);
        // dbg(a[i]);
        // dbg(a[i+1]);
        // dbg(idx);
        // if(idx>=0)dbg(b[idx]);
        // dbg(nw);
        // cout<<"\n";

        if(a[i]>a[i+1] || (nw <= a[i+1] && nw > a[i])){
            a[i]=nw;
        }
        if(a[i]>a[i+1]){
            cout<<"NO\n";
            return;
        }
    }

    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<"\n";

    cout<<"YES\n";
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

/*

nw = b[x] - a[i]
nw <= a[i+1]
b[x] - a[i] <= a[i+1]
b[x] <= a[i] + a[i+1]
maior b[x] menor que a[i] + a[+1]
*/