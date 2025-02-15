#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define DEBUG 1
#define OUT(x) cerr<<(#x)<<'='<<(x)<<endl

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

}


/*
Assume we fix the L
bal[L - 1] = number of excess ( on the left of L
The number of excess ) on the right inclusive of L but be negaitve of bal[L - 1]
how ever we cant have
bal[L - 1] = 3 => ((( AND THEN )))))) (((
i.e, the maximum excess of ) starting from L must never exceed bal[L - 1]



*/