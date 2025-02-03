#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &i : a){
        cin >> i;
    }
    vector<int> ans;
    map<int, int> mp;
    pair<int, int> mode = {1, -1};
    int free = 0;
    set<int> st;
    for(int i = 1; i <= n; i++){
        st.insert(i);
    }
    for(auto i : a){
        if(st.find(i) != st.end()){
            st.erase(st.find(i));
        }
    }
    for(int i = 0; i < n; i++){
        free++;
        int curr = a[i];
        while(mp[curr] < mode.first){
            if(free > 0){
                mp[curr]++;
                free--;
                ans.push_back(curr);
            }
        }
        mode.first = mp[curr];
        mode.second = curr;
    }
    while(ans.size() < n){
        ans.push_back(*st.begin());
        st.erase(st.begin());
    }
    for(auto i : ans){
        cout << i << " ";
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