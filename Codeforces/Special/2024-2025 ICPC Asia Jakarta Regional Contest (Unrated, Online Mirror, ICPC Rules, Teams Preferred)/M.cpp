#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

//Editorial
// '/' mirror k = 0
//N: 0, E: 1, S: 2, W: 3
// N <-> E
// S <-> W
// '\' mirror k = 1
// N <-> W
// S <-> E

int nxt(int dir, int k){
    if(k){
        switch(dir){
            case 0:
                return 3;
            case 1:
                return 2;
            case 2:
                return 1;
            case 3:
                return 0;
        }
    }
    else{
        switch(dir){
            case 0:
                return 1;
            case 1:
                return 0;
            case 2:
                return 3;
            case 3:
                return 2;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int R, C; cin >> R >> C;
    vector<string> grid(R);
    for(int i = 0; i < R; i++){
        cin >> grid[i];
    }
    vector<string> output;
    vector<pair<int, int>> slocs;
    vector<int> sdirs;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    //North
    for(int i = 0; i < C; i++){
        output.push_back("N" + to_string(i + 1));
        slocs.push_back({0, i});
        sdirs.push_back(2);
    }
    //South
    for(int i = 0; i < C; i++){
        output.push_back("S" + to_string(i + 1));
        slocs.push_back({R - 1, i});
        sdirs.push_back(0);
    }
    //East
    for(int i = 0; i < R; i++){
        output.push_back("E" + to_string(i + 1));
        slocs.push_back({i, C - 1});
        sdirs.push_back(3);
    }
    //West
    for(int i = 0; i < R; i++){
        output.push_back("W" + to_string(i + 1));
        slocs.push_back({i, 0});
        sdirs.push_back(1);
    }

    int nmirrors = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(grid[i][j] == '\\' || grid[i][j] == '/'){
                nmirrors++;
            }
        }
    }
    vector<string>ans;
    for(int idx = 0; idx < (int)output.size(); idx++){
        auto [r, c] = slocs[idx];
        int dir = sdirs[idx];
        bitset<200 * 200> bset;
        while(true){
            if(r < 0 || r >= R || c < 0 || c >= C){
                break;
            }
            if(grid[r][c] == '/'){
                bset[C * r + c] = 1;
                dir = nxt(dir, 0);
            }
            if(grid[r][c] == '\\'){
                bset[C * r + c] = 1;
                dir = nxt(dir, 1);
            }
            r += dx[dir];
            c += dy[dir];
        }
        if(bset.count() == nmirrors){
            ans.push_back(output[idx]);
        }
    }
    cout << ans.size() << '\n';
    while(!ans.empty()){
        cout << ans.back() << " ";
        ans.pop_back();
    }
}