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

int k,l1,r1,l2,r2;
int at=1;

void solve(){
    cin>>k>>l1>>r1>>l2>>r2;

    int ans=0;
    at=1;    

    while(1){
        if(l1*at>r2)break;

        int coiso=l2/at;
        if(at*coiso!=l2)coiso++;

        int l = max(coiso,l1);
        int r = min(r2/at, r1);

        if(l>r){
            at*=k;
            continue;
        }

        int sum=r-l+1;

        ans+=sum;
        at*=k;
    }

    cout<<ans<<"\n";
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

y = k*x
x = y/k
menor x possivel: l2/k (jogando pra cima)
maior x possivel: r2/k (jogando pra baixo)

[1,5]
[3,20]
pra k=1:
menor: 3/1 = 3
maior: 20/1 = 20
precisar checar se ta dentro do intervalo [l1,r1]

[3,20]
[1,5]
menor: 1/1 = 1
maior: 5/1 = 5

if(maior > r1) maior = r1; -> maior = min(r1,maior)
if(menor < l1) menor = l1; -> menor = max(l1,menor)

[1,5]
[15,20]
menor: 15/1=15
maior: 20/1=20
maior = min(5,20) = 5
menor = max(1, 15) = 15

menor > maior -> impossivel
if(menor > maior) continue
*/