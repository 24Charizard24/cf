#include <bits/stdc++.h>
using namespace std;
#define humberto long long
#define dbg(x) cout << #x << " = " << x << '\n';
#define all(v) v.begin(), v.end()

void solve(){
    string s;
    cin >> s;

    reverse(all(s));

    for(auto x: s){
        if(x == 'p') cout << 'q';
        else if(x == 'q') cout << 'p';
        else cout << 'w';
    }
    cout << "\n";

    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}