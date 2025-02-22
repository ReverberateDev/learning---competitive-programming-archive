#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // Adjacency list (vector of vectors)
vector<bool> visited;
vector<int> topo_order; // To store the topological sort

// DFS function to compute topological sort
void dfs(int node) {
    visited[node] = true;
    for (auto v : adj[node]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
    topo_order.push_back(node); // Push the node after exploring its neighbors
}

int main() {
    int n, m;
    cin >> n >> m; // n = number of nodes, m = number of edges
    
    adj.resize(n + 1); // Resize the adjacency list for n nodes
    visited.resize(n + 1, false); // Resize the visited array

    // Initialize the adjacency list
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Directed edge from u to v
    }
    
    // Perform DFS for all nodes
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Output the topological order (reverse the order because we add nodes post DFS)
    reverse(topo_order.begin(), topo_order.end());
    cout << "Topological Sort: ";
    for (int node : topo_order) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}
