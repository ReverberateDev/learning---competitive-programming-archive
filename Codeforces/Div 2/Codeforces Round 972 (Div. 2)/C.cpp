#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

/*
We assign each character a number code, characters that dont contain any such characters can be omitted
dp[i][j] = maximum possible score choosing words i to n and coming in with a charcter j
if j is not k, we know that we are currently in debt
info[i][j] = a pair that contains the guaranteed score after you traverse word i as well as the character you end on
e.g. enter with r
e k n a r e k n a
[][]          [][] not counted
*/

const int inf = 1e18;

int mp(char c){
    if(c == 'n'){
        return 0;
    }
    else if(c == 'a'){
        return 1;
    }
    else if(c == 'r'){
        return 2;
    }
    else if(c == 'e'){
        return 3;
    }
    else if(c =='k'){
        return 4;
    }
    else{
        return -1;
    }
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> strings(n);
    vector<vector<pair<int, int>>> info(n, vector<pair<int, int>>(5));
    vector<vector<int>> memo(n, vector<int>(5, -1));
    for(int i = 0; i < n; i++){
        string tmp; cin >> tmp;
        for(int j = 0; j < m; j++){
            int key = mp(tmp[j]);
            if(key != -1){
                strings[i].push_back(key);
            }
        }
        for(int j = 0; j < 5; j++){
            int curr = j, matched = 0, unmatched = 0;
            for(auto key : strings[i]){
                if(key == (curr + 1) % 5){
                    matched++;
                    curr = key;
                }
                else{
                    unmatched++;
                }
            }
            int score = matched - unmatched;
            info[i][j] = make_pair(score, curr);
        }
    }
    function<int(int, int)> dp = [&](int i, int j) -> int {
        int res = -inf;
        if(i == n){
            if(j < 4){
                return -((j + 1) + (j + 1));
            }
            return 0;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        //Use
        auto [scr, lst] = info[i][j];
        res = max(res, dp(i + 1, lst) + scr);
        if(DEBUG){
            cout << "i and j\n";
            cout << i << " " << j << '\n';
            cout << res << '\n';
        }
        //Don't use
        res = max(res, dp(i + 1, j));
        if(DEBUG){
            cout << "i and j\n";
            cout << i << " " << j << '\n';
            cout << res << '\n';
        }
        return memo[i][j] = res;
    };
    if(DEBUG){
        auto [scr, lst] = info[0][4];
        cout << scr << " " << lst << '\n';
        cout << dp(1, 1) << '\n';
    }
    cout << dp(0, 4) << '\n';
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
