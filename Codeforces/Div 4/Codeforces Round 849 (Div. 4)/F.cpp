#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

int s(int k){
    int sum = 0;
    while(k > 0){
        sum += k % 10;
        k /= 10;
    }
    return sum;
}

void solve(){
    int n, q; cin >> n >> q;
    vector<int>curr(n);
    set<int>valid;
    for(int i = 0; i < n; i++){
        cin >> curr[i];
        if(curr[i] > 9){
            valid.insert(i);
        }
    }
    while(q--){
        int temp; cin >> temp;
        if(temp == 1){
            int a, b; cin >> a >> b;
            a--, b--;
            while(!valid.empty()){
                auto it = valid.lower_bound(a);
                if(it == valid.end() || *it > b){
                    break;
                }
                curr[*it] = s(curr[*it]);
                int idx = *it;
                valid.erase(it);
                if(curr[idx] > 9){
                    valid.insert(idx);
                }
                a = idx + 1;
            }
        }
        else{
            int x; cin >> x;
            x--;
            cout << curr[x] << '\n';
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