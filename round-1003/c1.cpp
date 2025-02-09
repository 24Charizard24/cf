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

        a[n-1]=max(a[n-1],b[0]-a[n-1]);
        for(int i=n-2;i>=0;i--){
            int nw = b[0]-a[i];
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