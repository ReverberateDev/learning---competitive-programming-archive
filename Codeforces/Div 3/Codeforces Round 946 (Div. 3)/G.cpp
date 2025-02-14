#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    int m, x; cin >> m >> x;
    priority_queue<int> pq;
    int budget = 0;
    for(int i = 0; i < m; i++){
        int c; cin >> c;
        if(budget >= c){
            pq.push(c);
            budget -= c;
        }
        else if(!pq.empty() && pq.top() > c){
            auto curr = pq.top();
            pq.pop();
            budget += curr;
            pq.push(c);
            budget -= c;
        }
        budget += x;
    }
    cout << pq.size() << '\n';
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