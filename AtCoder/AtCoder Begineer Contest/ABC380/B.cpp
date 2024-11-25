#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

#define DEBUG 1

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    int curr = 0;
    for(int i = 1; i < s.length(); i++){
        if(s[i] == '-'){
            curr++;
        }
        else{
            cout << curr << " ";
            curr = 0;
        }
    }
}