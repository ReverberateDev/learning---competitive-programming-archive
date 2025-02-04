// C++ program to find topological sort.
#include <bits/stdc++.h>
using namespace std;

// Function to perform DFS and topological sorting
void topologicalSortUtil(int v, vector<vector<int> >& adj,
    vector<bool>& visited, stack<int>& st) {
        
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all adjacent vertices
    for (int i : adj[v]) {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, st);
    }

    // Push current vertex to stack which stores the result
    st.push(v);
}

// Function to perform Topological Sort
vector<int> topologicalSort(vector<vector<int>>& adj) {
    int V = adj.size();
    
    // Stack to store the result
    stack<int> st; 
    vector<bool> visited(V, false);

    // Call the recursive helper function to store
    // Topological Sort starting from all vertices one by
    // one
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, st);
    }
    
    vector<int> ans;

    // append contents of stack
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    
    return ans;
}

int main() {

    // Graph represented as an adjacency list
    vector<vector<int>> adj = {{1}, {2}, {}, {1, 2}};

    vector<int> ans = topologicalSort(adj);
    
    for (auto node: ans) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}