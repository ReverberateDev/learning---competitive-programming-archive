#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

const int inf = 1e18;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int r, c;
vector<vector<int>> mat, dist;

struct node{
    int i, j, dist;
    node(int _i, int _j, int _dist) {
        i = _i, j = _j, dist = _dist;
    }
    bool is_valid(){
        if(i < 0 || i >= r){
            return false;
        }
        if(j < 0 || j >= c){
            return false;
        }
        return true;
    }
    vector<node> nxt(){
        vector<node> res;
        for(int k = 0; k < 2; k++){
            int cost = (mat[i][j] != k);
            for(int l = 2 * k; l < (k + 1) * 2; l++){
                int ni = i + dx[l], nj = j + dy[l];
                node tmp = node(ni, nj, dist + cost);
                if(tmp.is_valid()){
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> c;
    mat.resize(r, vector<int>(c));
    dist.resize(r, vector<int>(c, inf));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> mat[i][j];
        }
    }

    deque<node> q;
    node tmp = node(0, 0, 0);
    q.push_front(tmp);
    dist[0][0] = 0;

    while(!q.empty()){
        node curr = q.front();
        q.pop_front();
        vector<node> tmp = curr.nxt();
        for(node tmp2 : tmp){
            if(tmp2.dist < dist[tmp2.i][tmp2.j]){
                dist[tmp2.i][tmp2.j] = tmp2.dist;
                int cost = tmp2.dist - curr.dist;
                if(cost == 1){
                    q.push_back(tmp2);
                }
                else{
                    q.push_front(tmp2);
                }
            }
        }
    }
    cout << dist[r - 1][c - 1];
}