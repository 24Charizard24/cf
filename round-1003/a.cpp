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

void solve(){
    string s;
    cin>>s;

    int r=s.size()-1;
    int ok=0;
    if(s.size() >= 2){
        if(s[s.size()-2] == 'u' && s[s.size()-1] == 's'){
            r=s.size()-3;
            ok=1;
        }
    }

    for(int i=0;i<=r;i++)cout<<s[i];
    if(ok)cout<<"i";
    cout<<"\n";
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