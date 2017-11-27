#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
using namespace std;
#define endl '\n'
int find_optimal(int n)
{
  if(n<=6)
    return n;

  int dp[n];
  int b;
  for(int i=1;i<=6;i++)
    dp[i-1]=i;

  for(int i=7;i<=n;i++)
  {
    dp[i-1]=0;
    for(int b=i-3;b>=1;b--)
    {
      int cur_len=(i-b-1)*dp[b-1];
      if(cur_len>dp[i-1])
        dp[i-1]=cur_len;
    }
  }
  return dp[n-1];
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  cout<<find_optimal(n)<<endl;
  return 0;
}
