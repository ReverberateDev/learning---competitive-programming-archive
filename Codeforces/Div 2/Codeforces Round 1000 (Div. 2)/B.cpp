#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    int n, l, r; cin >> n >> l >> r;
    l--, r--;
    vector<int> arr(n), left, right, middle;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < l; i++){
        left.push_back(arr[i]);
    }
    for(int i = r + 1; i < n; i++){
        right.push_back(arr[i]);
    }
    for(int i = l; i <= r; i++){
        middle.push_back(arr[i]);
    }
    if(DEBUG){
        cout << "left\n";
        for(auto i : left){
            cout << i << " ";
        }
        cout << "\n";
        cout << "right\n";
        for(auto i : right){
            cout << i << " ";
        }
        cout << "\n";
        cout << "middle\n";
        for(auto i : middle){
            cout << i << " ";
        }
        cout << "\n";
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    sort(middle.begin(), middle.end());
    reverse(middle.begin(), middle.end());
    //left
    int tmp = min(left.size(), middle.size());
    int ans = 1e18, curr = 0;
    int i = 0;
    for(; i < tmp; i++){
        if(left[i] >= middle[i]){
            break;
        }
        curr += left[i];
    }
    for(; i < middle.size(); i++){
        curr += middle[i];
    }
    ans = min(ans, curr);
    if(DEBUG){
        cout << "ans\n";
        cout << ans << '\n';
    }
    tmp = min(right.size(), middle.size());
    curr = 0;
    i = 0;
    for(; i < tmp; i++){
        if(right[i] >= middle[i]){
            break;
        }
        curr += right[i];
    }
    for(; i < middle.size(); i++){
        curr += middle[i];
    }
    ans = min(ans, curr);
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