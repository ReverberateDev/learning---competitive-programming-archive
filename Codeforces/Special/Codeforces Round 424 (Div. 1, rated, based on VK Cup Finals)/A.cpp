#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, p; cin >> n >> k >> p;
    vector<int> people(n), keys(k);
    for(auto &person : people){
        cin >> person;
    }
    for(auto &key : keys){
        cin >> key;
    }
    sort(people.begin(), people.end());
    sort(keys.begin(), keys.end());
    function<int(int)> func = [&](int strt) -> int {
        int max_dist = LLONG_MIN;
        for(auto person : people){
            int idx = strt++;
            int key = keys[idx];
            int dist = abs(person - key) + abs(key - p);
            max_dist = max(max_dist, dist);
        }
        return max_dist;
    };
    int ans = LLONG_MAX;
    for(int i = 0; i <= k - n + 1; i++){
        ans = min(ans, func(i));
    }
    cout << ans;
}
