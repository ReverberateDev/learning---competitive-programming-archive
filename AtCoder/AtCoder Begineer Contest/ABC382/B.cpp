#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, d; cin >> n >> d;
    string s; cin >> s;
    for(int i = s.size() - 1; i >= 0 && d; i--){
        if(s[i] =='@'){
            d--;
            s[i] = '.';
        }
    }
    cout << s << '\n';
}