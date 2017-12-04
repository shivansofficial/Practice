#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
#define endl '\n'
int min_initial_points(vector<vector<int> >a)
{
  int m=a.size();
  int n=a[0].size();
  int dp[m][n];
  dp[m-1][n-1]=a[m-1][n-1]>0?1:abs(a[m-1][n-1])+1;
  for(int i=n-2;i>=0;i--)
    dp[m-1][i]=max(dp[m-1][i+1]-a[m-1][i],1);
  for(int i=m-2;i>=0;i--)
    dp[i][n-1]=max(dp[i+1][n-1]-a[i][n-1],1);

  for(int i=m-2;i>=0;i--)
  {
    for(int j=n-2;j>=0;j--)
    {
      int min_exit_points=min(dp[i+1][j],dp[i][j+1]);
       dp[i][j]=max(min_exit_points-a[i][j],1);
    }
  }
  return dp[0][0];
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int m,n;
  cin>>m>>n;
  vector<vector<int> >a(m,vector<int>(n,0));
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
      cin>>a[i][j];
  cout<<min_initial_points(a)<<endl;
  return 0;
}
