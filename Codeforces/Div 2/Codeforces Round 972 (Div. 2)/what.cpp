#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

const int inf = 1e18;

int mp(char c){
    if(c == 'n') return 0;
    else if(c == 'a') return 1;
    else if(c == 'r') return 2;
    else if(c == 'e') return 3;
    else if(c == 'k') return 4;
    else return -1;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<string> strings(n);
    for(int i = 0; i < n; i++){
        cin >> strings[i];
    }

    vector<int> dp(5, -inf);
    dp[0] = 0;

    for(const auto& s : strings){
        vector<int> cur = dp;
        for(int j = 0; j < 5; j++){
            if(dp[j] == -inf) continue;
            int c = dp[j];
            int k = j;
            for(char x : s){
                if(mp(x) != -1) c--;
                if(k < 5 && x == "narek"[k]){
                    k++;
                    if(k == 5){
                        c += 10;
                        k = 0;
                    }
                }
            }
            cur[k] = max(cur[k], c);
        }
        dp = cur;
    }

    int ans = *max_element(dp.begin(), dp.end());
    cout << ans << '\n';
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