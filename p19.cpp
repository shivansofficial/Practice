#include<iostream>
#include<vector>
#include<math.h>
#include<map>

using namespace std;

int main()
{
  int n,k;
  cin>>n;
  cin>>k;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  vector<vector<int> >tab(n+1,vector<int>(k+1));
  tab[0][0] = 0;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=k;j++)
      for(int m=i-1;m>=0;m--)
        dp[i][j] = min(dp[i][j],dp[m][j-1]+ pow(2,(a[i-1]-a[m])));
  cout<<dp[n][k];
  return 0;
}
