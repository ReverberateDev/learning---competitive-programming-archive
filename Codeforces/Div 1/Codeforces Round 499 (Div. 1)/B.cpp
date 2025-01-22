#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

int query(int x){
    cout << x << '\n';
    fflush(stdout);
    int y; cin >> y;
    if(y == 0){
        exit(0);
    }
    return y;
}

signed main(){
    int m, n; cin >> m >> n;
    vector<int> pat(n);
    for(int i = 0; i < n; i++){
        pat[i] = query(1) == 1 ? 1 : -1;
    }
    int lo = 1, hi = m, ans = -1, cnt = 0;
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        int y = query(mid) * pat[cnt % n];
        if(y == 1){
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
        cnt++;
    }
    cout << ans;
}