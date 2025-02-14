#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

const int inf = 1e18;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    int curr = -inf;
    for(int i = 0; i < n; i++){
        auto itr = lower_bound(b.begin(), b.end(), curr + a[i]);
        int best = -inf;
        if(DEBUG){
            OUT(a[i]);
            OUT(curr);
        }
        if(curr <= a[i]){
            best = a[i];
        }
        if(itr != b.end()){
            int bval = b[itr - b.begin()];
            if(curr <= bval - a[i]){
                if(best != -inf){
                    best = min(best, bval - a[i]);
                }
                else{
                    best = bval - a[i];
                }
            }
        }
        if(DEBUG){
            OUT(best);
        }
        if(best == -inf){
            cout << "NO\n";
            return;
        }
        curr = best;
    }
    cout << "YES\n";
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

/*
Non decreasing is
1, 1, 3, 3, 4, 5

Assume we have a number x, we can make x = -x + b[idx]
if b[idx] is large, the answer will be large
if b[idx] is small, the answer will be small

3 1
9 8 7
8
*/