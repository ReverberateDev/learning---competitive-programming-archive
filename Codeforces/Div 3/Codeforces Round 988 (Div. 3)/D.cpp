#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

void solve(){
    int n, m, l; cin >> n >> m >> l;
    vector<tuple<int, int, vector<int>>>vect(n);
    for(auto &[x, y, _] : vect){
        cin >> x >> y; y = y - x + 2;
    }
    while(m--){
        int x, v; cin >> x >> v;
        auto it = upper_bound(vect.begin(), vect.end(), tuple(x, 0, vector<int>{}));
        if(it == vect.end()){
            continue;
        }
        get<2>(*it).emplace_back(v);
    }

    int ans = 0, jump = 1;
    priority_queue <int> pq;
    for(auto &[l, d, v] : vect){
        for(int p : v){
            pq.push(p);
        }
        while(jump < d){
            if(pq.empty()){
                cout << "-1\n";
                return;
            }
            jump += pq.top();
            pq.pop();
            ans++;
        }
    }
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
