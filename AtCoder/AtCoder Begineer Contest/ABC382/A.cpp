#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, d; cin >> n >> d;
    string s; cin >> s;
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '.'){
            ans++;
        }
    }
    ans+=d;
    cout << ans << '\n';
}