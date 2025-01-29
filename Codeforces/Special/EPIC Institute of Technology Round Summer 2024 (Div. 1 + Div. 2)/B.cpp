#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n; cin >> n;
    vector<int> arr(n), fin(n);
    map<int, int> add;
    int tot = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        fin[i] = arr[i];
        if(i > 0){
            fin[i] = max(fin[i - 1], arr[i]);
        }
        add[fin[i] - arr[i]]++;
        if(fin[i] > arr[i]){
            tot++;
        }
    }
    int ans = 0, cnt = 0;
    for(auto [v, no] : add){
        if(v == 0){
            continue;
        }
        int val = v;
        val -= cnt;
        ans += val * (tot + 1);
        cnt += val;
        tot -= no;
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--){
        solve();
    }
}