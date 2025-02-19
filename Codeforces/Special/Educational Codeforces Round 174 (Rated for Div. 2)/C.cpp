#include <bits/stdc++.h>
using namespace std;
#define double long double
#define int long long
#ifdef DEBUG
    #define OUT(x) cerr << (#x) << '=' << (x) << endl
    #define OUT2(c) cerr << (#c) << " = {"; for (auto it = (c).begin(); it != (c).end(); ++it) cerr << (it == (c).begin() ? "" : ", ") << *it; cerr << "}" << endl;
#else
    #define OUT(x)
    #define OUT2(c)
#endif

#define MOD 998244353
const int MAXP = 2e5 + 5;

vector<int> pow2(MAXP), invpow2(MAXP);

void precompute(){
    //precompute
    pow2[0] = 1;
    for(int i = 1; i < MAXP; i++){
        pow2[i] = (pow2[i - 1] * 2ll) % MOD;
    }
    int inv2 = 499122177ll;
    invpow2[0] = 1;
    for(int i = 1; i < MAXP; i++){
        invpow2[i] = (invpow2[i - 1] * inv2) % MOD;
    }
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int cnt1 = 0, cnt2 = 0, sum = 0, ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 1){
            cnt1++;
            sum = (sum + invpow2[cnt2]) % MOD;
        }
        else if(a[i] == 2){
            cnt2++;
        }
        else{
            int add = ((pow2[cnt2] * sum) % MOD - cnt1 + MOD) % MOD;
            ans = (ans + add) % MOD;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    precompute();
    while (tt--) {
        solve();
    }
}

/*
last character = 3
all other characters must be 1 or 2
last character = 2
all other characters must be 1
last character = 1
no solution

first character = 3
no solutions
first character = 2
all other characters can be 3
first character = 1
all other characters can be 2 or 3

i.e. the last character must be the largest
the first character must be the smallest

try for all combinations of first and last characters

1, 1
no solution
1, 2
no solution
1, 3***
all characters must be 2
2, 1
no solution
2, 2
no solution
2, 3
no solution
3, 1
no solution
3, 2
no solution
3, 3
no solution

for each 1, we locate all the 3s infront of it
each of these 3s will have an increasing number of 2s infront of it
e.g. 4, 7, 8, 12
if we pass by a 2?
3, 6, 7, 11
we can actually just -k for all of them right? how can we do this efficiently
*/