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

    while(1){
        int ok=0;
        int tg=-1;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                int sz=2;
                if(s.size()<3)sz=0;
                char nw=s[sz];
                if(i>0)nw=s[i-1];
                s[i]=nw;   
                ok=1;
                tg=i+1;
                break;
            }
        }
        
        string t;
        for(int i=0;i<s.size();i++){
            if(i==tg)continue;
            t.pb(s[i]);
        }
        swap(t,s);

        if(!ok)break;
    }

    cout<<s.size()<<"\n";
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

abbcc


*/