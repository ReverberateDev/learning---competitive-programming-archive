#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

void solve(){
    int n, q; cin >> n >> q;
    set<pair<int, int>>st;
    vector<int>ans(n + 1, 0);
    for(int i = 1; i <= n; i++){
        st.insert({i, i});
        ans[i] = 1;
    }
    while(q--){
        int temp; cin >> temp;
        if(temp == 1){
            int x, c; cin >> x >> c;
            auto r = st.upper_bound()
        }
        else{
            int c; cin >> c;
            cout << ans[c] << '\n';
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}