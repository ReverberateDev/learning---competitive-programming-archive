#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

#define DEBUG 0

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N; cin >> N;
    vector<int>A(N);
    for(auto &i : A){
        cin >> i;
    }
    vector<pair<int, int>>segments;
    pair<int, int>curr =     {-1, -1};
    for(int i = 0; i < (int)A.size(); i++){
        if(A[i] == curr.first){
            curr.second++;
        }
        else{
            if(curr.first != -1){
                segments.push_back(curr);
            }
            curr.first = A[i];
            curr.second = 1;
        }
    }
    segments.push_back(curr);
    if(DEBUG){
        cout << "Outputting segments\n";
        for(auto [a, b] : segments){
            cout << a << " " << b << '\n';
        }
    }
    deque<pair<int, int>>dq;
    map<int, int>mp;

    int n = segments.size();
    int left = 0, right = 0, ans = 0;
    //Conditions to add
    //Number does not exist
    //Value is not 1
    //Value is 3 or more but last segment is 2
    int monkeys = 0;
    while(left < n && right < n){
        while(right < n){
            bool add = false;
            if(mp[segments[right].first] == 0){
                if(DEBUG){
                    cout << "Segment " << right << " passed test 1\n";
                    cout << "Add value: " << add << '\n';
                }
                if(segments[right].second == 2 && monkeys <= 1){
                    if(DEBUG){
                        cout << "Segment " << right << " passed test 2\n";
                    }
                    add = true;
                }
                if(segments[right].second > 2 && (dq.size() <= 1 || dq.back().second == 2 )){
                    if(DEBUG){
                        cout << "Segment " << right << " passed test 3\n";
                    }
                    add = true;
                }
            }
            if(add == true){
                if(segments[right].second > 2){
                    monkeys++;
                }
                dq.push_back(segments[right]);
                mp[segments[right].first] = 1;
                if(DEBUG){
                    cout << "Adding segment " << right << '\n';
                }
                right++;
            }
            else{
                break;
            }
        }
        if(DEBUG){
            cout << "Compiling optimal range from " << left << " to " << right << '\n';
        }
        ans = max(ans, (right - left) * 2);
        //Remove left
        mp[segments[left].first] = 0;
        if(!dq.empty()){
            dq.pop_front();
        }
        if(segments[left].second > 2){
            monkeys--;
        }
        left++;
        if(right < left){
            //reset
            dq.clear();
            mp.clear();
            right = left;
            monkeys = 0;
        }
    }
    ans = max(ans, (right - left) * 2);
    cout << ans;
}