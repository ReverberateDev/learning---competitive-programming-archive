#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

const int inf = 1e18;

struct assignment{
    int t, d;
    assignment(int _t, int _d): t(_t), d(_d){

    };
    bool operator<(const assignment &other) const {
        return d < other.d;     
    }
};

void solve(){
    int n, m, q; cin >> n >> m >> q;
    vector<int> t_a(n), d_a(n), t_e(m);
    for(int i = 0; i < n; i++){
        cin >> t_a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> d_a[i];
    }
    for(int i = 0; i < m; i++){  
        cin >> t_e[i];
    }
    vector<assignment> assignments;
    for(int i = 0; i < n; i++){
        assignments.push_back(assignment(t_a[i], d_a[i]));
    }
    sort(assignments.begin(), assignments.end());
    vector<int> pre_t(m + 1, 0);
    for(int i = 1; i <= m; i++){
        pre_t[i] = pre_t[i - 1] + t_e[i - 1];
    }
    vector<int> suf(n + 1);
    int curr = inf;
    suf[n] = curr;
    for(int i = n - 1; i >= 0; i--){
        int t = assignments[i].t, d = assignments[i].d;
        curr = min(d, curr);
        curr -= t;
        suf[i] = curr;
    }
    vector<int> pre(n);
    curr = 0;
    for(int i = 0; i < n; i++){
        int t = assignments[i].t, d = assignments[i].d;
        curr += t;
        if(curr <= d){
            pre[i] = curr;
        }
        else{
            pre[i] = inf;
        }
        if(i != 0 && pre[i - 1] == inf){
            pre[i] = inf;
        }
    }
    vector<pair<int, int>> A, B;
    vector<pair<int, int>> ranges;
    ranges.push_back(make_pair(0, suf[0]));
    for(int i = 0; i < n; i++){
        ranges.push_back(make_pair(pre[i], suf[i + 1]));
    }
    sort(ranges.begin(), ranges.end(), [&](const pair<int, int> &a, const pair<int, int> &b){
        return a.second < b.second;
    });
    for(auto [L, R] : ranges){
        A.push_back(make_pair(R, L - R));
        B.push_back(make_pair(R, L));
        //both have 5, 0
    }
    //5, 5
    for(int i = 1; i < A.size(); i++){
        A[i].second = min(A[i].second, A[i - 1].second);
    }
    for(int i = B.size() - 2; i >= 0; i--){
        B[i] = make_pair(B[i].first, min(B[i].second, B[i + 1].second));
    }
    if(DEBUG){
        cout << "Debugging ranges\n";
        for(auto [L, R] : ranges){
            OUT(L);
            OUT(R);
        }
        cout << "Debugging A\n";
        for(auto [LA, RA] : A){
            OUT(LA);
            OUT(RA);
        }
        cout << "Debugging B\n";
        for(auto [LB, RB] : B){
            OUT(LB);
            OUT(RB);
        }
    }
    function<bool(int, int)> check = [&](int k, int x) -> bool {
        bool res = false;
        auto itr = upper_bound(A.begin(), A.end(), make_pair(x, inf));
        if(itr != A.begin()){
            itr--;
            int idx = itr - A.begin();
            if(A[idx].second <= -pre_t[k]){
                if(k == 2 && DEBUG){
                    OUT(A[idx].second);
                    cout << "Trying to 2\n";
                }
                res = true;
            }
        }
        itr = upper_bound(B.begin(), B.end(), make_pair(x, inf));
        if(itr != B.end()){
            int idx = itr - B.begin();
            if(B[idx].second + pre_t[k] <= x){
                res = true;
            }
        }
        return res;
    };
    while(q--){
        int x; cin >> x;
        int lo = 0, hi = m, ans = -1;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(check(mid, x)){
                lo = mid + 1;
                ans = mid;
            }
            else{
                hi = mid - 1;
            }
        }
        cout << ans << " ";
    }
    cout << '\n';
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
/*
3 4 5
8 100 8 -> time
10 150 20 -> deadline
SORT
8 8 100 -> time
10 20 150 -> deadline
pre
8, 16, 116
suf
2, 12, 50
2 32 1 1
9 200 51 50 10
*/