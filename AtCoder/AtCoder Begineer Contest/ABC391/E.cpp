#include <bits/stdc++.h>
using namespace std;
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

const int inf = 1e18;

bool check(int k, int val){
    int ones = 0, zeros = 0;
    for(int i = 0; i < 3; i++){
        if(k & (1 << i)){
            ones++;
        }
        else{
            zeros++;
        }
    }
    int final = -1;
    if(ones > zeros){
        final = 1;
    }
    else{
        final = 0;
    }
    return final == val;
}

struct node{
    int s, e, val, memo;
    node *ln, *mn, *rn;
    node(int _s, int _e, vector<int> V): s(_s), e(_e), val(0), memo(-1), ln(NULL), mn(NULL), rn(NULL){
        if(s == e){
            val = V[s];
        }
        else{
            int mid1 = s + (e - s) / 3;
            int mid2 = s + 2 * (e - s) / 3;
            ln = new node(s, mid1, V);
            mn = new node(mid1 + 1, mid2, V);
            rn = new node(mid2 + 1, e, V);
            combine();
        }
    };
    void combine(){
        int ones = 0, zeros = 0;
        if(ln->val == 0){
            zeros++;
        }
        else{
            ones++;
        }
        if(mn->val == 0){
            zeros++;
        }
        else{
            ones++;
        }
        if(rn->val == 0){
            zeros++;
        }
        else{
            ones++;
        }
        if(ones > zeros){
            val = 1;
        }
        else{
            val = 0;
        }
    }
    int dp(){
        if(s == e){
            return 1;
        }
        int want = val ^ 1;
        if(memo != -1){
            return memo;
        }
        int res = inf;
        for(int bmask = 0; bmask < (1 << 3); bmask++){
            if(check(bmask, want)){
                res = min(res, cost(bmask));
            }
        }
        return memo = res;
    }
    int cost(int bmask){
        int res = 0;
        for(int i = 0; i < 3; i++){
            if(bmask & (1 << i)){
                //make it 1
                if(i == 0){
                    if(ln->val == 1){
                        continue;
                    }
                    res += ln->dp();
                }
                else if(i == 1){
                    if(mn->val == 1){
                        continue;
                    }
                    res += mn->dp();
                }
                else{
                    if(rn->val == 1){
                        continue;
                    }
                    res += rn->dp();
                }
            }
            else{
                //make it 0
                if(i == 0){
                    if(ln->val == 0){
                        continue;
                    }
                    res += ln->dp();
                }
                else if(i == 1){
                    if(mn->val == 0){
                        continue;
                    }
                    res += mn->dp();
                }
                else{
                    if(rn->val == 0){
                        continue;
                    }
                    res += rn->dp();
                }
            }
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    vector<int> V;
    for(auto c : s){
        V.push_back((int)(c - '0'));
    }
    node tree(0, s.length() - 1, V);
    cout << tree.dp();
}