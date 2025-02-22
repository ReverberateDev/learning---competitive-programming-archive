#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct SegmentTree {
    int n;
    vector<ll> mn, mx, sum, add_val, set_val;
    vector<bool> lset;
    
    SegmentTree(int size, int A[] = NULL) {
        n = size;
        mn.assign(4 * n, 0);
        mx.assign(4 * n, 0);
        sum.assign(4 * n, 0);
        add_val.assign(4 * n, 0);
        set_val.assign(4 * n, 0);
        lset.assign(4 * n, false);
        if (A) build(1, 0, n - 1, A);
    }
    
    void build(int node, int s, int e, int A[]) {
        if (s == e) {
            mn[node] = mx[node] = sum[node] = A[s];
            return;
        }
        int m = (s + e) / 2;
        build(node * 2, s, m, A);
        build(node * 2 + 1, m + 1, e, A);
        combine(node);
    }
    
    void apply_set(int node, int s, int e, ll v) {
        lset[node] = true;
        set_val[node] = v;
        add_val[node] = 0;
        mn[node] = mx[node] = v;
        sum[node] = v * (e - s + 1);
    }
    
    void apply_add(int node, int s, int e, ll v) {
        if (lset[node]) { apply_set(node, s, e, set_val[node] + v); return; }
        mn[node] += v;
        mx[node] += v;
        sum[node] += v * (e - s + 1);
        add_val[node] += v;
    }
    
    void propagate(int node, int s, int e) {
        if (s == e) return;
        int mid = (s + e) / 2;
        if (lset[node]) {
            apply_set(node * 2, s, mid, set_val[node]);
            apply_set(node * 2 + 1, mid + 1, e, set_val[node]);
            lset[node] = false;
        }
        if (add_val[node] != 0) {
            apply_add(node * 2, s, mid, add_val[node]);
            apply_add(node * 2 + 1, mid + 1, e, add_val[node]);
            add_val[node] = 0;
        }
    }
    
    void combine(int node) {
        mn[node] = min(mn[node * 2], mn[node * 2 + 1]);
        mx[node] = max(mx[node * 2], mx[node * 2 + 1]);
        sum[node] = sum[node * 2] + sum[node * 2 + 1];
    }
    
    void range_add(int node, int s, int e, int x, int y, ll v) {
        if (x > e || y < s) return;
        if (x <= s && e <= y) { apply_add(node, s, e, v); return; }
        propagate(node, s, e);
        int m = (s + e) / 2;
        range_add(node * 2, s, m, x, y, v);
        range_add(node * 2 + 1, m + 1, e, x, y, v);
        combine(node);
    }
    
    void range_set(int node, int s, int e, int x, int y, ll v) {
        if (x > e || y < s) return;
        if (x <= s && e <= y) { apply_set(node, s, e, v); return; }
        propagate(node, s, e);
        int m = (s + e) / 2;
        range_set(node * 2, s, m, x, y, v);
        range_set(node * 2 + 1, m + 1, e, x, y, v);
        combine(node);
    }
    
    ll range_sum(int node, int s, int e, int x, int y) {
        if (x > e || y < s) return 0;
        if (x <= s && e <= y) return sum[node];
        propagate(node, s, e);
        int m = (s + e) / 2;
        return range_sum(node * 2, s, m, x, y) + range_sum(node * 2 + 1, m + 1, e, x, y);
    }
    
    ll range_min(int node, int s, int e, int x, int y) {
        if (x > e || y < s) return LLONG_MAX;
        if (x <= s && e <= y) return mn[node];
        propagate(node, s, e);
        int m = (s + e) / 2;
        return min(range_min(node * 2, s, m, x, y), range_min(node * 2 + 1, m + 1, e, x, y));
    }
    
    ll range_max(int node, int s, int e, int x, int y) {
        if (x > e || y < s) return LLONG_MIN;
        if (x <= s && e <= y) return mx[node];
        propagate(node, s, e);
        int m = (s + e) / 2;
        return max(range_max(node * 2, s, m, x, y), range_max(node * 2 + 1, m + 1, e, x, y));
    }
    
    void add(int x, int y, ll v) { range_add(1, 0, n - 1, x, y, v); }
    void set(int x, int y, ll v) { range_set(1, 0, n - 1, x, y, v); }
    ll sum_query(int x, int y) { return range_sum(1, 0, n - 1, x, y); }
    ll min_query(int x, int y) { return range_min(1, 0, n - 1, x, y); }
    ll max_query(int x, int y) { return range_max(1, 0, n - 1, x, y); }
};

int main() {
    int n = 10;
    int A[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    SegmentTree seg(n, A);
    cout << seg.sum_query(0, 9) << "\n";
    seg.add(0, 4, 3);
    cout << seg.sum_query(0, 9) << "\n";
    seg.set(2, 6, 5);
    cout << seg.min_query(0, 9) << "\n";
    cout << seg.max_query(0, 9) << "\n";
}
