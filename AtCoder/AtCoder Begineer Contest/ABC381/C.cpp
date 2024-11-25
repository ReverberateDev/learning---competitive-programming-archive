#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<pair<int, int>>vect;
    pair<int, int>curr = {-1, 0};
    unordered_map<char, int>mp;
    mp['/'] = 0;
    mp['1'] = 1;
    mp['2'] = 2;
    //0 -> /, 1 -> 1, 2 -> 2
    for(int i = 0; i < n; i++){
        int key = mp[s[i]];
        if(key == curr.first){
            curr.second++;
        }
        else{
            if(curr.first == -1){
                curr.first = key;
                curr.second++;
            }
            else{
                vect.push_back(curr);
                curr.first = key;
                curr.second = 1;
            }
        }
    }
    vect.push_back(curr);
    if(DEBUG){
        for(auto [a, b] : vect){
            cout << a << " " << b;
            cout << '\n';
        }
    }
    int ans = 0;
    for(int i = 1; i < vect.size() - 1; i++){
        if(vect[i - 1].first == 1 && vect[i].first == 0 && vect[i + 1].first == 2 && vect[i].second == 1){
            ans = max(ans, min(vect[i - 1].second, vect[i + 1].second));
        }
    }
    cout << (ans * 2) + 1;
}