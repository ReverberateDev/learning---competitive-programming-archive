#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define N 200000
#define M 20

int main(void){
	int n;
	int a[N];
	int nxt[N+2][M];
	int r[(1<<M)];
	int ans=0,cnt;

	cin>>n;
	rep(i,n)cin>>a[i];

	rep(j,M)nxt[n][j]=n+1,nxt[n+1][j]=n+1;  //n+1=\infty
	for(int i=n-1;i>=0;i--){
		rep(j,M)nxt[i][j]=nxt[i+1][j];
		nxt[i][a[i]-1]=i+1;
	}
    

    for(int i = 0; i < n; i++){
        for(int j = 0; j < M; j++){
            cout << nxt[i][j] << " ";
        }
        cout << '\n';
    }

	rep(i,(1<<M))r[i]=n+1;
	r[0]=0;
	rep(i,(1<<M)){
		cnt=0;
		rep(j,M){
			if((i>>j)&1){
				cnt+=2;
				r[i]=min(r[i],nxt[nxt[r[i^(1<<j)]][j]][j]);
			}
		}
		if(r[i]<=n)ans=max(ans,cnt);
	}

	cout<<ans<<endl;
	return 0;
}
