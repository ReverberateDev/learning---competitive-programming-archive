#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

int n, m, k;
unordered_map<int, bool> special;

struct dsu{
    vector<int> parents;
    vector<int> sizes;
    vector<int> special_sizes;
    dsu(int size): parents(size), sizes(size, 1), special_sizes(size, 0){
        iota(parents.begin(), parents.end(), 0);
        for(int i = 1; i < size; i++){
            special_sizes[i] = special[i];
        }
    }
    int find(int x){
        return parents[x] == x ? x : (parents[x] = find(parents[x]));
    }
    bool unite(int x, int y){
        int x_root = find(x);
        int y_root = find(y);
        if(x_root == y_root){
            return false;
        }
        if(sizes[x_root] < sizes[y_root]){
            swap(x_root, y_root);
        }
        sizes[x_root] += sizes[y_root];
        special_sizes[x_root] += special_sizes[y_root];
        parents[y_root] = x_root;
        return special_sizes[x_root] == k;
    }
    bool connected(int x, int y){
        return find(x) == find(y);
    }
};

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++){
        int tmp; cin >> tmp;
        special[tmp] = true;
    }
    dsu st(n + 1);
    vector<array<int, 3>> edges;
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    sort(edges.begin(), edges.end(), [&](const array<int, 3> a, const array<int, 3> b){
        return a[2] < b[2];
    });
    for(auto [a, b, c] : edges){
        if(!st.connected(a, b)){
            if(st.unite(a, b)){ 
                for(int i = 0; i < k; i++){
                    cout << c << " ";
                }
                return 0;
            }
        }
    }
}