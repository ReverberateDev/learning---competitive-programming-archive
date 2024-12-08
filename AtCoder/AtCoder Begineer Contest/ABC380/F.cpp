#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, l; cin >> n >> m >> l;
    int s = n + m + l;
    vector<int>vect(s);
    for(int i = 0; i < s; i++){
        cin >>  vect[i];
    }
    vector<int>T(s + 1);
    T[0] = 1;
    for(int i = 1; i <= s; i++){
        T[i] = T[i - 1] * 3;
    }
    auto get = [&](int x, int i){
        return x / T[i] % 3;
    };
    vector<vector<bool>>memo(2, vector<bool>(T[s], false));
    vector<vector<bool>>used(2, vector<bool>(T[s], false));
    auto dp = [&](auto dp, int t, int bmask){
        if(used[t][bmask]){
            return memo[t][bmask];
        }
        for(int i = 0; i < s; i++){
            if(get(bmask, i) == t){
                int bmask2 = bmask - T[i] * t + T[i] * 2;
                if(!dp(dp, t ^ 1, bmask2)){
                    memo[t][bmask] = true;
                }
                for(int j = 0; j < s; j++){
                    if(get(bmask, j) == 2 && vect[j] < vect[i]){
                        int bmask3 = bmask2 - T[j] * 2 + T[j] * t;
                        if(!dp(dp, t ^ 1, bmask3)){
                            memo[t][bmask] = true;
                        }
                    }
                }
            }
        }
        used[t][bmask] = true;
        return memo[t][bmask];
    };
    int bmask = 0;
    for(int i = n; i < n + m; i++){
        bmask += T[i];
    }
    for(int i = n + m; i < s; i++){
        bmask += T[i] * 2;
    }
    if (dp(dp, 0, bmask)){
        cout << "Takahashi" << endl;
    }
    else {
        cout << "Aoki" << endl;
    }
}