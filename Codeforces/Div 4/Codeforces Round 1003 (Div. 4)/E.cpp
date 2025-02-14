#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void print(int k, int curr){
    while(k--){
        cout << curr;
        curr ^= 1;
    }
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    if(k > n && k > m){
        cout << "-1\n";
        return;
    }
    if(n < m){
        m -= k;
        if(m - n >= 1 || (n == 0 && m)){
            cout << "-1\n";
            return;
        }
        for(int i = 0; i < k; i++){
            cout << "1";
        }
        int p = min(n, m);
        print(2 * p, 0);
        for(int i = 0; i < n - p; i++){
            cout << "0";
        }
        cout << '\n';
    }
    else{
        n -= k;
        if(n - m >= 1 || (m == 0 && n)){
            cout << "-1\n";
            return;
        }
        for(int i = 0; i < k; i++){
            cout << "0";
        }
        int p = min(n, m);
        print(2 * p, 1);
        for(int i = 0; i < m - p; i++){
            cout << "1";
        }
        cout << '\n';
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

/*
Assume abs(n - m) <= k
Is it possible?
let min(n, m) = p, let r be remainder
4, 3, 2
k of the same must appear at the end (m is greater)
n, m - k
n = 3, m = 5, k = 2
010101 p times alr
m = 2 left
we must end with the opposite one
*/