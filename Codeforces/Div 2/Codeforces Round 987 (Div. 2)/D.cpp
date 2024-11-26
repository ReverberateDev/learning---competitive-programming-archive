#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0

void solve(){
    int n; cin >> n;
    vector<int>h(n);
    for(auto &i : h){
        cin >> i;
    }
    deque<array<int, 3>>dq;
    for(int i = 0; i < n; i++){
        array<int, 3>curr = {i, h[i], h[i]};
        while(!dq.empty() && curr[1] < dq.back()[2]){
            curr[2] = max(curr[2], dq.back()[2]);
            curr[1] = min(curr[1], dq.back()[1]);
            dq.pop_back();
        }
        dq.push_back(curr);
    }
    if(DEBUG){
        for(auto i : dq){
            cout << i[0] << " " << i[1] << " " << i[2] << '\n';
        }
    }
    set<pair<int, int>>st;
    int best = -1;
    for(auto i : dq){
        best = max(best, i[2]);
        pair<int, int>temp = make_pair(i[1], best);
        st.insert(temp);
    }
    if(DEBUG){
        for(auto [a, b] : st){
            cout << a << " " << b << '\n';
        }
    }
    int bans = h[0];
    for(int i = 0; i < n; i++){
        bans = max(bans, h[i]);
        auto it = st.upper_bound(make_pair(h[i], LLONG_MAX));
        if(it == st.begin()){
            cout << h[i] << " ";
        }
        else{
            it--;
            while(it != st.begin() && h[i] <= it->first){
                it--;
            }
            if(it == st.begin() && h[i] <= it->first){
                cout << bans << " ";
            }
            else{
                cout << max(bans, it->second) << " ";
            }
        }
    }
    cout << '\n';
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