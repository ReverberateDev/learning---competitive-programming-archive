#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0

const int inf = 1e18;

//dp[i][j][k] = max ephony from first i letters with j changes and letter i is k
int getNum(char a){
    return (int)(a - 'a');
}

int calc(int a, char c){
    int c2 = getNum(c);
    int res = (a != c2);
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    int l = (int)s.length();
    int k; cin >> k;
    int n; cin >> n;
    map<string, int> mp;
    for(int i = 0; i < n; i++){
        string a, b; cin >> a >> b;
        int c; cin >> c;
        string tmp = a + b;
        mp[tmp] = max(mp[tmp], c);
    }
    int dp[l + 1][k + 1][26];
    for(int i = 0; i < l + 1; i++){
        for(int j = 0; j < k + 1; j++){
            for(int k = 0; k < 26; k++){
                dp[i][j][k] = -inf;
            }
        }
    }
    for(int i = 0; i < 26; i++){
        if('a' + i == s[0]){
            dp[0][0][i] = 0;
        }
        else{
            dp[0][1][i] = 0;
        }
    }
    if(DEBUG){
        string tmp = "";
        tmp.push_back((char)('a' + 1));
        tmp.push_back((char)('a' + 1));
        int gain = mp[tmp];
        cout << "Gain: " << gain << '\n';
    }
    for(int i = 1; i < l; i++){
        for(int j = 0; j <= min(i + 1, k); j++){
            for(int k2 = 0; k2 < 26; k2++){
                int best = -inf;
                for(int p = 0; p < 26; p++){
                    int cost = calc(k2, s[i]);
                    if(j - cost < 0){
                        continue;;
                    }
                    if(dp[i - 1][j - cost][p] == -inf){
                        continue;
                    }
                    if(DEBUG){
                        cout << "Processing\n";
                        cout << "i: " << i << " j: " << j << " k2: " << k2 << " p: " << p << '\n';
                        cout << "Cost: " << cost << '\n';
                    }
                    string tmp = "";
                    tmp.push_back((char)('a' + p));
                    tmp.push_back((char)('a' + k2));
                    int gain = mp[tmp];
                    if(DEBUG){
                        if(gain == 1){
                            cout << "Gain: " << gain << '\n';
                        }
                    }
                    int res = dp[i - 1][j - cost][p] + gain;
                    best = max(best, res);
                }
                dp[i][j][k2] = best;
            }
        }
    }
    int ans = LLONG_MIN;
    for(int j = 0; j <= k; j++){
        for(int k2 = 0; k2 < 26; k2++){
            ans = max(ans, dp[l - 1][j][k2]);
        }
    }
    cout << ans;
}