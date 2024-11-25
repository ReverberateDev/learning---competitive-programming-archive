#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

bool check(int n){
    unordered_map<int, int>mp;
    while(n){
        mp[n % 10]++;
        n /= 10;
    }
    if(mp[1] != 1){
        return false;
    }
    if(mp[2] != 2){
        return false;
    }
    if(mp[3] != 3){
        return false;
    }
    return true;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    if(check(n)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}