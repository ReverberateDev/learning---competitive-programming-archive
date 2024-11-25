#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

bool check(string s){
    int n = s.length();
    if(n % 2 == 0){
        return false;
    }
    int mid = ((n + 1) / 2) - 1;
    for(int i = 0; i < mid; i++){
        if(s[i] != '1'){
            return false;
        }
    }
    if(s[mid] != '/'){
        return false;
    }
    for(int i = mid + 1; i < n; i++){
        if(s[i] != '2'){
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
    int n;
    cin >> n >> s;
    if(check(s)){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
}