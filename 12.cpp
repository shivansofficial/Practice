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
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];

  int dp[n][2];

  for(int i=0;i<n;i++)
  {
    dp[i][0]=1;
    dp[i][1]=1;
  }

  int res=-1;

  for(int i=1;i<n;i++)
  {
    for(int j=0;j<i;j++)
    {
      if(a[i]>a[j] && dp[i][0]<dp[j][1]+1)
        dp[i][0]=dp[j][1]+1;
      if(a[i]<a[j] && dp[i][1]<dp[j][0]+1)
        dp[i][1]=dp[j][0]+1;
    }
  }

  for(int i=0;i<n;i++)
  {
    res=max(res,max(dp[i][0],dp[i][1]));
  }
  cout<<res<<endl;
  return 0;
}
