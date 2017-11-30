#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
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
  int dp[n][n];
  for(int gap=1;gap<n;gap++)
  {
    for(int i=0,j=gap;j<n;i++,j++)
    {

      int x=((i+2)<=j)?dp[i+2][j]:0;
      int y=((i+1)<=(j-1))?dp[i+1][j-1]:0;
      int z=(i<=(j-2))?dp[i][j-2]:0;
      dp[i][j]=max(a[i]+min(x,y),a[j]+min(y,z));
    }
  }
  cout<<dp[0][n-1]<<endl;
  return 0;
}
