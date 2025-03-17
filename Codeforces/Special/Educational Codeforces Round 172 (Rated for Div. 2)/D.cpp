#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 0

#ifdef OUTDEBUG
    #define OUT(x) cerr << (#x) << '=' << (x) << endl
    #define OUT2(c) cerr << (#c) << " = {"; for (auto it = (c).begin(); it != (c).end(); ++it) cerr << (it == (c).begin() ? "" : ", ") << *it; cerr << "}" << endl;
#else
    #define OUT(x)
    #define OUT2(c)
#endif

struct range{
    int l, r, idx;
    int ansl, ansr;
    range(int _l, int _r, int _idx): l(_l), r(_r), idx(_idx), ansl(-1), ansr(-1) {}
};

void solve() {
    int n; cin >> n;
    vector<range> ranges(n, range(0, 0, 0));
    for(int i = 0; i < n; i++){
        int l, r; cin >> l >> r;
        ranges[i] = range(l, r, i);
    }
    if(DEBUG){
        cout << "Checkpoint 0\n";
        for(auto &x : ranges){
            cout << x.l << ' ' << x.r << ' ' << x.idx << '\n';
        }
    }
    sort(ranges.begin(), ranges.end(), [](const range &a, const range &b){
        if(a.l == b.l){
            return a.r > b.r;
        }
        return a.l < b.l;
    });
    if(DEBUG){
        cout << "Checkpoint 1\n";
        for(auto &x : ranges){
            cout << x.l << ' ' << x.r << ' ' << x.idx << '\n';
        }
    }
    //calculate right end point
    set<int> right_end;
    for(int i = 0; i < n; i++){
        vector<range*> temp;
        int endi = i;
        while(endi + 1 < n && ranges[endi + 1].l == ranges[i].l && ranges[endi + 1].r == ranges[i].r){
            endi++;
        }
        for(int j = i; j <= endi; j++){
            temp.push_back(&ranges[j]);
        }
        i = endi;
        if(temp.size() > 1){
            right_end.insert(ranges[i].r);
        }
        for(auto &x : temp){
            auto itr = right_end.lower_bound(x->r);
            if(itr == right_end.end()){
                x->ansr = -1;
            }
            else{
                x->ansr = *itr;
            }
        }
        right_end.insert(ranges[i].r);
    }
    sort(ranges.begin(), ranges.end(), [](const range &a, const range &b){
        if(a.r == b.r){
            return a.l < b.l;
        }
        return a.r > b.r;
    });
    if(DEBUG){
        cout << "Checkpoint 2\n";
    }
    //calculate left end point
    set<int> left_end;
    for(int i = 0; i < n; i++){
        vector<range*> temp;
        int endi = i;
        while(endi + 1 < n && ranges[endi + 1].l == ranges[i].l && ranges[endi + 1].r == ranges[i].r){
            endi++;
        }
        for(int j = i; j <= endi; j++){
            temp.push_back(&ranges[j]);
        }
        i = endi;
        if(temp.size() > 1){
            left_end.insert(ranges[i].l);
        }
        for(auto &x : temp){
            auto itr = left_end.upper_bound(x->l);
            if(itr == left_end.begin()){
                x->ansl = -1;
            }
            else{
                x->ansl = *prev(itr);
            }
        }
        left_end.insert(ranges[i].l);
    }
    sort(ranges.begin(), ranges.end(), [](const range &a, const range &b){
        return a.idx < b.idx;
    });
    for(auto &x : ranges){
        if(DEBUG){
            cout << x.l << ' ' << x.r << ' ' << x.idx << ' ' << x.ansl << ' ' << x.ansr << '\n';
        }
        if(x.ansl == -1 || x.ansr == -1){
            cout << "0\n";
        }
        else{
            cout << (abs(x.ansr - x.ansl) + 1) - (abs(x.r - x.l) + 1) << '\n';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
}