#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Ordered multiset with policy-based data structure
template <typename T>
using ordered_multiset = tree<
    pair<T, int>,  // Store a pair (value, index) to handle duplicates
    null_type, 
    less<pair<T, int>>,  // Maintain order
    rb_tree_tag, 
    tree_order_statistics_node_update>;

int main() {
    ordered_multiset<int> ms;
    int idx = 0;

    // Insert elements
    ms.insert({10, idx++});
    ms.insert({20, idx++});
    ms.insert({10, idx++}); // Another 10 (multiset behavior)
    ms.insert({30, idx++});
    
    // Find number of elements less than 20
    cout << "Elements less than 20: " << ms.order_of_key({20, 0}) << "\n";

    // Find the 2nd smallest element (0-based index)
    cout << "2nd smallest element: " << (*ms.find_by_order(1)).first << "\n";

    // Erase one occurrence of 10
    ms.erase(ms.lower_bound({10, 0}));

    cout << "Elements less than 20 after deletion: " << ms.order_of_key({20, 0}) << "\n";

    return 0;
}