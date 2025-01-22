#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

const int inf = 1e18;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<map<int, int>> a(n);
    for(int i = 0; i < n; i++){
        a[i][-1] = inf;
        for(int j = 0; j < n; j++){
            int tmp; cin >> tmp;
            tmp--;
            a[i][tmp] = j;
        }
    }
    map<int, int> b;
    b[-1] = inf;
    for(int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        tmp--;
        b[tmp] = i;
    }

    vector<int> curr(2, -1);
    vector<int> ans(n, -1);
    for(int i = 0; i < n; i++){
        curr.push_back(i);
        sort(curr.begin(), curr.end(), [&](const int fst, const int snd){
            return b[fst] < b[snd];
        });
        curr.pop_back();
        for(int j = 0; j < n; j++){
            //see if we can give our curr cards to this dude
            if(curr[0] == j){
                if(a[j][curr[1]] < a[j][ans[j]]){
                    ans[j] = curr[1];
                }
            }
            else{
                if(a[j][curr[0]] < a[j][ans[j]]){
                    ans[j] = curr[0];
                }
            }
        }
    }
    for(auto i : ans){
        cout << i + 1<< " ";
    }
    //1 - 1
    //2 - 1
    //3 - 3
    //4 - 3
}

