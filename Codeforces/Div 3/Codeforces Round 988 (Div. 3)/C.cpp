#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

bool prime(int x){
    for(int i = 2; i <= (int)sqrt(x); i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}

bool check(vector<int>vect){
    for(int i = 0; i < vect.size() - 1; i++){
        if(prime(vect[i] + vect[i + 1])){
            return false;
        }
    }
    return true;
}

void solve(){
    int n; cin >> n;
    if(n < 9){
        vector<int>vect(n);
        iota(vect.begin(), vect.end(), 1);
        do{
            if(check(vect)){
                for(auto i : vect){
                    cout << i << " ";
                }
                cout << '\n';
                return;
            }
        } while (next_permutation(vect.begin(), vect.end()));
        cout << "-1\n";
    }
    else{
        //9 all odds but 1 - 8 all evens
        for(int i = 1; i <= n; i += 2){
            if(i == 1){
                continue;
            }
            cout << i << " ";
        }
        cout << "1 8 ";
        for(int i = 2; i <= n; i += 2){
            if(i == 8){
                continue;
            }
            cout << i << " ";
        }
        cout << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q; cin >> q;
    while(q--){
        solve();
    }
}