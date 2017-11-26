#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
#define endl '\n'

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n,t;
  cin>>n>>t;
  vector<int>a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];
  int dp[t+1][n];
  for(int i=0;i<=t;i++)
    dp[i][0]=0;
  for(int i=0;i<n;i++)
    dp[0][i]=0;
  for(int i=1;i<=t;i++)
  {
    for(int j=1;j<=n;j++)
    {
      int max_so_far=INT_MIN;
      for(int m=0;m<j;m++)
        max_so_far=max(max_so_far,a[j]-a[m]+dp[i-1][m]);
      dp[i][j]=max(dp[i][j-1],max_so_far);
    }
  }
  cout<<dp[t][n-1]<<endl;
  return 0;
}
