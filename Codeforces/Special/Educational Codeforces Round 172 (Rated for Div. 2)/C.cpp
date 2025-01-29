#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

//Assume 1 indexed
//Let pre[i] be the prefix sum of the number of fishes caught by Bob from 1 to i minus the number of fishes caught by Alice from 1 to i
//Let s[j] be the end point of the jth group (starts from 0)
//Total will be
//1 group
//0 * (pre[n] - pre[0])
//2 groups
//0 * (pre[s[0] - pre[0]]) + 1 * (pre[n] - pre[s[0]])
//0 - pre[s[0]] + pre[n]
//4 groups
//0 * (pre[s[0]] - pre[0]) + 1 * (pre[s[1]] - pre[s[0]]) + 2 * (pre[s[2]] - pre[s[1]]) + 3 * (pre[n] - pre[s[2]])...
// = 0 + (1 * pre[s[1]] - 1 * pre[s[0]]) + (2 * pre[s[2]] - 2 * pre[s[1]]) + (3 * pre[n] - 3 * pre[s[2]])...
//------------||||||||-------------------------------------|||||||||||||
// = 0 - pre[s[0]] - pre[s[1]] - pre[s[2]] + j * pre[n]

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    s = '.' + s;
    vector<int> pre(n + 2, 0);
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + (s[i] == '1' ? 1 : -1);
    }
    int lst = pre[n];
    sort(pre.begin(), pre.end());
    int curr = 0;
    for(int i = 0; pre[i] < 0; i++){
        curr -= pre[i];
        int tot = curr + (i + 1) * lst;
        if(tot >= k){
            cout << i + 2 << '\n';
            return;
        }
    }
    cout << "-1\n";
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