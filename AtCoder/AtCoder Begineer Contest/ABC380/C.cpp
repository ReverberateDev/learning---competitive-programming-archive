#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

#define DEBUG 1

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(auto &i : arr){
        cin >> i;
    }
    for(int i = 0; i < n - 1; i++){
        if(arr[i] != i + 1){
            if(arr[i] == i + 2 && arr[i + 1] == i + 1){
                i ++;
            }
            else{
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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