#include <bits/stdc++.h>
using namespace std;
#define humberto long long
#define dbg(x) cout << #x << " = " << x << '\n';
#define all(v) v.begin(), v.end()

const int N = int(2e5+50);
int v[N];
int teste = 0;
int used[N];

void solve(){
    teste++;

    int n;
    cin >> n;

    vector<int> freq;
    vector<int> resto;

    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(used[v[i]] != teste){
            used[v[i]] = teste;
            freq.push_back(v[i]);
        }
    }

    for(int i = 1 ; i <= n; i++){
        if(used[i] != teste){
            // dbg(i);
            resto.push_back(i);
        }
    }

    // dbg(freq.size());
    // dbg(resto.size());
    
    for(auto x: freq) cout << x << ' ';
    for(auto x: resto) cout << x << ' ';
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