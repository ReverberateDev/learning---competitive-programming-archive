#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

const int MAXN = 501;
const int inf = 1e18;
int n;
vector<int> colours;
int memo[MAXN][MAXN];
int memo2[MAXN][MAXN];

bool palindrome(int i, int j){
    if(memo2[i][j] != -1){
        return memo2[i][j];
    }
    int sz = j - i + 1;
    int tmp1 = colours[i] == colours[j];
    bool res;
    if(!tmp1){
        res = false;
    }
    else if(sz == 1){
        res = true;
    }
    else if(sz == 2){
        res = true;
    }
    else{
        res = palindrome(i + 1, j - 1) & tmp1;
    }
    return memo2[i][j] = res;
}

int dp(int i, int j){
    int sz = j - i + 1;
    if(sz == 1){
        return 1;
    }
    if(sz == 0){
        return 0;
    }
    if(palindrome(i, j)){
        return 1;
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    int res = inf;
    if(colours[i] == colours[j]){
        res = dp(i + 1, j - 1);
    }
    for(int x = i; x < j; x++){
        res = min(res, dp(i, x) + dp(x + 1, j));
    }
    return memo[i][j] = res;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    colours.resize(n);
    memset(memo, -1, sizeof(memo));
    memset(memo2, -1, sizeof(memo2));
    for(int i = 0; i < n; i++){
        cin >> colours[i];
    }
    cout << dp(0, n - 1);
}