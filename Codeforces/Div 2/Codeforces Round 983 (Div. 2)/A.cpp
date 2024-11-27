#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

void solve(){
    int n; cin >> n;
    int ones = 0, zeros = 0;
    for(int i = 0; i < 2 * n; i++){
        int temp; cin >> temp;
        (temp ? ones : zeros)++;
    }
    //off - 0 0, 1 1
    //on - 1 0
    //minimum
    int nones = ones / 2, nzeros = zeros / 2;\
    int ans1 = n - (nones + nzeros);
    int ans2 = min(ones, zeros);
    cout << ans1 << " " << ans2 << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt; cin >> tt;
    while(tt--){
        solve();
    }
}