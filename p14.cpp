#include<iostream>
#include<vector>
#include<math.h>
#include<map>

using namespace std;

int solve(vector<int>prices,int n,int k)
{
  vector<vector<int> >tab(k+1,vector<int>(n+1));
  for(int i=1;i<=k;i++)
    for(int j=1;j<n;j++)
      {
        int maxed = INT_MIN;
        for(int m=j-1;m>=0;m--)
          maxed = max(maxed,prices[j]-prices[m]+tab[i-1][m]);
        tab[i][j] = max(tab[i][j-1],maxed);
      }
    return tab[k][n-1];
}
int main()
{
  int n;
  cin>>n;
  int k;
  cin>>k;
  vector<int>prices(n);
  for(int i=0;i<n;i++)
    cin>>prices[i];
  cout<<solve(prices,n,k);
  return 0;
}
