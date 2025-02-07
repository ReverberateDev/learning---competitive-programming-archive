#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

const int inf = 1e18;
/*
struct info{
    int lost, ptr, idx;
    info(int _idx, vector<vector<int>> &best): idx(_idx), ptr(0){
        lost = best[idx][ptr] - best[idx][ptr + 1];
    }
    void nxt(vector<vector<int>> &best){
        if(ptr < best[idx].size() - 1){
            ptr++;
            lost = best[idx][ptr] - best[idx][ptr + 1];
        }
        else{
            lost = inf;
        }
    }
    bool operator<(const info &other) const {
        return lost < other.lost;
    }
};
*/
void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    vector<vector<int>> best(n, vector<int>(m + 2, inf));
    for(int i = 0; i < n; i++){
        best[i][0] = a[i];
        for(int bmask = 0; bmask < (1 << m); bmask++){
            int j = __builtin_popcountll(bmask);
            int curr = best[i][0];
            for(int idx = 0; idx < m; idx++){
                if(bmask & (1 << idx)){
                    curr &= b[idx];
                }
            }
            best[i][j] = min(best[i][j], curr);
        }
    }
    if(DEBUG){
        cout << "Outputting best\n";
        for(auto &a : best){
            for(auto &b : a){
                cout << b << " ";
            }
            cout << '\n';
        }
    }
    int ans = 0;
    vector<int> vect;
    for(int i = 0; i < n; i++){
        ans += best[i][0];
        for(int j = 0; j < m + 1; j++){
            vect.push_back(best[i][j] - best[i][j + 1]);
        }
    }
    sort(vect.begin(), vect.end());
    reverse(vect.begin(), vect.end());
    for(int i = 0; i < k; i++){
        if(vect[i] <= 0){
            break;
        }
        ans -= vect[i];
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