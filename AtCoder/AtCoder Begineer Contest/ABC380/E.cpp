#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0

void solve(){
    int n, q; cin >> n >> q;
    set<pair<int, int>>st;
    vector<int>ans(n + 2, 0);
    for(int i = 1; i <= n; i++){
        st.insert({i, i});
        ans[i] = 1;
    }
    st.insert({0, n + 1});
    st.insert({n + 1, n + 1});
    while(q--){
        if(DEBUG){
            cout << "Outputting ranges\n";
            for(auto [a, b] : st){
                cout << a << " " << b << '\n';
            }
            cout << "Done\n";
        }
        int temp; cin >> temp;
        if(temp == 1){
            int x, c; cin >> x >> c;
            auto itr = st.lower_bound({x, LLONG_MAX});
            auto [ri, rc] = *itr;
            auto [mi, mc] = *--itr;
            auto [_, lc] = *--itr;
            ans[mc] -= ri - mi;
            ans[c] += ri - mi;
            itr++;
            itr = st.erase(itr);
            if(c == rc){
                itr = st.erase(itr);
            }
            if(c == lc){}
            else{
                st.insert({mi, c});
            }

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