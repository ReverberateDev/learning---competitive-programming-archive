#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int>a(n);
    for(auto &i : a){
        cin >> i;
    }
    set<pair<int, int>>st;
    for(int i = 0; i < m; i++){
        int temp; cin >> temp;
        st.insert({temp, i});
    }
    vector<int>ans(m, -1);
    if(DEBUG){
        for(auto [a, b] : st){
            cout << a << " " << b << '\n';
        }
    }
    for(int i = 0; i < n; i++){
        auto it = st.lower_bound({a[i], LLONG_MIN});
        while(it != st.end()){
            if(DEBUG){
                cout << "Current: " << it->first << " " << it->second << '\n';
            }
            ans[it->second] = i + 1;
            it++;
            st.erase(prev(it));
        }
    }
    for(auto i : ans){
        cout << i << '\n';
    }
}