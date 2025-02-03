#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl


void solve(){
    int n; cin >> n;
    int vect[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> vect[i][j];
        }
    }
    vector<int> ones(n, 0);
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j >= 0; j--){
            if(vect[i][j] != 1){
                break;
            }
            else{
                ones[i]++;
            }
        }
    }
    multiset<int> vones;
    for(auto i : ones){
        vones.insert(i);
    }
    int mex = 0;
    for(int i = 0; i <= n; i++){
        auto tmp = vones.lower_bound(i);
        if(tmp == vones.end()){
            break;
        }
        vones.erase(tmp);
        mex++;
    }
    cout << mex << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //dp[i][j] = true if it is possible for the MEX to be j after doing column i
    int tt; cin >> tt;
    while(tt--){
        solve();
    }
}