#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
using namespace std;
#define endl '\n'
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m,sum;
  cin>>n>>m>>sum;
  int dp[n+1][sum+1];
  memset(dp,0,sizeof(dp));
  for(int i=1;i<=m && i<=sum ;i++)
    dp[1][i]=1;
  for(int i=2;i<=n;i++)
    for(int j=1;j<=sum;j++)
      for(int k=1;k<=m && k<j;k++)
        dp[i][j]+=dp[i-1][j-k];

  cout<<dp[n][sum]<<endl;
  return 0;
}
