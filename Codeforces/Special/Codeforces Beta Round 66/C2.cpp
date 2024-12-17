#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

const int N = 700, inf = 1e18;

string s;
int n, k, len, a[30][30], memo[N][27][N];

int dp(int idx, int lst, int rem){
    if(rem < 0){
        return -1e5;
    }
    if(idx == len){
        return 0;
    }
    if(memo[idx][lst][rem] != -1){
        return memo[idx][lst][rem];
    }
    int best = -inf;
    for(int i = 0; i < 26; i++){
        int cost = (i != (int)(s[idx] - 'a'));
        int curr = dp(idx + 1, i, rem - cost) + a[lst][i];
        best = max(best, curr);
    }
    return memo[idx][lst][rem] = best;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> k >> n;
    len = s.length();
    for(int i = 0; i < n; i++){
        char tmp1, tmp2; cin >> tmp1 >> tmp2;
        int tmp3; cin >> tmp3;
        a[tmp1 - 'a'][tmp2 - 'a'] = tmp3;
    }
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 27, k);
}