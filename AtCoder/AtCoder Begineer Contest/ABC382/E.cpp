#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x; cin >> n >> x;
    double dp1[n + 1], dp2[x + 1];
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));
    double p, P;
    dp1[0] = 1;
    for(int i = 0; i < n; i++){
        cin >> p;
        P = p / 100;
        dp1[i + 1] = dp1[i] * P;
        for(int j = i; j >= 0; j--){
            dp1[j] = dp1[j] * (1 - P);
            if(j){
                dp1[j] += dp1[j - 1] * P;
            }
        }
    }
    
    if(DEBUG){
        for(auto i : dp1){
            cout << i << " ";
        }
    }

    for(int i = 1; i <= x; i++){ //expected no. packs to get i rares
        for(int j = 1; j <= n; j++){
            dp2[i] += dp2[max(i - j, 0ll)] * dp1[j];
        }
        dp2[i]++;
        dp2[i] /= (1-dp1[0]);
    }
    cout << fixed << setprecision(16) << dp2[x];
}