#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
using namespace std;
#define endl '\n'
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n,k;
  cin>>n>>k;
  vector<int> a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];

  int dp[n+1][k+1];
  for(int i=0;i<=n;i++)
    for(int j=0;j<=k;j++)
      dp[i][j]=1000000000;

  dp[0][0]=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=k;j++)
    {
      for(int m=0;m<i;m++)
      {
        dp[i][j]=min(dp[i][j],dp[m][j-1]+(a[i-1]-a[m])*(a[i-1]-a[m]));
      }
    }
  }
  cout<<dp[n][k]<<endl;
  return 0;
}
