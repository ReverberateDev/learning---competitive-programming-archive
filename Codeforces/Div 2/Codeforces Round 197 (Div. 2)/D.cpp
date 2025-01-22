#include <bits/stdc++.h>
using namespace std;
#define double long double
#define DEBUG 1
#define OUT(x) cerr << (#x) << '=' << (x) << endl

class SegmentTree {
public:
    int n;
    vector<int> tree;
    vector<int> pat;

    SegmentTree(int size, const vector<int>& A) {
        n = size;
        tree.resize(4 * n, 0); // Segment tree array
        pat.resize(4 * n, 0); // XOR/OR pattern array
        build(1, 1, n, A);
    }

    void build(int node, int s, int e, const vector<int>& A) {
        if (s == e) {
            tree[node] = A[s];
            pat[node] = 1; // Base case: leaf nodes alternate starting with OR
        } else {
            int mid = (s + e) / 2;
            build(2 * node, s, mid, A);         // Build left child
            build(2 * node + 1, mid + 1, e, A); // Build right child
            combine(node);
        }
    }

    void combine(int node) {
        pat[node] = pat[2 * node] ^ 1; // Alternate between XOR and OR
        if (pat[2 * node]) {
            tree[node] = tree[2 * node] | tree[2 * node + 1];
        } else {
            tree[node] = tree[2 * node] ^ tree[2 * node + 1];
        }
    }

    void update(int node, int s, int e, int idx, int value) {
        if (s == e) {
            tree[node] = value;
        } else {
            int mid = (s + e) / 2;
            if (idx <= mid) {
                update(2 * node, s, mid, idx, value); // Update left child
            } else {
                update(2 * node + 1, mid + 1, e, idx, value); // Update right child
            }
            combine(node); // Recalculate parent node
        }
    }

    int query() {
        return tree[1]; // Root value represents the result
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    int sz = (1 << n);
    vector<int> A(sz + 1);
    for (int i = 1; i <= sz; i++) {
        cin >> A[i];
    }

    SegmentTree segTree(sz, A);

    while (m--) {
        int a, b;
        cin >> a >> b;
        segTree.update(1, 1, sz, a, b);
        cout << segTree.query() << '\n';
    }

    return 0;
}
