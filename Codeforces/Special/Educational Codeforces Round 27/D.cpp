#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ans = 0;
    vector<int> vect;
    int cnt = 0;
    int cur;
    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        switch(t){
            case 1:
                cin >> cur;
                while(!vect.empty() && vect.back() < cur){
                    vect.pop_back();
                    ans++;
                }
                break;
            case 2:
                ans += cnt;
                cnt = 0;
                break;
            case 3:
                int temp; cin >> temp;
                if(temp < cur){
                    ans++;
                }
                else{
                    while(!vect.empty() && vect.back() <= temp){
                        vect.pop_back();
                    }
                    vect.push_back(temp);
                }
                break;
            case 4:
                cnt = 0;
                break;
            case 5:
                vect.clear();
                break;
            case 6:
                cnt++;
                break;
        }
    }
    cout << ans << '\n';
}