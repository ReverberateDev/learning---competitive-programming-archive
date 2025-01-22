#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl
struct item{
    int t, d, p, original;
    bool operator<(const item &other) const{
        return d < other.d;
    }
};
int n;
vector<item> items;
pair<int, int> memo[2001][101];
pair<int, int> neg = {-1, -1};
const int inf = 1e18;


pair<int, int> dp(int tp, int idx){
    if(tp < 0){
        return {inf, inf};
    }
    int p = items[idx].p, t = items[idx].t, d = items[idx].d;
    if(idx == 0){
        if(tp == 0){
            return {0, 0};
        }
        else if(tp == p && t < d){
            return {t, 1};
        }
        else{
            return {inf, inf};
        }
    }
    if(memo[tp][idx] != neg){
        return memo[tp][idx];
    }
    int tmp1 = dp(tp - p, idx - 1).first + t;
    pair<int, int> res;
    if(tmp1 >= d){
        res = make_pair(inf, inf);
    }
    else{
        res = make_pair(tmp1, 1);
    }
    res = min(res, {dp(tp, idx - 1).first, 0});
    return memo[tp][idx] = res;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    items.resize(n);
    for(int i = 0; i < n; i++){
        cin >> items[i].t >> items[i].d >> items[i].p;
        items[i].original = i;
    }
    sort(items.begin(), items.end());
    for(int i = 0; i < 2001; i++){
        for(int j = 0; j < 101; j++){
            memo[i][j] = neg;
        }
    }
    for(int i = 2000; i >= 0; i--){
        if(dp(i, n - 1).first < inf){
            vector<int> ans;
            int curr = i;
            for(int j = n - 1; j >= 0; j--){
                if(dp(curr, j).second){
                    ans.push_back(items[j].original);
                    curr -= items[j].p;
                }
            }
            reverse(ans.begin(), ans.end());
            cout << i << '\n';
            cout << ans.size() << '\n';
            for(auto i : ans){
                cout << i + 1 << " ";
            }
            break;
        }
    }
}