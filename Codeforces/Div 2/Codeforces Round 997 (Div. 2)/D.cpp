#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

/*
Lets find the number of bad subarrays
Assume a subarray A[L, R] has a median x which can be bruteforced
(R - L + 1) / 2 elements will be strictly less than or equal to x
(R - L + 1) / 2 elements will be strictly greater than x
These two will be equal
For each X,
b[i] = -1 if a[i] <= x and 1 if a[i] > x
*/

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1), pre(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int x = 1; x <= 10; x++){
        for(int i = 1; i <= n; i++){
            b[i] = (a[i] <= x ? -1 : 1);
            pre[i] = pre[i - 1] + b[i];
        }
        int ptr = 1;
        map<int, int> mp;
        for(int i = 1; i <= n; i++){
            if(a[i] == x){
                while(ptr <= i){
                    mp[pre[ptr - 1]]++;
                    ptr++;
                }
            }
            int val = pre[i];
            ans += mp[val];
        }
    }
    ans = 1ll * n * (n + 1) / 2 - ans;
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