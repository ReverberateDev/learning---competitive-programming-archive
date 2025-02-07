#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

bool check(vector<vector<int>> &cows){
    int n = cows.size(), m = cows[0].size();
    int curr = -1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(curr > cows[j][i]){
                return false;
            }
            else{
                curr = cows[j][i];
            }
        }
    }
    return true;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> cows(n, vector<int>(m));
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> cows[i][j];
        }
        sort(cows[i].begin(), cows[i].end());
    }
    sort(ans.begin(), ans.end(), [&](const int &a, const int &b){
        return cows[a - 1][0] < cows[b - 1][0];
    });
    sort(cows.begin(), cows.end());
    int passes = check(cows);
    if(passes){
        for(auto i : ans){
            cout << i << " ";
        }
        cout << '\n';
    }
    else{
        cout << "-1\n";
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