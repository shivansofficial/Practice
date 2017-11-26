#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<string>
using namespace std;
#define endl '\n'
int x[]={1,1,1,-1,-1,-1,0,0};
int y[]={0,1,-1,0,1,-1,1,-1};
bool valid(int i,int j,vector<vector<char> >a)
{
  return !(i<0||j<0||i>a.size()-1||j>a[0].size()-1);
}
bool adj(char c,char p)
{
  return ((c-p)==1);
}
int get_max_len(vector<vector<char> >a,vector<vector<int> > dp,int i,int j,char prev)
{
  if(!valid(i,j,a)||!adj(a[i][j],prev))
    return 0;

  if(dp[i][j]!=-1)
    return dp[i][j];

  int ans=0;

  for(int k=0;k<8;k++)
  {
    ans=max(ans,1+get_max_len(a,dp,i+x[k],j+y[k],a[i][j]));
  }
  return dp[i][j]=ans;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int r,c;
  cin>>r>>c;
  vector<vector<char> > a(r,vector<char>(c));
  for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
      cin>>a[i][j];
  vector<vector<int> > dp(r,vector<int>(c,-1));
  int ans=0;
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
    {
      for(int k=0;k<8;k++)
      {
        ans=max(ans,1+get_max_len(a,dp,i+x[k],j+y[k],a[i][j]));
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
