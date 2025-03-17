#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
//#define DEBUG 1
#ifdef DEBUG
    #define OUT(x) cerr << (#x) << '=' << (x) << endl
    #define OUT2(c) cerr << (#c) << " = {"; for (auto it = (c).begin(); it != (c).end(); ++it) cerr << (it == (c).begin() ? "" : ", ") << *it; cerr << "}" << endl;
#else
    #define OUT(x)
    #define OUT2(c)
#endif

const int inf = 1e18;

void solve() {
    int n; cin >> n;
    vector<int> vect(n + 1), row(n + 1, 0), col(n + 1, 0), full(n + 1, 0), prow(n + 1, 0), pcol(n + 1, 0), pfull(n + 1, 0);
    vector<int> pre(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> vect[i];
    }
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + vect[i];
    }
    //preprocessing
    for(int i = 1; i <= n; i++){
        row[1] += vect[i];
    }
    for(int i = 2; i <= n; i++){
        row[i] = row[i - 1] - vect[n - i + 2];
    }
    for(int i = 1; i <= n; i++){
        col[i] = (n - i + 1) * vect[i];
    }   
    for(int i = 1; i <= n; i++){
        prow[i] = prow[i - 1] + row[i];
        pcol[i] = pcol[i - 1] + col[i];
    }
    full[1] = prow[n];
    for(int i = 2; i <= n; i++){
        full[i] = full[i - 1] - (n - i + 2) * vect[i - 1];
    }
    for(int i = 1; i <= n; i++){
        pfull[i] = pfull[i - 1] + full[i];
    }
    vector<int> ranges(1, 0);
    for(int i = n; i >= 1; i--){
        ranges.push_back(i);
    }
    for(int i = 1; i <= n; i++){
        ranges[i] = ranges[i - 1] + ranges[i];
    }
    ranges.push_back(inf);
    //Debug
    OUT2(vect);
    OUT2(row);
    OUT2(col);
    OUT2(full);
    OUT2(prow);
    OUT2(pcol);
    OUT2(pfull);
    OUT2(ranges);
    int q; cin >> q;
    function<int(int, int)> f = [&](int x, int y){
        OUT(x);
        OUT(y);
        return prow[x] - pre[y] * x;
    };
    while(q--){
        int l, r; cin >> l >> r;
        auto itr = lower_bound(ranges.begin(), ranges.end(), l - 1);
        int l1 = itr - ranges.begin() + 1;
        itr = upper_bound(ranges.begin(), ranges.end(), r);
        int r1 = itr - ranges.begin() - 1;
        OUT(l1);
        OUT(r1);
        int amtl = (ranges[l1 - 1] + 1) - l;
        int amtr = r - ranges[r1];
        OUT(amtl);
        OUT(amtr);
        if(l1 > r1 && abs(r1 - l1) == 2){
            int mid = l1 - 1;
            amtr = (l - ranges[mid - 1]) - 1;
            amtl = ranges[mid] - r;
            int ans = 0;
            if(amtl > 0){
                ans += f(amtl, l1 - 2);
            }
            if(amtr > 0){
                ans += full[r1 + 1] - f(n - (r1 + 1) + 1 - amtr, r1);
                OUT(f(n - (r1 + 1) + 1 - amtr, r1));
            }
            OUT(amtl);
            OUT(amtr);
            ans *= -1;
            ans += full[mid];
            cout << ans << '\n';
        }
        else if(l1 > r1){
            int ans = 0;
            if(amtl > 0){
                ans += f(amtl, l1 - 2);
            }
            if(amtr > 0){
                ans += full[r1 + 1] - f(n - (r1 + 1) + 1 - amtr, r1);
                OUT(f(n - (r1 + 1) + 1 - amtr, r1));
            }
            cout << ans << '\n';
        }
        else{
            int ans = pfull[r1] - pfull[l1 - 1];
            OUT(ans);
            if(amtl > 0){
                ans += f(amtl, l1 - 2);
            }
            if(amtr > 0){
                ans += full[r1 + 1] - f(n - (r1 + 1) + 1 - amtr, r1);
                OUT(f(n - (r1 + 1) + 1 - amtr, r1));
            }
            cout << ans << '\n';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; tt = 1;
    while (tt--) {
        solve();
    }
}