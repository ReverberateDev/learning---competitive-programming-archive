#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    string s; cin >> s;
    vector<char> ans;
    for(int i = s.length() - 1; i >= 0; i--){
        if(s[i] == 'p'){
            ans.push_back('q');
        }
        else if(s[i] == 'q'){
            ans.push_back('p');
        }
        else{
            ans.push_back('w');
        }
    }
    for(auto i : ans){
        cout << i;
    }
    cout << '\n';
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