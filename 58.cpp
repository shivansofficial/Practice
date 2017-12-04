#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
#define endl '\n'
int dp[100][100][100][3];
int count(int p,int q,int r,int last)
{
  if(p<0||q<0||r<0)
    return 0;
  if(p==1 && q==0 && r==0 && last==0)
    return 1;
  if(p==0 && q==1 && r==0 && last==1)
    return 1;
  if(p==0 && q==0 && r==1 && last==2)
    return 1;
  if(dp[p][q][r][last]!=-1)
    return dp[p][q][r][last];

  if(last==0)
    dp[p][q][r][last]=count(p-1,q,r,1)+count(p-1,q,r,2);
  else if(last==1)
    dp[p][q][r][last]=count(p,q-1,r,0)+count(p,q-1,r,2);
  else
    dp[p][q][r][last]=count(p,q,r-1,0)+count(p,q,r-1,1);
  return dp[p][q][r][last];
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int p,q,r;
  cin>>p>>q>>r;
  memset(dp,-1,sizeof(dp));
  cout<<count(p,q,r,0)+count(p,q,r,1)+count(p,q,r,2)<<endl;
  return 0;
}
