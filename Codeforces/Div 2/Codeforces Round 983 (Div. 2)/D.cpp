#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

int query(int a, int b){ //1 if 0 is present
    cout << "? " << a << " " << b << endl;
    //cout.flush();
    int res; cin >> res;
    return res;
}

void solve(){
    int n; cin >> n;
    set<int> active;
    vector<int> p(n, 0);
    int i;
    for(i = 2; i < n; i++){
        active.insert(i);
        if(!query(1, i)){
            p[i] = 1;
            break;
        }
    }
    i++;
    for(; i < n; i++){
        while(!active.empty()){
            auto tent = *active.begin();
            active.erase(active.begin());
            if(!query(tent, i)){
                active.insert(i);
                p[i] = tent;
                break;
            }
        }
    }
    cout << "!";
    for(int i = 1; i < n; i++){
        cout << " " << p[i];
    }
    cout << endl;
}


signed main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    int tt; cin >> tt;
    while(tt--){
        solve();
    }
}