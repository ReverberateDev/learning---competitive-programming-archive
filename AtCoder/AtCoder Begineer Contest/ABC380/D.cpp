#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

char flip(char c){
  if('a'<=c && c<='z'){
    return (c-'a')+'A';
  }
  else{
    return (c-'A')+'a';
  }
}

void solve(){
    string s; cin >> s;
    int q; cin >> q;
    while(q--){
        int k; cin >> k;
        k--;
        int blk = k/s.size();
        int pt = k%s.size();
        if(__builtin_popcountll(blk)%2){
            cout << flip(s[pt]) << " ";
        }
        else{
            cout << s[pt] << " ";
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}