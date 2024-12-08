#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

const int INF = 1e6;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;
    int sum = 0;
    vector<int> grp(n), val(n), pref(n);
    for(int i = 0; i < n; i++){
        cin >> grp[i] >> val[i];
        sum += val[i];
        pref[i] = sum;
    }
    if(sum % 3 != 0){
        cout << "-1";
        exit(0);
    }

    int target = sum / 3;

    // Use a vector of vectors of vectors instead of a raw 3D array
    vector<vector<vector<int>>> memo(target + 1, vector<vector<int>>(target + 1, vector<int>(n, -1)));

    auto dp = [&](auto dp, int a, int b, int idx) -> int {
        int c = pref[idx] - a - b;
        if (a < 0 || b < 0 || c < 0) {
            return INF;
        }
        if (memo[a][b][idx] != -1) {
            return memo[a][b][idx];
        }
        if (idx == 0) {
            if(a == 0 && b == 0 && c == val[idx]){
                if(grp[idx] == 3){
                    return 0;
                }
                else{
                    return 1;
                }
            }
            else if(a == 0 && b == val[idx] && c == 0){
                if(grp[idx] == 2){
                    return 0;
                }
                else{
                    return 1;
                }
            }
            else if(a == val[idx] && b == 0 && c == 0){
                if(grp[idx] == 1){
                    return 0;
                }
                else{
                    return 1;
                }
            }
            else{
                return INF;
            }
        }
        int ans = INF;
        for (int i = 1; i <= 3; i++) {
            int tmp = 0;
            if (grp[idx] != i) {
                tmp++;
            }
            int curr = INF;
            if (i == 1) {
                curr = dp(dp, a - val[idx], b, idx - 1) + tmp;
            } else if (i == 2) {
                curr = dp(dp, a, b - val[idx], idx - 1) + tmp;
            } else {
                curr = dp(dp, a, b, idx - 1) + tmp;
            }
            ans = min(ans, curr);
        }

        return memo[a][b][idx] = ans;
    };

    // Example to call dp
    int ans = dp(dp, target, target, n - 1);
    if(ans >= INF){
        cout << "-1\n";
    }
    else{
        cout << ans << '\n';
    }

    return 0;
}
