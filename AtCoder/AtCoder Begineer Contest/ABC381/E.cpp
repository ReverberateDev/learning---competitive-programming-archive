#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

#define DEBUG 0

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q; cin >> n >> q;
    string s; cin >> s;
    s = "0" + s;
    vector<int>pre1(n + 1, 0), pre2(n + 1, 0), vects;
    for(int i = 1; i <= n; i++){
        pre1[i] = pre1[i - 1] + (s[i] == '1');
        pre2[i] = pre2[i - 1] + (s[i] == '2');
        if(s[i] == '/'){
            vects.push_back(i);
        }
    }

    while(q--){
        int l, r; cin >> l >> r;
        int lo = 0, hi = r - l + 1, ans = 0;
        
        auto check = [&](int k, int loidx, int hiidx){
            while(loidx <= hiidx){
                int mididx = (loidx + hiidx) >> 1;
                int sidx = vects[mididx];
                int no_1s = pre1[sidx] - pre1[l - 1];
                int no_2s = pre2[r] - pre2[sidx];
                if(no_1s < k){
                    loidx = mididx + 1;
                }
                else if(no_2s < k){
                    hiidx = mididx - 1;
                }
                else{
                    return 1;
                }
            }
            return 0;
        };
        if(vects.empty()){
            cout << "0\n";
            continue;
        }
        auto it = lower_bound(vects.begin(), vects.end(), l);
        if(it == vects.end()){
            cout << "0\n";
            continue;
        }
        int loidx = it - vects.begin();
        it = upper_bound(vects.begin(), vects.end(), r);
        if(it == vects.begin()){
            cout << "0\n";
            continue;
        }
        it--;
        int hiidx = it - vects.begin();
        if(hiidx < loidx){
            cout << "0\n";
            continue;
        }

        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            if(DEBUG){
                cout << "Trying mid value: " << mid << '\n';
            }
            if(check(mid, loidx, hiidx)){
                if(DEBUG){
                    cout << mid << " checks out\n";
                }
                lo = mid + 1;
                ans = mid;
            }
            else{
                hi = mid - 1;
            }
        }
        if(DEBUG){
            cout << "Giving ans\n";
        }
        cout << ans * 2 + 1 << '\n';
    }
}