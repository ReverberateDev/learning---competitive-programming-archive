#include <bits/stdc++.h>
using namespace std;
int p[10010]={};
double dp[10010]={1},f[10010]={};
int main()
{
    int n,x;
    cin>>n>>x;
    for (int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    for (int i=0;i<n;i++)
    {
        double q=0.01*p[i];
        for (int j=i;j>=0;j--)
        {
            dp[j+1]+=dp[j]*q;
            dp[j]*=1-q;
        }
    }
    double s=1-dp[0];
    for (int i=1;i<=n;i++)
    {
        dp[i]/=s;
    }
    for(int i = 0; i <= n; i++){
        cout << dp[i] << " ";
    }
    cout << '\n';
    for (int i=1;i<=x;i++)
    {
        for (int j=1;j<=n;j++)
        {
            f[i]+=f[max(i-j,0)]*dp[j];
        }
        f[i]+=1;
    }
    printf("%.17lf",f[x]/s);
    return 0;
}