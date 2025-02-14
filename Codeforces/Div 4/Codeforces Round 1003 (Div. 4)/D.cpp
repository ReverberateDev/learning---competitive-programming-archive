#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> vect(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> vect[i][j];
        }
    }
    vector<int> stairs(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            stairs[i] += vect[i][j] * (m - j);
        }
    }
    vector<int> sums(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            sums[i] += vect[i][j];
        }
        sums[i] *= m;
    }
    if(DEBUG){
        cout << "Stairs\n";
        for(auto i : stairs){
            OUT(i);
        }
        cout << "Sums\n";
        for(auto i : sums){
            OUT(i);
        }
    }
    sort(sums.begin(), sums.end());
    int cnt = 0, ans = 0;
    for(int i = 0; i < sums.size(); i++){
        ans += sums[i] * cnt;
        cnt++;
    }
    for(auto i : stairs){
        ans += i;
    }
    cout << ans << '\n';
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
Assume array a is placed before array b

stairs for all arrays will be counted

0
00
000
0000
00001
000011
0000111
00001111

*/