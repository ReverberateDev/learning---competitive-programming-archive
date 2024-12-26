#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void update(vector<int> &a, vector<int> &b){
    deque<int> dq;
    int n = a.size();
    for(int i = 0; i < n; i++){
        while(!dq.empty() && dq.front() <= a[i]){
            dq.pop_front();
        }
        while(!dq.empty() && dq.back() > b[i]){
            dq.pop_back();
        }
        dq.push_front(a[i]);
        if(b[i] == dq.back()){
            a[i] = b[i];
        }
    }
    return;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    update(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    update(a, b);
    int ans = true;
    for(int i = 0; i < n; i++){
        ans &= (a[i] == b[i]);
    }
    cout << (ans ? "YES\n" : "NO\n");
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
//for each A you can only go up till B, if there is a B blocking then gg