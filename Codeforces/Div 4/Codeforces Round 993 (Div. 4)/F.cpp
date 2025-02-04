#include <bits/stdc++.h>
using namespace std;
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

/*
X = totA * totB  - (A[i] * totB + B[j] * totA - A[i] * B[j])
X = totA * totB - A[i] * totB - B[j] * totA + A[i] * B[j]
X = totB * (totA - A[i]) - B[j] * (totA - A[i])
X = (totB - B[j]) * (totA - A[i])
X = -8
2 and 4
4 and 2
*/

void solve(){
    int n, m, q; cin >> n >> m >> q;
    vector<int> a(n), b(m);
    int totA = 0, totB = 0;
    unordered_map<int, bool> A, B;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        totA += a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
        totB += b[i];
    }
    for(int i = 0; i < n; i++){
        A[totA - a[i]] = true;
    }
    for(int i = 0; i < m; i++){
        B[totB - b[i]] = true;
    }
    if(DEBUG){
        cout << "Outputting A\n";
        for(auto [f, s] : A){
            cout << f << " " << s << '\n';
        }
        cout << "Outputting B\n";
        for(auto [f1, s1] : B){
            cout << f1 << " " << s1 << '\n';
        }
    }
    while(q--){
        int x; cin >> x;
        bool flg = true;
        if(x < 0){
            for(int p = 1; p <= sqrt(abs(x)); p++){
                if(x % p == 0){
                    int q = abs(x) / p;
                    if(A.find(-p) != A.end() && B.find(q) != B.end()){
                        flg = false;
                        break;
                    }
                    if(A.find(p) != A.end() && B.find(-q) != B.end()){
                        flg = false;
                        break;
                    }
                    swap(p, q);
                    if(A.find(-p) != A.end() && B.find(q) != B.end()){
                        flg = false;
                        break;
                    }
                    if(A.find(p) != A.end() && B.find(-q) != B.end()){
                        flg = false;
                        break;
                    }
                    swap(p, q);
                }
            }
        }
        else{
            for(int p = 1; p <= sqrt(x); p++){
                if(x % p == 0){
                    int q = x / p;
                    if(A.find(-p) != A.end() && B.find(-q) != B.end()){
                        flg = false;
                        break;
                    }
                    if(A.find(p) != A.end() && B.find(q) != B.end()){
                        flg = false;
                        break;
                    }
                    swap(p, q);
                    if(A.find(-p) != A.end() && B.find(-q) != B.end()){
                        flg = false;
                        break;
                    }
                    if(A.find(p) != A.end() && B.find(q) != B.end()){
                        flg = false;
                        break;
                    }
                    swap(p, q);
                }
            }
        }
        if(flg){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt; tt = 1;
    while(tt--){
        solve();
    }
}