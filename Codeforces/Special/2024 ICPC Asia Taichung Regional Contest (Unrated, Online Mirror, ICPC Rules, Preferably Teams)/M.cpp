#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

template<typename T1, typename T2>
inline void chkmin(T1 &x, const T2 &y) {
    if (y < x) {
        x = y;
    }
}
 
 
template<typename T1, typename T2>
inline void chkmax(T1 &x, const T2 &y) {
    if (y > x) {
        x = y;
    }
}

int calc(vector<int> &arr){
    int n = arr.size();
    vector<pair<int, int>> arr2(n);
    for(int i = 0; i < n; i++){
        arr2[i] = {arr[i], i};
    }
    auto arr3 = arr2;
    sort(arr3.begin(), arr3.end());
    int ans = n * n;
    vector<int> suf(n);
    for(int i = n - 1; i >= 0; i--){
        suf[i] = lower_bound(arr3.begin(), arr3.end(), arr2[i]) - arr3.begin();
        if(suf[i] == i){
            suf[i] = n;
        }
        if(i != n - 1){
            chkmin(suf[i], suf[i + 1]);
        }
    }
    int pass = 1;
    for(int i = 1; i < n; i++){
        if(arr[i] < arr[i - 1]){
            pass = 0;
        }
    }
    if(pass){
        return 0;
    }
    for(int i = 0; i < n - 1; i++){
        int curr = (i + 1) * (i + 1);
        int tmp = suf[i + 1];
        curr += (n - tmp) * (n - tmp);
        chkmin(ans, curr);
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans = calc(arr);
    reverse(arr.begin(), arr.end());
    for(int i = 0; i < n; i++){
        arr[i] = -arr[i];
    }
    chkmin(ans, calc(arr));
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt; tt = 1;
    while(tt--){
        solve();
    }
}