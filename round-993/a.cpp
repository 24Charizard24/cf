#include <bits/stdc++.h>
using namespace std;
#define humberto long long
#define dbg(x) cout << #x << " = " << x << '\n';
#define all(v) v.begin(), v.end()

void solve(){
    int n;
    cin >> n;   

    humberto ans = 0;

    for(int a = 1; a <= n; a++){
        for(int b = 1; b <= n; b++){
            if(a + b == n) ans++;
        }
    }

    cout << ans << "\n";
    
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