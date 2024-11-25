#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; 
    cin >> N;
    vector<int> A(N);
    for (auto &i : A) cin >> i;

    vector<pair<int, int>> segments;
    pair<int, int> curr = {-1, -1};
    for (int i = 0; i < N; i++) {
        if (A[i] == curr.first) {
            curr.second++;
        } else {
            if (curr.first != -1) segments.push_back(curr);
            curr = {A[i], 1};
        }
    }
    segments.push_back(curr);
    deque<pair<int, int>> dq;
    map<int, int> mp;
    int left = 0, right = 0, ans = 0;

    while (left < segments.size()) {
        while (right < segments.size()) {
            auto [num, count] = segments[right];
            bool canAdd = false;

            if (mp[num] == 0) {
                if (count == 2) canAdd = true;
                if (count > 2 && (dq.empty() || dq.back().second == 2)) canAdd = true;
            }

            if (canAdd) {
                dq.push_back(segments[right]);
                mp[num]++;
                right++;
            } else {
                break;
            }
        }

        ans = max(ans, (int)dq.size() * 2);

        auto [num, count] = segments[left];
        mp[num]--;
        if (mp[num] == 0) mp.erase(num);
        if (!dq.empty()) dq.pop_front();
        left++;

        if (right < left) {
            dq.clear();
            mp.clear();
            right = left;
        }
    }

    cout << ans << '\n';
    return 0;
}
