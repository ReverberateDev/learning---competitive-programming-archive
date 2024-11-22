#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N; cin >> N;
    vector<int>A(N);
    for(auto &i : A){
        cin >> i;
    }
    unordered_map<int, int>mp;
    for(int i = 0; i < N; i++){
        if(mp.find(A[i]) == mp.end()){
            cout << "-1 ";
        }
        else{
            cout << mp[A[i]] << " ";
        }
        mp[A[i]] = i + 1;
    }
}