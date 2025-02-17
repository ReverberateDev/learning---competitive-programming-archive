#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

#ifdef DEBUG
    #define OUT(x) cerr << (#x) << '=' << (x) << endl
    #define OUT2(c) cerr << (#c) << " = {"; for (auto it = (c).begin(); it != (c).end(); ++it) cerr << (it == (c).begin() ? "" : ", ") << *it; cerr << "}" << endl;
#else
    #define OUT(x)
    #define OUT2(c)
#endif

const int inf = 1e18;

void solve() {
    int n; cin >> n;
    vector<int> vect(n + 1), pre(n + 1, 0), suf(n + 2, 0);
    for(int i = 1; i <= n; i++){
        cin >> vect[i];
    }
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + max(0ll, vect[i]);
    }
    for(int i = n; i >= 1; i--){
        suf[i] = suf[i + 1] + max(0ll, -1ll * vect[i]);
    }
    int ans = max(pre[n], suf[1]);
    for(int i = 1; i < n; i++){
        ans = max(ans, pre[i] + suf[i + 1]);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }

}

/*
In theory, we want to get all of the coins, but we can only get some of them

while the right end is negative, eat the right end
while the left end is postitive, eat the left end

right end will be postitive
left end will be negative

-10 -3 -17 inf -inf 1 19 20
something like this
eating the left or right end will be our final move

all negatives and positives can be groups together
we will be left with a string of alternating negatives and positives
*/