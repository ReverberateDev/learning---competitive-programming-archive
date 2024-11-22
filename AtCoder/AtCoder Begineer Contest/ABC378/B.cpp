#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<int>q(n), r(n);
    for(int i = 0; i < n; i++){
        cin >> q[i] >> r[i];
    }
    int tt; cin >> tt;
    while(tt--){
        int t, d; cin >> t >> d;
        t--;
        int Q = q[t], R = r[t];
        int extra = d - R;
        cout << R + Q * ((extra + Q - 1) / Q) << '\n';
    }
}
