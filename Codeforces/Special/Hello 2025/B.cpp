#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    int n, k; cin >> n >> k;
    map<int, int> mp;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        mp[tmp]++;
    }
    for(auto [key, val] : mp){
        arr.push_back(val);
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] <= k){
            k -= arr[i];
            arr[i] = 0;
        }
    }
    int ans = 0;
    for(auto i : arr){
        if(i){
            ans++;
        }
    }
    if(!ans){
        ans++;
    }
    cout << ans << '\n';
}
//1, 2
//2, 2
//3, 4
//4, 3
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt; cin >> tt;
    while(tt--){
        solve();
    }
}