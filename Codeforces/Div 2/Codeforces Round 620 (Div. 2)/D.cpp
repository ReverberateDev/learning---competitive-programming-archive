#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    s.push_back('@');
    vector<int> ans1(n), ans2(n);
    int cnt = n;
    for(auto &i : ans1){
        i = cnt--;
    }
    cnt = 1;
    for(auto &i : ans2){
        i = cnt++;
    }
    //n = 3
    //<< -> goes until 1
    //last must be changed shud be 2
    auto ret = [&](int x) -> int {
        //return the index that must be changed last 
        for(int i = x + 1; i < n; i++){
            if(s[i] != s[x]){
                return i;
            }
        }
        return n - 1;
    };
    int curr = 0;
    while(curr < n - 1){
        int nxt = ret(curr);
        if(s[curr] == '<'){
            sort(ans1.begin() + curr, ans1.begin() + nxt + 1);
            sort(ans2.begin() + curr, ans2.begin() + nxt + 1);
        }
        else{
            sort(ans1.begin() + curr, ans1.begin() + nxt + 1, greater<int>());
            sort(ans2.begin() + curr, ans2.begin() + nxt + 1, greater<int>());
        }
        curr = nxt;
    }
    for(auto i : ans1){
        cout << i << " ";
    }
    cout << '\n';
    for(auto i : ans2){
        cout << i << " ";
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