#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    vector<int> vect(5);
    cin >> vect[0] >> vect[1] >> vect[3] >> vect[4];
    int best = 0;
    function<int()> calc = [&](){
        int res = 0;
        for(int i = 2; i < 5; i++){
            if(vect[i] == vect[i - 1] + vect[i - 2]){
                res++;
            }
        }
        return res;
    };
    for(int i = -202; i <= 202; i++){
        vect[2] = i;
        best = max(best, calc());
    }
    cout << best << '\n';
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