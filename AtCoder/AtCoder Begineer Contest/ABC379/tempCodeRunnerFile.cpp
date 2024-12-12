#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    vector<int>ans;
    int current = 0, carry = 0;
    s = "." + s;
    vector<int>vect(n + 1, 0);
    for(int i = 1; i <= n; i++){
        vect[i] = vect[i - 1] + (i * (s[i] - '0'));
    }
    for(int i = n; i >= 1; i--){
        if(DEBUG){
            cout << "Current: " << current << "Carry: " << carry << '\n';
        }
        current += vect[i];
        ans.push_back(current % 10);
        current /= 10;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(auto i : ans){
        cout << i;
    }
}