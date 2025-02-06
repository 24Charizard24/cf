#include <bits/stdc++.h>
using namespace std;
#define humberto long long
#define dbg(x) cout << #x << " = " << x << '\n';
#define all(v) v.begin(), v.end()

void solve(){
    int a, b, c, m;
    cin >> m >> a >> b >> c;
    a = min(a,m);
    b = min(b,m);

    int ans = 0;
    ans += min(m, a);
    ans += min(m, b);

    int coisa = min(m-a,c);
    if(a < m) ans += coisa;
    c -= coisa;

    // dbg(coisa);

    coisa = min(m-b, c);
    if(b < m) ans += coisa;

    // dbg(coisa);

    
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