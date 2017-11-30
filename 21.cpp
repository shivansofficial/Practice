#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
#define endl '\n'
long long dp[20][10][10][2][2][2];
vector<int> dig;
long long count(long long n)
{
  int i,j,k,cur,is_odd,is_even,size;
  long long ans=0;
  dig.clear();
  while(n>0)
  {
    dig.push_back(n%10);
    n/=10;
  }
  size=dig.size();
  reverse(dig.begin(),dig.end());
  if(size<3)
    return 0LL;
  for(i=0;i<20;i++)
    for(j=0;j<10;j++)
      for(k=0;k<10;k++)
        for(is_odd=0;is_odd<2;is_odd++)
          for(is_even=0;is_even<2;is_even++)
            {
              dp[i][j][k][is_odd][is_even][0]=0;
              dp[i][j][k][is_odd][is_even][1]=0;
            }
  for(i=1;i<10;i++)
  {
    for(j=0;j<10;j++)
    {
      if(i*10+j<=dig[0]*10+dig[1])
        dp[1][i][j][0][i==j][(i*10+j)==(dig[0]*10+dig[1])]+=1;
    }
  }
  for(i=2;i<size;i++)
  {
    for(j=0;j<10;j++)//last_2nd
    {
      for(k=0;k<10;k++)//last
      {
        for(is_odd=0;is_odd<2;is_odd++)
        {
          for(is_even=0;is_even<2;is_even++)
          {
            for(cur=0;cur<10;cur++)
            {
              dp[i][k][cur][is_odd|(j==cur)][is_even|(k==cur)][0]+=dp[i-1][j][k][is_odd][is_even][0];
              if(cur==dig[i])
                dp[i][k][cur][is_odd|(j==cur)][is_even|(k==cur)][1]+=dp[i-1][j][k][is_odd][is_even][1];
              else if(cur<dig[i])
                dp[i][k][cur][is_odd|(j==cur)][is_even|(k==cur)][0]+=dp[i-1][j][k][is_odd][is_even][1];
            }
          }
        }
      }
    }
    for(j=1;j<10;j++)
      for(k=0;k<10;k++)
        dp[i][j][k][0][k==j][0]+=1;
  }
  for(i=0;i<10;i++)
    for(j=0;j<10;j++)
      {
        ans+=dp[size-1][i][j][1][1][0];
        ans+=dp[size-1][i][j][1][1][1];
      }
    return ans;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
    long long a,b,ans;
    cin>>a>>b;
    ans=count(b)-count(a);
    cout<<ans<<endl;
  }
  return 0;
}
