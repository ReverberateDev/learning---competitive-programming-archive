#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0

const int MAXM = 20;
const int INF = 1e18;

signed main(){
    int n; cin >> n;
    vector<int>vect(n + 1, -1);
    for(int i = 1; i <= n; i++){
        cin >> vect[i];
        vect[i]--;
    }
    int f[n + 1][MAXM];
    for(int m = 0; m < MAXM; m++){
        int curr = INF;
        for(int i = n; i >= 0; i--){
            f[i][m] = curr;
            if(vect[i] == m){
                curr = i;
            }
        }
    }
    if(DEBUG){
        for(int i = 0; i < n + 1; i++){
            for(int j = 0; j < MAXM; j++){
                cout << f[i][j] << " ";
            }
            cout << '\n';
        }
    }
    vector<int>bmasks(1 << MAXM);
    vector<int>dp(1 << MAXM, INF);
    iota(bmasks.begin(), bmasks.end(), 0);
    if(DEBUG){
        cout << bmasks.back() << '\n';
    }
    sort(bmasks.begin(), bmasks.end(), [&](const int a, const int b){
        return __builtin_popcountll(a) < __builtin_popcountll(b);
    });
    if(DEBUG){
        cout << "Checkpoint1\n";
    }
    dp[0] = 0;
    int ans = 0;
    for(auto bmask : bmasks){
        if(DEBUG){
            if(bmask == 1){
                cout << "Detected\n";
            }
        }
        if(bmask == 0){
            continue;
        }
        for(int i = 0; i < MAXM; i++){
            if(bmask & (1 << i)){
                if(DEBUG){
                    cout << "Checkpoint4. Bitmask: " << bmask << '\n';
                    cout << dp[bmask ^ (1 << i)] << '\n';
                }
                int prev = bmask ^ (1 << i);
                if(DEBUG){
                    cout << "Checkpoint7. Prev: " << prev << '\n';
                }
                int idx = dp[prev];
                if(DEBUG){
                    cout << "Checkpoint8. idx: " << idx << '\n';
                }
                if(idx == INF){
                    continue;
                }
                else{
                    idx = f[dp[prev]][i];
                    if(idx == INF){
                        continue;
                    }
                    else{
                        idx = f[idx][i];
                    }
                }
                if(DEBUG){
                    cout << "Checkpoint6. Idx: " << idx << '\n';
                }
                dp[bmask] = min(dp[bmask], idx);
                if(DEBUG){
                    cout << "Checkpoint5. Bitmask: " << bmask << '\n';
                }
            }
            if(DEBUG){
                cout << "Checkpoint3. Bitmask: " << bmask << '\n';
            }
        }
        if(dp[bmask] != INF){
            if(DEBUG){
                cout << "Registering: " << bmask << '\n';
            }
            if((int)__builtin_popcountll(bmask) > ans){
                ans = (int)__builtin_popcountll(bmask);
            }
        }
        if(DEBUG){
            cout << "dp[bmask]: " << dp[bmask] << '\n';
        }
        if(DEBUG){
            if(bmask == 1){
                cout << "Detected2\n";
                exit(0);
            }
        }
    }
    if(DEBUG){
        cout << "Checkpoint2\n";
    }
    ans *= 2;
    cout << ans;
}