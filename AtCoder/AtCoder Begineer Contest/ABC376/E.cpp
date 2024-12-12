#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt; cin >> tt;
    //for each max A, add the Bs then find the min K Bs
    while(tt--){
        int n, k; cin >> n >> k;
        map<int, vector<int>>mp;
        vector<pair<int, int>>vect(n);
        for(auto &[i, _] : vect){
            cin >> i;
        }
        for(auto &[_, i] : vect){
            cin >> i;
        }
        for(auto [a, b] : vect){
            mp[a].push_back(b);
        }
        priority_queue <int> pq;
        int ans = LLONG_MAX, amt = 0;
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            sort(itr->second.begin(), itr->second.end());

            for(auto i : itr->second){
                pq.push(i);
                amt += i;
            }
    
            while(pq.size() > k){
                amt -= pq.top();
                pq.pop();                
            }

            if(pq.size() < k){
                continue;
            }

            ans = min(ans, itr->first * amt);
        }
        cout << ans << '\n';
    }
}