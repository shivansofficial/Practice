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
  int v,e;
  cin>>v>>e;
  int g[v][v];
  memset(g,0,sizeof(g));
  for(int i=0;i<e;i++)
  {
    int x,y;
    cin>>x>>y;
    g[x][y]=g[y][x]=1;
  }
  int s,d,k;
  cin>>s>>d>>k;

  int dp[v][v][k+1];
  memset(dp,0,sizeof(dp));
  for(int e=0;e<=k;e++)
  {
    for(int i=0;i<v;i++)
    {
      for(int j=0;j<v;j++)
      {
        if(i==j && e==0)
          dp[i][j][e]=1;
        if(e==1 && g[i][j])
          dp[i][j][e]=1;
        if(e>0)
        {
          for(int a=0;a<v;a++)
          {
            if(g[i][a])
              dp[i][j][e]+=dp[i][a][e-1];
          }
        }
      }
    }
  }
  cout<<dp[s][d][k]<<endl;
  return 0;
}
