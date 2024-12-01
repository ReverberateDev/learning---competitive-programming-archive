#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

int n, m;
vector<vector<int>>ans;

void recur(vector<int>curr){
    int sz = curr.size();
    if(sz == n){
        ans.push_back(curr);
        return;
    }
    else{
        for(int i = (sz == 0 ? 1 : curr.back() + 10); i <= m - 10 * (n -sz - 1); i++){
            vector<int>nxt = curr;
            nxt.push_back(i);
            recur(nxt);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    recur({});
    cout << ans.size() << '\n';
    for(auto vect : ans){
        for(auto i : vect){
            cout << i << " ";
        }
        cout << '\n';
    }
}