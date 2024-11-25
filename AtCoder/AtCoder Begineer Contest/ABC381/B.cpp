#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

bool check(string s){
    int n = s.length();
    if(n % 2 != 0){
        return false;
    }
    for(int i = 1; i <= n / 2; i++){
        int a = 2 * i;
        int b = a - 1;
        a--, b--;
        if(s[a] != s[b]){
            return false;
        }
    }
    unordered_map<char, int>mp;
    for(int i = 0; i < n; i++){
        mp[s[i]]++;
    }
    for(auto it = mp.begin(); it != mp.end(); it++){
        if(it->second != 2){
            return false;
        }
    }
    return true;
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    if(check(s)){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
}