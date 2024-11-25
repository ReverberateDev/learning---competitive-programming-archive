#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

#define DEBUG 1

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<int>h(n);
    for(auto &i : h){
        cin >> i;
    }
    deque<int>dq;
    vector<int>ans;
    ans.push_back(0);
    for(int i = n - 1; i >= 1; i--){
        auto curr = h[i];
        while(!dq.empty() && curr >= dq.front()){
            dq.pop_front();
        }
        dq.push_front(curr);
        ans.push_back(dq.size());
    }
    reverse(ans.begin(), ans.end());
    for(auto i : ans){
        cout << i << " ";
    }
}