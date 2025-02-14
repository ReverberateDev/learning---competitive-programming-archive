/**
 *    author:  tourist
 *    created: 20.01.2025 09:46:55
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    /*
    vector<int> s(1 << m);
    vector<int> bc(1 << m);
    for (int t = 0; t < (1 << m); t++) {
      int x = (1 << 30) - 1;
      for (int i = 0; i < m; i++) {
        if (t & (1 << i)) {
          x &= b[i];
        }
      }
      s[t] = x;
      bc[t] = __builtin_popcountll(unsigned(t));
    }
    */
   vector<int> s(1 << m), bc(1 << m);
   for(int bmask = 0; bmask < (1 << m); bmask++){
       int x = (1 << 30) - 1;
       for(int i = 0; i < m; i++){
           if(bmask & (1 << i)){
               x &= b[i];
           }
       }
       s[bmask] = x;
       bc[bmask] = __builtin_popcountll(unsigned(bmask));
   }
    vector<int> gain(n * m);
    vector<int> c(m + 1);
    for (int i = 0; i < n; i++) {
      fill(c.begin(), c.end(), (1 << 30) - 1);
      for (int t = 0; t < (1 << m); t++) {
        c[bc[t]] = min(c[bc[t]], a[i] & s[t]);
      }
      for (int j = 1; j <= m; j++) {
        gain[i * m + j - 1] = c[j - 1] - c[j];
      }
    }
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
      ans += a[i];
    }
    sort(gain.rbegin(), gain.rend());
    for (int i = 0; i < k; i++) {
      ans -= gain[i];
    }
    cout << ans << '\n';
  }
  return 0;
}
