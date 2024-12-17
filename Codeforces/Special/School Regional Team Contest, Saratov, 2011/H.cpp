#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

const int MAXN = 201;

vector<string> getStr(string s){
    vector<string> res;
    int l = (int)s.length();
    for(int i = 0; i < l; i++){
        res.push_back(s.substr(i, 1));
    }
    for(int i = 0; i < l - 1; i++){
        for(int j = i + 1; j < l; j++){
            res.push_back(s.substr(i, 1) + s.substr(j, 1));
        }
    }
    for(int i = 0; i < l - 2; i++){
        for(int j = i + 1; j < l - 1; j++){
            for(int k = j + 1; k < l; k++){
                res.push_back(s.substr(i, 1) + s.substr(j, 1) + s.substr(k, 1));
            }
        }
    }
    for(int i = 0; i < l - 3; i++){
        for(int j = i + 1; j < l - 2; j++){
            for(int k = j + 1; k < l - 1; k++){
                for(int p = k + 1; p < l; p++){
                    res.push_back(s.substr(i, 1) + s.substr(j, 1) + s.substr(k, 1) + s.substr(p, 1));
                }
            }
        }
    }
    return res;
}

map<string, int> mp;
map<int, string> mp2;
int cnt = 0;
vector<int> adjlist[MAXN];
vector<int> xmt, ymt, xused;

int getNum(string s){
    if(mp.find(s) == mp.end()){
        mp[s] = cnt;
        mp2[cnt] = s;
        cnt++;
    }
    return mp[s];
}

bool dfs(int x){
    if(xused[x]){
        return false;
    }
    xused[x] = true;
    for(int y : adjlist[x]){
        if(ymt[y] == -1 || dfs(ymt[y])){
            ymt[y] = x;
            xmt[x]= y;
            return true;
        }
    }
    return false;
}

signed main(){
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        vector<string> tmp = getStr(s);
        for(auto str : tmp){
            int x = getNum(str);
            adjlist[i].push_back(x);
        }
    }

    int k = cnt;
    xmt.assign(n, -1);
    ymt.assign(k, -1);
    for(int v = 0; v < n; v++){
        xused.assign(n, false);
        dfs(v);
    }
    bool ok = true;
    for(int i = 0; i < n; i++){
        if(xmt[i] == -1){
            ok = false;
        }
    }
    if(!ok){
        cout << "-1\n";
    }
    else{
        for(int i = 0; i < n; i++){
            cout << mp2[xmt[i]] << '\n';
        }
    }
}