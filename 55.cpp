#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
#define endl '\n'
int lcs(string a , string b)
{
  int m=a.size();
  int n=b.size();
  int dp[m+1][n+1];
  for(int i=0;i<=m;i++)
  {
    for(int j=0;j<=n;j++)
    {
      if(i==0||j==0)
        dp[i][j]=0;
      else if(a[i-1]==b[j-1])
        dp[i][j]=1+dp[i-1][j-1];
      else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }
  return dp[m][n];
}
int is_kpalin(string a, int k)
{
  string ra=a;
  reverse(ra.begin(),ra.end());
  int l=lcs(a,ra);
  return (a.size()-l<=k);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string a;
  int k;
  cin>>a>>k;
  is_kpalin(a,k)?cout<<"Yes"<<endl:cout<<"No"<<endl;
  return 0;
}
