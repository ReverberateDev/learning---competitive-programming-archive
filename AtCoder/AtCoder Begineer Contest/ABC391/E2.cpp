#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

const int inf = 1e18;
const int MAXN = 2e5; // Adjust based on input size constraints

struct TernarySegmentTree {
    vector<int> tree, memo;
    int n;
    
    TernarySegmentTree(const vector<int>& V) {
        n = V.size();
        tree.resize(3 * n, 0);
        memo.assign(3 * n, -1);
        build(1, 0, n - 1, V);
    }
    
    void build(int node, int s, int e, const vector<int>& V) {
        if (s == e) {
            tree[node] = V[s];
            return;
        }
        int mid1 = s + (e - s) / 3;
        int mid2 = s + 2 * (e - s) / 3;
        
        build(3 * node + 1, s, mid1, V);
        build(3 * node + 2, mid1 + 1, mid2, V);
        build(3 * node + 3, mid2 + 1, e, V);
        
        combine(node);
    }
    
    void combine(int node) {
        int ones = (tree[3 * node + 1] == 1) + (tree[3 * node + 2] == 1) + (tree[3 * node + 3] == 1);
        int zeros = 3 - ones;
        tree[node] = ones > zeros ? 1 : 0;
    }
    
    int dp(int node, int s, int e) {
        if (s == e) return 1;
        if (memo[node] != -1) return memo[node];
        
        int want = tree[node] ^ 1;
        int res = inf;
        
        for (int bmask = 0; bmask < 8; bmask++) {
            if (check(bmask, want)) {
                res = min(res, cost(node, s, e, bmask));
            }
            if(DEBUG){
                cout << "New res\n";
                cout << res << '\n';
            }
        }
        return memo[node] = res;
    }
    
    int cost(int node, int s, int e, int bmask) {
        int res = 0;
        int mid1 = s + (e - s) / 3;
        int mid2 = s + 2 * (e - s) / 3;

        for (int i = 0; i < 3; i++) {
            int child = 3 * node + 1 + i;
            int cs = (i == 0) ? s : (i == 1) ? mid1 + 1 : mid2 + 1;
            int ce = (i == 0) ? mid1 : (i == 1) ? mid2 : e;

            if (bmask & (1 << i)) {  // Convert to 1
                if (tree[child] == 1) continue;
                res += dp(child, cs, ce);
            } else {  // Convert to 0
                if (tree[child] == 0) continue;
                res += dp(child, cs, ce);
            }
        }
        return res;
    }

    
    bool check(int k, int val) {
        int ones = __builtin_popcount(k & 7); // Only consider last 3 bits
        return (ones > 3 - ones) == val;
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    n = pow(3, n);
    string s;
    cin >> s;
    
    vector<int> V(n);
    for (int i = 0; i < n; i++) {
        V[i] = s[i] - '0';
    }
    
    TernarySegmentTree tree(V);
    cout << tree.dp(1, 0, n - 1);
}
