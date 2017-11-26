#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
using namespace std;
#define endl '\n'

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int m,n;
  cin>>m>>n;
  int a[m][n];
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
      cin>>a[i][j];
  int row[m][n],col[m][n];
  memset(row,0,sizeof(row));
  memset(col,0,sizeof(col));

  for(int i=0;i<m;i++)
  {
    int is_endless=1;
    for(int j=n-1;j>=0;j--)
    {
      if(!a[i][j])
        is_endless=0;
      row[i][j]=is_endless;
    }
  }
  for(int j=0;j<n;j++)
  {
    int is_endless=1;
    for(int i=m-1;i>=0;i--)
    {
      if(!a[i][j])
        is_endless=0;
      col[i][j]=is_endless;
    }
  }

  int ans=0;
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
      if(row[i][j] && col[i][j])
        ans++;

  cout<<ans<<endl;
  return 0;
}
