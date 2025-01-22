#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

const int inf = 1e18;

void solve(){
    int n; cin >> n;
    vector<int> vect(n + 1), tmp(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> vect[i];
    }
    sort(vect.begin() + 1, vect.end());
    for(int i = 1; i <= n - 1; i++){
        tmp[i] = vect[i + 1] - vect[i];
    }
    vector<pair<int, pair<int, int>>> pre(n + 2, {inf, {-1, -1}}), suf(n + 2, {inf, {-1, -1}});
    for(int i = 1; i <= n - 1; i++){
        pre[i] = min(pre[i - 1], {tmp[i], {i, i + 1}});
    }
    for(int i = n - 1; i >= 1; i--){
        suf[i] = min(suf[i + 1], {tmp[i], {i, i + 1}});
    }
    if(DEBUG){
        for(auto i : pre){
            OUT(i.first);
        }
        for(auto i : suf){
            OUT(i.first);
        }
    }
    for(int i = 1; i <= n - 1; i++){
        if(vect[i] != vect[i + 1]){
            continue;
        }
        int lidx = max(0ll, i - 2), ridx = min(n, i + 2);
        int goal = 2 * vect[i];
        if(goal > pre[lidx].first){
            cout << vect[i] << " " << vect[i] << " " << vect[pre[lidx].second.first] << " " << vect[pre[lidx].second.second] << '\n';
            return;
        }
        if(goal > suf[ridx].first){
            cout << vect[i] << " " << vect[i] << " " << vect[suf[ridx].second.first] << " " << vect[suf[ridx].second.second] << '\n';
            return;
        }
        if(i > 1 && i + 1 < n){
            int tmp1 = vect[i + 2] - vect[i - 1];
            if(goal > tmp1){
                cout << vect[i] << " " << vect[i] << " " << vect[i - 1] << " " << vect[i + 2] << '\n';
                return;
            }
        }
    }
    cout << "-1\n";
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