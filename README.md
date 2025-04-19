Competitive Programming Archives

This repository contains solutions and code for various competitive programming contests and problems.

Directory Structure:
- `.vscode/`: Contains Visual Studio Code configuration files.
- `AtCoder/`: Contains solutions for AtCoder contests.
  - `AtCoder Beginner Contest/`: Solutions for AtCoder Beginner Contests.
  - `AtCoder Grand Contest/`: Solutions for AtCoder Grand Contests.
  - `AtCoder Regular Contest/`: Solutions for AtCoder Regular Contests.
- `CodebreakerXYZ/`: Contains solutions for CodebreakerXYZ problems.
- `Codeforces/`: Contains solutions for Codeforces contests.
  - `Div 1/`: Solutions for Codeforces Division 1 contests.
  - `Div 2/`: Solutions for Codeforces Division 2 contests.
  - `Div 3/`: Solutions for Codeforces Division 3 contests.
  - `Div 4/`: Solutions for Codeforces Division 4 contests.
  - `Special/`: Solutions for special Codeforces contests.
- `References/`: Contains reference materials for data structures and algorithms.
  - `Data Structures/`: Reference materials for data structures.
  - `Graph Theory/`: Reference materials for graph theory.
- `labs.tex`: LaTeX file for lab reports or notes.
- `README.md`: This file.

How to Use:
1. Clone the repository:
    git clone https://github.com/your-username/competitive-programming-archives.git
2. Navigate to the directory of the contest/problem you want to view.
3. Open the relevant `.cpp` file to see the solution.

Example:
Here is an example of a solution for a Codeforces problem:
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1

#ifdef DEBUG
    #define OUT(x) cerr << (#x) << '=' << (x) << endl
    #define OUT2(c) cerr << (#c) << " = {"; for (auto it = (c).begin(); it != (c).end(); ++it) cerr << (it == (c).begin() ? "" : ", ") << *it; cerr << "}" << endl;
#else
    #define OUT(x)
    #define OUT2(c)
#endif

const int inf = 1e18;

void solve() {
    int n; cin >> n;
    // Initialize vectors for prefix and suffix sums
    vector<int> vect(n + 1), pre(n + 1, 0), suf(n + 2, 0);

    // Input the array elements
    for (int i = 1; i <= n; ++i) {
        cin >> vect[i];
    }

    // Compute prefix sums
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + vect[i];
    }

    // Compute suffix sums
    for (int i = n; i >= 1; --i) {
        suf[i] = suf[i + 1] + vect[i];
    }
}
...