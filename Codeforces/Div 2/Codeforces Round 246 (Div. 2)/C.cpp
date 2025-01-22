#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl
 
const int N = 100100;


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<bool> used(N, false);
    vector<int> primes, pos(n + 1), vect(n + 1);
    vector<pair<int, int>> ans;
    for(int i = 2; i * i < N; i++){
        if(used[i]){
            continue;
        }
        for(int j = i * i; j < N; j += i){
            used[j] = true;
        }
    }
    for(int i = 2; i < N; i++){
        if(!used[i]){
            primes.push_back(i);
        }
    }
    for(int i = 1; i <= n; i++){
        cin >> vect[i];
        pos[vect[i]] = i;
    }
    function<void(int, int)> f = [&](int a, int b){
        if(a > b){
            swap(a, b);
        }
        swap(vect[a], vect[b]);
        swap(pos[vect[a]], pos[vect[b]]);
        ans.push_back({a, b});
    };
    for(int i = 1; i <= n; i++){
        while(pos[i] != i){
            int g = lower_bound(primes.begin(), primes.end(), pos[i] - i + 1) - primes.begin();
            while(primes[g] > pos[i] - i + 1)
                g--;
            f(pos[i], pos[i] - primes[g] + 1);
        }
    }
    cout << ans.size() << '\n';
    for(auto [a, b] : ans){
        cout << a << " " << b << '\n';
    }
}