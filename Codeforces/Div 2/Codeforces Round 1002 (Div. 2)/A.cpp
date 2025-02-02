#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

void solve(){
    int n; cin >> n;
    set<int> st;
    map<int, int> A;
    for(int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        A[tmp]++;
        st.insert(tmp);
    }
    map<int, int> B;
    for(int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        B[tmp]++;
        st.insert(tmp);
    }
    if(A.size() >= 3 || B.size() >= 3){
        cout << "YES\n";
    }
    else if(A.size() == 2 && B.size() == 2){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt; cin >> tt;
    while(tt--){
        solve();
    }

}