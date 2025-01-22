#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

template<class T>
struct segmentTree{
    int n;
    vector<T> info;
    segmentTree(vector<T> _info){
        init(_info);
    }
    void init(vector<T> _info){
        n = _info;
        int sz = 2 * (1 << (__lg(n - 1) + 1));
        info.assign(sz, T());
        
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < 3; i++){
        for(int no = 1; no <= n; no++){
            int val; cin >> val;

        }
    }
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