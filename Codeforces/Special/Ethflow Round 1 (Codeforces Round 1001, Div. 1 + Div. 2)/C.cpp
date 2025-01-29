#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

int ans;

vector<int> diff(vector<int> arr){
    vector<int> res;
    for(int i = 1; i < arr.size(); i++){
        res.push_back(arr[i] - arr[i - 1]);
    }
    return res;
}

void build(vector<int> arr, int ptr){
    if(arr.size() == 1){
        return;
    }
    auto normal = arr;
    reverse(arr.begin(), arr.end());
    auto reversed = arr;
    auto dnormal = diff(normal);
    auto dreversed = diff(reversed);
    int a = accumulate(dnormal.begin(), dnormal.end(), 0);
    int b = accumulate(dreversed.begin(), dreversed.end(), 0);
    ans = max(ans, max(a, b));
    if(a > b){
        build(dnormal, ptr + 1);
    }
    else{
        build(dreversed, ptr + 1);
    }
}

void solve(){
    int n; cin >> n;
    int ans = 0;
    deque<int> vect;
    for(int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        vect.push_back(tmp);
        ans += tmp;
    }
    while(vect.size() > 1){
        int k = vect.size();
        int a = 0, b = 0;
        for(int i = 1; i < k; i++){
            a += vect[i] - vect[i - 1];

        }
        b = -a;
        if(b > a){
            for(int i = 1; i < k; i++){
                vect.push_back(-(vect[i] - vect[i - 1]));
            }
        }
        else{
            for(int i = 1; i < k; i++){
                vect.push_back(vect[i] - vect[i - 1]);
            }
        }
        while(k--){
            vect.pop_front();
        }
        ans = max(ans, max(a, b));
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--){
        solve();
    }
}